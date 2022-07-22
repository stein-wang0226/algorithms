#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//对区间满足条件的节点作更新，单点查询
// 1.输入四个数据a,b,k,c将区间[a,b]中的数i满足(i-a)%k  == 0加上c.     i%k==a
// 2.输入一个数y,输出序列中第y个数的值。
// 思路：因为k的值很小，那么对k取余的值也会很小，所以可以建立一个树状数组c[x][k][x%k]代表x对k取余的值，
// 然后每次更新树状数组的时候只需要更新update(a,.....) 与update(b+1,.....);
//查询只要将所有状态（的所有差分）相加***
int n; 
int a[50010]; 
int c[50010][11][11];//
int lowbit(int i) {
	return i&(-i); 
}
void update(int x,int k,int mod,int data) {// 
	while(x<=n){
		c[x][k][mod]+=data; 
		x+=lowbit(x);
	} 
}
int querysum(int x,int y) { //x,y值相等，不过x会改变，所以需要y固定
	int res=0,i;
	while(x>0){ 
		for(i=1;i<=10;i++){ //k<=10
			res+=c[x][i][y%i];//每次将所有状态加上   y%i 就是原来状态的x %i
		}
		x-=lowbit(x); 
	} 
	return res; 
}
int main(){ 
	int i,j;
	int x,q;
	int s,y,k,data;
	while(~scanf("%d",&n)){
		memset(c, 0, sizeof(c));//
		for(i=1;i<=n;i++) 
		scanf("%d",&a[i]);
		scanf("%d",&q);
		while(q--){
			scanf("%d",&x);
			if(x==1){ 
				scanf("%d%d%d%d",&s,&y,&k,&data);
				update(s,k,s%k,data);//差分区间修改
				update(y+1,k,s%k,-data);
			}
			else{
				scanf("%d",&y);
				int ans=querysum(y,y);
				cout<<(ans+a[y])<<endl;//加上初值
			}
		}
	} 
	return 0; 
}
