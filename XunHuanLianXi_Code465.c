#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

#if 0
int main()
{
	int i = 0;
	scanf("%d", &i);//�����ӡ�߶ȵ�һ��
	int n = 2 * i - 1;//�ܸ߶�
	int N = n - 1;//�ո����
	int S = 1;//*�Ÿ���
	if (i < 1)
	{
		printf("������󣡣���");//i������ڵ���1
	}
	while (n--)
	{
		for (int i = 0; i < N / 2; i++)
		{
			printf("%c", ' ');
		}
		for (int j = 0; j < S; j++)
		{
			printf("%c", '*');
		}
		printf("\n");
		if (n >= i)
		{
			N -= 2;//�ϰ�����ÿ��������1�ո�����2
			S += 2;//*�ż�����
		}//�ϰ�����
		else
		{
			N += 2;//�°�����ÿ��������1�ո�Ӷ�
			S -= 2;//*�ż�2
		}//�°�����
	}
	return 0;
}
#endif 


#if 0
int main()
{
	int a = 0;
	a = 2;
	int sum = 0;
	for (int n = 1; n <= 5; n++)
	{
		sum += a;
		printf("%d\n", a);
		a += 2 * pow(10, n);//2*10^n+��һ������
	}
	printf("%d", sum);
	return 0;
}
# endif 

#if 0
int main()
{
	int i = 0;
	scanf("%d", &i);
	printf("ż��λ��");
	for (int j = 31; j >= 1; j -= 2)
	{
		printf("%d ", (i >> j) & 1);
	}
	printf("\n����λ��");
	for (int j = 30; j >= 0; j -= 2)
	{
		printf("%d ", (i >> j) & 1);
	}
	return 0;
}
#endif



int main()
{
	int count = 0;
	int num1 = 10;
	int num2 = 20;
	int c = num1 ^ num2;//��������м���һ���м�λ��ͬ
	while (c)
	{
		c = c & (c - 1);
		count++;
	}
	printf("%d", count);
	return 0;
}
