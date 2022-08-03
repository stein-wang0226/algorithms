#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
// 
int T, n, a[N];
int r[N];
int head[N];
int num=0;
//维护b的前缀合数组  lowerbound
struct Edge{
	int from,to,next,w1,w2;
}edge[N*2];
vector<int>b;
int tot;
void add(int u,int v,int w1,int w2){
	edge[++tot].to=v;
	edge[tot].w1=w1;
	edge[tot].w2=w2;
	edge[tot].next=head[u];
	head[u]=tot;
}

void dfs1(int u,int sum,int fa){ //求A[]
	a[u]=sum;
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].to;
		if(fa==v)continue;
		int w1=edge[i].w1;
		dfs1(v,sum+w1,u);
	}
}

void dfs2(int u,int fa){
	if(u>1)r[u]=(upper_bound(b.begin(),b.end(),a[u])-b.begin());
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].to;
		if(fa==v)continue;
		int w2=edge[i].w2;
		num+=w2;
		b.push_back(num);
		dfs2(v,u);
		b.pop_back();
		num-=w2;
	}
}

void solve(){
	memset(head,-1,sizeof head);
	tot=0;
	cin>>n;
	int v,w1,w2;
	for(int i=2;i<=n;i++){
		cin>>v>>w1>>w2;
		add(i,v,w1,w2);
		add(v,i,w1,w2);
	}
	dfs1(1,0,0);
	num=0;
	b.clear();
	dfs2(1,0);

	for(int i=2;i<=n;i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;



}
signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}



