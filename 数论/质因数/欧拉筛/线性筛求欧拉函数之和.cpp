#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+5;
//求1~n 欧拉函数之和
int n;
int prime[N],vis[N];
int phi[N];

int main(){
    cin>>n;
    LL res=0;
    int cnt=0;
    phi[1]=1;// 特殊
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            prime[++cnt]=i;
           phi[i]=i-1; //质数
        }
        for(int j=1;prime[j]<=n/i;j++){
            vis[prime[j]*i]=1;// 线性筛
            if(i%prime[j]==0){
             phi[prime[j]*i]=prime[j]*phi[i];   //线性筛同时求欧拉函数
             break;         //线性筛优化   
            }
            else  phi[prime[j]*i]=(prime[j]-1)*phi[i];
        }
    }
    for(int i=1;i<=n;i++){
        res+=phi[i];
    }
    
    cout<<res<<endl;
    
    
    return 0;
}