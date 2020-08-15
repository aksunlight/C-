#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Sck_Handle
{
	char version[16];
	char ip[16];
	int port;
	
	unsigned char* p; 
	int len;
}Sck_Handle;

//客户端初始化
_declspec(dllexport)
int cltSocketInit(void** handle/*out*/)  //相对第一套没有改动 
{
	int ret = 0;
	Sck_Handle* tmpHandle = NULL;
	
	if(handle == NULL)
	{
		ret = -1;
		printf("func cltSocketInit() err:%d check handle == NULL err\n", ret);
		return ret;
	}
	
	tmpHandle = (Sck_Handle*)malloc(sizeof(Sck_Handle));
	if(tmpHandle == NULL)
	{
		ret = -2;
		printf("func cltSocketInit() err:%d check malloc err\n", ret);
		return ret;
	}
	
	memset(tmpHandle, 0, sizeof(Sck_Handle));
	strcpy(tmpHandle->version, "1.0.0.1");
	strcpy(tmpHandle->ip, "192.168.12.12");
	tmpHandle->port = 8081; 
	
	//间接赋值 
	*handle = tmpHandle;
	
	return ret;
}
	
//客户端发报文
_declspec(dllexport)
int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/)  //相对第一套没有改动 
{
	int ret = 0; 
	Sck_Handle* tmpHandle = NULL;
	
	if(handle == NULL || buf == NULL || buflen <= 0)
	{
		ret = -2;
		printf("func cltSocketSend() err:%d check handle == NULL || buf == NULL || buflen <= 0 err\n", ret);
		return ret;
	}
	
	tmpHandle = (Sck_Handle*)handle;
	tmpHandle->len = buflen;
	tmpHandle->p = (unsigned char*)malloc(buflen);
	if(tmpHandle->p == NULL)
	{
		ret = -2;
		printf("func cltSocketSend() err:%d check malloc len err\n", ret);
		return ret;
	}
	
	memcpy(tmpHandle->p, buf, buflen);  //数据发送/缓存到内存 
	
	return ret;
} 
	
//客户端收报文
_declspec(dllexport)
int cltSocketRev(void* handle/*in*/, unsigned char** buf/*in比第一套改动了*/, int* buflen/*in out*/)
{
	int ret = 0; 
	Sck_Handle* tmpHandle = NULL;
	unsigned char* tmpbuf = NULL; 
	
	if(handle == NULL || buf == NULL || buflen == NULL)
	{
		ret = -3;
		printf("func cltSocketRev() err:%d check handle == NULL || buf == NULL || buflen == NULL err\n", ret);
		return ret;
	}
	tmpHandle = (Sck_Handle*)handle;
	
	tmpbuf = (unsigned char*)malloc(tmpHandle->len);
	if(tmpbuf == NULL)
	{
		ret = -4;
		printf("func cltSocketRev() err:%d check tmpbuf == NULL err\n", ret);
		return ret;
	}
	
	memcpy(tmpbuf, tmpHandle->p, tmpHandle->len);
	*buf = tmpbuf;
	*buflen = tmpHandle->len;  //间接赋值 告诉调用者收到的数据的长度 
	
	return ret;
} 
	
int cltSocketFree(void* p)
{
	if(p == NULL)
	{
		return -1;
	}
	free(p);
	return 0;
} 
	
//客户端释放资源
_declspec(dllexport)
int cltSocketDestory(void** handle/*in比第一套改动了*/)  
{
	int ret = 0; 
	Sck_Handle* tmpHandle = NULL;
	
	if(handle == NULL)
	{
		ret = -5;
		printf("func cltSocketDestory() err:%d check handle == NULL err\n", ret);
		return ret;
	}
	
	tmpHandle = (Sck_Handle*)(*handle);
	if(tmpHandle->p != NULL)
	{
		free(tmpHandle->p);  //释放结构体 成员域的 指针所指向的内存空间 
	}
	free(tmpHandle);  //释放结构体内存 
	*handle = NULL;
	
	return ret;
}
