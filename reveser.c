#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#pragma warning(disable:4996)
#define ROW 12
#define COL 12
#define NUMS 20
void menu()
{
	printf("*******************************\n");
	printf("***** 1.play        0.exit ****\n"); 
	printf("*******************************\n");
}
void ShowBoard(char showboard[][COL], int row, int col)
{
	printf("   ");
	for (int i = 1; i < ROW - 1; i++)
	{
		printf(" %2d ", i);
	}
	printf("\n————————————————————\n");
	for (int i = 1; i < ROW - 1; i++)
	{
		printf("%2d |", i);
		for (int j = 1; j < COL - 1; j++)
		{
			printf(" %c| ",showboard[i][j]);
		}
		printf("\n————————————————————");
		printf("\n");
	}
}
char SetMine(char mineboard[][COL],int row,int col)
{
	int num = NUMS;
	while (num)
	{
		int x = rand() % 10 + 1;
		int y = rand() % 10 + 1;
		if (mineboard[x][y] == '0')
		{
			mineboard[x][y] ='1';
			num--;
		}
	}
}
int G_mine(char mine[][COL], int row, int col, int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + \
		mine[x][y - 1] + mine[x][y + 1] + \
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void game()
{
	char showboard[ROW][COL];
	char mineboard[ROW][COL];
	srand((unsigned long)time(NULL));
	memset(showboard, '*', sizeof(showboard));
	memset(mineboard, '0', sizeof(mineboard));
	SetMine(mineboard, ROW, COL);
	int count = (ROW - 2) * (COL - 2) - NUMS;
	do
	{
		ShowBoard(showboard,ROW,COL);
		int x;
		int y;
		printf("请输入你扫的位置\n");
		scanf("%d %d", &x, &y);
		if (x < 1 || x>10 || y < 1 || y>10)
		{
			printf("你输入的位置越界了，请重输!\n");
		}
		else if (showboard[x][y] != '*')
		{
			printf("你输入的位置已经被扫过了！！！\n");
		}
		else if (mineboard[x][y] == '1')
		{
			break;
		}
		else
		{
			int ret = G_mine(mineboard, ROW, COL, x, y);
			showboard[x][y] = ret + '0';
			count--;
		}
	} while (count>0);
	if (count > 0)
	{
		printf("你被炸死了\n");
		ShowBoard(mineboard, ROW, COL);
	}
	else
	{
		ShowBoard(showboard, ROW, COL);
		printf("你赢了\n");
	}
}
int main()
{
	int input = 0;
	int quit = 0;
	while (!quit)
	{
		menu();
		printf("请输入<1 or 0>:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("要不要再玩一局？？？\n");
			break;
		case 0:
			quit = 1;
			break;
		default:
			printf("输入错误！请重输\n");
			break;
		}
	}
	return 0;
}
//void Reverse(char* begin, char* end)
//{
//	while (begin < end)
//	{
//		char temp = '0';
//		temp = *begin;
//		*begin = *end;
//		*end = temp;
//		begin++;
//		end--;
//	}
//}
//int main()
//{
//	char str[100] = { 0 };
//	fgets(str, sizeof(str), stdin);
//	str[strlen(str) - 1] = '\0';
//	char* begin = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		Reverse(begin, end-1);//end目前指向空格，所以要减一。
//		if (*end != '\0')
//		{
//			end++;
//		}
//		begin = end;
//	}
//	Reverse(str, str + strlen(str) - 1);
//	printf("%s", str);
//	return 0;
//}
//int main()
//{
//	for (int i = 0; i < 100000; i++)
//	{
//		int count = 0;
//		int temp = i;
//		while (temp)
//		{
//			count++;
//			temp /= 10;
//		}
//		int sum = 0;
//		temp = i;
//		while(temp)
//		{
//			sum += pow(temp % 10, count);
//			temp /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d\n", sum);
//		}
//	}
//	return 0;
//}
//void Reverse(char* begin, char* end)
//{
//	char temp;
//	while (begin <= end)
//	{
//		temp = *begin;
//		*begin = *end;
//		*end = temp;
//		begin++;
//		end--;
//	}
//}
//int main()
//{
//	char str[100] = { 0 };
//	fgets(str, sizeof(str), stdin);
//	str[strlen(str) - 1] = '\0';
//	char* begin = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		Reverse(begin, end-1);
//		if (*end != '\0')
//		{
//			end++;
//		}
//		begin = end;
//	}
//	Reverse(str, str+strlen(str)-1);
//	printf("%s", str);
//	return 0;
//}