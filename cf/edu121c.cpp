#include <bits/stdc++.h>
#define LOCAL
using namespace std;
pair<int ,int>p[105];
int t,n;
int dp[105];//dp[i]  前i个怪兽的答案
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
	cin>>n;
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++){
		cin>>p[i].first;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i].second;
	}
	unsigned long long ans=0;
	dp[1]=(1+p[1].second)*p[1].second/2;
	for(int i=2;i<=n;i++){
		if((p[i].first-p[i-1].first)>=p[i].second){
			dp[i]=dp[i-1]+(1+p[i].second)*p[i].second/2;
		}
		else {
			int flag=0;
			for(int j=i-1;j>=1;j--){
				int len=p[i].first-p[j].first;
				if((p[i].second-p[j].second)<=len){//找最靠后的能连续蓄力的时刻就行，更前面的不用考虑
					dp[i]=dp[j]+(1+p[j].second)*len+len*(len-1)/2;
					flag=1;
					break;//
				}
			}
			if(!flag){
			dp[i]=(1+p[i].second)*p[i].second/2;
			}
		}
	}
	cout<<dp[n]<<endl;
}
    return 0;
}
