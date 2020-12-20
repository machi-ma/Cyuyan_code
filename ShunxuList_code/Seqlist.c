#include"SeqList.h"
void CheckSeqList(Seqlist* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;//扩容成原来的两倍，最多浪费不到50%
		ps->arr=(SLDateType*)realloc(ps->arr, sizeof(SLDateType) * ps->capacity);
		if (ps->arr == NULL)
		{
			printf("realloc失败\n");
			return;
		}
	}
}
void SeqListInit( Seqlist *ps)
{
	ps->arr = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	//初始化，申请动态内存
	if (ps->arr == NULL)
	{
		printf("malloc failed");
		return;
	}
	ps->size = 0;
	ps->capacity = 4;//初始容量为4
}
void SeqListPushBack(Seqlist* ps, SLDateType x)
{
	assert(ps);
	CheckSeqList(ps);//判断是否需要扩容
	ps->arr[ps->size] = x;//将新值赋给下标为size的arr
	
	ps->size++;
}
void SeqListPopBack(Seqlist* ps)
{
	assert(ps);
	ps->size--;//减少数组中的有效数目，让最后一个数无效
}
void SeqListPrint(const Seqlist* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}
void SeqListPushFront(Seqlist* ps, SLDateType x)
{//将每一个只能向后移动，
	assert(ps);
	CheckSeqList(ps);
	int i = ps->size;//不能改变size的值
	while (i > 0)
	{
		ps->arr[i] = ps->arr[i - 1];
		i--;
	}
	ps->arr[0] = x;//把新值符给第一个
	ps->size++;
}
void SeqListPopFront(Seqlist* ps)
{
	//可以用最后一个覆盖第一个，然后size--，但是会打乱原来的顺序
	/*ps->arr[0] = ps->arr[ps->size - 1];
	ps->size--;*/
	//也可以整体向<-移动，不会打乱顺序
	int i = 1;
	for (i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
int  SeqListFind(const Seqlist* ps, SLDateType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			printf("找到了，下标是%d\n", i);
			return i;
		}
		
	}
	printf("找不到\n");
	return -1;
}

void SeqListDestory(Seqlist* ps)
//我们使用了malloc申请了动态内存，如果不释放，会发生内存泄漏
{
	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListInsert(Seqlist* ps, int pos, SLDateType x)
{//size是0  size是1  size是多个三种情况
	assert(ps);
	assert(pos < ps->size);//pos不能小于ps->size
	CheckSeqList(ps);
	int  end = ps->size;//pos位置到最后整体，向后移动一位，预留pos位置
	for (end; end > pos; end--)
	{
		ps->arr[end] = ps->arr[end - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}
void SeqListErase(Seqlist* ps, int pos)//pos是位置
{
	
	assert(ps);
	assert(pos < ps->size);
	
	int start = pos;
	for (start; start < ps->size; start++)
	{
		ps->arr[start] = ps->arr[start + 1];
	}
	ps->size--;
}