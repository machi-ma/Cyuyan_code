#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma warning(disable:4996)


typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType date;
	struct SListNode* next;

}SListNode;

//��������
//��ӡ������
void PrintSListNode(SListNode* phead);

//����β�庯��
void SLNodePushBack(SListNode** pphead, SLTDateType x);

//����βɾ����
void SLNodePopBack(SListNode** pphead);

//����ͷ�庯��
void SListPushFront(SListNode** pphead, SLTDateType x);

//����ͷɾ����
void SListNodePopFront(SListNode** pphead);

//��������x֮����뺯��
void SListNodeInsertAfter(SListNode*pos, SLTDateType x);

//������Һ���
SListNode* FindSListNode(SListNode* phead, SLTDateType pos);

//����ɾ��posλ��֮���м�ɾ�����ĺ���
void SListNodeEraseaAfter(SListNode* pos);