#include <bits/stdc++.h>

using namespace std;
int n;


bool Have(int x,int k){
	if(x%k==0)return 1;
	int tmp=x;
	while(tmp){
		int y=tmp%10;
		if(y==k)return 1;
		tmp/=10;
	}
	return 0;
}
vector<int>vec;
int main(){
	cin>>n;
	vec.emplace_back(0);
	for(int i=1;i<=10000;i++)
		if(Have(i,9)&&!Have(i,7))vec.emplace_back(i);
	int len=vec.size();
	vector<int>vec2;
    // for(auto i:vec)cout<<i<<' ';

	for(int i=1;i<len;i++){
		vec2.emplace_back(vec[i]-vec[i-1]);
	}
    //for(auto i:vec2)cout<<i<<' ';
	int cnt=0;
	vector<int>id;
	for(int i=1;i<=n;i++)id.emplace_back(i);
		int pos=0;
    for(int i=1;i<=n;i++){//模拟
        int last=n-i+1;//剩下的个数
        pos=(pos+vec2[i-1]-1)%last+1;
        cout<<id[pos-1]<<" ";
        if(i==n)break;
        auto it=id.begin()+pos-1;
        id.erase(it);
        last--;
        pos=(pos-1+last)%last;//前移一格开始数
    }



    return 0;
}