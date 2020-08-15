#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"demo_20_C动态库工程头文件第二套.h"

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
	
	//客户端发报文
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
