#include <iostream>
#include <algorithm>
#include <vector>

//分解质因子 高精度乘法
//  因为 对于n! 包含n以内全部质因子，可用线性筛求出，再计算个数，相乘即可
using namespace std;


const int N = 5010;//线性筛求所有质因子

int primes[N], cnt;
int sum[N];
bool vis[N];//因子次数


void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!vis[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            vis[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}


int get(int n, int p)
                         // 所有p倍数个数，再将n/p (每个倍数/p)

{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}


vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}


int main()
{
    int a, b;
    cin >> a >> b;

    get_primes(a);

    for (int i = 0; i < cnt; i ++ )
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(a - b, p) - get(b, p); // 最后答案因子个数
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt; i ++ )
        for (int j = 0; j < sum[i]; j ++ )// 累乘  这里用快速幂不能变快 高精度ksm L会增加到L方
            res = mul(res, primes[i]);

    for (int i = res.size() - 1; i >= 0; i -- ) printf("%d", res[i]);
    puts("");

    return 0;
}
