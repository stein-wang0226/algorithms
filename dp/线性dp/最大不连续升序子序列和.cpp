#include <bits/stdc++.h>//jump  ：最大升序子序列和 
using namespace std;
int a[1005],ans[10005],n,t,x;
int main() {
	while(~scanf("%d",&n)&&n) {//输入方式
		memset(a,0,sizeof a);
		memset(a,0,sizeof a);
		for(int i=1; i<=n; i++) { //将起点视作a[0]
			scanf("%d",&a[i]);//input
			ans[i]=a[i];//赋值到ans中，储存前i项最大结果
		}
		int Max=0;
		for(int i=0; i<=n; i++) {

			int k=ans[0];//储存前i项的ans最大值
			for(int j=0; j<i; j++) {
				if(ans[j]>k&&a[j]<a[i])k=ans[j];//找到符合 的最大ans
			}
			ans[i]+=k;
			if(ans[i]>Max)Max=ans[i];
		}

		cout<<Max<<"\n";
	}
	return 0;
}
