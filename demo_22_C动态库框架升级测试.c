#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"demo_22_C动态库框架升级头文件.h"

int Hw_EncData(unsigned char* in, int inlen, unsigned char* out, int* outlen)
{
	printf("func Hw_EncData bagin...\n");
	strcpy((char*)out, "123456789");
	printf("func Hw_EncData end...\n");
	*outlen = 9;
	return 0;
}

int main(void)
{
    int ret = 0;
	void* handle = NULL;
	
	unsigned char buf[1024];  //发送缓存 
	int buflen;
	
	unsigned char* out = NULL;  //接收缓存 
	int outlen; 
	
	strcpy((char*) buf, "aaaaaaffffff");
	buflen = 9;
	
	//客户端初始化
	ret = cltSocketInit(&handle/*out*/); 
	if(ret != 0)
	{
		printf("func cltSocketInit() err:%d", ret);
		goto End;
	}
	
	//设置加密函数入口地址，回调函数的入口地址
	ret = cltSocketSetCallBack(handle, Hw_EncData); 
	if(ret != 0)
	{
		printf("func cltSocketSetCallBack() err:%d", ret);
		goto End;
	}
	
	//客户端发报文并加密（升级） 
    ret = cltSocketSend(handle/*in*/, buf/*in*/, buflen/*in*/); 
	if(ret != 0)
	{
		printf("func cltSocketSend() err:%d", ret);
		goto End;
	}
	
	//客户端收报文
    ret = cltSocketRev(handle/*in*/, &out/*in*/, &outlen/*in out*/); 
	if(ret != 0)
	{
		printf("func cltSocketRev() err:%d", ret);
		goto End;
	}
	printf("out:%s, outlen:%d\n", out, outlen); 
	
//	if(out != NULL) free(out);  不要这样写  
	ret = cltSocketFree(out);

End:	
	//客户端释放资源
	ret = cltSocketDestory(&handle/*in*/);

//	system("pause");
	return 0;
} 
