#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;
void IOS(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
}
typedef pair<int,int> PII;
typedef long long ll;
int vis[110][110][110];
int S,A,B;
struct node{
	int s,a,b;
	int step;
}now,front;

void bfs()
{
	now.s=S;
	now.a=0;
	now.b=0;
	now.step=0;
	queue<node>q;
	q.push(now);
	vis[S][0][0]=1;
	while(!q.empty())
	{
		front=q.front();
		 
		q.pop();
	   
		if(front.s==front.a&&front.b==0)
		{   //cout<<front.s<<' '<<front.a<<' '<<front.b<<endl;
			cout<<front.step<<endl;
			return;
		}
		//共有六种操作
		for(int i=1;i<=6;i++)
		{		
		//s->a
		 now=front;
		if(i==1)
		{
			//如果未满
			if(now.s+now.a<=A)
			{
			   now.a=now.a+now.s;
			   now.s=0;	
			   
			} 
			//如果满了,还有剩余 
			else
			{
				now.s=  now.a+now.s-A;
				now.a= A; 
			}
		
		}
		//s->b
		else if(i==2)
		{
			//如果未满
			if(now.s+now.b<=B)
			{
			   now.b=now.b+now.s;
			   now.s=0;	
			} 
			//如果满了,还有剩余 
			else
			{
				now.s=  now.s+now.b-B;
				now.b= B; 
			}
		
		}
		//a->s
		else if(i==3)
		{
			//如果未满
			if(now.s+now.a<=S)
			{
			   now.s=now.a+now.s;
			   now.a=0;	
			} 
			//如果满了,还有剩余 
			else
			{
				now.a=  now.a+now.s-S;
				now.s= S; 
			}
		
		}
		//a->b
		else if(i==4)
		{
			//如果未满
			if(now.b+now.a<=B)
			{
			   now.b=now.a+now.b;
			   now.a=0;	
			} 
			//如果满了,还有剩余 
			else 
			{
				now.a=  now.a+now.b-B;
				now.b= B; 
			}
			
		}
		//b->a
		else if(i==5)
		{
			//如果未满
			if(now.b+now.a<=A)
			{
			   now.a=now.a+now.b;
			   now.b=0;	
			} 
			//如果满了,还有剩余 
			else
			{
				now.b=  now.a+now.b-A;
				now.a= A; 
			}
		
		}
		//b->s 
		else if(i==6)
		{
			//如果未满
			if(now.s+now.b<=S)
			{
			   now.s=now.b+now.s;
			   now.b=0;	
			} 
			//如果满了,还有剩余 
			else
			{
				now.b=  now.b+now.s-S;
				now.s= S; 
			}
		
			
		}
		// cout<<i<<' '<<front.s<<' '<<front.a<<' '<<front.b<<endl;
		now.step=front.step+1;
		
		if(!vis[now.s][now.a][now.b])
		{   vis[now.s][now.a][now.b]=1;
			q.push(now);
		}
		
	 	}	
	}
	cout<<"NO"<<endl;
	return ;
}
int main(){
   while(~scanf("%d%d%d",&S,&A,&B))
   {memset(vis,0,sizeof(vis));
   	if(S==0&&A==0&&B==0)
   	{
   		break;
	   }
	if(S%2==1)
	{
		cout<<"NO"<<endl;
		continue;
	}
	else
	{
		
	 if(A<B)
	 swap(A,B);
	 bfs();
 	} 
   }
   return 0;
}
