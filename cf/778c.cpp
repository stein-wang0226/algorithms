#include <bits/stdc++.h>
//# pragma GCC optimize(3) 
#define int long long
using namespace std;

const int N=2e5+5;

int T,n,a[N];
int flag=1;
// 每次合并最小的两个
map<int,int>mp;
void dfs(int x){
if(mp.count(x)){
  mp[x]--;
  if(mp[x]==0)mp.erase(x); ///**
  return ;  // 不再继续
}
if(x<=1){flag=0;return ;}   // 这步优化加上
if(!flag)return;
if(mp.empty())return;
int a=x/2,b=x/2;
if(x%2)b++;
dfs(a);dfs(b);
}
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0); 
cin>>T;
while(T--){
cin>>n;
//小顶堆
mp.clear();
int sum=0;
for(int i=1;i<=n;i++){
  cin>>a[i];
  mp[a[i]]++;
   sum+=a[i];
}
if(n==1){cout<<"yes"<<endl;continue;}
flag=1;
dfs(sum);
if(mp.empty())cout<<"yes"<<endl;
else cout<<"No"<<endl;
}
    return 0;
}
