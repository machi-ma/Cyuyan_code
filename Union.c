#include<stdio.h>
#pragma warning(disable:4996)
//int main()
//{
//	struct p
//	{
//		int f;//4字节
//		char d;//内存对齐，4字节
//		double a;//8字节
//		int b;//四字节
//		char c; //内存对齐，1字节
//		short e;//3字节
//		struct p* x;//4字节
//	};
//	//总的结构体大小要整除最大整数倍
//	printf("%d", sizeof(struct p));
//	return 0;
//}
//int main()
//{
//    unsigned char puc[4];
//    struct tagPIM
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPimData;
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//    pstPimData->ucPim1 = 2;
//    pstPimData->ucData0 = 3;//只占一个字节的1个bit位
//    pstPimData->ucData1 = 4;//只占一个字节的2个bit位
//    pstPimData->ucData2 = 5;//只占一个字节的3个bit位
//    //三个合起来占一个字节，二进制数表示位：0010 1001,16进制为：29
//    
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    //结果是：02 29 00 00 
//    return 0;
//}
//int main()
//{
//	struct P
//	{
//		char g;//直接放,  占1个字节
//		int i[10];//偏移量 1； 对齐数：4   占 3+4*10=43 个字节
//		char h;//偏移量  44  对齐数：1  占1个字节
//		double b;//偏移量 ：45 对齐数：8  占3+8=11 个字节
//		float c;//偏移量 56：对齐数：1     占1个字节
//	}x;//总大小57 ，不能整除8，最后的大小是64
//	printf("%d", sizeof(struct P));
//	return 0;
//}
int main()
{
	struct p1
	{
		char c;//1
		double f;//7+8
		int i;//4
	};//总大小20 ，最大对齐数 8,不能整除8，最后的大小是24
	struct p2
	{
		int i;//4字节
		struct p1 x;//偏移量 4：最大对齐数 8，占4+24
		double f;//偏移量 40,对齐数8，占8个字节
		short k;//偏移量 48，对齐数2，占2个字节
	};// 总大小是42 ，最大对齐数 8, 不能整除8，最后的大小是48
	printf("p1 = %d\n", sizeof(struct p1));

	printf("p2 = %d", sizeof(struct p2));
	return 0;
}