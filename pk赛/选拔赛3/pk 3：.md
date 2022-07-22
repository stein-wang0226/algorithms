# 

pk 3：

# t1.（分块优化）

已知该函数返回的值为 xx 二进制表示中 1 的个数，将该函数简记作 \text{popcount }(x)popcount (x)。求下列式子的值
$$
\displaystyle\sum_{i=1}^N\sum_{j=i+1}^N \text{popcount }\left(a_i\text{ xor } a_j\right)
$$

## 20~60tps

在二进制下考虑一个数 ，可以认为 是一个由 构成的 64 维向量。 不难发现 xor 在每一位上独立，只有 1 xor 0才能对答案产生贡献。 可以 统计每一位 0/1 的数量，在最后统计答案即可。

```C++
//位运算  
// 60tps
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
using uint64 = unsigned long long;

const int N = 2e7 + 5;
uint64 T,n,seed;
uint64 a[N];
int cnt[N]; 
// 统计每一位1的个数
// 只有0xor1会产生贡献  每位0 1 个数相乘 累加即可
void solve(){
    cin>>n>>seed;
    std::mt19937_64 mt_rand(seed);

for (int i = 1 ; i <= n ; i++) {
     a[i] = mt_rand();
}

for(int i=1;i<=n;i++){//小常数写法
	for(int j=0;j<64;j++){
		cnt[j]+=a[i]&1,a[i]>>=1; 
	}
}
int ans=0;
for(int i=0;i<64;i++){ // 统计答案
	ans+=cnt[i]*(n-cnt[i]);
}
cout<<ans<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

      solve();
  
  return 0;
}

```

另外：60 pts 发现每个数都是在 范围内的随机数，那么期望意义下，每一个 只有 个 1 ，可以考虑每次 只统计 lowbit 上的信息。

```C++
for(int i = 1 ; i <= n ; i++) {
	uint64 x = mt_rand();
    while (x) {
        s[__builtin_ctzll(x)]++;
        x &= (x - 1);
    }
}


```

通过 __builtin_ctzll(x) 来表示 x 的 lowbit 的位置。

100tps：分块优化常数**

sqrt(64)=8

发现我们每次只统计 1 位的信息似乎对性能有些浪费，那么我们是否可以多统计几位呢？ 我们可以每 8位当成一个小数据块，然后我们被分成了 64/8=8个数据。 类似 20pts 的思路 ，同样的我们统计每一个数据中每种权值出现的次数。 权值的值域为 [0,2^8]，我们可以枚举两两权值预处理出 xor 后的贡献。 这样就得到了 O(nw/8)的实现方法。

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
using uint64 = unsigned long long;
const int N = 36666670;
const int S = 255; // 11111111
uint64 T, n, seed;
int val[300][300]; //预处理
int cnt[300][8]; //64位分8段 cnt[i][j] :第j段的8位二进制数i的总出现次数
// 统计每一位1的个数
// 只有0xor1会产生贡献  每位0 1 个数相乘 累加即可
void solve() {
	cin >> n >> seed;
	std::mt19937_64 mt_rand(seed);

	for (int i = 1; i <= n; i++) {  //直接读入  存不下
		uint64 t = mt_rand(), v;
		for (int j = 0; j < 8; j++) {
			v = t & S; //末8位
			cnt[v][j]++; // 记录权值出现次数
			t >>= 8;
		}
	}

//每段分别求和
	int ans = 0;
	for (int i = 0; i <=S; i++) { //枚举一大一小两个8位二进制数（预处理过）
		for (int j = i + 1; j <= S; j++) {
			uint64 x = val[i][j], res = 0; //
			for (int k = 0; k < 8; k++) { //8段分别求和
				res += cnt[i][k] * cnt[j][k]; // 出现次数的乘积（对数）*val（1的个数）就是答案
			}
			ans += res * x;
		}
	}
	cout<<ans<<endl;
}
signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

//预处理8位所有数的两两异或值 二进制的1个数
	for (int i = 0; i <= S; i++) {
		for (int j = i + 1; j <= S; j++) {
			val[i][j] = __builtin_popcount(i ^ j);
		}
	}
	solve();

	return 0;
}

```

# t2

60tps:

自己的dp

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e6 + 5;
int T, n, a[N],t[N];
int dp[N][2]; //dp[i][1/0]  前i个时刻 第i个选与不选的最大值（状态机）
int maxx[N]; 
//考虑相邻两个
void solve(){
    cin>>n;
    int flag=1;
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=1;i<n;i++){
		if(t[i]!=t[i+1]){
			flag=0;break;
		}
	}
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(dp,0,sizeof dp);
    memset(maxx,0,sizeof maxx);
    dp[0][0]=dp[0][1]=0;
    //特判; t相等：这意味着只要满足相邻两个音符的距离不小于
	//可以从dp 0~i-t 转移到dp i
	//记一个前缀最大值即可优化转移
    if(flag){  //特判 t相等的情况
    	int tt=t[1];
		 for(int i=1;i<=n;i++){
		        int v=a[i]*t[i];
		        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);//不选 转移1
		       	if(i>=tt)dp[i][1]=maxx[i-tt]+v; //转移2 从最大的转移过来
		        else dp[i][1]=v;
		       	maxx[i]=max(maxx[i-1],dp[i][1]);   //维护前缀最大值
		    }
	int ans=max(dp[n][1],dp[n][0]);
	cout<<ans<<endl;
			return ;
	}
    
    
    for(int i=1;i<=n;i++){
        int v=a[i]*t[i];
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);//不选 转移1
        for(int j=i-1;j>0;j--){//从后向前找 不能重叠 的（最大）
          if (i - t[i] >= j && j + t[j] <= i) {  //不重叠
			dp[i][1]=max(dp[i][1],dp[j][1]+v);
			 if (dp[j][1] >= dp[j][0])break;  // 剪枝如果选j比不选j更优秀
			 //那i前一个音符肯定是j  不用向前找
          }  //转移2
        }
        if(i<=t[i])dp[i][1]=v;
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


```

```C++
//树状数组维护  
//因为还要考虑到前面的音符可能会影响到后面的音符
//dp j能转移到 dp i当且仅当 j<=i-ti&&j+tj<=i
//这是个二维偏序
//注意到 i是递增的，所以我们可以按照j+tj 从小到大的顺序加入树状数组维护前缀最大值
// 具体操作：对于递增的i  不断向树状数组按j+tj大小添加dpj(以保证j+tj<i)  然后区间查询max(dp[j])  (j<=i-ti) 
```

```C++
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

```



```C++
//同样做法的正解 （dp的方式区别）
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
ll t[N], a[N], c[N], n, dp[N];
ll lowbit(ll x) {
	return x & -x;
}
ll query(ll i) {
	ll ret = 0;
	while(i > 0) {
		ret = max(c[i], ret);
		i -= lowbit(i);
	}
	return ret;
}
void update(ll i, ll val) {
	while(i <= n)
	{
		c[i] = max(c[i], val);
		i += lowbit(i);
	}
}

void solve() {
	ll mx = 0;
	cin >> n;
	vector<vector<int> > add(n + 5);
	for(ll i = 1; i <= n; i++) {
		cin >> t[i];
	}
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(ll i = 1; i <= n; i++) {
		for(ll p : add[i]) {
			update(p, dp[p]);
		}
		if(i - t[i] <= 0) {
			dp[i] = t[i] * a[i]; 
		}
		else {
			dp[i] = query(i - t[i]) + t[i] * a[i];
		}
		if(i + t[i] <= n) {
			add[i + t[i]].push_back(i);
		}
		mx = max(mx, dp[i]);
	}
	cout << mx << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

```

# t4:贪心

是否能全部消灭只和序列中的 1 的数量有关，1 的数量小于 x 则输出-1 对于最多能消灭多少个带无敌的敌人的问题，显然能 01 匹配的尽量匹配，对于多出来的 1 可以选择两个 1 匹配。 注意无敌的敌人数量不能超出敌人总数，两个 1 匹配之后不能让 1 的总数小于敌人

```C++

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5 + 5;
ll n, m, cnt[N], flag[N];
ll pre = 0;
int main() {
	scanf("%lld%lld", &n, &m);
	string s;
	cin >> s;
	//能 01 匹配的尽量匹配，对于多出来的 1
	//可以选择两个 1 匹配
	for(int i = 1; i <= n; i++) {
		flag[i] = flag[i - 1];
		if(s[i - 1] == '1') {
			cnt[i] = cnt[i - 1] + 1;//1的前缀和
			if(pre) flag[i]++, pre--;// 
		}
		else {
			cnt[i] = cnt[i - 1];
			pre++;//之前0的个数
		}
	}
	while(m--) {
		ll x, k;
		cin >> x >> k;
		if(cnt[k] < x) {
			printf("-1\n");
		}
		else {
			printf("%lld\n", min(x, flag[k] - (x - cnt[k])));
		}
	}
	return 0;
}

```

