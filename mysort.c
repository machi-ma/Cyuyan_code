#include<stdio.h>
#include<string.h>
#include<assert.h>
#pragma warning (disable :4996)
#define ROW 3
#define COL 4
//int Find(int arr[ROW][COL], int* row, int* col, int n)
//{
//    *row = 0;
//    *col = COL - 1;
//    while ((*row < ROW) && (*col >= 0))
//    {
//        if (arr[*row][*col] > n)
//        {
//            (*col)--;
//        }
//        else if (arr[*row][*col] < n)
//        {
//            (*row)++;
//        }
//        else
//            return 1;
//    }
//    return 0;
//}
//int main()
//{
//    int arr[ROW][COL] = { {1,2,3,4},{5,7,9,10},{21,37,46,98} };
//    int input = 0;
//    int row = 0;
//    int col = 0;
//    printf("请输入一个整数：");
//    scanf("%d", &input);
//    int ret = Find(arr, &row, &col, input);
//    if (ret == 1)
//    {
//        printf("row = %d,col = %d\n", row, col);
//    }
//    else
//    {
//        printf("Not found\n");
//    }
//    return 0;
//}
void  Reserch(int arr[][COL], int ro, int co, int k)
{
	int  row = 0;
	 int col = COL-1;
	while ((col < ROW) && (row >= 0))
	{
		if (arr[row][col] < k)
		{
			row++;
		}
		else if (arr[row][col] > k)
		{
			col--;
		}
		else
		{
			printf("找到了，下标是%d %d\n", row, col);
		}
	}
}
int s_Reserch(int arr[][COL],int *row,int* col, int k)
{
	*row = 0;
	* col = COL- 1;
	while ((*row < ROW) && (*col >= 0))
	{
		if (arr[*row][*col] > k)
		{
			(*col)--;
		}
		else if (arr[*row][*col] < k)
		{
			(*row)++;
		}
		else
		{
			
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[ROW][COL] = { {1,2,3,4},{5,6,7,8,},{10,11,12,13} };
	int input = 0;
	int row = 0;
	int col = 0;
	printf("请输入你将查找的数：\n");
	scanf("%d", &input);
	 Reserch(arr,ROW,COL,input);
	////if (ret == 1)
	//{
	//	printf("找到了，下标是%d %d\n", row, col);
	//}
	////else
	//{
	//	printf("找不到了");
	//}
	return 0;
}
//unsigned int Mystrlen(const char* str)
//{
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char* str = "abcd1234";
//	unsigned int i=Mystrlen(str);
//	printf("%d", i);
//	return 0;
//}
//char* MyStrcpy(char* str, const char* des)
//{
//	while (*(des - 1) != '\0')
//	{
//		*str = *des;
//		str++;
//		des++;
//	}
//}
//int main()
//{
//	char arr1[] = "abcdeg";
//	char arr2[64];
//	char* s = MyStrcpy(arr2, arr1);
//	printf("%s", arr2);
//	return 0;
//}
//int Strcmp(const char* str1, const char* str2)
//{
//    int ret = 0;
//    while (!(ret = *str1 - *str2) && *str1)
//    {
//        str1++;
//        str2++;
//    }
//
//
//    if (ret < 0)
//    {
//        return -1;
//    }
//    else if (ret > 0)
//    {
//        return 1;
//    }
//    return 0;
//}
//int MyStrcmp(char* s1, char* s2)
//{
//	while ((*s1 == *s2) && (*s1 || *s2))
//	{
//		s1++;
//		s2++;
//	}
//    if (*s1 > * s2)
//    {
//        return 1;
//    }
//    else if (*s1 < *s2)
//    {
//        return -1;
//    }
//	return 0;
//
//}
//
//int main()
//{
//	char* st = "ba78941110";
//	char* de = "ba78941111";
//	int ret = MyStrcmp(st, de);
//	printf("%d", ret);
//	return 0;
//}
//char* Mystrcat(char* str2,const char *str)
//{
//	assert(str2 != NULL);
//	assert(str != NULL);
//	char* temp = str2;
//	while (*temp != '\0')
//	{
//		temp++;
//	}
//	while (*str != '\0')
//	{
//		*temp = *str;
//		temp++;
//		str++;
//	}
//	//*temp = '\0';
//	
//}
//int main()
//{
//	char *str = "hello";
//	char str2[100] = "wold";
//	Mystrcat(str2, str);
//	printf("%s\n", str2);
//	return 0;
//}
//int Search(int arr[][COL], int row, int col, int k)
//{
//	int x = row*col/2;
//	int y = col*col/2;
//	if (k > arr[x][y])
//	{
//	}
//}
//int main()
//{
//	int k = 0;
//	printf("请输入你要查找的数：\n");
//	scanf("%d", &k);
//	int arr[ROW][COL];
//	int ret=Search(arr, ROW, COL,k);
//	return 0;
//}
//int Com(void* _s1, void* _s2)
//{
//	char* s1 = *(char**)_s1;
//	char* s2 = *(char**)_s2;
//	return strcmp(s1, s2);
//}
//void swap(char* _s1, char* _s2,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		char temp = *(_s1+i);
//		*(_s1 + i) = *(_s2 + i);
//		*(_s2 + i) = temp;
//	}
//}
//void MyQsort(void* str, int num, int sz, int Com(const void*, const void*))
//{//str代表待排序数据块的首地址
//	assert(str != NULL);
//	assert(Com != NULL);
//	char* e = (char*)str;//为了指针加一，字节也加1；
//	for (int i = 0; i < num; i++)
//	{
//		int flag = 0;
//		for (int j = 0; j < num - i - 1; j++)
//		{
//			if (Com(e + j * sz, e + (j + 1) * sz) > 0)
//			{
//				swap(e + j * sz, e + (j + 1) * sz, sz);
//				flag = 1;
//			//不知道数据类型，所以要交换每一个字节，就要传入数据类型的大小
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	//int arr[] = { 14,46,98,5,45,61,26,87,43,123,456,65,651,789,1024 };
//	char* arr[] = { "ac561","c4568","ab454","b48955" };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	MyQsort(arr, sz, sizeof(int), Com);
//	return 0;
//}
//void Print_Int(int *str, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", *(str + i));
//	}
//	printf("\n");
//}

//int InCom(void* _x, void* _y)
//{
//	int* x = (int* )_x;
//	int* y = (int* )_y;
//	if (*x >  *y)
//	{
//		return 1;
//	}
//	if (*x < *y)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int arr[] = { 14,46,98,5,45,61,26,87,43,123,456,65,651,789,1024 };
//	//char* arr[] = { "ac561","c4568","ab454","b48955" };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Print_Int(arr, size);
//	qsort(arr, size, sizeof(int), InCom);
//	//qsort(arr, size, sizeof(int), Char_com);
//	Print_Int(arr, size);
//}
//void swap(char* str, char* est,int size)
//{
//	while (size)
//	{
//		char temp = *str;
//		*str = *est;
//		*est = temp;
//		str++;
//		est++;
//		size--;
//	}
//}
//int  Char_Com(const void *_x,const void *_y)
//{
//	char* x = *(char**)_x;
//	char* y = *(char**)_y;
//	return strcmp(x, y);
//}
//void MySort(void* str, int num,int size,int (*Char_Com)(const void *,const void*))
//{
//	assert(str != NULL);
//	assert(Char_Com != NULL);
//	char* e = (char*)str;
//	for (int i = 0; i < num; i++)
//	{
//		for (int j = 0; j < num - i - 1;j++)
//		{
//			if (Char_Com((e+j*size), (e + (j+1) * size))>0)
//			{
//				swap(e + j * size, e +(j+1)* size,size);
//			}
//		}
//	}
//}
//int main()
//{
//	char* str[] = { "a4564","b4516","ac456","ba458","c45678" };
//	int num = sizeof(str) / sizeof(str[0]);
//	MySort(str, num, sizeof(char*), Char_Com);
//	//printf("%d", str[0]);
//	return 0;
//}