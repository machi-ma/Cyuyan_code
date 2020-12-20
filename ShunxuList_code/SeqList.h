#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#pragma warning(disable:4996)

#define N 100

typedef int SLDateType;

typedef struct Seqlist
{
	SLDateType* arr;//��������
	SLDateType size;//������Ŀ
	SLDateType capacity;//����
}Seqlist;

//��������
//��ʼ��ps����
void SeqListInit(Seqlist *ps);

//β�庯��
void SeqListPushBack(Seqlist* ps,SLDateType x);

//βɾ����
void SeqListPopBack(Seqlist* ps);

//��ӡ����
void SeqListPrint(const Seqlist* ps);

//ͷ�庯��
void SeqListPushFront(Seqlist* ps, SLDateType x);

//ͷɾ����
void SeqListPopFront(Seqlist* ps);

//˳���Ѱ�Һ���
int  SeqListFind(const Seqlist* ps, SLDateType x);

//˳������ٺ���
void SeqListDestory(Seqlist* ps);

//˳����м���뺯��
void SeqListInsert(Seqlist* ps, int pos, SLDateType x);

//˳����м�ɾ������
void SeqListErase(Seqlist* ps, int pos);