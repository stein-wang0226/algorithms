#include <bits/stdc++.h>//最长不连续降序子列 
using namespace std;
struct w_v {
	int w,v,index;//index储存原始序号 ，方便记录和输出
} a[1005];
int dp[1005];
bool cmp(w_v a,w_v b) {
	return a.w<b.w;//按体重升序
}
int main() {
	int k=1;//读入个数
	while(~scanf("%d %d",&a[k].w,&a[k].v)) { //input
		a[k].index=k;
		k++;
	}
	k--;
	sort(a+1,a+k+1,cmp);//之前忘记+1 
	//按速度找最长 降序列
	int maxdp=1;
	dp[1]=1;
	for(int i=2; i<=k; i++) { //dp
		int maxlen=0;//记录最长值
		for(int j=1; j<i; j++) {
			if(a[j].w==a[i].w)continue;//之前忽略而出错
			if(a[j].v>a[i].v&&dp[j]>maxlen)maxlen=dp[j];
		}
		dp[i]=maxlen+1;//已i结尾的最大降序子列长度
		if(dp[i]>maxdp)maxdp=dp[i];//
	}
	printf("%d\n",maxdp);
//	for(int i=1;i<=k;i++){
//		cout<<dp[i]<<endl;
//	}
	//推答案
	int curlen=maxdp;//当前长度
	int cur_amin=0;//当前末尾值
	int ans[1005];
	for(int i = k; i > 0,curlen>0; i--) { //从后面往前面推
		if(curlen == dp[i]&&a[i].v>cur_amin) {
			ans[curlen] = a[i].index;
			curlen--;
			cur_amin = a[i].v;
		}
	}
	for(int m=1; m<=maxdp; m++) {
		cout<<ans[m]<<endl;
	}



	return 0;
}
