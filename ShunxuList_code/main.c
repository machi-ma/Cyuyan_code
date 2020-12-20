#include"SeqList.h"
void test2()
{
	Seqlist ps1;
	SeqListInit(&ps1);
	SeqListPushBack(&ps1, 1);
	SeqListPushBack(&ps1, 2);
	SeqListPushBack(&ps1, 3);
	SeqListPushBack(&ps1, 4);
	SeqListPrint(&ps1);
	SeqListPopBack(&ps1);
	SeqListPrint(&ps1);
	SeqListInsert(&ps1, 2,9);
	SeqListPrint(&ps1);
	SeqListErase(&ps1, 1);
	SeqListPrint(&ps1);
	SeqListFind(&ps1,5);
	SeqListDestory(&ps1);
}
int main()
{
	
	test2();
	return 0;
}