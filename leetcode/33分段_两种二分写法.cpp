

// 分两段二分   ：利用mid左侧或右侧的单调性
//我的做法 l==r  更推荐
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=(int)nums.size();       
        if(n==0){
            return -1;
        }
        if(n==1){
            if(nums[0]==target)return 0;
            else 
                return -1;
        }
        int  l=0,r=n-1;
        int ans=-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>=nums[0]){// 左边单调
                if(target<nums[0]||nums[mid]<target )l=mid+1;
                else r=mid;
            }
            else{//右侧单调
                 if(target>nums[mid]&&target<=nums[n-1] )l=mid+1;
                else r=mid;
            }
        }
    if(nums[l]==target)ans=l;
    return ans;
    }
};
//题解二分法：用mid输出
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

