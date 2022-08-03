#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n,m, a[N],d[N];
// 贪心保护城市较多的区间
void solve()
{
	cin>>n>>m;//	memset(a,0,sizeof a);

	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+m);
	d[1]=(a[1]-a[m]+n)%n-1;
	for(int i=2;i<=m;i++){
		d[i]=a[i]-a[i-1]-1;
	}
	if(m==1){//特判
		cout<<min(n,2ll)<<endl;
		return ;
	}
	sort(d+1,d+1+m,greater<int>());
    //
	int ans=m;
	int time=0;
	for(int i=1;i<=m;i++){
        if(time*2+1<d[i])ans+=time*2+1,time+=2; // 未合并 ，可保护两次
        else if(time*2+1==d[i])ans+=time*2,time++;// 可保护一次
        else{
        	for(int j=i;j<=m;j++){
        		ans+=d[j];
        	}
        	break;
        }  //来不及保护
    }
    cout<<ans<<endl;
}



signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}




