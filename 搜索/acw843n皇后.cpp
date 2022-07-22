#include<bits/stdc++.h>
using namespace std;
//按行枚举
int n;
int col[10];// 标记列
int dj[20];//标记对角线   （i+j）
int udj[20];//反对角线    （i-j+10）
char ans[10][10];//存答案
void output(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<ans[i][j];
        cout<<endl;
    }
    cout<<endl;
}
bool check(int x,int y){
    if(col[y]==0&&dj[x+y]==0&&udj[x-y+10]==0)return 1;
    return 0;
}
void dfs(int k){//k 位枚举到第几行
    if(k==n+1){
        output();
        return ;
    }
    for(int j=1;j<=n;j++){
        if(check(k,j)){
            ans[k][j]='Q';//标记
            col[j] =dj[k+j]=udj[k-j+10]=1;//标记
            dfs(k+1);
            col[j] =dj[k+j]=udj[k-j+10]=0;//还原
            ans[k][j]='.';//还原
        }
    }
}

int main(){
      freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    cin>>n;
  //  memset(col,0,sizeof col);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]='.';        
        }
    }

    dfs(1);
    return 0;
}