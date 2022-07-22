#include <bits/stdc++.h>
#define LOCAL
//#define int long long
//扩展欧几里得算法
int x,y,a,b;
int ex_gcd(int a,int b,int &x,int &y){
    if(b==0){//跳出条件
        x=1;
        y=0;
        return a;//
    }
    int gcd=ex_gcd(b,a%b,x,y);
    int temp=x;
    x=y;
    y=temp-(a/b)*y;
    return gcd ;//
}
using namespace std;
int T,n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
    cin>>a>>b;
    // 有解 
    int d=ex_gcd(a,b,x,y);
    cout<<x<<" "<<y<<endl;
}
    return 0;
}
