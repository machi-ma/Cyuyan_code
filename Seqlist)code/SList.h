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

//函数声明
//打印链表函数
void PrintSListNode(SListNode* phead);

//链表尾插函数
void SLNodePushBack(SListNode** pphead, SLTDateType x);

//链表尾删函数
void SLNodePopBack(SListNode** pphead);

//链表头插函数
void SListPushFront(SListNode** pphead, SLTDateType x);

//链表头删函数
void SListNodePopFront(SListNode** pphead);

//链表中在x之后插入函数
void SListNodeInsertAfter(SListNode*pos, SLTDateType x);

//链表查找函数
SListNode* FindSListNode(SListNode* phead, SLTDateType pos);

//链表删除pos位置之后（中间删除）的函数
void SListNodeEraseaAfter(SListNode* pos);