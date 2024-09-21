

#include "bits/stdc++.h"
using namespace std;
//寻找两个正序数组的中位数 Olog n
// 两个数组分别划分为左右两段 分界位置为i ，j （也属于左侧）,且满足 i+j = (m+n)/2 (下标1开始)，二分i或j即可
// 由于中位数 正序 则满足 a[i+1]>b[j] 且 b[j+1]>a[i]
//奇数时 ans = min(a[i+1],b[j+1])  偶数ans= （max(a[i],b[j])+min)(a[i+1],b[j+1])）/2

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
        //为方便处理边界  分别在两数组两端插入 inf
    if(m==0){
      if(n%2){
        return nums2[n/2];
      }
      else return (nums2[n/2-1]+nums2[n/2])/2.0;
    }
    if(n==0){
      if(m%2){
        return nums1[m/2];
      }
      else return (nums1[m/2-1]+nums1[m/2])/2.0;
    }
    nums1.emplace(nums1.begin(),-1e9);
    nums1.emplace_back(1e9);
    nums2.emplace(nums2.begin(),-1e9);
    nums2.emplace_back(1e9);
        int l = 0, r = m; // 0表示 num1全没有划分到左
        while(l<r){
            int i = (l+r+1)>>1; // 表示nums1中划分到左的个数
            int j = (m+n)/2-i;// nums2 个数
//            if (j<0){ // 力扣要加上不然会越界
//                r = i-1;
//                continue;
//            }
//            if(j>n){
//                l = i;
//                continue;
//            }
            if(j>=0&&(j>n||nums2[j+1]>=nums1[i])) {  // 偏左或找到
                if(j<=n&&nums1[i+1]>=nums2[j]){ // 找到i，j
                  l = i ;
                  break;
                }
                else l=i;
              }
              else r = i-1;
            }
            double ans;
            int i=l,j = (m+n)/2-i;
        if((m+n)%2){//奇数
          ans=min(nums1[i+1],nums2[j+1]);
        }
        else ans =(max(nums1[i],nums2[j])+min(nums1[i+1],nums2[j+1]))/2.0;
        return ans;

      }
    }solve;
    int main(){
      vector<int>a={2,3,4,5,6,7,8,9,10};
      vector<int>b={1};

      cout<<solve.findMedianSortedArrays(a,b);

    }