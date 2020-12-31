#include"SList.h"
void text()
{
	SListNode* ps = NULL;
	SLNodePushBack(&ps, 1);
	SLNodePushBack(&ps, 2);
	SLNodePushBack(&ps, 3);
	SLNodePushBack(&ps, 4);
	SLNodePushBack(&ps, 5);
	SLNodePushBack(&ps, 6);
	PrintSListNode(ps);
	printf("\n");
	SListNode* pos = FindSListNode(ps, 5);
	SListNodeInsertAfter(pos, 22);
	PrintSListNode(ps);
	printf("\n");
	SListNode* pos2 = FindSListNode(ps, 2);
	SListNodeEraseaAfter(pos2);
	PrintSListNode(ps);
	printf("\n");


}
int main()
{
	text();//²âÊÔº¯Êý
	return 0;
}