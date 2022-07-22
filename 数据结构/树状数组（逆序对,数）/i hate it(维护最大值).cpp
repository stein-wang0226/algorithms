#include<bits/stdc++.h>
// 求的是区间最值 而不是前缀  不能像区间和那样用前缀相减
using namespace std;

const int maxn = 2e5+5;
//nlog^2?
inline int read() {
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0', c=getchar();
    return x;
}

int N, M;
int a[maxn], c[maxn]; //

inline int lowbit(const int &x) { return x&-x; }

void updata(int x) { 
    while(x<=N) {
        c[x]=a[x]; //先更新起始 
        int lx=lowbit(x);
        for(int i=1; i<lx; i<<=1) {
            c[x]=max(c[x],c[x-i]);
        }
        x+=lowbit(x);
    }
}

int query(int x, int y) {
    int ans=0;
    while(y>=x) {
        ans=max(ans,a[y]), --y;
        while(y-lowbit(y)>=x) {
            ans=max(ans,c[y]);
            y-=lowbit(y);
        }
    }
    return ans;
}

int main() {
    while(scanf("%d%d", &N, &M)!=EOF) {
        memset(c,0,sizeof(c));
        for(int i=1; i<=N; ++i) a[i]=read(), updata(i);
        while(M--) {
            char c;
            int A, B;
            scanf("\n%c%d%d", &c, &A, &B);
            if(c=='Q') printf("%d\n", query(A,B));
            else if(c=='U') {
                a[A]=B;
                updata(A);
            }
        }
    }
}

