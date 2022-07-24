class Solution {
public:
    bool check(int len,vector<int>&nums,int target,vector<int>&sum){ //长度为len的 存在>target
        int n=nums.size();
        if(len>n){
                return sum[n]>=target;
        }
        for(int s=1;s<=n;s++){//起点
            int t=s+len-1;//终点
            if(t>n){
                break;
            }
            int sumt=sum[t]-sum[s-1];
            if(sumt>=target)return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int>sum(n+1);sum[0]=0;
        for(int i=1;i<=n;i++){
             sum[i]=sum[i-1]+nums[i-1];
        }
        int l=0,r=1e5+5;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid,nums,target,sum))r=mid;
            else l=mid+1;
        }
        if(l==100005)return 0;
        return l;
    }
};