#include<bits/stdc++.h>
//#define LOCAL
using namespace std;
const int N=1005;
int m,n;
int dp[15][15];  // a前i 变b前j个最小次数
string a[N],b;
int main(){
    #ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int ii=1;ii<=m;ii++){
        int t;
        cin>>b>>t;
        int ans=0;
        for(int i=1;i<=n;i++){
         memset(dp,0X3F,sizeof dp);
         // **初始条件   长度为0的变化
        for(int jj=0;jj<=a[i].size();jj++)dp[jj][0]=jj; 
        for(int jj=0;jj<=b.size();jj++)dp[0][jj]=jj;
            for(int j=0;j<(int)a[i].size();j++){
                for(int k=0;k<(int)b.size();k++){
                   
                  if(a[i][j]==b[k])dp[j+1][k+1]=min(dp[j][k],dp[j+1][k+1]);    //相同  不操作
                  else  {
                      dp[j+1][k+1]=min(dp[j][k+1]+1,dp[j+1][k]+1);//最后一步是对结尾  增/删 
                      dp[j+1][k+1]=min(dp[j][k]+1,dp[j+1][k+1]);   // 改

                  }
                }
            }
            
            if(dp[a[i].size()][b.size()]<=t)ans++;
        }
        cout<<ans<<endl;
    }
    
    
    
    
    
}