#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//数独  dfs
//思路 ：判断问号处应该填何值时，首先在9*9的大矩阵中，枚举1-9的数，判断该问号所在行和列是否有该数的存在，再在3*3的小矩阵中，枚举1-9的数，判断该问号处的小矩阵是否有该数的存在。
int num;
int fun;
int Map[10][10];
 struct node{
    int x;
    int y;
}p[81];

int check(int n,int m)
{
    int tx,ty;
    int i,j;
    /*判断行列是否有该数 的存在*/
    for( i = 0; i < 9; i ++)
    {
        if(Map[p[n].x][i]==m||Map[i][p[n].y]==m)
            return 0;
    }
    tx = p[n].x/3*3;
    ty = p[n].y/3*3;
    /*判断3*3的小正方形内是否已经有该数的存在*/
    for( i = 0; i < 3; i ++)
    {
        for( j = 0; j < 3; j ++)
        {
            if( Map[tx+i][ty+j]==m)
                return 0;
        }
    }
    return 1;
}
void dfs(int n)
{
    int i,j;
    if( n == num)//每个问号都处理完
    {
        for( i = 0; i < 9; i ++)
        {
            for( j = 0; j < 8; j ++)
            {
                printf("%d ",Map[i][j]);
            }
            printf("%d\n",Map[i][8]);
        }
        fun = 1;
    }
    else
    {
        for( i = 1; i <= 9; i ++)
        {
            if(check(n,i)&&!fun)/*填的数合法且最终答案没有形成*/
            {//下面三行是核心
                Map[p[n].x][p[n].y] = i;/*填表*/
                dfs(n+1);/*递归*/
                Map[p[n].x][p[n].y] = 0;/*回溯*/
            }
        }
    }
    return;
}
int main()
{
    char s;
    int i,j;
    int count = 0; 
    while(cin>>s)
    {
        num = 0;
        fun = 0;
        if(s == '?')
        {
            Map[0][0] = 0;
        }
        else
        {
            Map[0][0] = s-'0';
        }
        for( i = 0; i < 9; i ++)
        {
            for( j = 0; j < 9; j ++)
            {
                if(!(i==0&&j==0))
                    cin>>s;
                if( s == '?')
                {
                    p[num].x = i;
                    p[num].y = j;
                    Map[i][j] = 0;
                    num++;
                }
                else
                {
                    Map[i][j] = s-'0';
                }
            }
        }
        if(count++)
            printf("\n"); 
        dfs(0);
    }
    return 0;
}
