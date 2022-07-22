#include <bits/stdc++.h>
#define LOCAL
//字符串哈希
#define  ULL unsigned long long
const int N=1e5+5,P=13331;//经验值131,13331,2333   mod 2^64  ull自动溢出
using namespace std;
int n,m;
string s;
ULL h[N],p[N];//h[i] 存 原字符串前i个的哈希值（前缀哈希值） 
//p[i]  预处理p的i次幂 
ULL get(int l,int r){//求 （l,r）区间的子串的哈希值  O1 查询**
  return h[r]-h[l-1]*p[r-l+1];
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m;
cin>>s;
p[0]=1;
for(int i=1;i<=n;i++){//预处理前缀哈希值 和p的幂
  h[i]=h[i-1]*P+s[i-1];//
  p[i]=p[i-1]*P;
}
while(m--){
  int l1,l2,r1,r2;
  cin>>l1>>r1>>l2>>r2;
  if(get(l1,r1)==get(l2,r2))puts("Yes");//子串哈希值相同
  else puts("No");
}
    return 0;
}
