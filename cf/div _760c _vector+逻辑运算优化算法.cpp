#include <bits/stdc++.h>     

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);//初始化容器  才能通过下标赋值，否则只能pushback
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> g(a.begin(), a.begin() + 2);//将a0 ~a2 拷贝到vec g中
    for(int i = 0; i < n; i++)//g[0]  g[1]分别存放积 偶 位的gcd
    {
        g[i % 2] = __gcd(g[i % 2], a[i]);//求gcd  
    }  
    vector<bool> good(2, true);//容量为2 初值为true   分别代表求得的奇数位的gcd能否整除任意偶数位 或 相反
    for(int i = 0; i < n; i++)
    {
        good[i % 2] = good[i % 2] && (a[i] % g[(i % 2) ^ 1] > 0);//**用逻辑运算 不需要flag
    }   
    long long ans = 0;//** 初值为0
    for(int i = 0; i < 2; i++)
        if(good[i])//true 为奇/偶数位全都不能整除的合法情况
            ans = g[i ^ 1];
    cout << ans << endl;
}

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        solve();
    }
}