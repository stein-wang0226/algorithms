#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 1e2 + 7;
const int INF = 0x7fffffff;
const double PI = acos(-1);
struct Point { //点类
	string name;
	double x, y;
    int i;  //编号
};
vector<Point> p;
double d[maxn][maxn]; //距离矩阵
int n;
double sum=0; //当前最短路径长度

double dist(Point a, Point b) { //计算两点距离
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get_sum(vector<Point> a){  //返回路径长度
	double sum=0;
	for(int i=1;i<a.size();i++){
		sum+=d[a[i].i][a[i-1].i];
	}
	sum += d[a[0].i][a[a.size()-1].i];
	return sum;
}

void init() { //初始化
    srand((unsigned)time(NULL)); //设置随机数种子
    cin >> n;
    p.clear();
    for (int i = 0; i < n; i++) {
    	Point t;
    	cin >> t.name >>t.x >>t.y;
    	t.i=i;
    	p.push_back(t);
    }
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		d[i][j] = d[j][i] = dist(p[i], p[j]);
    	}
    }
    sum=get_sum(p);
}

void Monte_Carlo(){  //蒙特卡洛得到一个较好的初始解
	vector<Point> cur=p;
	for(int t=0;t<8000;t++){
		for(int i=0;i<n;i++){
			int j = rand()%n;
			swap(cur[i],cur[j]);
		}
		double new_sum = get_sum(cur);
		if(new_sum<sum){
			sum=new_sum;
			p=cur;
		}
	}
}
double e=1e-16,at=0.99999999,T=1.0;
//e表示终止温度  at表示温度的变化率  T是初始温度
int L = 200000; //L为最大迭代次数

void Simulated_Annealing(){  //模拟退火 
    while(L--){  //最多迭代L次
    	vector<Point> cur=p;
    	int c1=rand()%n,c2=rand()%n;
    	if(c1==c2){
    		L++;continue;
    	}
    	swap(cur[c1],cur[c2]);
        double df = get_sum(cur) - sum;  //计算代价
        double sj=rand()%10000;     //sj为0~1之间的随机数
        sj/=10000;
        if(df < 0){  //如果结果更优，直接接受
        	p = cur;
        	sum+=df;
        }else if(exp(-df/T)>sj){  //否则以一定概率接受
        	p = cur;
        	sum+=df;
        }
        T*=at;  //降温
        if(T<e) break;  //T降到终止温度后退出
    }
}

void show(){  //显示当前结果
	cout<<"路径长度: "<<sum<<endl;
	cout<<"路径:";
	for(int i=0;i<n;i++)
		cout<<' '<<p[i].name;
	puts("");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	init();
	Monte_Carlo();
	Simulated_Annealing();
	show();
	return 0;
}