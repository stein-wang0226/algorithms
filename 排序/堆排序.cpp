#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//小根堆  排序 
const int N=1e5+5;
int m,n,h[N];//h[]堆中元素
int cnt;//heap 元素数size
void down(int x){
    int t=x;//x存原下标 看是否需要下移
    if(x*2<=cnt&&h[x*2]<h[t])t=x*2;
    if(x*2+1<=cnt&&h[2*x+1]<h[t])t=2*x+1;   //分别与存在的左右儿子比较，下移
    if(x!=t){//需要下沉
        swap(h[x],h[t]);
        down(t);//递归继续
    }
}
void up(int x){
    int t=x;
    if(x/2&&h[x/2]>h[x])t=x/2;
    if(x!=t){
        swap(h[x],h[t]);
        up(t);
    }
}

void insert(int k){//堆底插入k
    h[++cnt]=k;
    up(cnt);//上移维护堆
}

signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m;

//1.O(n)的建堆 ,更快
cnt=n;
for(int i=1;i<=n;i++)cin>>h[i];

for(int i=n/2;i>=1;i--)down(i);
//n/2个叶子不需要
//2.nlog   建堆 每次插入
// cnt=0; for(int i=1;i<=n;i++){
 // int n;  cin>>k;insert(k);
//}
for(int i=1;i<=m;i++){
    cout<<h[1]<<" ";
    h[1]=h[cnt--];//将堆底覆盖堆顶
    down(1);//维护堆
}


    return 0;
}
