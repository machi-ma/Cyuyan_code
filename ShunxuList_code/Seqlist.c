#include"SeqList.h"
void CheckSeqList(Seqlist* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;//���ݳ�ԭ��������������˷Ѳ���50%
		ps->arr=(SLDateType*)realloc(ps->arr, sizeof(SLDateType) * ps->capacity);
		if (ps->arr == NULL)
		{
			printf("reallocʧ��\n");
			return;
		}
	}
}
void SeqListInit( Seqlist *ps)
{
	ps->arr = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	//��ʼ�������붯̬�ڴ�
	if (ps->arr == NULL)
	{
		printf("malloc failed");
		return;
	}
	ps->size = 0;
	ps->capacity = 4;//��ʼ����Ϊ4
}
void SeqListPushBack(Seqlist* ps, SLDateType x)
{
	assert(ps);
	CheckSeqList(ps);//�ж��Ƿ���Ҫ����
	ps->arr[ps->size] = x;//����ֵ�����±�Ϊsize��arr
	
	ps->size++;
}
void SeqListPopBack(Seqlist* ps)
{
	assert(ps);
	ps->size--;//���������е���Ч��Ŀ�������һ������Ч
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
{//��ÿһ��ֻ������ƶ���
	assert(ps);
	CheckSeqList(ps);
	int i = ps->size;//���ܸı�size��ֵ
	while (i > 0)
	{
		ps->arr[i] = ps->arr[i - 1];
		i--;
	}
	ps->arr[0] = x;//����ֵ������һ��
	ps->size++;
}
void SeqListPopFront(Seqlist* ps)
{
	//���������һ�����ǵ�һ����Ȼ��size--�����ǻ����ԭ����˳��
	/*ps->arr[0] = ps->arr[ps->size - 1];
	ps->size--;*/
	//Ҳ����������<-�ƶ����������˳��
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
			printf("�ҵ��ˣ��±���%d\n", i);
			return i;
		}
		
	}
	printf("�Ҳ���\n");
	return -1;
}

void SeqListDestory(Seqlist* ps)
//����ʹ����malloc�����˶�̬�ڴ棬������ͷţ��ᷢ���ڴ�й©
{
	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListInsert(Seqlist* ps, int pos, SLDateType x)
{//size��0  size��1  size�Ƕ���������
	assert(ps);
	assert(pos < ps->size);//pos����С��ps->size
	CheckSeqList(ps);
	int  end = ps->size;//posλ�õ�������壬����ƶ�һλ��Ԥ��posλ��
	for (end; end > pos; end--)
	{
		ps->arr[end] = ps->arr[end - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}
void SeqListErase(Seqlist* ps, int pos)//pos��λ��
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