//你有 个朋友，现在要给每个朋友买一个礼物。有 家商店可以购买礼物，已知在每一家商店给每一位
//朋友买礼物时给这个朋友带来的满意度，求在最多访问 家商店的前提下，朋友满意度中最小值的最
//大值是多少。

//最小值中最大值 ——二分
//首先，注意到最多访问 家商店，所以只要有两件商品出自同一家商店即可。
//即check 该mid在每家店找每个比它小的 将对应朋友标记  看是否每个朋友都标记,且至少某家店有至少两个满足
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAX=1e5+5;
int t,n,m;
vector<vector<int>>a;//用vector 否则开不下，初始化：vector<>a(m,n)  ->指定值初始化表示容量为m,初值都为n 就一个m只代表容量
	//vector 中有值才能下标访问
int check (int mid){
vector<bool> abl(m,0);
    bool pair = false;//是否有在某个店买两个以上
    for(int i = 0; i < n; ++i){
        int c = 0;
        for(int j = 0; j < m; ++j){
            if(a[i][j] >= mid){
                abl[j] = true;
                c++;
            }
        }
        if(c > 1) pair = true;
    }
    if(!pair && m > 1) return false;
    bool ans = true;
    for(bool b: abl){
        ans = ans && b;
    }
    return ans;

}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;

while(t--){
	cin>>n>>m;
	 a.assign(n, vector<int>(m)); //存储商品满意度**
	//用vector 否则开不下，初始化：vector<>a(m,n)  ->指定值初始化表示容量为m,初值都为n 就一个m只代表容量
	//vector 中有值才能下标访问
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}

int l = 1, r = 1e9;
while (l < r) {//模板2
	int mid = (l + r + 1) / 2;   //防止相邻时死循环
	if (check(mid))	
		l = mid;
	else
		r = mid - 1;
}


cout<<l<<endl;
}
    return 0;
}
