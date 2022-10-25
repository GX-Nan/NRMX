idf_component_register(SRCS "Main.c" "./Dc_Motor/Dc_Motor.c""./OLED/oled.c""./Tcp_Client/tcp_client_select.c""./Tcp_Client/wifi_softap_sta.c""./Tcp_Client/event_handler.c""./OLED/fonts.c"
                    INCLUDE_DIRS ".""./Dc_Motor""./OLED""./Tcp_Client"
                    )