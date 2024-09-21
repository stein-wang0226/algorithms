//
// Created by wyx on 2022-08-25 16:33.
//
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N=2e4+5;
const int mod=80112002;
int T,n,m,k,a[N];
vector<int>G[N];
int in[N],out[N];
//  拓扑序+ 一维简单dp
int dp[N];
queue<int>que;

void solve() {
	cin>>n>>m;
	int u,v;
	memset(dp,0,sizeof dp);
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		G[u].emplace_back(v);
		in[v]++;
		out[u]++;
	}
	vector<int>vec1,vec2;
	int idx=0;
	for(int i=1;i<=n;i++){
		if(in[i]==0)vec1.emplace_back(i),que.push(i),dp[i]=1,idx++; 
		else if(out[i]==0)vec2.emplace_back(i);  
	}
	vector<int> order;
	while(!que.empty()){
		u=que.front();que.pop();
		order.emplace_back(u);
		for(auto v:G[u]){
			if(--in[v]==0){
				que.push(v);
				idx++;
			}
		}
	}
	//if(idx!=n)cerr<<"error"<<endl;
	//dp  按拓扑序dp转移
	for(auto u:order){
		for(auto v:G[u]){
			dp[v]+=dp[u];
			dp[v]%=mod;
		}
	}
	int ans=0;
	for(auto v:vec2)ans+=dp[v],ans%=mod;
		cout<<ans%mod<<endl;

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
