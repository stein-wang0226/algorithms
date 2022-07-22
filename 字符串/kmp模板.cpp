//kmp
//#define int long long
//NEXT [i]  i前最大相等前后缀长度 （模式串指针）j=next[j]  j+1不匹配时j回移到next[j]   
#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    int ans=0;
    cin >> n >> p + 1 >> m >> s + 1;//从1开始 next初值0
//预处理next
    for (int i = 2, j = 0; i <= n; i ++ )// 
    {
        while (j && p[i] != p[j + 1]) j = ne[j];//未匹配上就前移
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j;//
    }
//匹配
    for (int i = 1, j = 0; i <= m; i ++ )
    {
        while (j && s[i] != p[j + 1]) j = ne[j];//j+1未匹配  j之前都匹配 前移到next[j]
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n)
        {//匹配上  输出位置
            printf("%d ", i - n);
            j = ne[j];
            ans++;
        }
    }
    //cout<<ans<<endl;

    return 0;
}
//下标从0开始的写法（不推荐）
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n, m;
char s[N], p[N];
int ne[N];

int main()
{
    cin >> m >> p >> n >> s;

    ne[0] = -1;
    for (int i = 1, j = -1; i < m; i ++ )
    {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j ++ ;
        ne[i] = j;
    }

    for (int i = 0, j = -1; i < n; i ++ )
    {
        while (j != -1 && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == m - 1)
        {
            cout << i - j << ' ';
            j = ne[j];
        }
    }

    return 0;
}