
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



