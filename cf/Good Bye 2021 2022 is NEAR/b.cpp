#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//开头递减即可//相同特判
int t,n;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
string s;string ans;
while(t--){
    s.clear();
    ans.clear();
    cin>>n>>s;
    ans+=s[0];
    int cnt=1;
    //特判  末尾相等baa   -->baaaab   
    int flag=0;
    for(int i=1;i<n;i++){
        if(s[i]<s[i-1]){
            flag=1;//递减为1
            ans+=s[i];
            cnt++;
        }
        else if(flag&&s[i]==s[i-1]){
          int j;
          for( j=i;s[j]==s[i];j++){//将连续相等的加上
              ans+=s[j];
              cnt++;
          }  
          i=j-1;
          flag=0;
        }
        
        
        else break;
    }
    //mirror
    for(int i=cnt-1;i>=0;i--){
        ans+=ans[i];
    }
    cout<<ans<<endl;
}
    return 0;
}
