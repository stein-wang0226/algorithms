#include<bits/stdc++.h>//µ¼µ¯À¹½Ø 
using namespace std;
const int N=1e5+5;
int a[N],dp1[N],dp2[N];
int main() {
	int n=0;
	while(~scanf("%d",&a[n]))n++;
	dp1[0]=dp2[0]=1;
	for(int i=1; i<n; i++) {
		int Max=0;
		for(int j=0; j<i; j++) {
			if(a[j]>=a[i])Max=max(Max,dp1[j]);
		}
		dp1[i]=Max+1;
	}
	int maxn=0;
	for(int i=0; i<n; i++)maxn=max(maxn,dp1[i]);
	cout<<maxn<<endl;


	for(int i=1; i<n; i++) {
		int Max2=0;
		for(int j=0; j<i; j++) {
			if(a[j]<a[i])Max2=max(Max2,dp2[j]);
		}
		dp2[i]=Max2+1;
	}
	int maxn2=0;
	for(int i=0; i<n; i++)maxn2=max(maxn2,dp2[i]);
	cout<<maxn2<<endl;
	return 0;
}
