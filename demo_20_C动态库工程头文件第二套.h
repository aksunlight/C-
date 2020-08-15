#ifndef _INC_DEMO_20_C动态库工程头文件第二套_H__
#define _INC_DEMO_20_C动态库工程头文件第二套_H__

#ifdef __cpulspuls
extern "c" {
#endif

//数据类型的封装 
//handle的概念：底层库的内存资源，记录着函数运行的上下文信息 

//客户端初始化
int cltSocketInit(void** handle/*out*/); 
	
//客户端发报文
int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/); 
	
//客户端收报文
int cltSocketRev(void* handle/*in*/, unsigned char** buf/*in*/, int* buflen/*in out*/); 

int cltSocketFree(void* p);  //在底层库分配的内存，需要调用底层库的api函数进行释放 
	
//客户端释放资源
int cltSocketDestory(void** handle/*in*/);

#ifdef __cpulspuls
}
#endif

#endif
