#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n, a[N];
//递归搜索区间
//若满足 则左子树全部节点小于根节点，右子树所有节点大于等于根节点
//设根节点为 l ll，序列末尾为 r rr，易知在序列中一定存在下标为 i , j i,ji,j 的点，使得[ l + 1 , i ] [l+1,i][l+1,i]的下标对应元素均小于p r e [ l ] pre[l]pre[l]，而[ j , r ] [j ,r][j,r]的下标对应元素均大于等于 p r e [ l ] pre[l]pre[l]
// 若成立 则搜索遍历所有区间
//递归到叶节点时 恰好为后序遍历
//即先序dfs 回溯时加结点 恰为后序
int is_mir;
vector<int>ans; //后序
void dfs(int l,int r){
    if(l>r)return ;
    int root=l; //左端点为根结点
    int i=l+1,j=r;
    if(!is_mir){
        while(i<=r&&a[i]<a[l])i++;
        while(j>l&&a[j]>=a[l])j--;
    }
    else{//镜像
        while(i<=r&&a[i]>=a[l])i++;
        while(j>l&&a[j]<a[l])j--;    
    }

    dfs(root+1,j);//左子树  跳出时：j==i-1 
    dfs(i,r);//右子树

    ans.push_back(a[root]); //回溯加序列
}


void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    is_mir=0;
    ans.clear();
    dfs(1,n);
    if(ans.size()==n){//整个区间都被遍历  满足
        cout<<"YES"<<endl;
    for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=(int)ans.size()-1)cout<<" ";
    }
    cout<<endl;
    }
    else{
        ans.clear();
        is_mir=1;
        dfs(1,n);
        if(ans.size()==n){
            cout<<"YES"<<endl;
    for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=(int)ans.size()-1)cout<<" ";
    }
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }


}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


      solve();
  
  return 0;
}
