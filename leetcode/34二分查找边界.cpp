class Solution {
public://左右位置边界条件不同
    vector<int> searchRange(vector<int>& nums, int target) {
        int lpos=-1,rpos=-1;
        int n=(int)nums.size();
                vector<int>ans;
        if(n==0){
            ans.push_back(-1);ans.push_back(-1);return ans;
        }
        int l=0,r=n-1;
        //左
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]<target)l=mid+1;
            else r=mid;
        }
        if(nums[l]==target)lpos=l;
        l=0,r=n-1;
        //右
        while(l<r){
            int mid=(l+r+1)>>1;
            if(nums[mid]>target)r=mid-1;
            else l=mid;
        }
        if(nums[l]==target)rpos=l;
        ans.push_back(lpos);
        ans.push_back(rpos);
        return ans;
    }
};