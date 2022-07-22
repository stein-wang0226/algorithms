#include<bits/stdc++.h>
using namespace std;
//下面就是 归并排序求逆序对 的过程==
const int N=5e5+5;
long long a[N],ans[N],cnt=0,n;//ans记录逆序对的数量；
void msort(long long *a,int l,int r) {
	if(l>=r) return ;
	int mid=(l+r)/2;
	msort(a,l,mid);//递归的体现
	msort(a,mid+1,r);//
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r) {
		if(a[i]>a[j]) {
			ans[k++]=a[j++];
			cnt+=mid-i+1;}//因为a[i]-a[mid]按递增顺序排列 所以a[j]之前有mid-i+1对逆序对
		else {
			ans[k++]=a[i++];
		}
	}
	while(i<=mid)
		ans[k++]=a[i++];
	while(j<=r)
		ans[k++]=a[j++];
	for(int i=l; i<=r; i++)
		a[i]=ans[i];
}
int main() {
	scanf("%lld",&n);
	for(int i=0; i<n; i++)
		scanf("%lld",&a[i]);
	msort(a,0,n-1);//从1到n将a数组排序；
	cout<<cnt<<"\n";
	return 0;
}
