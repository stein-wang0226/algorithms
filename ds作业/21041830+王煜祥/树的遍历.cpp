#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct Node {
	int val, siz;
	Node *son[100];
	~Node(){for(int i = 0; i < siz; i++) delete son[i];}
};
int n, fa[N], Val[N];
vector<int> g[N];
Node *build(int id) {
	Node *x = new Node();
	x -> val = id;
	x -> siz = g[id].size();
	for(int i = 0; i < g[id].size(); i++) {
		x -> son[i] = build(g[id][i]);
	}
	return x;
}
void show1(Node *x) {
	cout << x -> val << " ";
	for(int i = 0; i < x -> siz; i++) {
		show1(x -> son[i]);
	}
}
void show2(Node *x) {
	for(int i = 0; i < x -> siz; i++) {
		show2(x -> son[i]);
	}
	cout << x -> val << " ";
}
void show3(Node *x) {
	stack<Node*> stk;
	stk.push(x);
	while(!stk.empty()) {
		auto x0 = stk.top();
		stk.pop();
		cout << x0 -> val << " ";
		for(int i = x0 -> siz - 1; i >= 0; i--) {
			stk.push(x0 -> son[i]);
		}
	}
}
void show4(Node *x) {
	stack<Node*> stk;
	stack<int> ans;
	stk.push(x);
	while(!stk.empty()) {
		auto x0 = stk.top();
		stk.pop();
		ans.push(x0 -> val);
		for(int i = 0; i < x0 -> siz; i++) {
			stk.push(x0 -> son[i]);
		}
	}
	while(!ans.empty()) cout << ans.top() << " ", ans.pop();
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> Val[i];
	cout << fa[0];
	for(int i = 2; i <= n; i++) {
		cin >> fa[i];
		g[fa[i]].push_back(i);
	}
	auto root = build(1);
	show1(root); cout << "\n";
	show2(root); cout << "\n";
	show3(root); cout << "\n";
	show4(root); cout << "\n"; 


}
int main() {
		std::ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	
	solve();

}
/*
6
1 2 3 4 5 6
0 1 1 1 3 3
*/
