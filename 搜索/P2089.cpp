#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
int n;//将n拆成10个正数
int cnt=0;
int a[10];
vector<int>ans[10000];
void dfs(int n,int res){
    if(n==10){
        if(res==0){cnt++;
            for(int i=1;i<=10;i++)ans[cnt].push_back(a[i]);
        }
        return ;
    }
    for(int i=1;i<=3;i++){
        a[n+1]=i,dfs(n+1,res-i);
    }
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
if(n<10){
    cout<<"0"<<endl;
    return 0;
}
dfs(0,n);
if(cnt){
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
else cout<<"0"<<endl;
    return 0;
}
