#include"SList.h"
void PrintSListNode(SListNode* phead)
{
	struct SListNode* cur = phead;
	while (cur!= NULL)//从头开始打印，直到最后一个的next为空
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL");
}
SListNode* BuySListNode(SLTDateType x)//创建一个新的结点
{
	SListNode* newNode = (SListNode*)malloc(sizeof(struct SListNode));
	if (newNode == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	newNode->date = x;//将插入的值给新结点的date
	newNode->next = NULL; //新结点的next为NULL

	return newNode;//返回新结点的地址
}
void SLNodePushBack(SListNode** pphead, SLTDateType x)
{
	//尾插有两种情况 1 没有结点
	//               2 有结点
	struct SListNode* newNode = BuySListNode(x);//插入就需要创建新的结点
	if (*pphead == NULL)
	{
		*pphead = newNode;//将新的结点地址给头（也是尾）
	}
	else
	{
		struct SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		
		tail->next = newNode;//把新的结点地址给尾
	}

}
void SLNodePopBack(SListNode** pphead)
{
	//尾删分三种情况：1 没有结点
	//            2 只有一个结点
	//			  3 2个及以上

	if (*pphead == NULL)
	{
		return;//没有结点直接退出函数
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);//有一个结点，释放掉，并让其指向空
		*pphead = NULL;
	}
	else
	{
		struct SListNode* tail = *pphead;
		struct SListNode* perv = NULL;
		//有多个结点，先找到最后一个，然后释放掉，再让倒数第二个结点next为空
		while (tail->next != NULL)
		{
			perv = tail;
			tail = tail->next;
		}
		free(tail);
		perv->next = NULL;
	}
}
void SListPushFront(struct SListNode** pphead, SLTDateType x)
{
	struct SListNode* newNode = BuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;//newNode是新的头
}
void SListNodePopFront(SListNode** pphead)
{    
 //分三种情况1 没有结点
		//   2 只有一个结点
		//	 3 2个及以上  2.3可以兼容
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		//两种方法，第一种直接让第二个结点的地址作为头
		//*pphead = (*pphead)->next;

		//第二种如下：
		SListNode* cur = (*pphead)->next;//保存第二个地址
		free(*pphead);//释放第一个
		*pphead = NULL;
		*pphead= cur;//让第二个成为新的头
	}
}
SListNode* FindSListNode(SListNode* phead, SLTDateType pos)
{
	assert(phead);
	SListNode* cur = phead;
	while (cur!= NULL)
	{
		if (cur->date != pos)
		{
			cur = cur->next;
		}
		else
		{
			break;
		}
	}
	if (cur!=NULL)
	{
		printf("找到了\n");
		return cur;
	}
	else
	{
		printf("不存在\n");
		return NULL;
	}
}
void SListNodeInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	//SListNode* newNode = BuySListNode(x);
	//SListNode* temp = pos->next;//先保存pos下一个结点的地址
	//pos->next = newNode;//将新结点地址给到pnextNode->next
	//newNode->next =pos->next->next;	
	SListNode*newNode= BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListNodeEraseaAfter(SListNode* pos)
{
	SListNode* next = pos->next;//pos下一个地址
	SListNode* nextnext = next->next;//pos下下一个结点地址
	pos->next = nextnext;
	free(next);//释放pos之后的第一个（next）
	next = NULL;
}

