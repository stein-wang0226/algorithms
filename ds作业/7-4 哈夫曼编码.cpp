#include <bits/stdc++.h>
using namespace std;
char cc=char('z'+1);
struct Node {
	int v;
	int is_leaf;
	char c;
	int id;
	bool operator<(const Node &b)const{
		if(v==b.v&&c==b.c)return id>b.id;
		if (v == b.v)return c > b.c;
		return v > b.v;

	}
}node[10005];
map <Node,vector<Node>> G; //2个
map<char,string >ans;
void init(){
	ans.clear();
	G.clear();
}
void dfs(Node u,string code){
	if(u.is_leaf==1&&u.c!=cc){
		ans[u.c]=code;
		return ;
	}
	Node l = G[u][0],r=G[u][1];
	dfs(l,code+"0");
	dfs(r,code+"1");
}
int main(){
	int T;
	cin>>T;
	while(T--){
		init();
		string s;
		cin>>s;
		map<char,int>cnt;
		for(char & i : s){
			cnt[i]++;
		}
		int idx=0;
		priority_queue<Node>Q;
		for(auto v:cnt){
			node[++idx].c=v.first;
			node[idx].v=v.second;
			node[idx].is_leaf=1;
			node[idx].id=idx;
			Q.push(node[idx]);
		}
        //建树
		while(Q.size()>1){
			Node a=Q.top();
			Q.pop();
			Node b=Q.top();
			Q.pop();
			Node cur;
			cur.is_leaf=0;
			cur.v=a.v+b.v;
			cur.c=cc;
			cur.id=++idx;
			Q.push(cur);
			G[cur].emplace_back(a);
			G[cur].emplace_back(b);

		}
		Node root = Q.top();
		string ss;
		dfs(root,ss);


		for(char &c:s){
			cout<<ans[c];
		}
		cout<<endl;

	}




	return 0;
}