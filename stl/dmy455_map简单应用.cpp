#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+5;
int T,n,m,k;
map<string,int>score;// 每人分数
map<string,int>get_;//每题可得的分
signed main(){
cin>>n>>m>>k;
string s,s1,s2;
vector<string>name;// 按序
for(int i=1;i<=n;i++){
    cin>>s;
    name.push_back(s);
    score[s]=0;
}
for(int i=1;i<=m;i++){
    int t;
    cin>>s>>t;
    get_[s]=t;
}
for(int i=1;i<=k;i++){
cin>>s>>s1>>s2;
if(s2=="AC"&&score.count(s)){
    score[s]+=get_[s1];
}
}
for(auto i:name){//  按序
    cout<<i<<" "<<score[i]<<endl;
}


    return 0;
}
