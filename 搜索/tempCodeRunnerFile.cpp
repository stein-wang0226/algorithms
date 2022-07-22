#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//sticks
//总长度sum和小棒最长的长度max，则原棒可能的长度必在max~sum之间，然后从小到大枚举max~sum之间能被sum整除的长度len，用dfs求出所有的小棒能否拼凑成这个长度，如果可以，第一个len就是答案。
//1.以一个小棒为开头，用dfs看看能否把这个小棒拼凑成len长，如果可以，用visit[i]记录下用过的小棒，然后继续以另外一个小棒为开头，以此类推。
//2.小棒的长度从大到小排序，这个就不解释了。
///3.如果当前最长的小棒不能拼成len长，那么以比它短的开始也一定不能取得全局的成功。因为每一支木棍都要被用到，最长的那根如果现在不行，那么以后也不行。所以直接return，返回前一步。

//dfs+剪枝——最多64根
#include <iostream>
#include <algorithm>
using namespace std;
bool isEnd=false;
int len=-1;
int a[64];
int visit[64]={0};
int num;
void dfs(int used_num,int now_len,int now_index){ //used为当前已被用过的小棒数，now_index为当前要处理的小棒。
	if(isEnd==true)
		return;
	if(now_len==len){ //当前长度为len，即又拼凑成了一根原棒。
        if(used_num==num) //完成的标志：所有的num根小棒都有拼到了。
			isEnd=true;
		else{
			dfs(used_num,0,0);
		}
		return;
	}
	if(now_len==0){ //当前长度为0，寻找下一个当前最长小棒。
		while(visit[now_index]==1) now_index++; //寻找第一个当前最长小棒。
        visit[now_index]=1;
		dfs(used_num+1,a[now_index],now_index+1);
		visit[now_index]=0;
	}
	else{
        for(int i=now_index;i<num;i++){
			if(visit[i]==0&&now_len+a[i]<=len){
				if((visit[i-1]==0&&a[i]==a[i-1])) //不重复搜索：最重要的剪枝。
				continue;
				visit[i]=1;
				dfs(used_num+1,now_len+a[i],i+1);
				visit[i]=0;
			}
		}
	}
}
bool compare(int a,int b){
  return a>b; //降序排列
}
int main(){
	while(cin>>num){
		if(num==0)
			break;
		isEnd=false;
		int sum=0;
		int max=0;
		for(int i=0;i<num;i++){
			cin>>a[i];
			sum+=a[i];
			if(a[i]>max)
				max=a[i];
		}
		sort(a,a+num,compare); //从大到小排序。
		
		for(len=max;len<sum;len++){
			if(sum%len!=0)
				continue;
			else{ //枚举能被sum整除的长度。
				memset(visit,0,sizeof(visit));
				dfs(0,0,0);
				if(isEnd==true){
					break;
				}					
			}
		}
		cout<<len<<endl;
	}
	return 0;
}