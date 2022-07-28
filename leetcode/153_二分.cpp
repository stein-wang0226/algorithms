#include <bits/stdc++.h>

using namespace std;
//给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size()-1;
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>nums[n-1]) l=mid+1;
            else r=mid;
        }
        return l;
    }
};
