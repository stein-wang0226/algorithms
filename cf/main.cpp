#include <bits/stdc++.h>
#define LOCAL
using namespace std;
long long t,n,k,x;
string s;
long long num[2005];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
cin>>n>>k>>x;
x--;//从1开始
cin>>s;
long long  cnt=0;
memset(num,0,sizeof num);
for(int i=n-1;i>=0;i--){//从后往前
if(s[i]=='*')
cnt++;
else if(cnt>0){///连续*
num[i]=x%(cnt*k+1);//0
x/=(cnt*k+1);//类似进制操作
cnt=0;
}
}
for(int i=1;i<=x;i++)cout<<'b';//开头不是a
for(int i=0;i<n;i++){
  if(s[i]=='a'){
    cout<<'a';
  }
  for(int j=1;j<=num[i];j++){
    cout<<'b';
  }
}
cout<<endl;





}
    return 0;
}
