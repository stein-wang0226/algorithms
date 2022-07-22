#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e3 + 5;
int T, n,m,q ;
char a[N][N];
int col[N]; //每一列个数
//模拟一下先计算出总列数  记录每一列的*数
//假设不添加 计算最后一列有多少个 那么这些位置不用移动（t个）  将后面填入空  然后再添加补空即可   
// 所以答案为   n-t；                                                                                                   
void solve(){
    cin>>n>>m>>q;
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='*')sum++,col[j]++;
        }
    }

    while(q--){
        //
    int x,y;
    cin>>x>>y;
    if(a[x][y]=='*'){
        col[y]--,sum--;
    }
    else{
        col[y]++,sum++;
    }
    a[x][y]=(a[x][y]=='*'?'.':'*');
    int c=sum/n; //整列数
    int num=sum%n; //最后一列行数
    int t=0;//    不需要移动的*数
    for(int j=1;j<=c;j++){
        t+=col[j];
    }
    for(int i=1;i<=num;i++){
        t+=(a[i][c+1]=='*');// 最后一列
    }

cout<<sum-t<<endl;

}

}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

      solve();

  return 0;
}
