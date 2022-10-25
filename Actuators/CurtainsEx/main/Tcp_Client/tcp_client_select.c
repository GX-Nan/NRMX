#define tcp_client_select_c_

#include "tcp_client_select.h"

static const char *TAG = "tcp_client_select";

#if 1 //是否打印日志
#define my_printf ESP_LOGE
#else
#define my_printf(...)
#endif

/**
 * @brief  select TCP客户�??
 * @param  none
 * @retval none
 */

int substring(char *res, int pos, int len, char *substr) //从pos开始取len个字符到substr�??
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

int del_substr(char *res, int pos, int len) //从res的pos位置开始删除len个字�??  res----首地址 pos----规定的位�?? len-----删除len位地址
{
    int i = 0; //判断是否超出字符串范�??
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
void GPIO_init()
{
    // gpio配置结构�??
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ull << 27) | (1ull << 26)|(1ull << 25),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 0,
        .pull_up_en = 0,
    };
    gpio_config(&io_conf);
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

    char TopNumber[11];
    char TopNumber_2[11];
    char Sub[2];
    char Main[5];
    char Data[2];

    //尝试DNS解析,如果解析失败说明确实需要DNS解析,但是需要先连接路由�??
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

    /*服务器配�??*/
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(pv_tcp_client_select_value->port);
    server_addr.sin_addr.s_addr = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;
    freeaddrinfo(res);
    char *CatchNumber = (char *)pvPortMalloc(512 * sizeof(char)); //当前内存 229644
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
        //把sfd文件描述符添加到集合�??
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
            //没有超时机制，不会返�??0
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
                    printf("MessageJudge is:%s\r\n", pv_tcp_client_select_value->MessageJudge); //赋值给判断判断的数�??
                    CatchNumber = strstr(pv_tcp_client_select_value->MessageJudge, "ZB"); // 229516
                    if (CatchNumber != 0)
                    {
                        for (int i = 0; i <= strlen(CatchNumber) / 10; i++)
                        {

                            strncpy(TopNumber, CatchNumber, 10); //拷贝副本

                            strncpy(TopNumber_2, CatchNumber, 10);

                            substring(TopNumber_2, 3, 3, Main); //提取Main得字�???

                            substring(TopNumber, 7, 1, Sub); //提取Main得字�???

                            substring(TopNumber, 8, 2, Data); //提取Sub得字�???
                            //26--->up 27---->stop  25----》down
                            if (strcmp(Main, "102") == 0)
                            {
                                if (strcmp(Sub, "1") == 0||strcmp(Sub, "0") == 0) //尝试匹配字符
                                {
                                    int Addtion = (atoi(Data));
                                    switch (Addtion)
                                    {
                                    case 0:
                                        gpio_set_level(25, 0);
                                        gpio_set_level(27, 0);
                                        vTaskDelay(500 / portTICK_RATE_MS);
                                        gpio_set_level(26, 1);//26--->up
                                        printf("up\r\n");
                                        break;
                                    case 1:
                                        gpio_set_level(27, 0);
                                        gpio_set_level(26, 0);
                                        vTaskDelay(500 / portTICK_RATE_MS);
                                        gpio_set_level(25, 1);
                                        printf("Down\r\n");
                                        break;
                                    case 2:
                                        // gpio_set_level(26, 0);
                                        // vTaskDelay(500 / portTICK_RATE_MS);
                                        // gpio_set_level(26, 1);
                                        // printf("down----time----500\r\n");  
                                        break;
                                    case 3:
                                        // gpio_set_level(26, 0);
                                        // vTaskDelay(500 / portTICK_RATE_MS);
                                        // gpio_set_level(27, 0); 
                                        // printf("Up----time----500\r\n");  
                                        break;
                                    case 4:
                                        gpio_set_level(26, 0);
                                        gpio_set_level(25, 0); 
                                        vTaskDelay(500 / portTICK_RATE_MS);
                                        gpio_set_level(27, 1);
                                        printf("stop\r\n");
                                        break;
                                    }
                                }
                            }

                            del_substr(CatchNumber, 0, 10);
                            strcpy(Sub, "");
                            strcpy(Main, "");
                        }
                    }
                }
            }
        }
    }
    heap_caps_free(CatchNumber);

    CatchNumber = NULL;

    vTaskDelete(NULL);
}

/**
 * @brief  select TCP客户�??
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
    // vPortInitialiseBlocks();//初始�??
    GPIO_init();
    //--------------------------------------------------------------------
    //启动定时�??
    //定时器结构体初始�??

    //--------------------------------------------------------------
    //创建TCP任务
    xTaskCreate(tcp_client_select_task, "tcp_client_select_task", 4096, pv_tcp_client_select_value, task_priority, NULL);
}
