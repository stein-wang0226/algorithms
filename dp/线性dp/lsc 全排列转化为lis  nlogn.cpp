//最长公共子序列 （区别子串） 全排列 LIS单调栈 nlogn ，因为元素相同仅顺序转化为上升子序列问题
//p1439   思路：将a1 视为标准  即a1[1]~a1[n]->1 ,2~n;a[i] i做一一映射 ,则a2也相应变化，求此时a2(离散化)记录  value[a[i]]=i;
#include <bits/stdc++.h>
using namespace std;
int n,k;
const int N =1e5+5;
int a1[N], a2[N],value[N];
int main() {
	cin>>n;
	for(int  i=1; i<=n; i++) {
		cin>>a1[i];
		value[a1[i]]=i;
	}
	for(int  i=1; i<=n; i++) {
		int x;
		cin>>x;
		a2[i]=value[x];//映射后的a2权值
	}
//对a[2] lis
	int len[N],tot=1;
	len[1]=a2[1];
	for(int i=2; i<=n; i++) {
		if(a2[i]>len[tot]) {
			len[++tot]=a2[i];
		}
     else{
     	k=upper_bound(len,len+tot,a2[i])-len;//第一个大于a2[i]的下标 ，替换（保证末尾尽可能小） 
     	len[k]=a2[i]; 
	 }
	}
	cout<<tot;
	return 0;
}
