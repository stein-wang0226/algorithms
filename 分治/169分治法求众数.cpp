#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
// 分治求众数  O(nlogn)  ---二分   主函数分析O(nlogn)
 vector<int>nums={10,9,9,9,10};
class Solution {
    int count_in_range(vector<int>& nums, int target, int lo, int hi) {
        int cnt=0;
        if(target==-1)return 0;
        for(int i=lo;i<=hi;i++){
            if(target==nums[i])
                cnt++;
        }
        return cnt;
    }
    int majority_element_rec(vector<int>& nums, int l, int r) { //分治求众数 左右分别求众数，再二选一即可
    
    if(nums[l]==nums[r])
        return  nums[l];
    int mid= (l+r)>>1;
    int l_num = majority_element_rec(nums,l,mid);
    int r_num = majority_element_rec(nums,mid+1,r); //求得左右两边众数
    
    int l_cnt=count_in_range(nums,l_num,l,r);
    if(l_cnt>(r-l+1)/2)return l_num;
    int r_cnt =count_in_range(nums,r_num,l,r);
    if(r_cnt>(r-l+1)/2)return r_num;
    return -1; //返回-1 相当于0次



    }
public:
    int majorityElement(vector<int>& nums) {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
}sol;


signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

cout<<sol.majorityElement(nums);
  return 0;
}
