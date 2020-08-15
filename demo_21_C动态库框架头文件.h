#ifndef _INC_DEMO_21_C动态库框架头文件_H__
#define _INC_DEMO_21_C动态库框架头文件_H__
//数据类型的封装 
//handle的概念：底层库的内存资源，记录着函数运行的上下文信息 

#ifdef __cpulspuls
extern "c" {
#endif
//完成发送报文的时候，进行数据加密解密 
//定义函数指针类型，通过函数指针类型来预定厂商去实现加密解密函数的原型
typedef int (*EncData)(unsigned char* in, int inlen, unsigned char* out, int* outlen);
typedef int (*DecData)(unsigned char* in, int inlen, unsigned char* out, int outlen);

//客户端初始化
int cltSocketInit(void** handle/*out*/); 
	
//客户端发报文
int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/); 

//客户端发报文并加密 
//int cltSocketSendAndEnc(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/, EncData encDataCallback);
//或者
int cltSocketSendAndEnc(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/, 
                int (*encDataCallback)(unsigned char* in, int inlen, unsigned char* out, int* outlen)); 

//客户端收报文
int cltSocketRev(void* handle/*in*/, unsigned char** buf/*in*/, int* buflen/*in out*/); 

int cltSocketFree(void* p);  //在底层库分配的内存，需要调用底层库的api函数进行释放 
	
//客户端释放资源
int cltSocketDestory(void** handle/*in*/);
#ifdef __cpulspuls
}
#endif

#endif
