#ifndef _INC_DEMO_20_C��̬�⹤��ͷ�ļ��ڶ���_H__
#define _INC_DEMO_20_C��̬�⹤��ͷ�ļ��ڶ���_H__

#ifdef __cpulspuls
extern "c" {
#endif

//�������͵ķ�װ 
//handle�ĸ���ײ����ڴ���Դ����¼�ź������е���������Ϣ 

//�ͻ��˳�ʼ��
int cltSocketInit(void** handle/*out*/); 
	
//�ͻ��˷�����
int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/); 
	
//�ͻ����ձ���
int cltSocketRev(void* handle/*in*/, unsigned char** buf/*in*/, int* buflen/*in out*/); 

int cltSocketFree(void* p);  //�ڵײ�������ڴ棬��Ҫ���õײ���api���������ͷ� 
	
//�ͻ����ͷ���Դ
int cltSocketDestory(void** handle/*in*/);

#ifdef __cpulspuls
}
#endif

#endif
