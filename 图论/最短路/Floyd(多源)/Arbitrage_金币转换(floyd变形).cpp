#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//金钱转换————最短路变形————取max
//是否存在环使权值相乘大于1
//多源--Floyd
int m,n;
double dp[35][35];
void floyd(){
for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i][j],dp[i][k]*dp[k][j]);
        }
    }
}
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
int Case=0;
while(cin>>n,n){
    
    Case++;
    map<string,int>Mp;
    memset(dp,0,sizeof dp);//初始化为0**
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        Mp.insert(pair<string,int>(s,i));//建立映射
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string s1,s2;
        double rate;
        cin>>s1>>rate>>s2;
        dp[Mp[s1]][Mp[s2]]=rate;//有向
    }
    floyd();
int flag=0;
for(int i=1;i<=n;i++){
    if(dp[i][i]>1){
        flag=1;
        break;
    }
}
if(flag)printf("Case %d: Yes\n",Case);
else printf("Case %d: No\n",Case);

}
    return 0;
}
