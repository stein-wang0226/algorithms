#include<bits/stdc++.h>
using namespace std;
struct q1{
	int x,y,index;
}a[10005];
int dp[10005];
bool cmp(q1 a, q1 b){
	return a.x < b.x;
}
int main(){
	memset(dp,0,sizeof(dp));
	int k = 0;
	int Tmin = 10000;
	while(~scanf("%d%d",&a[k].x,&a[k].y)){
		dp[k] = 1;
		a[k].index = k + 1;
		Tmin = min(Tmin,a[k].y);
		k ++;
	}
	sort(a,a+k,cmp);
	int Max = 0;
	for(int i = 1; i < k; i++){
		int _max = 0;
		for(int j = 0; j < i; j++){
			if(a[i].x == a[j].x)continue;//������ͬ�Ĳ�����
			if(a[i].y < a[j].y){
				_max = max(dp[j],_max);
			}
		}
		dp[i] += _max;
		Max = max(Max,dp[i]);
	}
	cout << Max <<endl;
	
	int aka = Max;//�൱��len��
	int cnt = 0, OK[1000];//�𰸱��浽����
	for(int i = k-1; i > 0; i--){//�Ӻ�����ǰ����
		if(aka == dp[i] && Tmin <= a[i].y){
			cnt ++;
			OK[cnt] = a[i].index;
			aka --;
			Tmin = a[i].y;
		}
	}
	for(int i = cnt; i >= 1; i--){
		cout<< OK[i] <<endl;
	}
    return 0;
}


