idf_component_register(SRCS "Main.c" "./PWM/PWM.c""./OLED/oled.c""./Tcp_Client/tcp_client_select.c""./Tcp_Client/wifi_softap_sta.c""./Tcp_Client/event_handler.c""./OLED/fonts.c"
                    INCLUDE_DIRS ".""./PWM""./OLED""./Tcp_Client"
                    )