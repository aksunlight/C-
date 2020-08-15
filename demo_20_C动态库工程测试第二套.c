#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"demo_20_C��̬�⹤��ͷ�ļ��ڶ���.h"

int main(void)
{
    int ret = 0;
	void* handle = NULL;
	
	unsigned char buf[1024];  //���ͻ��� 
	int buflen;
	
	unsigned char* out = NULL;  //���ջ��� 
	int outlen; 
	
	strcpy((char*) buf, "aaaaaaffffff");
	buflen = 9;
	
	//�ͻ��˳�ʼ��
	ret = cltSocketInit(&handle/*out*/); 
	if(ret != 0)
	{
		printf("func cltSocketInit() err:%d", ret);
		goto End;
	}
	
	//�ͻ��˷�����
    ret = cltSocketSend(handle/*in*/, buf/*in*/, buflen/*in*/); 
	if(ret != 0)
	{
		printf("func cltSocketSend() err:%d", ret);
		goto End;
	}
	
	//�ͻ����ձ���
    ret = cltSocketRev(handle/*in*/, &out/*in*/, &outlen/*in out*/); 
	if(ret != 0)
	{
		printf("func cltSocketRev() err:%d", ret);
		goto End;
	}
	printf("out:%s, outlen:%d\n", out, outlen); 
	
//	if(out != NULL) free(out);  ��Ҫ����д  
	ret = cltSocketFree(out);

End:	
	//�ͻ����ͷ���Դ
	ret = cltSocketDestory(&handle/*in*/);

//	system("pause");
	return 0;
} 
