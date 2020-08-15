#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"demo_22_C��̬��������ͷ�ļ�.h"

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
	
	//���ü��ܺ�����ڵ�ַ���ص���������ڵ�ַ
	ret = cltSocketSetCallBack(handle, Hw_EncData); 
	if(ret != 0)
	{
		printf("func cltSocketSetCallBack() err:%d", ret);
		goto End;
	}
	
	//�ͻ��˷����Ĳ����ܣ������� 
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
