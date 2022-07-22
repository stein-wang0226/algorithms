#include <iostream>//sg函数模板题--组合游戏的组合
//x点的sg值是 去除 x的 后继节点的sg值后的最小正整数 
#include <cstdio>//记忆化递归+sg函数
#include <ctime>
#include<string.h>
#define LOCAL
using namespace std;
int fibonacci[25];//16就大于1000
int SG[1005];
int m,n,p;
int sg(int t){//找 去除 t的 后继节点的sg值后的最小正整数 
int vis[1005]={0};//记录后继结点的sg值
    if(SG[t]!=-1)return SG[t];//已生成过无需计算 //未生成过再算，减少计算
    for(int i=1;i<=16;i++){
        int next=t-fibonacci[i];//后继结点
        if(next<0)break;
        if(SG[next]==-1)SG[next]=sg(next);//后继节点未生成则向前递归 储存
        vis[SG[next]]=1;//标记后继节点
    }
    for(int i=0;;i++){//从小开始
        if(!vis[i])return i;//不是后继节点的sg值直接返回
    }

}
int main()
{
// std::ios::sync_with_stdio(false);
// cin.tie(0); 
// cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
//先预处理fibonacci（1000）
fibonacci[1]=1;fibonacci[2]=2;
for(int i=3;i<=20;i++){
    fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
}
memset(SG,-1,sizeof SG);//初始化位-1表示未算过，方便记忆化递归
SG[0]=0;//0的sg 显然为0
int ans=0;
while(cin>>m>>n>>p,n*n*p){
    ans=sg(m)^sg(n)^sg(p);

    if(ans)cout<<"Fibo"<<endl;
    else cout<<"Nacci"<<endl;
}


    return 0;
}
