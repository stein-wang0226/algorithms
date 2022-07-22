#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
// 771c  给定一个排列 将逆序对连边  求连通分量数
//法1：单调栈(增) 栈内维护每个分量最大值   如果当前元素x大于之前每个分量max(大于栈顶) ,x入栈.  否则将所有除栈顶外比x大的都pop (与x逆序,都会相连,仅保留最大的栈顶)    答案为栈长度-连通块数
// 法2   先假设为一整个连通分量  如果当前maxx<i   ans+1即可  区间[1,i-1]  与区间[i,n]之间无逆序对  ans+1
int T,n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
cin>>n;
stack<int>st;
for(int i=1;i<=n;i++){
  int x;
  cin>>x;
  if(st.empty()||st.top()<x)st.push(x);
  else {
    int maxx=st.top();//存max 
      while(!st.empty()&&st.top()>x)st.pop();//全弹出  --都连成一块
      st.push(maxx);   //栈顶留最大值
  }
}
  cout<<st.size()<<endl;
}
    return 0;
}
