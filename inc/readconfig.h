/**********************************************************
* ** 文件名：readconfig.h
* ** Copyright (C) 2018 xiethon@126.com
*
* ** 创建者:xiethon
* ** 日  期：2018年01月01日11时34分
* ** 描  述：
* ** 版  本：V1.0
*
* ** 修改人：
* ** 日  期：
* ** 修改描述：
* ** 版本号：
*
****************************************************/
#ifndef _READCONFIG_H_
#define _READCONFIG_H_

//从配置文件中读取一个字符串
int config_string_get( char *configfile,char *section, char *key,char* ret_buf);
//从配置文件中读取一个整型值
int config_int_get( char* configfile,char *_section, char *key,int* ret_val);
//从配置文件中读取一个浮点值
int config_float_get( char* configfile,char *_section, char *key,float* ret_val);

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif //READCONFIG_H
