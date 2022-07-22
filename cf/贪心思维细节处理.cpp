#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAX=2e5+5;
int t,n,l,r,a[MAX],b[MAX];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
	cin>>n>>l>>r;
	int k;
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	for(int i=1;i<=l;i++){
		cin>>k;
		a[k]++;
	}
	for(int i=1;i<=r;i++){
		cin>>k;
		b[k]++;
	}
int ans=l+r-2*min(l,r);//(l,r)之差
int ret=0;//已配
for(int  i=1;i<=n;i++){
	int k=min(a[i],b[i]);
	ret+=k;
	a[i]-=k;
	b[i]-=k;
}
int ans0=n/2+ans/2-ret;
int cnt=0;
if(l>r)for(int  i=1;i<=n;i++){
	int m=min(ans/2,a[i]/2);
	cnt+=m;
	ans-=m*2;
	if(ans==0)break;
}
if(l<r)for(int  i=1;i<=n;i++){
	int m=min(ans/2,b[i]/2);
	cnt+=m;
	ans-=m*2;
	if(ans==0)break;
}
ans0-=cnt;
cout<<ans0<<endl;
}
    return 0;
}
