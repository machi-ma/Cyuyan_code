#include<stdio.h>

void Print_arr1(int arr[][3], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
void Print_arr2(int(*arr)[3], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[2][3] = { 1,2,3,4,5,6 };
	Print_arr1(arr, 2, 3);
	Print_arr2(arr, 2, 3);
	return 0;
}