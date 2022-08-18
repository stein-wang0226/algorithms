
//最长回文子串

#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
using namespace std;
//1.区间dp 0/1
class Solution {
public:
	

	string longestPalindrome(string s) {
		int n= s.size();
    	bool dp[n+5][n+5]; //
    	if(n<2)return s;
    	for(int i=0;i<n;i++)dp[i][i]=1; //长度为1都是回文

    	//区间dp
    		int ans=0;
    	string res="";
    	for(int len=2;len<=n;len++){
    		for(int i=0;i<n;i++){
    			int j=i+len-1;
    			if(j>=n)break;
    			if(s[i]!=s[j])dp[i][j]=0;
    			else{
    				if(j-i<3)dp[i][j]=1;
    				else  dp[i][j]=dp[i+1][j-1];
    			}
    			if(dp[i][j]){
    				if(len>ans){
    					ans=len;
    					res=s.substr(i,len);
    				}
    			}
    		}
    	}
    	return res;

    }
};


//2.中心扩展
//3.马拉车
class Solution {
public:
	int expand(const string& s, int left, int right) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			--left;
			++right;
		}
		return (right - left - 2) / 2;
	}

	string longestPalindrome(string s) {
		int start = 0, end = -1;
		string t = "#";
		for (char c: s) {
			t += c;
			t += '#';
		}
		t += '#';
		s = t;

		vector<int> arm_len;
		int right = -1, j = -1;
		for (int i = 0; i < s.size(); ++i) {
			int cur_arm_len;
			if (right >= i) {
				int i_sym = j * 2 - i;
				int min_arm_len = min(arm_len[i_sym], right - i);
				cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
			} else {
				cur_arm_len = expand(s, i, i);
			}
			arm_len.push_back(cur_arm_len);
			if (i + cur_arm_len > right) {
				j = i;
				right = i + cur_arm_len;
			}
			if (cur_arm_len * 2 + 1 > end - start) {
				start = i - cur_arm_len;
				end = i + cur_arm_len;
			}
		}

		string ans;
		for (int i = start; i <= end; ++i) {
			if (s[i] != '#') {
				ans += s[i];
			}
		}
		return ans;
	}
};

int main(){

	vector<int >nums={};
	solve.




	return 0;



}