#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
using namespace std;

#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
using namespace std;

class Solution {
public:
    //记录每个字母差值p-tmp(滑窗) 和总差值differ
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(); int m = p.size();
        vector<int>ans;
        map<int,int>dif;
        int differ=0;
        for(int i=0;i<m;i++){//init
            dif[p[i]-'a']++;
            differ++;
        }
        for(int i=0;i<m;i++){
            if(dif[s[i]-'a']>0) differ--;
            else  differ++;
            dif[s[i]-'a']--;
        }
        if(differ==0) ans.push_back(0);

        for(int i=m;i<n;i++){
            if(dif[s[i]-'a']<=0) differ++;
            else differ--;
                         dif[s[i]-'a']--;
            if(dif[s[i-m]-'a']>=0) differ++;
            else differ--;
            dif[s[i-m]-'a']++;
        if(differ==0) ans.push_back(i-m+1);
        }
        return ans;
    }
};




int main(){

vector<int >nums={};
solve.




return 0;



}