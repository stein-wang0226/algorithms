
//我的双指针做法+set去重
struct node{
    int a,b,c;
    bool operator <(const node&y)const{
            if(a==y.a){
                if(b==y.b){
                    return c<y.c;
                }
                    return b<y.b;
            }
            return a<y.a;
    };
};
set <node>st;
class Solution {
    //sort, 左端遍历 右端中间双指针    O n^2/2
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        st.clear();
        int n= nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i&&nums[i]==nums[i-1])continue;
            int sum=-nums[i];
            int l=i+1,r=n-1;
            while(l<r){
                if(sum==nums[l]+nums[r]){
                    vector<int>tmp;
                    tmp.push_back(nums[i]);tmp.push_back(nums[l]);tmp.push_back(nums[r]); 
                    sort(tmp.begin(),tmp.end());
                    st.insert({tmp[0],tmp[1],tmp[2]});
                    l++,r--;
                }
                else if(nums[l]+nums[r]>sum){
                    r--;
                }
                else l++;
            }
        }
        for(auto i:st){
            vector<int>tmp;
            tmp.push_back(i.a);tmp.push_back(i.b);tmp.push_back(i.c);
            res.push_back(tmp);
        }
            return res;
    }
};

//标准双指针写法：for+while
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            // 双指针标准做法 for +while
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};
