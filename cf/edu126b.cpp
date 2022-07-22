//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 0;

void solve()
{
    
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);


    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int ans = 32768 - x;
        if (x == 0)
            ans = 0;
        for (int j = 0; j < 20; j++) {
            int x2 = x + j;
            ans = min(ans, __builtin_ffs(32768) - __builtin_ffs(x2) + j);  // __builtin_ffs()  返回x中最后一个为1的位是从后向前的第几位
        }
        cout << ans << ' ';
    }
}