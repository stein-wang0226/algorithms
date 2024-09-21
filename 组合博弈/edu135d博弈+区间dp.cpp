//
// Created by wyx on 2022-08-25 16:33.
//
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N=2e3+5;
int T,n,a[N],b[N];
// 后选的(内部 )优先级大   区间dp 
//  若len=2  相等平局 否则A win
// 区间dp转移
// 若 A选sl 且dp l+1,r-1,  dp l+2,r 都为1 则A win
//若A选sr   , 且 dp l+1,r-1 和 dp l+1,r-1,dp l ,r-2均为1 则 A win
//若   上述两个dp种均有-1  则 B win
//另外 讨论 详见pzr题解



void solve()
{
	string s; cin>>s;
	int l = 0, r = s.length() - 1;
	vector <vector<int>>dp(s.length() + 1, vector<int>(s.length() + 1, 0));
	for(int step = 2; step <= s.length(); step += 2)
	{
		for(int l = 0; l <= s.length() - step; l++)
		{
			int r = l + step - 1;
			if(step == 2) 
			{
				if(s[l] != s[l+1]) dp[l][r] = 1;
			}
			else
			{
				if(min(dp[l+2][r], dp[l+1][r-1]) == 1) {dp[l][r] = 1; continue;}
				if(min(dp[l][r-2], dp[l+1][r-1]) == 1) {dp[l][r] = 1; continue;}
				if(min(dp[l+2][r], dp[l+1][r-1]) == -1 && min(dp[l][r-2], dp[l+1][r-1]) == -1) {dp[l][r] = -1; continue;}

				dp[l][r] = -1;

	            // Alice choose s[l]
				if(min(dp[l+2][r], dp[l+1][r-1]) == 0)
				{
					if(!((s[r] < s[l] and dp[l+1][r-1] == 0) or (s[l+1] < s[l] and dp[l+2][r] == 0))) 
					{
						dp[l][r] = 0;
						if(!((s[r] == s[l] and dp[l+1][r-1] == 0) or (s[l+1] == s[l] and dp[l+2][r] == 0))) dp[l][r] = 1;
					}
				}

	            // Alice choose s[r]
				if(min(dp[l][r-2], dp[l+1][r-1]) == 0)
				{
					if(!((s[l] < s[r] and dp[l+1][r-1] == 0) or (s[r-1] < s[r] and dp[l][r-2] == 0))) 
					{
						dp[l][r] = 0;
						if(!((s[l] == s[r] and dp[l+1][r-1] == 0) or (s[r-1] == s[r] and dp[l][r-2] == 0))) dp[l][r] = 1;
					}
				}
			}
		}
	}
	
	if(dp[0][s.length()-1] == 1) cout<<"Alice\n";
	if(dp[0][s.length()-1] == 0) cout<<"Draw\n";
	if(dp[0][s.length()-1] == -1) cout<<"Bob\n";
}


signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while (T--) {
		solve();
	}
	return 0;
}
