class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //双指针
        int sum=nums[0];
        int n=int(nums.size());
        int ans=0;
        for(int i=0,j=0;i<n;i++){
            while(nums[i]>=k){
               if(i<n-1) i++,j=i,sum=nums[i];
                else return ans;
            }
            while(j<n-1&&sum*nums[j+1]<k){
                j++;
                sum*=(nums[j]);
            }
            if(j>=i)ans+=(j-i+1);
            sum/=nums[i];
        }
        return ans;
    }
};

// 先遍历右端点更简便
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0 || k == 1) return 0;
        int l = 0;
        int prod = 1; //存储nums[l]~nums[r]的累积
        int res = 0;
        for(int r = 0; r < nums.size(); r++){
            prod *= nums[r];
            while(prod >= k){
                prod /= nums[l++];
            }
            res += r - l + 1;
        }
        return res;
    }
};