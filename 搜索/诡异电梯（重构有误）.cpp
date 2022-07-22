#include <iostream>//方向不一致可以等待
#include <cstdio>//关键：通过i和  step的奇偶性判断 人走的方向和楼梯的方向  *****
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#define MAX 25
#define mod 1000000007
#define INF 1000000
#define exp 1e-10
#define pi acos(-1.0)
using namespace std;
int n,m,s,dxy[4][2]={{1,0},{0,1},{-1,0},{0,-1}},visit[MAX][MAX],vis[MAX][MAX];//visit表示记录访问过 vis表示是否一等待 
char map[MAX][MAX];
int x1,yy1,x2,y2;
struct node
{
	int x,y,step;
}ss;
queue<node>q,qq;
bool god(int x,int y)
{
	if(x>=0&&y>=0&&x<n&&y<m&&!visit[x][y]&&map[x][y]!='*')return 1;
	return 0;
}
void bfs()
{
	int i,j,k,l,x,y,X,Y,step;
	while(!q.empty())
	{
		ss=q.front();
		q.pop();
		X=ss.x;
		Y=ss.y;
		step=ss.step;
		if(map[X][Y]=='T') 
		{
			s=step;
			return;
		}
		for(i=k=0;i<4;i++)//通过i和  step的奇偶性判断 人走的方向和楼梯的方向  *****
		{
			x=X+dxy[i][0];
			y=Y+dxy[i][1];
			if(god(x,y))
			{
				if(map[x][y]=='|')//
				{
					x+=dxy[i][0];
					y+=dxy[i][1];
					if(!god(x,y))continue;
            if(i%2==0&&step%2==1||i%2==1&&step%2==0)//方向一致
            {
            visit[x][y]=1;
            ss.x=x;
            ss.y=y;
            ss.step=step+1;
            q.push(ss);
              }
				    else if(!vis[x][y])//不一致 未等待
				    {
				    	vis[x][y]=1;
				    	ss.x=X;
				    	ss.y=Y;
				    	ss.step=step+1;
				    	q.push(ss);
				    }
				}
				else if(map[x][y]=='-')//另一种情况同理
				{
					x+=dxy[i][0];
					y+=dxy[i][1];
					if(!god(x,y))continue;
					if(i%2==0&&step%2==1||i%2==1&&step%2==0)
					{
					visit[x][y]=1;
					ss.x=x;
					ss.y=y;
					ss.step=step+1;
					q.push(ss);
					}
					else if(!vis[x][y])
					{
							vis[x][y]=1;
				    	ss.x=X;
				    	ss.y=Y;
				    	ss.step=step+1;
				    	q.push(ss);
					}
				}
				else
				{
					visit[x][y]=1;
					ss.x=x;
					ss.y=y;
					ss.step=step+1;
					q.push(ss);
				}
			}
		}
	}
}
int main()
{    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
	int i,j,k,l;
	while(cin>>n>>m)
	{
    memset(vis,0,sizeof vis);
    memset(visit,0,sizeof visit);
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
		cin>>map[i][j];
	
		if( map[i][j]=='S')x1=i,yy1=j;
		if(map[i][j]=='T')x2=i,y2=j;
	    }  
	    q=qq;
	    ss.x=x1;
	    ss.y=yy1;
	    ss.step=0;
	    q.push(ss);
	    visit[x1][yy1]=1;
	    s=0;
	    bfs();
	    cout<<s<<endl;
	}
	return 0;
}
 
 
	