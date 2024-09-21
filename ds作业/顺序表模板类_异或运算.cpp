
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define LISTINCREMENT 2  //线性表存储空间的分配增量

typedef struct SqList
{
	int *elem; //存储空间的基址
	int length; //当前长度
	int listsize; //当前分配的存储容量 
}SqList;
bool InitList(SqList *L) //线性表的初始化
{
	L->elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if( L->elem == NULL)
	{
		printf("内存分配失败 程序终止！\n");
		exit(-1);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return true;
}

bool ListInsert(SqList *L,int pos,int e) //在第pos个位置插入e的值
{
	int * newbase, *q, *p;
	if(pos < 1 || pos > L->length+1 ) //pos值不和法
		return false;
	if(L->length >= L->listsize) //当前存储空间已满 增加分配
	{
		newbase = (int *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(int));
		if(newbase == NULL)
		{
			printf("内存分配失败程序终止！\n");
			exit(-1);
		}
		L->elem = newbase; //新基址
		L->listsize += LISTINCREMENT;
	}
	q = L->elem + pos - 1; //q为插入位置
	for(p = L->elem + L->length - 1; p >= q; --p) //插入位置及之后的元素右移
		*(p+1) = *p;
	*q = e; //插入e
	L->length++; //表长增加 1
	return true;
}


int ListLength(SqList L) //求线性表的长度
{
	return L.length;
}

bool GetElem(SqList L,int pos,int *e) //取第pos个数据元素的值
{
	if(pos < 1 || pos > L.length)
		return false;
	*e = *(L.elem + pos - 1);
	return true;
}

bool equal(int c1,int c2)
{
	if(c1 == c2)
		return true;
	else
		return false;
}

int LocateElem(SqList L,int e,bool (*compare)(int,int))// 定位
{
	int *p;
	int i = 1; //i的初始值为第一个元素的位序
	p = L.elem;
	while(i <= L.length && !compare(*(p++),e))
		i++;
	if(i <= L.length)
		return i;
	else
		return 0;
}

void exclusive(SqList *La,SqList *Lb,SqList *Lc)//  异或运算
{  
	int e;
	int La_len, Lb_len, Lc_len;
	int i;
	La_len = ListLength(*La); //求线性表的长度
	Lb_len = ListLength(*Lb);
	Lc_len=0; // 当前长度为0
	for(i = 1; i <= Lb_len; i++)
	{
		GetElem(*Lb,i,&e); //
		if( !LocateElem(*La,e,equal) ) //在b不在a
			ListInsert(Lc,++Lc_len,e); // 
	}
	for(i = 1; i <= La_len; i++)
	{
		GetElem(*La,i,&e); //
		if( !LocateElem(*Lb,e,equal) ) //在a不在b
			ListInsert(Lc,++Lc_len,e); // 
	}

}
void copy(SqList *La,SqList *Lb){ // 按元素复制  防止地址重复
	// clear Lb
	InitList(Lb);
	int Lb_len=0;
	int e;
	for(int i=1;i<=La->length;i++){
		GetElem(*La,i,&e);
		ListInsert(Lb,++Lb_len,e);
	}

}
int main()
{
	SqList La, Lb,Lc;
	int j;
	int va, vb;
	int num1, num2;
	InitList(&La);
	printf("请输入La元素的个数：");
	scanf("%d",&num1);
	for(j = 1; j <= num1; j++) 
	{
		printf("请输入La中第%d个元素的值为",j);
		scanf("%d",&va);
		ListInsert(&La,j,va);
	}
	InitList(&Lb);
	scanf("%d",&num2);
	for(j = 1; j <= num2; j++) 
	{
		scanf("%d",&vb);
		ListInsert(&Lb,j,vb);
	}
	InitList(&Lc);
	exclusive(&La,&Lb,&Lc); 
	copy(&La,&Lc);
	return 0;
}

