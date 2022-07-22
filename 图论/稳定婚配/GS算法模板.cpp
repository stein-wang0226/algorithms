#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;
// 稳定婚配模板   O(n^2)

const int N = 2e3+ 5;

int n,T;

int cur[N];  //  cur[i]当前第i个男生追求的是目标中第几个
int match_boy[N],match_girl[N];// 匹配情况
int boy[N][N];   // boy[i][j]  第i个男生第j个喜欢的女生编号
int girl[N][N];    // *** girl[i][j]  第i个女生对第j个男生的好感度  **注意含义
void GS(){
    int flag;   // 表示男生是否全部找到
    memset(match_boy,0,sizeof match_boy);
     memset(match_girl,0,sizeof match_girl);
    memset(cur,0,sizeof cur);
    while(flag){//没有匹配发生  中止
        flag=0;  //没有匹配发生 
        for(int i=1;i<=n;i++){// 遍历未匹配男生
            if(match_boy[i])continue; // 已匹配
            int temp=boy[i][cur[i]++]; // 男生列表中下一个
            if(!match_girl[temp]){//该女生未被匹配 
                match_boy[i]=temp;
                match_girl[temp]=i;   // 相互匹配
            }
            else if(girl[temp][i]>girl[temp][match_girl[temp]]){// 已匹配 但更喜欢新男生 抛弃难友
                match_boy[match_girl[temp]]=0; // 被抛弃的男友落单
                match_boy[i]=temp;  // 新的一对相互匹配
                match_girl[temp]=i;
            }
            flag=1;
        }
    }
}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
// 输入注意数组含义
  
  return 0;
}
