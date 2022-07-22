#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t,n,l,a[105],ans[35];//第i位1的个数
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
cin>>n>>l;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
memset(ans,0,sizeof ans);
for(int i=1;i<=n;i++){
	for(int j=0;a[i]>0;j++){
		if(a[i]%2)ans[j]++;
		a[i]>>=1;
	}
}
int ret=0;
for(int i=0;i<l;i++){
	if(ans[i]*2>=n)ret+=pow(2,i);
}
cout<<ret<<endl;
}
    return 0;
}
