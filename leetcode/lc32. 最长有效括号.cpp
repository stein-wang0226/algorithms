#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
//最长有效括号
class Solution1 {//法一：从左到右，从右到左都扫一遍，计算left-right>=0最大区间取最大
public:
	int longestValidParentheses(string s) {
		int left = 0, right = 0, maxlength = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				left++;
			} else {
				right++;
			}
			if (left == right) {
				maxlength = max(maxlength, 2 * right);
			} else if (right > left) {
				left = right = 0;
			}
		}
		left = right = 0;
		for (int i = (int)s.length() - 1; i >= 0; i--) {
			if (s[i] == '(') {
				left++;
			} else {
				right++;
			}
			if (left == right) {
				maxlength = max(maxlength, 2 * left);
			} else if (left > right) {
				left = right = 0;
			}
		}
		return maxlength;
	}
};
//法二dp
//1.dp[i]=dp[i−2]+2     ....()
//  ...?(.....))   **  dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2  dp[i−dp[i−1]−2]含义 i-1的（的左侧匹配的最长子串

class Solution {
public:
	int longestValidParentheses(string s) {
		int maxans = 0, n = s.length();
		vector<int> dp(n, 0);
		for (int i = 1; i < n; i++) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				} else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
				}
				maxans = max(maxans, dp[i]);
			}
		}
		return maxans;
	}
};

//法3  模拟栈，最好写每次（）抵消时计算下标差值
class Solution3 {
public:
	int longestValidParentheses(string s) {
		int n=s.size();
		int maxx=0;
    	stack<int>stk;//存下标
    	stk.push(-1); //关键  全匹配减的位置
    	for(int i=0;i<n;i++){
    		if(stk.top()>=0&&s[stk.top()]=='('&&s[i]==')'){
    			stk.pop();
    			int tmp=i-stk.top();
    			maxx=max(maxx,tmp);
    			
    		}
    		else{
    			stk.push(i);
    		}
    	}
    	return maxx;
    }
};

