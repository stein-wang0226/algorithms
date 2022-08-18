#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e3 + 5;
int  n,m;
int cost[N],v[N]; //花费  容量  未排序
int ans0;//贪心结果
int maxx=0;//总结果
map<int,int>mp0;//最初贪心订单对应
map<int,int>mp; //临时存放订单对应平台
struct Order{
    int cost,v,id;
    double rate;
    bool operator<(const Order&b)const{
        if(cost==b.cost)return v<b.v;
        return cost>b.cost;
    }
}order[N];
struct Platform{
    int last ,id;  //剩余容量
}p0[N],p[N];
int p_v[N]; //最初总容量
vector<set<int>>res(N,set<int>()); //存放结果
vector<set<int>>greedy_ret(N,set<int>()); //贪心结果
vector<set<int>>final_res(N,set<int>()); //贪心结果
void Output2Terminal(){//
    for(int i=1;i<=m;i++){
        cout<<"平台"<<i<<"交易订单为:";
        for(auto j :final_res[i] ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int calMin(vector<set<int>>result){//计算当前方案res下的最小值
    int minn=1e18;
    for(int i=1;i<=m;i++){
        int sum=0;
        for(auto j:result[i]){
            sum+=cost[j];
        }
        minn=min(minn,sum);
    }
    return minn;
}
void sswap(int a,int b){ //订单交换
    int p1=mp[a],p2=mp[b]; //对应平台编号
    if(p1&&p2){// 都被分配
        if (p[p1].last + v[a] >= v[b] && p[p2].last + v[b] >= v[a]) {// 容量允许
            res[p1].erase(a), res[p1].insert(b);
            res[p2].erase(b), res[p2].insert(a);
            mp[b]=p1;
            mp[a]=p2;
            p[p1].last=p[p1].last-v[b]+v[a];
            p[p2].last=p[p2].last-v[a]+v[b];
        }
    }
    else{
        if(!p1&&p2){
            if(p[p2].last + v[b] >= v[a]){
                res[p2].erase(b), res[p2].insert(a);
                mp[b] = 0;
                mp[a] = p2;
                p[p2].last = p[p2].last - v[a] + v[b];
            }
        }
        else if(p1){
            if (p[p1].last + v[a] >= v[b]){
                p[p1].last = p[p1].last - v[b] + v[a];
                res[p1].erase(a), res[p1].insert(b);
                mp[a] = 0;
                mp[b] = p1;
            }
        }
    }
}
double rand(double l, double r){//随机数rand重载 返回[l,r)
    return (double)rand() / RAND_MAX * (r - l) + l;
}
void simulate_anneal(){//模拟退火
    int cur=ans0;
    double  len=5e4;
    for(double t=len;t>1e-6;t*=0.995){//系数为0.99
        int a=rand(0,double(t/len*(double)n))+1; //随机a
        int b=rand(0,double(t/len*(double)n))+1; //随机a
        if(a!=b)sswap(order[a].id,order[b].id);
        int tmp=calMin(res);
        double dt=(double)tmp-cur;
        double k=len/50000.0; //接受差解的概率系数  此处越少越容易接受  （跳出原解
        if(exp(k*dt /(t)) <= rand(0, 1)){ // dt<0:不如之前则可能换回来，否则不变
            sswap(a,b);
        }
        else cur=tmp; //更新
        if(cur>maxx){
            maxx=cur;
            final_res=res;
        }
        cout<<maxx<<" "<<cur<<endl;
    }
}
void init(){
    for(int i=1;i<=m;i++){
        p[i]=p0[i];
    }
    res=greedy_ret;
    for(int i=1;i<=n;i++)mp[i]=mp0[i];
}

bool ans_check(vector<set<int>>ret,int ans){ //check答案
    if(calMin(ret)!=ans)return 0; //最小值是否正确
    //容量是否满足
    for(int i=1;i<=m;i++){
        int last_v=p_v[i];
        for(auto j:ret[i]){
            last_v-=v[j];
        }
        if(last_v<0)return 0; //
    }
    return 1;
}
void Out2File(){//输出到csv文件
    string filename = "result4.csv";
    ofstream fout;
    fout.open(filename,ios::out);
    if(!fout.is_open())cerr<<"error"<<endl;
    for(int i=1; i <=m;i++){
        int cost0 = 0, V = 0;
        fout << "平台" << i <<",";
        for(auto j:final_res[i]) {
            fout << j <<",";
            cost0 += cost[j];
            V += v[j];
        }
        fout << cost0 << "," << V <<endl;
    }
}
void solve(){
    ifstream  fin,fin2;
    fin.open("实例1.txt");
    if(!fin.is_open())cerr<<"error"<<endl;
    fin>>n>>m; //平台数 交易数
    int id;
    for(int i=1;i<=n;i++){
        fin>>id>>v[i]>>cost[i];
        order[i].id=i;
        order[i].v=v[i];
        order[i].cost=cost[i];
    }
    for(int i=1;i<=m;i++){
        fin>>p_v[i];
        p0[i].last=p_v[i];
        p0[i].id=i;
    }
    fin.close();
    int num;
    //读入结果
   // vector<set<int>>tmp=res;
    fin2.open("greedy_output.txt");
    fin2>>ans0;
    for(int i=1;i<=m;i++){ //平台
        fin2>>num;
        while(num--){
            fin2>>id; //订单编号
            greedy_ret[i].insert(id);
            p0[i].last-=order[id].v; //更新容量
            mp0[id]=i;
        }
    }
    fin2.close();
    sort(order+1,order+1+n);//
    maxx=ans0;
    final_res=greedy_ret;

    for(int i=1;i<=1000;i++){//多次退火
         init();
         simulate_anneal() ;
    }
    Output2Terminal();
    Out2File();
    if(ans_check(final_res,maxx))cout<<"没毛病"<<endl;
    else cout<<"shit"<<endl;
    cout<<calMin(final_res)<<endl;
}
signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand((unsigned int)(time(0))); //真随机
    solve();
    return 0;
}