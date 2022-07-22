//不知道哪里出问题
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e6+5;
int T, n, a[N],t[N],A[N];
int dp[N][2]; //dp[i][1/0]  前i个时刻 第i个选与不选的最大值（状态机）
//考虑相邻两个
int c[N]; //树状数组维护 j+tj最大值
int lowbit(int x){ return x&(-x);}
// 维护前缀最大值的树状数组（不用区间）
struct node{ //建立映射
    int id,val; 
    bool operator <(const node&b)const{
        return val<b.val;
    }
}p[N];

void update(int i,int val){ //单点更新  
	while(i<=n){
		c[i]=max(t[i],val);
		i+=lowbit(i);
	}
}
int query(int i){//查询前缀最大值
	int res=0;
	while(i>0){
		res=max(res,c[i]);
		i-=lowbit(i);
	}
	return res;
}
void solve(){
    cin>>n;
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++)cin>>t[i],p[i].val=i+t[i],p[i].id=i; 
    for(int i=1;i<=n;i++)cin>>A[i];
    sort(p+1,p+1+n);//
    memset(dp,0,sizeof dp);
    dp[0][0]=dp[0][1]=0;
	//树状数组维护  
	//因为还要考虑到前面的音符可能会影响到后面的音符
	//dp j能转移到 dp i当且仅当 j<=i-ti&&j+tj<=i
	//这是个二维偏序
	//注意到 i是递增的，所以我们可以按照j+tj 从小到大的顺序加入树状数组维护前缀最大值
	// 具体操作：对于递增的i  不断向树状数组按j+tj大小添加dpj(以保证j+tj<i)  然后区间查询max(dp[j])  (j<=i-ti) 
	int j=1;
	for(int i=1;i<=n;i++){
		int v=A[i]*t[i];
		while(p[j].val<=i)update(p[j].id,dp[p[j].id][1]),j++;  //树状数组维护：之前不会影响到i的j dp[j]max  按tj+j的顺序更新
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);//不选 转移1
		int temp=0;
		if(i>t[i])temp=query(i-t[i]);//找到前缀最大值 转移2
        dp[i][1]=temp+v;
    }

int ans=max(dp[n][1],dp[n][0]);
cout<<ans<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
      solve();
  
  return 0;
}
