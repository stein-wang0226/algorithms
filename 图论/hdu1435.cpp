#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#define oo 0x13131313
using namespace std;
const int maxn=200+5; 
const double eps=1e-8;
int N;//总共多少对男女(发射点 接收点) 
struct point
{
	int c;//容量 
	double x,y,z;//坐标 
};
point S[maxn],E[maxn];//发射点 接收点
int ranks[maxn][maxn],ranke[maxn][maxn];//发射点对接收点的排名 接收点对发射点的排名
int man[maxn],woman[maxn];//man[i]表示男编号为i所匹配的女对象编号 ，woman[i]表示女编号为i所匹配的男对象编号 
int tempman[maxn];//tempman[i]表示男编号为i所匹配的临时女对象编号是自己原先对所有女孩排完序后第几喜欢
                  //(当前剩下的能选择的女孩中男孩所选择的自己最喜欢的那位女孩所有女孩中排第几) 
struct node//排序关键字 
{
	double dis;//距离 
	int c; //容量 
	int pos;//参加排序的点的编号 
	int r;//参加排序的点的排名 
}Rank[maxn];//排序数组 
double dist(point A,point B)
{
	return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z);  
}
void input()
{
	int id,c;
	double x,y,z;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d%d%lf%lf%lf",&id,&c,&x,&y,&z);
		S[id].c=c;
		S[id].x=x;
		S[id].y=y;
		S[id].z=z;
	}
	for(int i=1;i<=N;i++)
	{
		scanf("%d%d%lf%lf%lf",&id,&c,&x,&y,&z);
		E[id].c=c;
		E[id].x=x;
		E[id].y=y;
		E[id].z=z;
	}
} 
bool cmp(node a,node b)//使排序数组的下标按距离、容量为第一和第二关键字进行排序 
{
	if(fabs(a.dis-b.dis)>eps)
		return a.dis<b.dis;
	else
		return a.c>b.c;
}
bool cmp2(node a,node b)//使排序数组的下标与点的编号对应 
{
	return a.pos<b.pos;
}
void countrank()
{
	for(int i=1;i<=N;i++)
	{
		memset(Rank,0,sizeof(Rank));
		for(int j=1;j<=N;j++)
		{
			Rank[j].c=E[j].c;
			Rank[j].dis=dist(S[i],E[j]);
			Rank[j].pos=j;
		}
		sort(Rank+1,Rank+N+1,cmp);//使排序数组的下标按距离、容量为第一和第二关键字进行排序
		for(int j=1;j<=N;j++)
		{
			ranks[i][j]=Rank[j].pos;//i追求的最合适第j个是谁
		}
	}
	for(int i=1;i<=N;i++)
	{
		memset(Rank,0,sizeof(Rank));
		for(int j=1;j<=N;j++)
		{
			Rank[j].c=S[j].c;
			Rank[j].dis=dist(E[i],S[j]);
			Rank[j].pos=j;
		}
		sort(Rank+1,Rank+N+1,cmp);//使排序数组的下标按距离、容量为第一和第二关键字进行排序
		for(int j=1;j<=N;j++)
		{
			Rank[j].r=j;//记录当前点j对排名 
		}
		sort(Rank+1,Rank+N+1,cmp2);//使排序数组的下标与点的编号对应 
		for(int j=1;j<=N;j++)
		{
			ranke[i][j]=Rank[j].r; //ranke i追求的j的排名; 
		}
	}
}
void GS()  
{
	int ok=1;
	memset(man,0,sizeof(man));//初始化男所匹配女对象编号为0，表示单身  
    memset(woman,0,sizeof(woman)); 
    for(int i=1;i<=N;i++)
    {
        tempman[i]=1;//初始化男孩只能选择的女孩是自己第一喜欢（最喜欢）的 
    }
    while(ok==1)  
    {
    	ok=0;
		for(int i=1;i<=N;i++)  //男生去求偶  
		{
			if(man[i]==0)//单身   
			{
				ok=1; 
				int womenpos=ranks[i][tempman[i]];//当前男孩最想要选的女孩编号
			 if(woman[womenpos]==0)//该女孩目前是单身，则暂时追求成功
			 {
			 	woman[womenpos]=i;//女孩接受该男孩，有了男对象i了，不为0，脱单
				man[i]=womenpos; //男孩暂时追求成功，不为0，脱单 
				tempman[i]++;//万一女孩抛弃了他，男孩失恋后下次求偶只能选择的女孩是自己第几喜欢的 
			 }
			  else if(ranke[womenpos][woman[womenpos]]>ranke[womenpos][i])//状态不稳定，因为这个女孩当前的男友不如现在追求她的男孩i好，
			  {														//女孩抛弃原来男友，与当前男孩匹配 
			  	man[woman[womenpos]]=0;//女孩的原先男友失恋了，被女孩抛弃，变为单身
				woman[womenpos]=i;//女孩接受该男孩，有了男对象i了，不为0，脱单
			    man[i]=womenpos;  //男孩暂时追求成功，不为0，脱单
		        tempman[i]++; //万一女孩抛弃了他，男孩失恋后下次求偶只能选择的女孩是自己第几喜欢的  
			  }  
			   else
			   {
			   		tempman[i]++;//男孩追求的这个第tempman[i]喜欢的女孩不成功，只能再继续选择相对“次喜欢”的  
			   } 
			}
		 } 
	} 
}
void output()  
{
 	 for(int i=1;i<=N;i++) 
 	 {
	  	printf("%d %d\n",woman[i],i);  
	 } 
} 
int main()
{
    //freopen("D:\in.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
    {
        input();
        countrank();
        GS();
        output();  
    }
    return 0;
}