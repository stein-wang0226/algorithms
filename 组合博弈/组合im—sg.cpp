#include <bits/stdc++.h>
#define LOCAL
//#define int long long
// 组合nim   ：n堆 每拿a[i]个  
using namespace std;
const int N=105;
const int M =1e4+5;   //  数范围
int n,k,a[N];//  a为取石子方法数
int s[N];
int SG[M];  //记忆化储存sg值
int sg(int x){// 记忆化递归
	int vis[M]={0};
	if(SG[x]!=-1) return SG[x];//已生成直接返回
	for(int i=1;i<=k;i++){
		int next=x-a[i];//后继结点
		if(next<0)break;  // 已sort a  小于0跳出 未sort则continue  
		if(SG[next]==-1) SG[next]=sg(next);// 递归生成sg
		vis[SG[next]]=1;   //标记后继结点
	}
	for(int i=0;;i++){//求 mex
	if(!vis[i])return SG[x]=i;     //记忆化
	}
}

signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
memset(SG,-1,sizeof SG);  //  初始化
cin>>k;
for(int i=1;i<=k;i++)cin>>a[i];//方法数
sort(a+1,a+1+k);   //  **
cin>>n;
int ans=0;   //异或0不变
for(int i=1;i<=n;i++){
    int  m;
    cin>>m;
    ans^=sg(m);
}// 石子数
	if(ans)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
    return 0;
}
