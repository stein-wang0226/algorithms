#include <iostream>
#include <cstring>
#include <cstdlib>
#define N 10000005
using namespace std;
int pre[N],sum[N],ans=0;
int find_r(int x1){
 if(pre[x1]!=x1){//不路径压缩会tle 
  pre[x1]=find_r(pre[x1]);
 }
 return pre[x1];
}
void init() {
	for(int i=0; i<=N; i++) {
		pre[i]=i;
		sum[i]=1;
	}
}
void merge(int x, int y) {  //***合并同时记录最多节点的树
	int root_x = find_r(x);
	int root_y = find_r(y);
	if (root_x != root_y) {
		pre[root_x] = root_y;
		sum[root_y] += sum[root_x];        //**合并
		if(ans<sum[root_y])ans=sum[root_y];  //记录最大值
	}
}

int main() {
	int n,a,b;
	while(scanf("%d",&n)!=EOF) {
		ans=1;
		if(n==0) {
			printf("1\n");
			continue;
		}
			init();
		for(int i=1; i<=n; i++) {
			scanf("%d %d",&a,&b);
			merge(a,b);
		}
		printf("%d\n",ans);
	}
	return 0;
}
