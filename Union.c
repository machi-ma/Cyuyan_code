#include<stdio.h>
#pragma warning(disable:4996)
//int main()
//{
//	struct p
//	{
//		int f;//4�ֽ�
//		char d;//�ڴ���룬4�ֽ�
//		double a;//8�ֽ�
//		int b;//���ֽ�
//		char c; //�ڴ���룬1�ֽ�
//		short e;//3�ֽ�
//		struct p* x;//4�ֽ�
//	};
//	//�ܵĽṹ���СҪ�������������
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
//    pstPimData->ucData0 = 3;//ֻռһ���ֽڵ�1��bitλ
//    pstPimData->ucData1 = 4;//ֻռһ���ֽڵ�2��bitλ
//    pstPimData->ucData2 = 5;//ֻռһ���ֽڵ�3��bitλ
//    //����������ռһ���ֽڣ�����������ʾλ��0010 1001,16����Ϊ��29
//    
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    //����ǣ�02 29 00 00 
//    return 0;
//}
//int main()
//{
//	struct P
//	{
//		char g;//ֱ�ӷ�,  ռ1���ֽ�
//		int i[10];//ƫ���� 1�� ��������4   ռ 3+4*10=43 ���ֽ�
//		char h;//ƫ����  44  ��������1  ռ1���ֽ�
//		double b;//ƫ���� ��45 ��������8  ռ3+8=11 ���ֽ�
//		float c;//ƫ���� 56����������1     ռ1���ֽ�
//	}x;//�ܴ�С57 ����������8�����Ĵ�С��64
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
	};//�ܴ�С20 ���������� 8,��������8�����Ĵ�С��24
	struct p2
	{
		int i;//4�ֽ�
		struct p1 x;//ƫ���� 4���������� 8��ռ4+24
		double f;//ƫ���� 40,������8��ռ8���ֽ�
		short k;//ƫ���� 48��������2��ռ2���ֽ�
	};// �ܴ�С��42 ���������� 8, ��������8�����Ĵ�С��48
	printf("p1 = %d\n", sizeof(struct p1));

	printf("p2 = %d", sizeof(struct p2));
	return 0;
}