/**********************************************************
* ** 文件名：readconfig.c
* ** Copyright (C) 2018 xiethon@126.com
*
* ** 创建者：xiethon
* ** 日  期：2018年01月01日11时25分
* ** 描  述：读取配置文件实现代码
* ** 版  本：V1.0
*
* ** 修改人：
* ** 日  期：
* ** 修改描述：
* ** 版本号：
*
****************************************************/
#include"../inc/debug.h"
#include"../inc/readconfig.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/********************************
function：config_string_get
description： 获取段名内字段的值
param：configfile,配置文件文件名，section,段名。key，字段，ret_buf,要返回的字符串
return：成功返回0，不成功返回-1
**********************************/
int config_string_get( char* configfile,char *_section, char *key,char* ret_buf)
{
    FILE  *fp            = NULL;
    char  buf[128];
    char  key_buf[128]  = {'\0'};
    char  section[128] = {'\0'};
    int len = 0;
    int i = 0;

    // 先对输入参数进行异常判断
    if (section == NULL || key == NULL ||  configfile == NULL)
    {
        DEBUG("GetConfigFileStringValue: input parameter(s) is NULL!\n");
        return;
    }
    if((fp = fopen(configfile,"r")) == NULL)
    {
        perror("open config file err");
        return;
    }
    sprintf(section, "[%s]", _section);
    while(feof(fp) == 0)
    {
        memset(buf,'\0',sizeof(buf)); //清空缓冲区
        fgets(buf,sizeof(buf),fp); //读取一行

        //过滤注释行，或以特殊字符开头的行
        if (buf[0] == '#' || buf[0] == '\r' || buf[0] == '\n' || buf[0] == '\0')
        {
            continue;
        }
        //匹配段名
        if (strncasecmp(section, buf, strlen(section)) ==0)
        {
            //匹配字段
            while(feof(fp) ==0)
            {
                memset(buf,'\0',sizeof(buf));
                fgets(buf,sizeof(buf),fp);
                if (buf[0] == '#' || buf[0] == '\r' || buf[0] == '\n' || buf[0] == '\0')
                {
                    continue;
                }
                if (strncasecmp(key, buf, strlen(key)) ==0) //忽略大小写
                {
                    //匹配字段成功
                    len = strlen(key);
                    //过滤多余字符
                    for(i=len;i<strlen(buf);i++)
                    {
                        if(buf[i] == '=')
                        {
                            break;
                        }
                    }
                    for(i=i+1;i<len;i++)
                    {
                        if(buf[i] == '\0')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    strcpy(ret_buf,buf+i);
                    return 0;
                }
            }
        }
    }
    fclose(fp);
    fp = NULL;
    memset(ret_buf,'\0',strlen(ret_buf));
    return -1;
}

/********************************
function：config_int_get
description： 获取段名内字段的值
param：configfile,配置文件文件名，section,段名。key，字段,ret_val:要获取的数据
return：成功返回0，不成功返回-1
**********************************/
int config_int_get( char* configfile,char *_section, char *key,int* ret_val)
{
    char buf[128];
    int ret = config_string_get(configfile,_section,key,buf);
    if(ret != 0)
        return ret;
    *ret_val = atoi(buf);
    return 0;
}

/********************************
function：config_int_get
description： 获取段名内字段的值
param：configfile,配置文件文件名，section,段名。key，字段,ret_val:要获取的数据
return：成功返回0，不成功返回-1
**********************************/
int config_float_get( char* configfile,char *_section, char *key,float* ret_val)
{
    char buf[128];
    int ret = config_string_get(configfile,_section,key,buf);
    if(ret != 0)
        return ret;
    *ret_val = atof(buf);
    return 0;
}
