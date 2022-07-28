#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
using namespace std;

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int x,vector<int>&nums){
                    int n=nums.size();
        if(x==0){
            if(nums[0]>nums[1]) 
            return true;
            else return false;
        }
        if(x==n-1){
        if(nums[n-1]>nums[n-2])return true;
        else return false;
        }
        if(nums[x]>nums[x-1]&&nums[x]>nums[x+1])return true;
        return false;
    }
    int findPeakElement(vector<int>& nums) {
            int n=nums.size();
            if(n==1)return 0;
            int l=0,r=n-1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(check(mid,nums))return mid;
                if(nums[mid]<nums[mid+1])l=mid+1;//在左侧
                else r=mid-1;//右侧
            }
            return -1;
    }
}solve;


int main(){

vector<int>nums={1,2};
cout<<solve.findPeakElement(nums);


return 0;



}