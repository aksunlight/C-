#ifndef _INC_DEMO_21_C��̬����ͷ�ļ�_H__
#define _INC_DEMO_21_C��̬����ͷ�ļ�_H__
//�������͵ķ�װ 
//handle�ĸ���ײ����ڴ���Դ����¼�ź������е���������Ϣ 

#ifdef __cpulspuls
extern "c" {
#endif
//��ɷ��ͱ��ĵ�ʱ�򣬽������ݼ��ܽ��� 
//���庯��ָ�����ͣ�ͨ������ָ��������Ԥ������ȥʵ�ּ��ܽ��ܺ�����ԭ��
typedef int (*EncData)(unsigned char* in, int inlen, unsigned char* out, int* outlen);
typedef int (*DecData)(unsigned char* in, int inlen, unsigned char* out, int outlen);

//�ͻ��˳�ʼ��
int cltSocketInit(void** handle/*out*/); 
	
//�ͻ��˷�����
int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/); 

//�ͻ��˷����Ĳ����� 
//int cltSocketSendAndEnc(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/, EncData encDataCallback);
//����
int cltSocketSendAndEnc(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/, 
                int (*encDataCallback)(unsigned char* in, int inlen, unsigned char* out, int* outlen)); 

//�ͻ����ձ���
int cltSocketRev(void* handle/*in*/, unsigned char** buf/*in*/, int* buflen/*in out*/); 

int cltSocketFree(void* p);  //�ڵײ�������ڴ棬��Ҫ���õײ���api���������ͷ� 
	
//�ͻ����ͷ���Դ
int cltSocketDestory(void** handle/*in*/);
#ifdef __cpulspuls
}
#endif

#endif
