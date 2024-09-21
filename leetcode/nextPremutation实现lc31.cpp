#include "bits/stdc++.h"
using namespace std;
//nextPermutation 算法、
// 我们需要将一个左边的「s较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。
// 同时我们要让这个「较小数」尽量靠右，而「较大数」尽可能小。当交换完成后，「较大数」右边的数需要按照升序重新排列。这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。
//1. 从后向前查找第一个升序对(i,i+1),(后面全为降序)  此时确定「较小数」为a[i] (可交换且最靠左)  (找不到则进入3步即可，本身已经是降序)
//2.然后 在[i+1,n]中从后向前找第一个>a[i]的数 a[j] 作为「较大数」 交换两者
// 3.直接将[i+1,n]反转成为为升序  (本身降序无需排序)
class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int l=0, r=n;
    int flag = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        flag = 1;
        l = i; break;
      }
    }
    if (flag) {//2
      for (int j = n - 1; j >= l + 1; j--) {
        if (nums[j] > nums[l]) {
          r =  j;
          break;
        }
      }
      swap(nums[l], nums[r]);
    }
    if(flag)reverse(nums.begin()+l+1,nums.end());
    else reverse(nums.begin(),nums.end()); 


  }

};