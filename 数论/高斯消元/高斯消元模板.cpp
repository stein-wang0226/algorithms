#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
//  高斯消元求解 线性方程组
using namespace std;
const int N=110;
const double eps=1e-8;   //   0  
double a[N][N];//矩阵
// n+1列  n行 **
int T,n;
// 遍历列  每次将一行首元素将该列其余消0


int guass(){ // 高斯消元，答案存于a[i][n]中，0 <= i < n
    int c,r;
    for(c=0,r=0;c<n;c++){//遍历每一列 处理完一列固定一行 消为阶梯型
        int t=r;          //  r 初值为0   每次完整做一列非全0 r++
        for(int i=r;i<n;i++)
            if(fabs(a[i][c]>fabs(a[t][c])))
                t=i;//   找该列绝对值最大那一行

        if(fabs(a[t][c])<eps)continue;            //该列都为0则不用消
        
        for(int i=c;i<=n;i++)swap(a[t][i],a[r][i]);// 将绝对值最大的换到顶端  ---(用最大的去消，减少舍入误差)
        for(int i=n;i>=c;i--)a[r][i]/=a[r][c]; //将当前行的首位变一，(整行同乘) ，从后往前防止a[r][c]改变影响
        for(int i=r+1;i<n;i++)  // 用当前行将下面所有列消0
            if(fabs(a[i][c])>eps)   //对非0 操作
                for(int j=n;j>=c;j--)
                    a[i][j]-=a[r][j]*a[i][c];//首位消为0

        r++   ;  //销完一列 固定一行
    }

    // r 为秩
        if(r<n)// R(a)<n 的情况
        {
            for(int i=r;i<n;i++)
                if(fabs(a[i][n])>eps)
                return  2;//无解  R(a,b)>R(a)   a都为0的行b存在正数

        return 1;          //  无穷解
    }
    // 回代求解   a[i][n] 存解
    for(int i=n-1;i>=0;i--)// 倒序遍历行  用下面的标准向量[1,0,0,..]消除1上方的元素
        for(int j=i+1;j<n;j++)
            a[i][n]-=a[i][j]*a[j][n];

        return 0;//唯一解



//
    }


    signed main(){
#ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
#endif
        cin>>n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n+1;j++)
                cin>>a[i][j];

            int ans=guass();
            if(ans==2)puts("No solution");
            else if(ans==1)puts("Infinite group solutions");
            else {
                for(int i=0;i<n;i++){
            if(fabs(a[i][n])<eps)a[i][n]=0;  //防止输出-0.00的情况
            printf("%.2lf\n",a[i][n]);      //输出解
        }
    }
    return 0;
}
