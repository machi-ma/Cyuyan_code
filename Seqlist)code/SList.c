#include"SList.h"
void PrintSListNode(SListNode* phead)
{
	struct SListNode* cur = phead;
	while (cur!= NULL)//��ͷ��ʼ��ӡ��ֱ�����һ����nextΪ��
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL");
}
SListNode* BuySListNode(SLTDateType x)//����һ���µĽ��
{
	SListNode* newNode = (SListNode*)malloc(sizeof(struct SListNode));
	if (newNode == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	newNode->date = x;//�������ֵ���½���date
	newNode->next = NULL; //�½���nextΪNULL

	return newNode;//�����½��ĵ�ַ
}
void SLNodePushBack(SListNode** pphead, SLTDateType x)
{
	//β����������� 1 û�н��
	//               2 �н��
	struct SListNode* newNode = BuySListNode(x);//�������Ҫ�����µĽ��
	if (*pphead == NULL)
	{
		*pphead = newNode;//���µĽ���ַ��ͷ��Ҳ��β��
	}
	else
	{
		struct SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		
		tail->next = newNode;//���µĽ���ַ��β
	}

}
void SLNodePopBack(SListNode** pphead)
{
	//βɾ�����������1 û�н��
	//            2 ֻ��һ�����
	//			  3 2��������

	if (*pphead == NULL)
	{
		return;//û�н��ֱ���˳�����
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);//��һ����㣬�ͷŵ���������ָ���
		*pphead = NULL;
	}
	else
	{
		struct SListNode* tail = *pphead;
		struct SListNode* perv = NULL;
		//�ж����㣬���ҵ����һ����Ȼ���ͷŵ������õ����ڶ������nextΪ��
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
	*pphead = newNode;//newNode���µ�ͷ
}
void SListNodePopFront(SListNode** pphead)
{    
 //���������1 û�н��
		//   2 ֻ��һ�����
		//	 3 2��������  2.3���Լ���
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		//���ַ�������һ��ֱ���õڶ������ĵ�ַ��Ϊͷ
		//*pphead = (*pphead)->next;

		//�ڶ������£�
		SListNode* cur = (*pphead)->next;//����ڶ�����ַ
		free(*pphead);//�ͷŵ�һ��
		*pphead = NULL;
		*pphead= cur;//�õڶ�����Ϊ�µ�ͷ
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
		printf("�ҵ���\n");
		return cur;
	}
	else
	{
		printf("������\n");
		return NULL;
	}
}
void SListNodeInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	//SListNode* newNode = BuySListNode(x);
	//SListNode* temp = pos->next;//�ȱ���pos��һ�����ĵ�ַ
	//pos->next = newNode;//���½���ַ����pnextNode->next
	//newNode->next =pos->next->next;	
	SListNode*newNode= BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListNodeEraseaAfter(SListNode* pos)
{
	SListNode* next = pos->next;//pos��һ����ַ
	SListNode* nextnext = next->next;//pos����һ������ַ
	pos->next = nextnext;
	free(next);//�ͷ�pos֮��ĵ�һ����next��
	next = NULL;
}

