#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

#if 0
int main()
{
	int i = 0;
	scanf("%d", &i);//输入打印高度的一半
	int n = 2 * i - 1;//总高度
	int N = n - 1;//空格个数
	int S = 1;//*号个数
	if (i < 1)
	{
		printf("输入错误！！！");//i必须大于等于1
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
			N -= 2;//上半三角每当行数减1空格数减2
			S += 2;//*号加两个
		}//上半三角
		else
		{
			N += 2;//下半三角每当行数减1空格加二
			S -= 2;//*号减2
		}//下半三角
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
		a += 2 * pow(10, n);//2*10^n+上一个数；
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
	printf("偶数位：");
	for (int j = 31; j >= 1; j -= 2)
	{
		printf("%d ", (i >> j) & 1);
	}
	printf("\n奇数位：");
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
	int c = num1 ^ num2;//两个异或，有几个一就有几位不同
	while (c)
	{
		c = c & (c - 1);
		count++;
	}
	printf("%d", count);
	return 0;
}
