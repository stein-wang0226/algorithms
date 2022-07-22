# pk赛2补题：

# t1:

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n, a[N];
int head[N],tot;
//将子树分成链考虑   u的子链中最大值最大的继续向上延续  否则都中止向上，加到ans
int dp[N]; //u中最长子链
int ans;
struct Edge{
    int to,next;
}edge[N*2];
void add(int u,int v){
    edge[++tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}


void dfs(int u){
    int sum=0; 
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        dfs(v);
        sum+=dp[v]; //  先加上所有最大值
        dp[u]=max(dp[u],dp[v]); //更新
    }
    ans+=sum-dp[u]; //减去最大的 （继续向上）
    dp[u]=max(dp[u],a[u]);
}
void solve(){
    memset(head,-1,sizeof head);
    tot=0;
    cin>>n;
    int u;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>u;
        add(u,i); //单向就行
    }
    ans=0;
    dfs(0);//0
    ans+=dp[0];  //加上最后的最大值（不能继续）
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

# t3:

```C++
#include <bits/stdc++.h>
#define N 100007
#define mod 1000000007
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

int n, q, a[N], b[N];

inline void work() {
	int k = rd();
	int tot = 0;
	for (int i = 1; i * i <= k; ++i) 
		if (k % i == 0) {
			b[++tot] = i;
			if (k / i != i) b[++tot] = k / i;
		}
	sort(b + 1, b + 1 + tot);
	int ans = 1, ptr = 1; //ptr  因子数
    //已有所有因子
    //用类似双指针记一遍即可
	for (int i = 1; i <= n; ++i) {
		while (ptr < tot && a[i] >= b[ptr + 1]) ++ptr;
		ans = 1ll * ans * ptr % mod;
	}
	printf("%d\n", ans);
}

int main() {
	n = rd(); q = rd();
	for (int i = 1; i <= n; ++i) a[i] = rd();
	sort(a + 1, a + 1 + n);
	while (q--) work();
	return 0;
}
```

# t4:

可以发现每次使⽤特权⼀定跳到根最优，因为任何点都可以从根⾛到。(可能重复)

## 1.80tps：树上背包（裸）

dp[i] [j]表示从i出发 ，向下j次最多走到的点数 O(n^3)  --(优化)--》每次枚举到当前size O(n^2)

可用线段树优化到 nlog

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;
const int N = 2e3 + 5;
int T, n, k, q, a[N];
int head[N], tot;
int dp[N][N];// dp[i][j]从 i出发 ，向下走j趟的最多点数
struct Edge {
	int to, next;
} edge[N * 2];
void add(int u, int v) {
	edge[++tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot;
}

int dfs(int u) {
	int sz = 1;
	for (int i=head[u];~i;i=edge[i].next) {
		int v=edge[i].to;
		int szs = dfs(v);
		sz += szs;
		for (int j = sz; j >= 1; --j)
			for (int k = 1; k <= szs; ++k)
				if (j >= k) dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
	}
	for (int i = 1; i <= sz; ++i) ++dp[u][i];
	return sz;
}

void solve() {
	memset(head, -1, sizeof head);
	memset(dp,0,sizeof dp);
	tot = 0;
	cin >> n;
	int u;
	for (int i = 2; i <= n; i++) {
		cin >> u;
		add(u, i);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<dp[1][i]<<endl;
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	solve();

	return 0;
}
```

贪心做法  每次选最长的即可

```C++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, siz[N];
// 贪心  每次全最长
//求出每个点对应的最长链 --》

vector<int> g[N], ans;
void dfs(int x) {
	siz[x] = 1;
	vector<int> tmp;
	int mx = 0;
	for(int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		dfs(y);
		tmp.push_back(siz[y]);
		mx = max(mx, siz[y]);
	}
	siz[x] += mx; //最长链
	for(int i = 0; i < tmp.size(); i++) {
		int k = tmp[i];
		if(k == mx) { //mx不加（肯定父节点选择重复，（到最深的情况））
			mx = 0;
			continue;
		}
		ans.push_back(k);//
	}
}
void solve() {
	int n;cin>>n;
	for(int i = 2; i <= n; i++) {
		int x;cin>>x;
		g[x].push_back(i);
	}
	dfs(1);
	ans.push_back(siz[1]);//第一次的情况要补上
	sort(ans.begin(), ans.end());//
	//for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	int k = ans.size() - 1, out = 0;
	for(int i = 0; i < n; i++) {
		if(k >= 0) {
			out += ans[k--];//从大到小；累加即可
		}
		cout << out << "\n";
	}
}
int main() {
		std::ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	solve();
	return 0;
}

```

# t2: 简单dp  矩阵快速幂



75tps版本：不会卡常555

```C++

#include <bits/stdc++.h>
# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 45;
const int mod=19260817;
int n,T,op,a,b,c,d,e;

int dp[N][N][10000]; //dp[i][j][k]  表示当前在 （i,j）已经走了k步的方案数
//车： dp[i][j][k]
int dx1[8]={1,1,-1,-1,2,2,-2,-2};
int dy1[8]={2,-2,2,-2,1,-1,1,-1};
int dx2[4]={2,2,-2,-2};
int dy2[4]={2,-2,2,-2};

bool check(int x,int y){
    if(x<=a&&x>=1&&y<=b&&y>=1)return true;
    return false;
}


int qpow(int a,int k){
    int res=1;
    while(k){
        if(k&1)res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res%mod;
}
void solve(){
    cin>>op>>a>>b>>c>>d>>e;
    memset(dp,0,sizeof dp);
    if(op==1){
        if(a<=1||b<=1){
            cout<<0<<endl;
            return;
        }
        dp[c][d][0]=1;
        for(int i=1;i<=e;i++){  //步数
            for(int x=1;x<=a;x++){
                for(int y=1;y<=b;y++){
                    for(int k=0;k<8;k++){
                        int curx=x+dx1[k];
                        int cury=y+dy1[k];
                        if(check(curx,cury)&&dp[curx][cury][i-1])
                            dp[x][y][i]=(dp[curx][cury][i-1]+dp[x][y][i])%mod;
                    }   
                }
            }
        }
    int ans=0;
    for(int x=1;x<=a;x++){
        for(int y=1;y<=b;y++){
            ans+=dp[x][y][e];
                        ans%=mod;
        }
    }
    cout<<ans<<endl;

    }


    else if(op==2){
        if(a<=2||b<=2){
            cout<<0<<endl;
            return;
        }
        dp[c][d][0]=1;
        for(int i=1;i<=e;i++){  //步数
            for(int x=1;x<=a;x++){
                for(int y=1;y<=b;y++){
                    for(int k=0;k<4;k++){
                        int curx=x+dx2[k];
                        int cury=y+dy2[k];
                        if(check(curx,cury)&&dp[curx][cury][i-1])
                            dp[x][y][i]=(dp[curx][cury][i-1]+dp[x][y][i])%mod;
                    }   
                }
            }
        }
    int ans=0;
    for(int x=1;x<=a;x++){
        for(int y=1;y<=b;y++){
            ans+=dp[x][y][e];
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    }


    else{
    //     dp[c][d][0]=1;
    //     for(int i=1;i<=e;i++){  //步数
    //         for(int x=1;x<=a;x++){
    //             for(int y=1;y<=b;y++){
    //               //x 方向
    //                 for(int k=1;k<=b;k++ ){
    //                     if(k!=y&&dp[x][k][i-1])dp[x][y][i]=(dp[x][y][i]+dp[x][k][i-1])%mod;
    //                 }
    //                 //y
    //                 for(int k=1;k<=a;k++ ){
    //                     if(k!=x&&dp[k][y][i-1])dp[x][y][i]=(dp[x][y][i]+dp[k][y][i-1])%mod;
    //                 }
    //             }
    //         }
    //     }
    // int ans=0;
    // for(int x=1;x<=a;x++){
    //     for(int y=1;y<=b;y++){
    //         ans+=dp[x][y][e];
    //          ans%=mod;
    //     }
    // }
    // cout<<ans<<endl;
    //快速幂
    //每次独立  a+b-2种选择
    int ans=qpow(a+b-2,e);
    cout<<ans%mod<<endl;
    }

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

```

利用临界矩阵乘法（传递性）***  将二维点拆为一维数组

map[i] [j] 表示i-》j的可达方法数  快速幂即可

100tps

用邻接矩阵加速递推

```C++

#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N = 105;
const int mod=19260817;
int n,T,op,a,b,c,d,e;
int dx1[8]={1,1,-1,-1,2,2,-2,-2};
int dy1[8]={2,-2,2,-2,1,-1,1,-1};
int dx2[4]={2,2,-2,-2};
int dy2[4]={2,-2,2,-2};
// 将格子编号1~100
// 矩阵m[i][j]  的值表示从编号i的点到编号j的点 方案数
// 那么求 k（c,j）号点的路径数只要做e次幂求矩阵中所有方案数的和即可
struct Matrix{
	int m[N][N];
}ori,res;

void init(){
	memset(res.m,0,sizeof res.m);
	for(int i=1;i<=100;i++)res.m[i][i]=1; //单位阵
}
Matrix mul (Matrix a,Matrix b){ //矩阵乘法
	Matrix ret;
	memset(ret.m,0,sizeof ret.m);
	for(int i=1;i<=100;i++){
		for(int k=1;k<=100;k++){
			if(a.m[i][k])
				for(int j=1;j<=100;j++)
					ret.m[i][j]+=a.m[i][k]*b.m[k][j]%mod;
		}
	}
	return ret;
}
void qpow(Matrix a,int k){//ksm
	while(k){
		if(k&1) res=mul(res,a);
		a=mul(a,a);
		k>>=1;
    }
}
int qpow(int a,int k){
int res=1;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
    }
    return res%mod;
}
bool check(int x,int y){
    if(x<=a&&x>=1&&y<=b&&y>=1)return true;
    return false;
}
void solve(){
   cin>>op>>a>>b>>c>>d>>e;
   if(op==0){
   	    int ans=qpow(a+b-2,e);
	     cout<<ans%mod<<endl;
	     return;
   }
   if(op==1){
   	init();
   	// 这里初始化关系矩阵 （每个点i到可达点j初始化1）
    memset(ori.m,0,sizeof ori.m);
   	for(int i=1;i<=a;i++){
	   	for(int j=1;j<=b;j++){ // (i,j)
		   	for(int k=0;k<8;k++){
			   	int cx=i+dx1[k];
			   	int cy=j+dy1[k];
			   	if(check(cx,cy))
			   		ori.m[(i-1)*b+j][(cx-1)*b+cy]=1; //对应编号的关系矩阵
			   }
		   }
	   }
   } 
	else if(op==2){
		//同理
		init();
		   	// 这里初始化关系矩阵 （每个点i到可达点j初始化1）
                   memset(ori.m,0,sizeof ori.m);
		   	for(int i=1;i<=a;i++){
			   	for(int j=1;j<=b;j++){ // (i,j)
				   	for(int k=0;k<4;k++){
					   	int cx=i+dx2[k];
					   	int cy=j+dy2[k];
					   	if(check(cx,cy))
			   		ori.m[(i-1)*b+j][(cx-1)*b+cy]=1; //对应编号的关系矩阵
					   }
				   }
			   }
	}
	//
	qpow(ori,e);
   	int sze=a*b;
   	int pos=(c-1)*b+d;//起始位置编号
   	int ans=0;
	for(int i=1;i<=sze;i++){
	ans=(ans+res.m[pos][i])%mod;		
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


```

