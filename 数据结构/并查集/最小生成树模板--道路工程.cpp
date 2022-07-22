#include <bits/stdc++.h>
using namespace std;
//最小生成树
int pre[105], m, n, t;
void init(int n) {  //初始化为自身
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
	}
}
int find_r(int x) {   //寻找根节点函数
	while (pre[x] != x) {  //不为根
		x = pre[x];       //一直向上找
	}
	return x;
}
void merge(int x, int y) {
	int root_x = find_r(x);
	int root_y = find_r(y);
	if (root_x != root_y) {  //不属于同一集合
		pre[root_x] = root_y;  //合并
	}
}
struct edge {
	int from, to, dis;
	bool operator<(const edge &b) const {
		return dis < b.dis;  //升序
	}
} a[6000];
int main() {
	while (~scanf("%d",&n),n) {
		int ans=0;
		init(n);
		memset(a,0,sizeof a);
		for (int i = 1; i <= n * (n - 1) / 2; i++) {
			scanf("%d %d %d",&a[i].from,&a[i].to,&a[i].dis);
		}
		sort(a + 1, a + n * (n - 1) / 2+1);  //升序排序
		for (int i = 1; i <= n * (n - 1) / 2; i++) {
			int x=a[i].to;
			int y=a[i].from;
			if(find_r(x)!=find_r(y)) { //不属于同一集合合并 ，防止成环
				merge(x,y);
				ans+=a[i].dis;
			}
		}
		printf("%d\n",ans);
	}
}

