[Problem - E - Codeforces](https://codeforces.com/contest/1705/problem/E)



这个操作有点类似于高精度二进制计算,首先我们把能合并的数字都合并,这样整个序列就变成了一个二进制数字,答案就是二进制数的最高位.

修改一个数字等价于删去一个数字然后加上一个数字,等价于某一位加[公式]或者某一位减去[公式],所以我们只需要模拟这个过程即可.

给二进制数的某一位加上1,例如给001101的第三位加上1变成了000011,我们发现其实就等价于找到要加的那位右边第一个等于0的位,然后将其改为1然后把要加的那位和第一个等于0的位之间所有的1变为1即可,这其实就是一个区间加的操作,可以用线段树实现.

给二进制的某一位减去1也类似,我们只需要找到这一位右边第一个等于[公式]的位,把这位变成0,然后把中间的数都变为[公式]即可.

找某个位置右边第一个等于0/1的位置和查询权值线段树中最大值都是线段树经典操作

```C++
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 105, INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
struct Node{
    int l, r;
    int add;
    int sum;
}tr[maxn * 4];
int cnt[maxn], a[maxn];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void update(int u, int add){
    tr[u].sum += (tr[u].r - tr[u].l + 1) * add;
    tr[u].add += add;
}

void pushdown(int u){
    if (tr[u].add){
        update(u << 1, tr[u].add), update(u << 1 | 1, tr[u].add);
        tr[u].add = 0;
    }
}

void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r;
    if (l == r){
        tr[u].sum = cnt[r];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int add){
    if (tr[u].l >= l && tr[u].r <= r){
        update(u, add);
        return;
    } 
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, add);
    if (r > mid) modify(u << 1 | 1, l, r, add);
    pushup(u);
}

int query0(int u, int l){
    if (tr[u].r < l || tr[u].sum == tr[u].r - tr[u].l + 1) return -1;
    if (tr[u].l == tr[u].r) return tr[u].r;
    pushdown(u);
    int t = query0(u << 1, l);
    if (~t) return t;
    return query0(u << 1 | 1, l);
}

int query1(int u, int l){
    if (tr[u].r < l || !tr[u].sum) return -1;
    if (tr[u].l == tr[u].r) return tr[u].r;
    pushdown(u);
    int t = query1(u << 1, l);
    if (~t) return t;
    return query1(u << 1 | 1, l);
}

int querymax(int u){
    if (tr[u].l == tr[u].r) return tr[u].r;
    pushdown(u);
    if (tr[u << 1 | 1].sum) return querymax(u << 1 | 1);
    return querymax(u << 1);
}

int query(int u, int x){
    if (tr[u].l == tr[u].r) return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) return query(u << 1, x);
    return query(u << 1 | 1, x);
}

int main(){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1; i <= N - 1; i++){
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] %= 2;
    }

    build(1, 1, N);

    // for(int i = 1; i <= 10; i++)
    //     cout << query(1, i) << ' ';
    // cout << '\n';
    while(m--){
        int k, x;
        cin >> k >> x;
        {
            int pos = query1(1, a[k]);
            modify(1, pos, pos, -1);
            if (pos != a[k])
                modify(1, a[k], pos - 1, 1);
        }
        a[k] = x;
        {
            int pos = query0(1, a[k]);
            modify(1, pos, pos, 1);
            if (pos != a[k])
                modify(1, a[k], pos - 1, -1);
        }
        cout << querymax(1) << '\n';
    }

}

```

