#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N][N],t,n;
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) { //input
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=n-1; i>=1; i--) { //µ¹Ðò
			for(int j=1; j<=i; j++) {
				a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
			}
		}
cout<<a[1][1]<<"\n";
	}
	return 0;
}
