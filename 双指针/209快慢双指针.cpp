#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
using namespace std;
//快慢双指针

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int sum = 0;
        for(int end=0,start=0;end<n;end++) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};




int main(){

vector<int >nums={};
solve.
return 0;



}