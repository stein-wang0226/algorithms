#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3) 
//#define int long long
using namespace std;

const int N=2e5+5;
// 模拟栈
//碰到大于栈顶(之前最大)就一直压栈 等于直接弹出
int T,n;
int a[N];
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i];
}
stack<int>stk;
int last=0; //之前被pop的值
for(int i=1;i<=n;i++){
  if(stk.empty()||stk.top()<a[i]){
      int mx=last; //
      if(!stk.empty())mx=max(last,stk.top());
      for(int j=mx+1;j<=a[i];j++){
        stk.push(j);
        cout<<"push"<<" "<<j<<endl;
      }
  }
  if(stk.top()==a[i]){
    cout<<"pop"<<endl;
    last=max(last,stk.top());
    stk.pop();
  }
}
    return 0;
}
