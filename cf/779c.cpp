#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int n;
string s;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
//求1~n中的二进制数个数  即该形式最大二进制数的值
//原数每一位 1/0 不变 正数第i位>1则将之后全变1 即 +2^n-1  
cin>>s;
int ans=0;
int len=s.size();
for(int i=0;i<len;i++){
    int k=s[i]-'0';
    if(k==1)ans+=pow(2,len-1-i);
    else if(k>1){
        ans+=pow(2,len-i);
        ans--;
        break;
    }
}
cout<<ans<<endl;
    return 0;
}
