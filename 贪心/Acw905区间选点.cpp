#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
//给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。
//  按左端点排序   之后出现左端点大于之前最小右端点 则+1
using namespace std;
const int N=1e5+5;
int T,n;
struct Node{
    int a,b;
    bool operator<(const Node&m){
        return a<m.a;
    }
} p[N];
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
    cin>>p[i].a>>p[i].b;
}
sort(p+1,p+1+n);
int minn=p[1].b;
int cnt=1;
for(int i=2;i<=n;i++){
if(p[i].a>minn){
    cnt++;
    minn=p[i].b;
}
minn=min(minn,p[i].b);
}

cout<<cnt<<endl;


    return 0;
}

