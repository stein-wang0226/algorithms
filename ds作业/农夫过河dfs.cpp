#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+5;

int T;
map<int ,string >S;
struct status
{
	int people;
	int wolf;
	int sheep;
	int vegetable;
	bool operator <(const status&b)const{
		return  people*8+wolf*4+sheep*2+vegetable<b.people*8+b.wolf*4+b.sheep*2+b.vegetable;
	}
};
int check(status s){
	if(s.wolf==s.sheep&&s.people!=s.wolf||s.sheep==s.vegetable&&s.people!=s.sheep)return 0;
	return 1;
}
int End(status s){ //成功
	if(s.wolf==1&&s.sheep==1&&s.vegetable==1)return 1;
	return 0;
}
map<status,int>vis;
void dfs1(status s,vector<int>order){ // 标记剪枝法 (只能一个方案)
	vis[s]=1;
	if(End(s)){
		for(auto i:order){
			cout<<S[i]<<'-';
		}
		cout<<endl;
		return ;
	}
	vector<int>tmp=order;

	status s1=status{!s.people,!s.wolf,s.sheep,s.vegetable};
	tmp.emplace_back(1);
	if(!vis[s1]&&s.wolf==s.people&&check(s1))
      dfs1(s1,tmp);//同一侧且未搜索

  status s2=status{!s.people,s.wolf,!s.sheep,s.vegetable};
  tmp.pop_back();//回
  tmp.emplace_back(2);
  if(!vis[s2]&&s.sheep==s.people&&check(s2))
  	dfs1(s2,tmp);

  status s3=status{!s.people,s.wolf,s.sheep,!s.vegetable};
  tmp.pop_back();//回
  tmp.emplace_back(3);
  if(!vis[s3]&&s.vegetable==s.people&&check(s3))
  	dfs1(s3,tmp);

  status s4=status{!s.people,s.wolf,s.sheep,s.vegetable};//不带
    tmp.pop_back();//回
    tmp.emplace_back(0);
    if(!vis[s4]&&check(s4))
    	dfs1(s4,tmp);

}

void dfs2(status s,vector<int>order,int depth){ // 不标记  限制深度 -- 可输出全部方案  复杂度较高
	if(End(s)){
		for(auto i:order){
			cout<<S[i]<<'-';
		}
		cout<<endl;
		return ;
	}
    if(depth>7)return; // 限制深度
    vector<int>tmp=order;

    status s1=status{!s.people,!s.wolf,s.sheep,s.vegetable};
    tmp.emplace_back(1);
    if(s.wolf==s.people&&check(s1))
        dfs2(s1,tmp,depth+1);//同一侧且未搜索

    status s2=status{!s.people,s.wolf,!s.sheep,s.vegetable};
    tmp.pop_back();//回
    tmp.emplace_back(2);
    if(s.sheep==s.people&&check(s2))
    	dfs2(s2,tmp,depth+1);

    status s3=status{!s.people,s.wolf,s.sheep,!s.vegetable};
    tmp.pop_back();//回
    tmp.emplace_back(3);
    if(s.vegetable==s.people&&check(s3))
    	dfs2(s3,tmp,depth+1);

    status s4=status{!s.people,s.wolf,s.sheep,s.vegetable};//不带
    tmp.pop_back();//回
    tmp.emplace_back(0);
    if(check(s4))
    	dfs2(s4,tmp,depth+1);

}
void solve() {
	S[1]="wolf",S[2]="sheep",S[3]="vegetable";S[0]="people";
  vector<int>order;// 状态1 2 3 分别表示运狼羊菜
  vis.clear();
  cout<<"start"<<endl;
  dfs1(status{0,0,0,0},order);
  cout<<"--------"<<endl;
  dfs2(status{0,0,0,0},order,0);

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
