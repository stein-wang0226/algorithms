#include <bits/stdc++.h>
#define LOCAL
#define int long long
//单调栈求每个数之后第一个大于他的位置
// 倒序遍历  即找之前第一个大于他的位置
// 单调栈 每次 栈顶比a[i]小就弹出 此时栈顶为答案，将a[i]入栈
using namespace std;
const int N=3e6+5;
int T,n,a[N];
int f[N];
stack<int>S;  //栈中存下标
signed main(){
    std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);

#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=n;i>=1;i--){
        while(!S.empty()&&a[S.top()]<=a[i]){
            S.pop();
        }
    if(S.empty())f[i]=0;
    else f[i]=S.top();
    S.push(i);
}
for(int i=1;i<=n;i++)cout<<f[i]<<" ";
    return 0;
}
