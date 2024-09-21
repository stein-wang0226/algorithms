#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  //计算每个字母的贡献
  //对每种字母分别记录位置 得到间隔
  string s;
  cin>>s;
  int n=s.size();
  map<char,vector<int>>pos;
  for(int i=0;i<n;i++){
    pos[s[i]].push_back(i+1);//
  }

  int ans=0;
  //
  for(auto &it:pos){
    it.second.insert(it.second.begin(),0);
    it.second.push_back(n+1); // 方便一次计算
    int len=it.second.size();
    for(int i=1;i<=len-2;i++){
        ans+=(it.second[i]-it.second[i-1])*(it.second[i+1]-it.second[i]);//前面选择0-t种可能性-后面选择--t'种可能性
      }

    }
    cout<<ans<<endl;





    return 0;
  }