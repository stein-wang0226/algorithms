//纯思维
/* 不妨考虑一下，在我们已经找到了所有长度为t的所有排列时，怎样才能找到所有长度为t+1的排列
结论是：当且仅当在已经使用过的序列之后，还能找到1~k的所有数，这样就能形成所有排列
比如示例rolls = [4,2,1,2,3,3,2,4,1], k = 4中，就有[4,2,1,3],[3,2,4,1]两个完整的子序列，则3就是最小的找不到的序列
因此题目可以转化为能形成多少个互不交叉的完整的序列(不必有序)
为了尽可能多地找到完整序列，总是应该选择还没搜索过的最小的下标，也就是从上一次使用的最后一个下标之后开始查找，因此下标具有传递性

 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,int>cnt;//bit数
    map<int,int>sum;//后缀和
    set<int>st;
    long long countExcellentPairs(vector<int>& nums, int k) {
        // 就是二进制1总个数
        for(auto i:nums){
            st.insert(i);
        }
        for(auto i:st){
            cnt[ __builtin_popcount(i)]++;
        }
        int len=cnt.size();
        int count=0;
        for(auto it=cnt.rbegin();it!=cnt.rend();it++){
            count+=(*it).second;
            sum[(*it).first]=count;
        }
        long long res=0;
        for(auto i:cnt){
            int nn=k-i.first;

           if((sum.lower_bound(nn))!=sum.end()){
            auto pos=(*sum.lower_bound(nn)).first;
            res+=(i.second)*sum[pos];
           }
        }

        return res;
    }
}solve;

int main(){
vector<int>nums={1,2,3,1};
int ans=solve.countExcellentPairs(nums,3);
cout<<ans;
}