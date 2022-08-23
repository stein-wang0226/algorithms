#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 3e3 + 5;
int T, n,m, a[N];
vector<int>g[N];
int link[N][N];
int vis[N];
vector<int> ans;
bool check(vector<int>res,int num){
	for(auto i:res){
		if(link[i][num]==1)return 0;
	}
	return 1;
}
void dfs(int num,vector<int>&res){
	if(res.size()+n-num+1<ans.size())return ;
	if(num>=n+1){
		if(res.size()>ans.size())ans=res;
		return ;
	}
	if(!vis[num]&&check(res,num)){
		res.emplace_back(num);
	dfs(num+1,res); //选
	//回溯
	res.pop_back();

}
dfs(num+1,res); //不选

}
int ans0[N];
void solve(){
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		g[b].emplace_back(a);
		g[a].emplace_back(b);
		link[a][b]=link[b][a]=1;
	}
	vector<int>res;
	dfs(1,res);
	for(auto i:ans){
		ans0[i]=1;
	}
	cout<<ans.size()<<endl;
	for(int i=1;i<=n;i++){if(ans0[i])cout<<1<<" ";else cout<<0<<" ";}

}
signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	T=1;
	while (T--) {
		solve();
	}
	return 0;
}

