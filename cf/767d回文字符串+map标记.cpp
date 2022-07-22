#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//最多只需找一对判断即可
//proof:1.  若存在单个回文显然yes;
//2.不存在  则子串长只有2或3,此时只要有一对能组成回文就存在(任何回文的首尾)2 3；3 2  ；2 2； 3 3；中间最多夹一个  
int t,n;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
  map<string,int>vis;//*** 依次将某个元素标记  并直接查相应的回文字符是否已经出现,yes
  cin>>n;
  int flag=0;
  for(int i=1;i<=n;i++){  
    string s,s1,s2;
    cin>>s;
    if(flag)continue;
    if(s.size()==1){flag=1;}
    vis[s]=1;//***
    s1=s;
    reverse(s1.begin(),s1.end());
    if(vis[s1]){flag=1;}
    if(s.size()==2){//3  2
      for(int i=0;i<26;i++){//任意加一位
        s2=s1+char('a'+i);
        if(vis[s2]){flag=1;}
      }
    }
    if(s.size()==3){//2  3  后两位反转
    s2="";
      s2+=s[2];s2+=s[1];
        if(vis[s2]){flag=1;}
    }
  }

if(flag)cout<<"yes"<<endl;
else cout<<"no"<<endl;
}
    return 0;
}