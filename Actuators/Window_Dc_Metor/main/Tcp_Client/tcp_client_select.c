#define tcp_client_select_c_

#include "tcp_client_select.h"

static const char *TAG = "tcp_client_select";

void Time_reverse(void *arg);
void Time_Forward(void *arg);

esp_timer_handle_t handle_reverse = 0;
esp_timer_handle_t handle_Forward = 0;

esp_timer_create_args_t reverse = {
    .callback = &Time_reverse, //定时器回调函�?
    .arg = NULL,               //传递给回调函数的参�?
    .name = "reverse"          //定时器名�?
};

esp_timer_create_args_t Forward = {
    .callback = &Time_Forward, //定时器回调函�?
    .arg = NULL,               //传递给回调函数的参�?
    .name = "Forward"          //定时器名�?
};

#if 1 //是否打印日志
#define my_printf ESP_LOGE
#else
#define my_printf(...)
#endif

/**
 * @brief  select TCP客户�?
 * @param  none
 * @retval none
 */
static int New_Mode;
static int LastMode;
static float Local_Time;
static int Value = 0;
static int StopTime = 0;
static float Start_Time;
static int TimerFalg=0;

void Time_reverse(void *arg)
{
    int64_t tick = esp_timer_get_time();
    Local_Time = tick / 1000000;
    printf("timer cnt = %f \r\n", Local_Time - Start_Time);
    oled_show_str(0, 0, "Time_reverse --", &Font_7x10, 1);
    // oled_show_str(2,0,  Local_Time - Start_Time, &Font_7x10, 1);
    if ((Local_Time - Start_Time) >= 20 || StopTime == 1) //
    {
        Slow_Motion_Down(1);
        Stop();
        //定时器暂停、删�?
        esp_timer_stop(handle_reverse);
        esp_timer_delete(handle_reverse);
        TimerFalg=1;
        StopTime = 0;
        printf("Time_reverse stop and delete!!! \r\n");
    }
}

void Time_Forward(void *arg)
{

    int64_t tick = esp_timer_get_time();
    Local_Time = tick / 1000000;
    printf("timer cnt = %f \r\n", Local_Time - Start_Time);

    oled_show_str(0, 0, "Time_Forward --", &Font_7x10, 1);

    if ((Local_Time - Start_Time) >= 20 || StopTime == 1) //
    {
        Slow_Motion_Down(1);
        Stop();
        //定时器暂停、删�?
        esp_timer_stop(handle_Forward);
        esp_timer_delete(handle_Forward);
        TimerFalg=1;
        StopTime = 0;
        printf("Time_Forward stop and delete!!! \r\n");
    }
}

int substring(char *res, int pos, int len, char *substr) //从pos开始取len个字符到substr�?
{
    char *p = res;
    int i = 0;
    if (pos > strlen(res))
        return 0;
    pos--;
    while (i < len)
    {
        substr[i++] = res[pos++];
        if (pos > strlen(res))
        {
            substr[i] = '\0';
            break;
        }
    }
    substr[i] = '\0';
    return 1;
}

int del_substr(char *res, int pos, int len) //从res的pos位置开始删除len个字�?  res----首地址 pos----规定的位�? len-----删除len位地址
{
    int i = 0; //判断是否超出字符串范�?
    if (pos > strlen(res))
        return 0;
    char *p = res + (pos - 1), *q = res + (pos + len - 1);
    do
    {
        *p++ = *q++;

    } while (*q != '\0');
    *p = '\0';
    return 1;
}
void Work_Mode(int Mode)
{
    int64_t tick, tick1;
    switch (Mode)
    {
    case 1:
        if (Value == 3&&TimerFalg!=1)
        {
            esp_timer_stop(handle_reverse);
            esp_timer_delete(handle_reverse);
            Slow_Motion_Down(1);
            Stop();
        }
        Clockwise(); //正转
        //V_Max();
        Slow_Motion_Up(1);
        //电机启动
        tick = esp_timer_get_time();
        Start_Time = tick / 1000000;
        //定时�?-------------------------------------
        /*创建定时�?*/ //初始化参�?              //定时器句�?,用于后期对定时器做其它操�?
        esp_timer_create(&Forward, &handle_Forward);
        /*以单次方式启动定时器*/ //定时器句�?       //us级定�?,1000*1000就是1s
        esp_timer_start_periodic(handle_Forward, 1000 * 1000);
        TimerFalg=0;
        Value = 2;

        break;
    case 2:

        if (Value == 2&&TimerFalg!=1)
        {
            if(handle_Forward)
            esp_timer_stop(handle_Forward);
            esp_timer_delete(handle_Forward);
            Slow_Motion_Down(1);
            Stop();
        }
        AntiClockwise();   //反转
        Slow_Motion_Up(1);
                           // vTaskDelay(5000 / portTICK_RATE_MS);
        //V_Max(); //电平反转 所�? pwm�?0就是满电�?
        tick1 = esp_timer_get_time();
        Start_Time = tick1 / 1000000;

        esp_timer_create(&reverse, &handle_reverse);
        esp_timer_start_periodic(handle_reverse, 1000 * 1000);
        TimerFalg=0;
        Value = 3;

        break;
    case 3:
        StopTime = 1;

        Slow_Motion_Down(1);

        oled_show_str(0, 0, "Motor Station : Stop", &Font_7x10, 1);
        Stop();
        StopTime = 0;
        break;
    }
    LastMode = Mode;
}

void tcp_client_select_task(void *arg)
{

    pv_tcp_client_select_struct_t *pv_tcp_client_select_value = (pv_tcp_client_select_struct_t *)arg;
    uint8_t need_dns = 0;

    struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
    };
    struct addrinfo *res;

    int err, len;
    int socket_fd;
    char connection_state = 0;
    struct sockaddr_in server_addr, local_addr;
    fd_set read_set;

    char substr[11];
    char TopNumber[11];
    char Sub[2];
    char Main[2];

    //尝试DNS解析,如果解析失败说明确实需要DNS解析,但是需要先连接路由�?
    err = getaddrinfo(pv_tcp_client_select_value->ip, NULL, &hints, &res);
    if (err != 0 || res == NULL)
    {
        my_printf(TAG, "DNS lookup failed err=%d res=%p", err, res);
        need_dns = 1;
    }
    if (need_dns)
    { //等待模组连接上路由器
        xEventGroupWaitBits(EventGroupHandleWiFiEvent, EventBitsWiFiStaConnected, false, true, portMAX_DELAY);
    }
    err = getaddrinfo(pv_tcp_client_select_value->ip, NULL, &hints, &res);
    if (err != 0 || res == NULL)
    {
        my_printf(TAG, "DNS lookup failed err=%d res=%p", err, res);
        return;
    }

    /*本地地址配置*/
    local_addr.sin_family = AF_INET;

    /*服务器配�?*/
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(pv_tcp_client_select_value->port);
    server_addr.sin_addr.s_addr = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;
    freeaddrinfo(res);
    char *CatchNumber = (char *)pvPortMalloc(512 * sizeof(char)); //当前内存 229644
    char *LastNumber = (char *)pvPortMalloc(512 * sizeof(char));
    printf("分配地址\r\n");
    while (true)
    {
        //创建socket
        socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd < 0)
        {
            my_printf(TAG, "Failed to allocate socket.");
        }
        //绑定socket
        err = bind(socket_fd, (struct sockaddr *)&local_addr, sizeof(local_addr));
        if (err < 0)
        {
            my_printf(TAG, "Failed to bind socket");
            close(socket_fd);
        }
        //清空fdset
        FD_ZERO(&read_set);
        //把sfd文件描述符添加到集合�?
        FD_SET(socket_fd, &read_set);

        if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0)
        {
            ESP_LOGE(TAG, "Socket connection failed: %d", socket_fd);
            close(socket_fd);
        }
        else
        {
            ESP_LOGE(TAG, "Socket connection sucess: %d", socket_fd);
            connection_state = 1;
            pv_tcp_client_select_value->socket_fd = socket_fd;
            pv_tcp_client_select_value->connected = 1;
        }
        vTaskDelay(3000 / portTICK_PERIOD_MS); //延时

        while (connection_state)
        {
            err = select(socket_fd + 1, &read_set, NULL, NULL, NULL);
            //没有超时机制，不会返�?0
            if (err < 0)
            {
                my_printf(TAG, "select error \r\n");
                close(socket_fd);
                connection_state = 0;
                pv_tcp_client_select_value->connected = 0;
            }

            if (FD_ISSET(socket_fd, &read_set))
            {
            again:
                len = read(socket_fd, pv_tcp_client_select_value->read_buff, sizeof(pv_tcp_client_select_value->read_buff));

                if (len < 0)
                {
                    if (errno == EINTR)
                    {
                        goto again;
                    }
                }
                if (len <= 0)
                {
                    close(socket_fd);
                    connection_state = 0;
                    pv_tcp_client_select_value->connected = 0;
                }
                else
                { //接收到客户端消息
                    pv_tcp_client_select_value->read_buff[len] = 0;
                    strcpy(pv_tcp_client_select_value->MessageJudge, pv_tcp_client_select_value->read_buff);
                    //  printf("MessageJudge is:%s\r\n", pv_tcp_client_select_value->MessageJudge); //赋值给判断判断的数�?
                    // printf("Sizeof Message:%d\r\n",sizeof(pv_tcp_client_select_value->MessageJudge));
                    // ZB1010101----->开�?
                    // ZB1010102----->关窗
                    // ZB1010103----->停止
                    CatchNumber = strstr(pv_tcp_client_select_value->MessageJudge, "ZB"); // 229516
                    if (CatchNumber != 0)
                    {
                        for (int i = 0; i <= strlen(CatchNumber) / 10; i++)
                        {
                            strncpy(substr, CatchNumber, 10);
                            strncpy(TopNumber, CatchNumber, 10); //拷贝副本
                            substring(TopNumber, 3, 1, Main);    //提取Main得字�?
                            substring(TopNumber, 5, 1, Sub);     //提取Sub得字�?
                            if (strcmp(substr, LastNumber) != 0)
                            {
                                if (strcmp(Main, "1") == 0)
                                {
                                    if (strcmp(Sub, "1") == 0) //尝试匹配字符
                                    {

                                        if (strcmp(substr, "ZB10101011") == 0) //窗户1开�?
                                        {
                                            New_Mode = 1;
                                            printf("window---one---Open\r\n");
                                            if (New_Mode != LastMode)
                                            {
                                                Work_Mode(1);
                                            }
                                        }
                                        else if (strcmp(substr, "ZB10101021") == 0) //窗户1关闭
                                        {
                                            printf("window---one---close\r\n");
                                            New_Mode = 2;
                                            if (New_Mode != LastMode)
                                            {
                                                Work_Mode(2);
                                            }
                                        }
                                        else if (strcmp(substr, "ZB10101031") == 0) //窗户1停止
                                        {
                                            printf("window---one---Stop\r\n");
                                            New_Mode = 3;
                                            if (New_Mode != LastMode)
                                            {
                                                Work_Mode(3);
                                            }
                                        }
                                    }
                                }
                            }
                            del_substr(CatchNumber, 0, 10);
                            strcpy(Sub, "");
                            strcpy(Main, "");
                        }
                    }
                    printf("free_heap_size = %d\n", esp_get_free_heap_size());

                    // pv_tcp_client_select_value->CallBack(pv_tcp_client_select_value->read_buff,len);//回传
                    // len = write(socket_fd, pv_tcp_client_select_value->read_buff, len);
                }
            }
        }
    }
    heap_caps_free(CatchNumber);
    CatchNumber = NULL;

    vTaskDelete(NULL);
}

/**
 * @brief  select TCP客户�?
 * @param  pv_tcp_client_select_value 客户端结构体
 * @param  task_priority TCP客户端任务优先级
 * @param  RecvDataCallBack 接收回调函数
 * @retval none
 */
void tcp_client_select_task_init(pv_tcp_client_select_struct_t *pv_tcp_client_select_value, int task_priority, void (*RecvDataCallBack)(char *data, int len))
{
    pv_tcp_client_select_value->socket_fd = -1;
    pv_tcp_client_select_value->connected = 0;
    pv_tcp_client_select_value->CallBack = RecvDataCallBack;
    // vPortInitialiseBlocks();//初始�?

    //--------------------------------------------------------------------
    //启动定时�?
    //定时器结构体初始�?

    //--------------------------------------------------------------
    //创建TCP任务
    xTaskCreate(tcp_client_select_task, "tcp_client_select_task", 4096, pv_tcp_client_select_value, task_priority, NULL);
}
