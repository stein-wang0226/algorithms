#include <bits/stdc++.h>
#define LOCAL
//#define int long long
//给定两个升序排序的有序数组 A 和 B，以及一个目标值 x。
//数组下标从 0 开始。
//请你求出满足 A[i]+B[j]=x 的数对 (i,j)。
//应为升序 所以一个从头开始  一个从尾开始即可
using namespace std;
const int N=1e5+5;
int n,m,x,a[N],b[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m>>x;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=m;i++)cin>>b[i];
//头尾模板
int ans=0;
 for (int i = 1, j = m ; i <= n; i ++ )
    {
        while (j > 0 && a[i] + b[j] > x) j -- ;
        if (j >= 0 && a[i] + b[j] == x) cout << i-1 << ' ' << j-1 << endl,ans++;
    }                                                          //   下标从0开始
    return 0;


//快慢双指针
  for (int i = 0, j = 0; i < n; i++)
    {
        times[a[i]] ++; // times数组用来存放每个数字出现的次数

        while (j <= i && times[a[i]] > 1) // 当i移动到现在的位置的时候，该位置上的数字就出现了一次以上，所以可以判定这个数字和前一位数字重复（原数列单调）
                                          // 这时候，j指针就向后移动，一路上将元素删除（在出现数组中删去对应数字的出现次数），直到i指针指向数字的出现次数降为1
        {
            times[a[j]] --;
            j++;
        }

        res = max(res, i - j + 1); // res依次迭代 记录最大的子列长度

    }
    return 0;
    }