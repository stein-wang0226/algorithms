#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t,num;//num为未知个数
int Map[5][5],vis[5][5];
int px[16];//未知位置
int py[16];//
int check(int x,int y,int n){//判断是否能填
    for(int i=1;i<=4;i++){
        if(Map[x][i]==n)return 0;
    }
     for(int i=1;i<=4;i++){
        if(Map[i][y]==n)return 0;
    }
    if(x<=2&&y<=2){
        if(Map[1][1]==n||Map[1][2]==n||Map[2][1]==n||Map[2][2]==n)return 0;
    }
   if(x>2&&y<=2){
        if(Map[3][1]==n||Map[3][2]==n||Map[4][1]==n||Map[4][2]==n)return 0;
    }
    if(x<=2&&y>2){
        if(Map[1][3]==n||Map[1][4]==n||Map[2][3]==n||Map[2][4]==n)return 0;
    }
    if(x>2&&y>2){
        if(Map[3][3]==n||Map[3][4]==n||Map[4][3]==n||Map[4][4]==n)return 0;
    }
    return 1;
}
void dfs(int k){//k为已填未知的个数,正在填k+1
if(k==num){//已填完 输出
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            cout<<Map[i][j];
        }
        cout<<endl;
    }
    return ;
}
for(int i=1;i<=4;i++){
    if(!vis[px[k+1]][py[k+1]]&&check(px[k+1],py[k+1],i)){//该位置能填i
        Map[px[k+1]][py[k+1]]=i;//填
         vis[px[k+1]][py[k+1]]=1;
        dfs(k+1);//填下一个
         vis[px[k+1]][py[k+1]]=0;//回溯
    }
}
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;int Case=0;
while(t--){
    Case++;
    num=0;
    memset(Map,0,sizeof Map);
    memset(px,0,sizeof px);
    memset(py,0,sizeof py);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            char s;
            cin>>s;
            if(s=='*'){
                Map[i][j]=0;
                px[++num]=i;
                py[num]=j;
            }
        else{
            Map[i][j]=s-'0';
        }
        }
    }
    memset(vis,0,sizeof vis);
    printf("Case #%d:\n",Case);
    dfs(0);
}
    return 0;
}
