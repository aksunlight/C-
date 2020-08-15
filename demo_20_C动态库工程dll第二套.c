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

//�ͻ��˳�ʼ��
_declspec(dllexport)
int cltSocketInit(void** handle/*out*/)  //��Ե�һ��û�иĶ� 
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
	
	//��Ӹ�ֵ 
	*handle = tmpHandle;
	
	return ret;
}
	
//�ͻ��˷�����
_declspec(dllexport)
int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/)  //��Ե�һ��û�иĶ� 
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
	
	memcpy(tmpHandle->p, buf, buflen);  //���ݷ���/���浽�ڴ� 
	
	return ret;
} 
	
//�ͻ����ձ���
_declspec(dllexport)
int cltSocketRev(void* handle/*in*/, unsigned char** buf/*in�ȵ�һ�׸Ķ���*/, int* buflen/*in out*/)
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
	*buflen = tmpHandle->len;  //��Ӹ�ֵ ���ߵ������յ������ݵĳ��� 
	
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
	
//�ͻ����ͷ���Դ
_declspec(dllexport)
int cltSocketDestory(void** handle/*in�ȵ�һ�׸Ķ���*/)  
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
		free(tmpHandle->p);  //�ͷŽṹ�� ��Ա��� ָ����ָ����ڴ�ռ� 
	}
	free(tmpHandle);  //�ͷŽṹ���ڴ� 
	*handle = NULL;
	
	return ret;
}
