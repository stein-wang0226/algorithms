#include<bits/stdc++.h>
#define ll long long
using namespace std;
//dp 不超时
//思路：每一个新丑数由之前某个数*2/*5/*7/*3 ,所以每次 记录之前某数*2（3 5 7）的最大位置，
//新丑数必定为相应最大位置+1 *相应值（2 3 5 7）的较小者，找到后更新最大位置（+1）
ll a[6000];
int main () {
	a[1]=1;
	int n,k1=1,k2=1,k3=1,k4=1;
	for(int i=2; i<= 5842; i++) {//先储存所有丑数，以便多组
		a[i]=min(a[k1]*2,min(a[k2]*3,min(a[k3]*5,a[k4]*7)));
		if(a[i]==a[k1]*2)k1++;//eg.当前丑数已由第k1 个丑数*2后产生，那新丑数至少由第k1+1 位*2产生；
		if(a[i]==a[k2]*3)k2++;
		if(a[i]==a[k3]*5)k3++;
		if(a[i]==a[k4]*7)k4++;
	}
	while(~scanf("%d",&n)&&n) {
		if(n%10==1&&n % 100!=11)printf("The %dst humble number is %lld.\n",n,a[n]);
		else if(n%10==2&&n % 100!=12)printf("The %dnd humble number is %lld.\n",n,a[n]);
		else if(n%10==3&&n % 100!=13)printf("The %drd humble number is %lld.\n",n,a[n]);
		else
			printf("The %dth humble number is %lld.\n",n,a[n]);
	}
	return 0;
}
