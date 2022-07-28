#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 4e5 + 5;
int T, n, a[N];
vector<int> g[N];
int pre[N*2];
int find_r(int x) {//递归
	if (x != pre[x]) pre[x] = find_r(pre[x]);//
	return pre[x];
}
void merge(int x,int y) {	   //合并函数
	int rx=find_r(x);
	int ry=find_r(y);
	if(rx!=ry) pre[rx]=ry;
}
void init(int n) {			//初始化函数
	for(int i=1; i<=n; i++)
		pre[i]=i;
    for(int i=1; i<=n; i++)
        g[i].clear();
}
void solve(){
    //二分图判别--并查集(扩展域1~2n)实现,将两边的点分别并到1~n  n+1~2n 两个集合 不出现祖先相同的情况   染色法也可
    // 将点i拆为i和i+n(虚点) 分属两边  若i和a同集合 则i+n与a+n同集合，反之交换
    // 每个数字肯定出现2次  且在不同牌上
    cin>>n;
    init(n*2);
    int x,y;
    int flag=1;
    for(int i=1;i<=n;i++)
{
    cin>>x>>y;
    if(x==y)flag=0;
    if(g[x].size()>=2||g[y].size()>=2)flag=0;
    if(g[x].size()&&g[y].size()) //都为1
    {
        int fa=find_r(g[x][0]);// 之前的x所属
        int fb=find_r(g[y][0]+n);// 之前的y所属的令一遍
        if(fa==fb)flag=0; // 之前对立 ，现在在一张牌上
    }
    if(g[x].size())merge(i,g[x][0]+n),merge(g[x][0],i+n);
    if(g[y].size())merge(i,g[y][0]+n),merge(g[y][0],i+n);
    g[x].push_back(i);
    g[y].push_back(i);
}
if(flag)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
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
