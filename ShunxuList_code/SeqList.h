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
	SLDateType* arr;//柔性数组
	SLDateType size;//已有数目
	SLDateType capacity;//容量
}Seqlist;

//函数声明
//初始化ps函数
void SeqListInit(Seqlist *ps);

//尾插函数
void SeqListPushBack(Seqlist* ps,SLDateType x);

//尾删函数
void SeqListPopBack(Seqlist* ps);

//打印函数
void SeqListPrint(const Seqlist* ps);

//头插函数
void SeqListPushFront(Seqlist* ps, SLDateType x);

//头删函数
void SeqListPopFront(Seqlist* ps);

//顺序表寻找函数
int  SeqListFind(const Seqlist* ps, SLDateType x);

//顺序表销毁函数
void SeqListDestory(Seqlist* ps);

//顺序表中间插入函数
void SeqListInsert(Seqlist* ps, int pos, SLDateType x);

//顺序表中间删除函数
void SeqListErase(Seqlist* ps, int pos);