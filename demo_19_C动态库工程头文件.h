#ifndef _INC_DEMO_19_C动态库工程头文件_H__
#define _INC_DEMO_19_C动态库工程头文件_H__

#ifdef __cpulspuls
extern "c" {
#endif

//数据类型的封装 
//handle的概念：底层库的内存资源，记录着函数运行的上下文信息 
//底层库提供的是一种机制，而不是满足某人的策略 

//客户端初始化
int cltSocketInit(void** handle/*out*/); 
	
//客户端发报文
int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/); 
	
//客户端收报文
int cltSocketRev(void* handle/*in*/, unsigned char* buf/*in*/, int* buflen/*in out*/); 
	
//客户端释放资源
int cltSocketDestory(void* handle/*in*/);

#ifdef __cpulspuls
}
#endif

#endif
