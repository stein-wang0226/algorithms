#define Max_size 100
#include<bits/stdc++.h>

using namespace std;
class elemType{
	int e;
};

struct  sqQueue
{
	elemType *base;
	int front; // 头指针
	int length;
};
// rear= frint+length

bool  InitQueue(sqQueue &Q){
	//
	Q.base= new elemType[Max_size];
	if(!Q.base){cerr<<"error";exit(114514);}
	Q.front=0;
	return 1;
}


bool push(sqQueue &Q, elemType e){
	if(Q.length==Max_size)return 0; // 已满
	Q.length++;
	int pos=(Q.front+Q.length)%Max_size;
	Q.base[pos]=e;
	return 1;
}
bool pop(sqQueue &Q,elemType &e){
	if(Q.length==0){ // 空
		return 0;
	}
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%Max_size;
	return 1;
}


