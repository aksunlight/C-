#ifndef _INC_DEMO_19_C��̬�⹤��ͷ�ļ�_H__
#define _INC_DEMO_19_C��̬�⹤��ͷ�ļ�_H__

#ifdef __cpulspuls
extern "c" {
#endif

//�������͵ķ�װ 
//handle�ĸ���ײ����ڴ���Դ����¼�ź������е���������Ϣ 
//�ײ���ṩ����һ�ֻ��ƣ�����������ĳ�˵Ĳ��� 

//�ͻ��˳�ʼ��
int cltSocketInit(void** handle/*out*/); 
	
//�ͻ��˷�����
int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/); 
	
//�ͻ����ձ���
int cltSocketRev(void* handle/*in*/, unsigned char* buf/*in*/, int* buflen/*in out*/); 
	
//�ͻ����ͷ���Դ
int cltSocketDestory(void* handle/*in*/);

#ifdef __cpulspuls
}
#endif

#endif
