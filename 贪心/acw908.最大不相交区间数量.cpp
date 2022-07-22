#include <bits/stdc++.h>
#define endl "\n"
# pragma GCC optimize(3) 
//#define LOCAL
//#define int long long
using namespace std;
// 按左端点排序  不相交尽量多  所以遍历时右端点尽量小
//发现不相交则cnt+1    一直更新右端点最小值
const int N=2e5+5;

int T,n;
int x[N],y[N];
struct Node{
  int a,b;
  bool operator <(const Node &m)const{
    return a<m.a;
  }
}p[N];
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
  cin>>x[i]>>y[i];
  p[i].a=x[i];
  p[i].b=y[i];
}
sort(p+1,p+1+n);

int ans=1; int r=0x3f3f3f3f;
r=p[1].b;
for(int i=2;i<=n;i++){
if(p[i].a>r)ans++,r=p[i].b;
else r=min(r,p[i].b);
}
cout<<ans<<endl;

    return 0;
}
