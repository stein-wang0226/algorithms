#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
using namespace std;



class Solution {
public:

//法一 分别计算前缀后缀最大值 的最小值 求和即可
//法二： 单调维护递减， 每次遇到递增计算对应矩形面积**可以接雨水的区域，top前一个为left该区域的宽度是 i−left−1，高度是 min(height[left],height[i])−height[top]


    int trap(vector<int>& height) {
        stack<int>stk; //存下标
        int n=(int)height.size();
        int ans=0;
        for(int i=0;i<n;i++){
            while(!stk.empty()&&height[stk.top()]<height[i]){  // 一层一层矩形加
                int topp=stk.top();
                stk.pop();//
                if (stk.empty()) {//注意
                    break;
                }
                int left=stk.top();
                ans+=(i-left-1)*(min(height[left],height[i])-height[topp]);
            }
            stk.push(i);
        }
        return ans;
    }
}solve;
int main(){

vector<int >height={0, 1 ,0 ,2, 1, 0 ,1 ,3, 2, 1 ,2, 1};
cout<<solve.trap(height);

return 0;



}