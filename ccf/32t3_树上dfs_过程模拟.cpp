// 次级类别儿子 ； 后代类别  子树的所有结点
// dfs 提前计算除子树概率和即可
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
int sum[N],sum0[N]; // 该子树的权重和
int w[N]; //
vector<int>G[N];
vector<int>G_[N];
int n,m;
int root;
set<int>st; // 存结点
int vis[N]; // 存在标记；
int delta[N]; // 每个delta
set<int>spring[N];// 后代
void dfs_spring(int u){ // 计算全部后代
    spring[u].insert(u);
    for(auto v:G[u]) {
        dfs_spring(v);
        for(auto i :spring[v])spring[u].insert(i);
    }

}
void dfs_cal_sum(int u){ // cal st 的 sum
    sum[u] = w[u]; // 自己的
    for(auto v:G[u]){ //  树 不用标记
        if(!vis[v])continue;
        dfs_cal_sum(v);
        // 回溯计算
        sum[u]+=sum[v];
    }
}
void cal_delete(int u){ // 删除子树 update sum
    // 向上删去 sum[u]
    int v= u;
    while(G_[v].size()>0&&u!=root){
         v = G_[v][0]; // 唯一父亲
        sum[v]-=sum[u];
    }
}
void del_node(int u){ // 更新st
    st.erase(u);vis[u]=0;
    for(auto v:G[u])del_node(v);
}

void cal_delta(int u){//计算 delta
    delta[u] = abs(sum[u]-(sum[root]-sum[u])); // 2sum[u]-sum[1]
}
void save(int u){
    st.insert(u);
    for(auto v:G[u]){
        if(vis[v]){
            save(v);//
        }
    }
}
set<int>S;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i],S.insert(i),vis[i]=1; //
    for(int i=2;i<=n;i++){
        int v;cin>>v;
        G[v].push_back(i);
        G_[i].push_back(v); //反图
    }
    int q;
    dfs_spring(1);
    dfs_cal_sum(1); // 计算sum
    for(int i=1;i<=n;i++)sum0[i] = sum[i];


    while(m--){
        // init
        st = S;
        for(int i=1;i<=n;i++)vis[i]=1;
        for(int i=1;i<=n;i++)sum[i] = sum0[i];

        cin>>q;
        root = 1;
        while(st.size()>1){
            int minn = 1e18, min_id = 0;
            for (auto u: st) {
                cal_delta(u);
                if (delta[u] < minn) {
                    minn = delta[u];
                    min_id = u;
                }
            }
            cout<<min_id<<" ";
            if (spring[min_id].count(q)) { // q是否属于min_id
                // 保留
                root = min_id;
                // 重新计算   //清空
                memset(sum,0,sizeof(sum));
                st = set<int>(); // 清空
                save(root); //仅保留 root的现有子树
                memset(vis,0,sizeof(vis));
                for(auto i:st)vis[i]=1; // 更新vis
                dfs_cal_sum(root); // 重新计算sum
            }
            // delete min_id
            else{
                del_node(min_id);
                cal_delete(min_id);
            }
        }

        cout<<endl;
    }
    return 0;
}