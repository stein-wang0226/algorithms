#include<bits/stdc++.h>
#define ll long long//如果前面的和是非负数，累加后面的数一定比后面的数本身大
//如果前面的和是负数，即需要移动起始位置，寻找后面的数
using namespace std;//思路如果前面为正则继续向后加，遇到负数则先储存比较，知道和为负
const int N=2e5+5;
int  dp[N],cur[N];//dp前i项最大子段和
int  a[N];
int t,n,Case=0;
int main() {
	cin>>t;
	while(t--) {
		Case++;
		int pos1=0,pos2=0,maxpos1,maxpos2;
		cin>>n;
		for(int i=0; i<n; i++) { //input
			scanf("%d",&a[i]);
		}
		dp[0]=a[0];
		cur[0]=max(0,a[0]);//考虑开头为-
		if(a[0]<0&&a[1]>=0)pos1=1;
		for(int i=1; i<n; i++) {
			if(cur[i-1]+a[i]>=0) {//cur 为当前末尾正序列
				cur[i]=cur[i-1]+a[i];
				pos2=i;
			} else  { //cur 为负则清空 ，重新加
				cur[i]=0;
				pos1=i+1;
			}
			if(a[i]>0) {
				dp[i]=max(dp[i-1],cur[i]);		// 比较当前尾列是否更大  ,更新dp
				if(cur[i]>dp[i-1]) {//更新位置
					maxpos1=pos1;
					maxpos2=pos2;
				}
			} else {
				dp[i]=max(dp[i-1],a[i]);    //ai为负则不可能更大
				if(a[i]>dp[i-1])	maxpos1=maxpos2=i;

			}
		}
		printf("Case %d:\n",Case);
		printf("%d %d %d",dp[n-1],maxpos1+1,maxpos2+1);
		if(t>0)	cout<<"\n"<<"\n";
		else  cout<<"\n";
	}
	return 0;
}
