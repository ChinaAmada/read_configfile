/**********************************************************
* ** 文件名：main.c
* ** Copyright (C) 2018 xiethon@126.com
*
* ** 创建者：xiethon
* ** 日  期：2018年01月01日11时40分
* ** 描  述：读取配置文件测试代码
* ** 版  本：V1.0
*
* ** 修改人：
* ** 日  期：
* ** 修改描述：
* ** 版本号：
*
****************************************************/
#include"../inc/readconfig.h"
#include"../inc/debug.h"

int main(void)
{
    char ip[32];
    char hostname[32];
    int port = 0;
    int ret = config_string_get( "./etc/config.ini","NET", "ip",ip);
    if(-1 == ret)
        DEBUG("get config ip error\n");
    else
        DEBUG("ip=%s",ip);

    if(config_int_get( "./etc/config.ini","NET", "port",&port) ==-1)
        DEBUG("get config port error\n");
    else
        DEBUG("port=%d\n",port);

    if(config_string_get( "./etc/config.ini","NET", "hostname",hostname) ==-1)
        DEBUG("get config port error\n");
    else
        DEBUG("hostname=%s",hostname);
}
