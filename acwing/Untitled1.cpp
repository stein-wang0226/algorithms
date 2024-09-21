#include<bits/stdc++.h> 
using namespace std;



class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			int n = nums.size();
			vector<vector<int>> ans;
			sort(nums.begin(), nums.end());
			for (int i = 0; i < n; i++) {
				int l = i + 1, r = n - 1;
				int target_sum = -nums[i];
				for (; l < r;) {
					int res = nums[l] + nums[r];
					if (res == target_sum) {
						ans.push_back(vector<int> {nums[i], nums[l], nums[r]});
					}
					if (r == l + 1) { // pan
						break;
					}
					while (nums[l] + nums[r] < target_sum && l < r)
						l++;

					res = nums[l] + nums[r];
					if (res == target_sum) {
						ans.push_back(vector<int> {nums[i], nums[l], nums[r]});
					}
					while (nums[l] + nums[r] > target_sum && l < r)
						r--;
					res = nums[l] + nums[r];
					if (res == target_sum) {
						ans.push_back(vector<int> {nums[i], nums[l], nums[r]});
					}
				}
			}
			return ans;
		}
};

int main(){


Solution s;
vector<int> input = {-1, 0, 1, 2, -1, -4};
auto ans = s.threeSum(input);



}






