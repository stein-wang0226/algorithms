#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。
//单调栈 栈顶比他大就弹出 直到比他小将他插入  （保证栈内单调增（递减除最小元素都没有作用））
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
stack<int>S;
int n;
cin>>n;
for(int i=1;i<=n;i++){
    int k;
    cin>>k;
while(!S.empty()&&S.top()>=k)S.pop();
if(!S.empty())cout<<S.top()<<' ';
else cout<<"-1"<<" ";
S.push(k);
}
    return 0;
}
