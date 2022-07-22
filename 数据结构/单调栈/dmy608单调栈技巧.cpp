#include <bits/stdc++.h>
//# pragma GCC optimize(3) 
//#define int long long
using namespace std;
// 按序选N个数字字典序最小
// 维护单调栈升序   
// 但要保证n个数的排列  如果某个数在之后不在出现 则不能被弹出(这样保证最后能留N个数排列)  已在栈中则跳过
// 保证 n个数排列保留在栈中
const int N=2e6+5;

int T,n,m,a[N];
int vis[N];  // 是否在栈中
int last[N]; // 最后出现位置
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0); 

cin>>m>>n;

for(int i=1;i<=m;i++)cin>>a[i],last[a[i]]=i;
stack<int>stk;
memset(vis,0,sizeof vis);
for(int i=1;i<=m;i++){
    if(vis[a[i]])continue;
    while(!stk.empty()&&a[i]<stk.top()&&last[stk.top()]>i){ // 后面还有才能弹出
        vis[stk.top()]=0; // 弹出
        stk.pop();     // 后pop
    }
    stk.push(a[i]);vis[a[i]]=1;
}
vector<int>ans;
int len=stk.size();
while(stk.size()){
    int u=stk.top();
    stk.pop();
    ans.push_back(u);
}
for(int i=len-1;i>=1;i--)cout<<ans[i]<<" ";
cout<<ans[0];
cout<<endl;
    return 0;
}
