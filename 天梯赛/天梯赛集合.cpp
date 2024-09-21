求整数段和
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int min=a;
	int max=b;
	int j=0,sum=0;
	for(int i=min;i<=max;i++){
		j=0;
		sum+=i;
		if(i==-100) cout<<" ";
		if(i<=-10&&i>-100) cout<<"  ";
		if(i>-10&&i<0) cout<<"   ";
		if(i>=0&&i<10) cout<<"    ";
		if(i>=10&&i<100) cout<<"   ";
		if(i==100) cout<<"  ";
		cout<<i;
		if((i-min+1)%5==0){
			j=1;
			cout<<endl;
		} 
	}
	if(j==0) cout<<endl;
	cout<<"Sum = "<<sum<<endl;
}


 念数字
#include<iostream>
#include<string>
using namespace std;
int main(){
	char a[100];
	cin>>a;
	for(int i = 0; a[i] != '\0'; i++){
		if(a[i] == '-')	cout<<"fu";
		if(a[i] == '0') cout<<"ling";
		if(a[i] == '1') cout<<"yi";
		if(a[i] == '2') cout<<"er";
		if(a[i] == '3') cout<<"san";
		if(a[i] == '4') cout<<"si";
		if(a[i] == '5') cout<<"wu";
		if(a[i] == '6') cout<<"liu";
		if(a[i] == '7') cout<<"qi";
		if(a[i] == '8') cout<<"ba";
		if(a[i] == '9') cout<<"jiu";
		if(a[i+1] != '\0') cout<<" ";
	}
	cout<<endl;
} 

连续因子
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int max = sqrt(n);
	for(int len = 12; len >= 1; len--){
		for(int start = 2; start <= max; start++){
			long long int ans = 1;
			for(int i = start; i - start <= len - 1; i++){
				ans *= i;
			}
			if(n % ans == 0){
				cout<<len<<endl<<start;
				for(int i = start + 1; i - start <= len - 1; i++){
					cout<<"*"<<i;
				}
				return 0;
			}
		}
	}
	cout<<1<<endl<<n;
	return 0;
}
考试座位号
#include<iostream>
#include<string>
using namespace std;
int main(){
	int m,n;
	cin>>n;
	string a[n];//准考证号 
	int b[n],c[n];//试机座位号，考试座位号 
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	cin>>m;
	int d;
	for(int i=0;i<m;i++){
		cin>>d;
		for(int j=0;j<n;j++){
			if(b[j]==d){
				cout<<a[j]<<" "<<c[j]<<endl;
			}
		}
	}
}

 输出GPLT
#include<iostream>
#include<string>
using namespace std;
int main(){
	int g=0,p=0,l=0,t=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='g'||s[i]=='G')
			g++;
		if(s[i]=='p'||s[i]=='P')
			p++;
		if(s[i]=='l'||s[i]=='L')
			l++;
		if(s[i]=='t'||s[i]=='T')
			t++;
	}
	while(g+p+l+t!=0){
		if(g>0){
			cout<<'G';
			g--;
		}
		if(p>0){
			cout<<'P';
			p--;
		}
		if(l>0){
			cout<<'L';
			l--;
		}
		if(t>0){
			cout<<'T';
			t--;
		}	
	}
}
打印沙漏
#include<iostream>
#include<string>
using namespace std;
int main(){
	int m,i,p,n,count=0;
	char c;
	cin>>n>>c;
	if(n<7){
		p=n-1;
		cout<<c<<endl;
		if(p>=0)
			cout<<p;
		return 0;
	}
	for(i=1;n>count;i+=2){
		if(i==1)
			count++;
		else
			count=count+2*i;
		if(n<count){
			count=count-2*i;
			i-=2;
			m=i;
			p=n-count;
			break;
		}
		if(n==count){
			m=i;
			p=0;
			break;
		}
	}
	for(;i>1;i-=2){
		for(int j=(m-i)/2;j>0;j--){
			cout<<" ";
		}
		for(int j=i;j>0;j--){
			cout<<c;
		}
		cout<<endl;
	}
	for(;i<=m;i+=2){
		for(int j=(m-i)/2;j>0;j--){
			cout<<" ";
		}
		for(int j=i;j>0;j--){
			cout<<c;
		}
		cout<<endl;
	}
	if(p>=0)
		cout<<p<<endl;
} 

紧急救援
#include<iostream>
#define INF 99999999//用来表示无穷大（也就是不可达）
#define MAX 505
using namespace std;
int N,M,S,D;//城市数量，道路数量，起始点，终点
int path[MAX],quan[MAX],dis[MAX],per[MAX],book[MAX],sum[MAX],cost[MAX][MAX];
//记录父节点数组，点权数组，最短路径，最多救援队数，这个点有没有被加入集合中，最短路径的条数，顶点之间边的关系

//从终点逆推到起点输出路径 
void printPath(int v){
  if (v==S){
    cout<<v;
    return;
  }
  printPath(path[v]);
  cout<<" "<<v;
}

int main(){
	cin>>N>>M>>S>>D;
	int s,d,l,min;//源点，目的点，长度，距离最小值 
	
	//进行cost数组的初始化（自己到自己的距离是0，其余全部不可达）
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)
				cost[i][j]=0;
			else
				cost[i][j]=INF;
		}
	}
	
	//输入每个城市的权值 
	for(int i=0;i<N;i++){
		cin>>quan[i];
	}
	
	//进行cost数组的输入 
	for(int i=0;i<M;i++){
		cin>>s>>d>>l;
		cost[s][d]=l;
		cost[d][s]=l;
	}
	
	//初始化dis数组，初始化book数组 
	for(int i=0;i<N;i++){
		dis[i]=cost[S][i];
		book[i]=0;
	} 
	per[S]=quan[S],sum[S]=1;//初始化起始救援队数量和最短路径条数 
	
	//Dijkstra算法 
	for(int i=0;i<N;i++){
		int u=-1;
		min=INF;
		//找到离源点S最近的点 
		for(int j=0;j<N;j++){
			if(book[j]==0&&dis[j]<min){
				min=dis[j];//更新最小值 
				u=j;
			}
		}
		if(u==-1) break;//如果u没有变化说明所有的点都遍历过了
		book[u]=1;//将这个最近的点加入集合中
		//更新dis和per数组 
		for(int v=0;v<N;v++){
			if(cost[u][v]!=INF&&book[v]==0){//如果可达 
				if(dis[v]>dis[u]+cost[u][v]){//且源点到其他点的距离大于通过新加的点中转再到其他点的距离 
					dis[v]=dis[u]+cost[u][v];//更新源点到其他点的距离，更新最短路径数组 
					per[v]=per[u]+quan[v];//更新源点到其他点的人数，更新最多救援队数数组
					path[v]=u;//记录父节点 
					sum[v]=sum[u];
				}else if(dis[v]==dis[u]+cost[u][v]){//且源点到其他点的距离等于通过新加的点中转再到其他点的距离
					sum[v]+=sum[u];//最短路径的条数 
					if(per[v]<per[u]+quan[v]){//距离一样，找到更多的救援队数 
						per[v]=per[u]+quan[v];//更新最多救援队数 
						path[v]=u;//记录父节点 
					}
				}
			}
		} 
	} 
	
	cout<<sum[D]<<" "<<per[D]<<endl;
	printPath(D);
} 

谁先倒
#include<iostream>
using namespace std;
int main(){
	int A,B,countA=0,countB=0;
	cin>>A>>B;
	int n;
	cin>>n;
	int a1[n],a2[n],b1[n],b2[n];
	for(int i=0;i<n;i++){
		cin>>a1[i]>>a2[i]>>b1[i]>>b2[i];
	}
	for(int i=0;i<n;i++){
		if(a2[i]==a1[i]+b1[i])
			countA++;
		if(b2[i]==a1[i]+b1[i])
			countB++;
		if(a2[i]==a1[i]+b1[i]&&b2[i]==a1[i]+b1[i]){
			countA--;
			countB--;
		}
		if(countA==A+1){
			cout<<"A"<<endl<<countB<<endl;
			break;
		}
		if(countB==B+1){
			cout<<"B"<<endl<<countA<<endl;
			break;
		}
	}
} 

大笨钟

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main(){
	string a;
	cin>>a;
	int i=10*(a[0]-'0')+(a[1]-'0'),j=10*(a[3]-'0')+(a[4]-'0');
	if(i>=0&&i<=12){
		if(i==12){
			if(j>0)
				cout<<"Dang";
		}
		cout<<"Only "<<a<<".  Too early to Dang."<<endl;
	}
	else{
		if(j>0)
			i++;
		for(int k=0;k<i-12;k++){
			cout<<"Dang";
		}
		cout<<endl;
	}
}

 装睡
#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	string name[n];
	int huxi[n],maibo[n],flag[n]={0};
	for(int i=0;i<n;i++){
		cin>>name[i];
		scanf("%d %d",&huxi[i],&maibo[i]);
		if(huxi[i]<15||huxi[i]>20)
			flag[i]=1;
		if(maibo[i]<50||maibo[i]>70)
			flag[i]=1;
	}
	for(int i=0;i<n;i++){
		if(flag[i]==1)
			cout<<name[i]<<endl;
	}
}
稳赢#include<iostream>
#include<string>
using namespace std;
int main(){
	int k,p=0,count=0;
	string a,b[10000];
	cin>>k;
	for(int i=0;;i++){
		cin>>a;
		if(a=="End")
			break;
		count++;
		if(p==k){
			p=0;
			b[i]=a;
		}	
		else{
			p++;
			if(a=="ChuiZi")
				b[i]="Bu";
			if(a=="JianDao")
				b[i]="ChuiZi";
			if(a=="Bu")
				b[i]="JianDao";
		}
	}
	for(int i=0;i<count;i++){
		cout<<b[i];
		if(i<count-1)
			cout<<endl;
	}
} 
日期格式化
#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;
	cin>>a;
	for(int i=6;i<10;i++){
		cout<<a[i];
	}
	cout<<"-";
	for(int i=0;i<2;i++){
		cout<<a[i];
	}
	cout<<"-";
	for(int i=3;i<5;i++){
		cout<<a[i];
	}
}
出租
#include<iostream>
using namespace std;
int main(){
	char a[11];
	int index[11],arr1[10]={0},arr[10]={0};
	int count=0;
	for(int i=0;i<11;i++){
		cin>>a[i];
		switch(a[i]-'0'){
			case 0: arr1[0]=1; break;
			case 1: arr1[1]=1; break;
			case 2: arr1[2]=1; break;
			case 3: arr1[3]=1; break;
			case 4: arr1[4]=1; break;
			case 5: arr1[5]=1; break;
			case 6: arr1[6]=1; break;
			case 7: arr1[7]=1; break;
			case 8: arr1[8]=1; break;
			case 9: arr1[9]=1; break;
		}
	}
	for(int i=9;i>=0;i--){
		if(arr1[i]==1){
			arr[count]=i;
			count++;
		}
	}
	for(int i=0;i<11;i++){
		for(int j=0;j<count;j++){
			if((a[i]-'0')==arr[j])
				index[i]=j;
		}
	}
	cout<<"int[] arr = new int[]{";
	for(int i=0;i<count;i++){
		cout<<arr[i];
		if(i<count-1)
			cout<<",";
	}
	cout<<"};"<<endl;
	cout<<"int[] index = new int[]{";
	for(int i=0;i<11;i++){
		cout<<index[i];
		if(i<10)
			cout<<",";
	}
	cout<<"};";
}
Left-pad
#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	char c;
	string s;
	cin>>n>>c;
	getchar();
	getline(cin,s);
	if(s.size()<n){
		for(int i=0;i<n-s.size();i++){
			cout<<c;
		}
		cout<<s;
	}
	if(s.size()==n)
		cout<<s;
	if(s.size()>n){
		for(int i=s.size()-n;i<s.size();i++){
			cout<<s[i];
		}
	}
}
情人节
#include<iostream>
#include<string>
using namespace std;
int main(){
	int i=0;
	string A,B,C;
	while(C!="."){
		cin>>C;
		i++;
		if(i==2)
			A=C;
		if(i==14)
			B=C;
	}
	i--;
	if(i<2)
		cout<<"Momo... No one is for you ...";
	if(i>=2&&i<14)
		cout<<A<<" is the only one for you...";
	if(i>=14)
		cout<<A<<" and "<<B<<" are inviting you to dinner...";
}
出生年
#include<iostream>
using namespace std;
int main(){
	int y,n,b[4];
	cin>>y>>n;
	for(int i=y;i<3100;i++){
		int count=1;
		b[0]=i/1000;
		b[1]=(i%1000)/100;
		b[2]=(i%100)/10;
		b[3]=i%10;
		if(b[0]!=b[1]&&b[0]!=b[2]&&b[0]!=b[3])
			count++;
		if(b[1]!=b[2]&&b[1]!=b[3])
			count++;
		if(b[2]!=b[3])
			count++;
		if(count==n){
			printf("%d %04d",i-y,i);
			break;
		}
	}
}
 一帮一
#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],book[n]={0};
	string b[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			if(a[i]!=a[j]&&book[i]==0&&book[j]==0){
				cout<<b[i]<<" "<<b[j]<<endl;
				book[i]=1;
				book[j]=1;
				break;
			}
		}
	}
} 
判断素数
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,flag=1;
    long int a[11];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==1)
			flag=0;
		for(int j=2;j<=sqrt(a[i]);j++){
			if(a[i]%j==0){
				flag=0;
				break;
			}
		}
		if(flag==1||a[i]==2)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		flag=1;
	}
}
a-b#include<iostream>
#include<string>
using namespace std;
int book[256];
int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	for(int i=0;i<b.length();i++){
		book[b[i]]=1;
	}
	for(int i=0;i<a.length();i++){
		if(book[a[i]]==1)
			continue;
		cout<<a[i];
	}
	return 0;
}
倒数第N个字符串
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string find(int x){
	string c;
	switch(x){
		case 0: c='a'; break;
		case 1: c='b'; break;
		case 2: c='c'; break;
		case 3: c='d'; break;
		case 4: c='e'; break;
		case 5: c='f'; break;
		case 6: c='g'; break;
		case 7: c='h'; break;
		case 8: c='i'; break;
		case 9: c='j'; break;
		case 10: c='k'; break;
		case 11: c='l'; break;
		case 12: c='m'; break;
		case 13: c='n'; break;
		case 14: c='o'; break;
		case 15: c='p'; break;
		case 16: c='q'; break;
		case 17: c='r'; break;
		case 18: c='s'; break;
		case 19: c='t'; break;
		case 20: c='u'; break;
		case 21: c='v'; break;
		case 22: c='w'; break;
		case 23: c='x'; break;
		case 24: c='y'; break;
		case 25: c='z'; break;
		default: break;
		return c;
	}
}
int main(){
	int l,n;
	string s="";
	cin>>l>>n;
	n=pow(26,l)-n;
	for(int i=l-1;i>=0;i--){
		s+=find((n%(int)pow(26,i+1))/pow(26,i));
	}
	cout<<s;
}
阅览室
#include<iostream>
#include<string>
using namespace std;
class Book{
	public:
	int stime,etime;
	bool flag;
	Book(){
		flag=0;
	}
};
int main(){
	int n,id,hh,mm,time[10]={0},avetime[10]={0},sumtime[10]={0};
	char op;
	Book book[1000];
	cin>>n;
	for(int i=0;i<n;){
		scanf("%d %c %d:%d",&id,&op,&hh,&mm);
		if(id==0){
			i++;
			for(int j=0;j<1000;j++){
				book[j].flag=0;
			}
		}
		else {
			if(op=='S'){
				book[id].stime=hh*60+mm;
				book[id].flag=1;
			}
			if(op=='E'&&book[id].flag==1){
				book[id].etime=hh*60+mm;
				book[id].flag=0;
				time[i]++;
				sumtime[i]+=book[id].etime-book[id].stime;
				avetime[i]=(int)(sumtime[i]*1.0/time[i]+0.5);
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<time[i]<<" "<<avetime[i]<<endl;
	}
} 
奇偶分家
#include<iostream>
using namespace std;
int main(){
	int n,countA=0,countB=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2==0)
			countB++;
		else
			countA++;
	}
	cout<<countA<<" "<<countB;
} 
帅到没朋友
#include<iostream>
using namespace std;
int data[1000000];
int main(){
	int num,n;
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		if(k==1){
			cin>>num;
			if(data[num]==0)
				data[num]=1;
		}
		else{
			for(int j=0;j<k;j++){
				cin>>num;
				data[num]=-1;
			}
		}
	}
	int m,t=0;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=0;i<m;i++){
		if(data[b[i]]==1||data[b[i]]==0){
			t++;
			if(t!=1)
				cout<<" ";
			printf("%05d",b[i]);
			data[b[i]]=-1;
		}
	}
	if(t==0)
		cout<<"No one is handsome"<<endl;
}
紧急救援
#include<iostream>
#define INF 99999999//用来表示无穷大（也就是不可达）
#define MAX 505
using namespace std;
int N,M,S,D;//城市数量，道路数量，起始点，终点
int path[MAX],quan[MAX],dis[MAX],per[MAX],book[MAX],sum[MAX],cost[MAX][MAX];
//记录父节点数组，点权数组，最短路径，最多救援队数，这个点有没有被加入集合中，最短路径的条数，顶点之间边的关系

//从终点逆推到起点输出路径 
void printPath(int v){
  if (v==S){
    cout<<v;
    return;
  }
  printPath(path[v]);
  cout<<" "<<v;
}

int main(){
	cin>>N>>M>>S>>D;
	int s,d,l,min;//源点，目的点，长度，距离最小值 
	
	//进行cost数组的初始化（自己到自己的距离是0，其余全部不可达）
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)
				cost[i][j]=0;
			else
				cost[i][j]=INF;
		}
	}
	
	//输入每个城市的权值 
	for(int i=0;i<N;i++){
		cin>>quan[i];
	}
	
	//进行cost数组的输入 
	for(int i=0;i<M;i++){
		cin>>s>>d>>l;
		cost[s][d]=l;
		cost[d][s]=l;
	}
	
	//初始化dis数组，初始化book数组 
	for(int i=0;i<N;i++){
		dis[i]=cost[S][i];
		book[i]=0;
	} 
	per[S]=quan[S],sum[S]=1;//初始化起始救援队数量和最短路径条数 
	
	//Dijkstra算法 
	for(int i=0;i<N;i++){
		int u=-1;
		min=INF;
		//找到离源点S最近的点 
		for(int j=0;j<N;j++){
			if(book[j]==0&&dis[j]<min){
				min=dis[j];//更新最小值 
				u=j;
			}
		}
		if(u==-1) break;//如果u没有变化说明所有的点都遍历过了
		book[u]=1;//将这个最近的点加入集合中
		//更新dis和per数组 
		for(int v=0;v<N;v++){
			if(cost[u][v]!=INF&&book[v]==0){//如果可达 
				if(dis[v]>dis[u]+cost[u][v]){//且源点到其他点的距离大于通过新加的点中转再到其他点的距离 
					dis[v]=dis[u]+cost[u][v];//更新源点到其他点的距离，更新最短路径数组 
					per[v]=per[u]+quan[v];//更新源点到其他点的人数，更新最多救援队数数组
					path[v]=u;//记录父节点 
					sum[v]=sum[u];
				}else if(dis[v]==dis[u]+cost[u][v]){//且源点到其他点的距离等于通过新加的点中转再到其他点的距离
					sum[v]+=sum[u];//最短路径的条数 
					if(per[v]<per[u]+quan[v]){//距离一样，找到更多的救援队数 
						per[v]=per[u]+quan[v];//更新最多救援队数 
						path[v]=u;//记录父节点 
					}
				}
			}
		} 
	} 
	
	cout<<sum[D]<<" "<<per[D]<<endl;
	printPath(D);
} 
 到底有多二
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	int count=0,count2=0;
	float s=10;
	string a;
	cin>>a;
	count=a.size();
	for(int i=0;i<a.size();i++){
		if(a[i]=='2')
			count2++;
	}
	if(a[0]=='-'){
		count=a.size()-1;
		s=(1.0*count2/count)*1.5;
	}else{
		s=1.0*count2/count;
	}
	if((a[a.size()-1]-'0')%2==0)	
		s*=2;
	printf("%.2f%%\n",s*100);
}
查验身份证
#include<iostream>
using namespace std;
int main(){
	int n,z=0,count=0;
	int c[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char s[11]={'1','0','X','9','8','7','6','5','4','3','2'};///校验码
	cin>>n;
	char a[n][18];//数据 
	int b[n]={0};//flag 
	for(int i=0;i<n;i++){
		for(int j=0;j<18;j++){
			cin>>a[i][j];
		}
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<17;j++){
			if(a[i][j]>='0'&&a[i][j]<='9'){
				z=z+(int)(a[i][j]-'0')*c[j];
			}
			else{
				b[i]=1;
				break;
			}
		}
		z=z%11;
		if(a[i][17]!=s[z])
			b[i]=1;
		z=0;
	}
	for(int i=0;i<n;i++){
		if(b[i]==1){
			count++;
			for(int j=0;j<18;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	if(count==0){
		cout<<"All passed"<<endl;
	}
}
出生年
#include<iostream>
using namespace std;
int main(){
	int y,n,b[4];
	cin>>y>>n;
	for(int i=y;i<3100;i++){
		int count=1;
		b[0]=i/1000;
		b[1]=(i%1000)/100;
		b[2]=(i%100)/10;
		b[3]=i%10;
		if(b[0]!=b[1]&&b[0]!=b[2]&&b[0]!=b[3])
			count++;
		if(b[1]!=b[2]&&b[1]!=b[3])
			count++;
		if(b[2]!=b[3])
			count++;
		if(count==n){
			printf("%d %04d",i-y,i);
			break;
		}
	}
}
一帮一
#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],book[n]={0};
	string b[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			if(a[i]!=a[j]&&book[i]==0&&book[j]==0){
				cout<<b[i]<<" "<<b[j]<<endl;
				book[i]=1;
				book[j]=1;
				break;
			}
		}
	}
} 
老板的作息表

#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
set<string>st;
unordered_map<string , int> vis;
void f(string s) {
   	if(vis[s] == 2 || s == "00:00:00" || s == "23:59:59")
		st.erase(s);
	else
		st.insert(s);
}
int main()
{
	//卡输入输出,如果不解除缓存,就TLE(21)分
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , k , j = 0;
    cin >> n;
    while(n-- ) {
    	char ch;
        string s1 , s2;
        cin >> s1 >> ch >> s2;
        ++vis[s1] , ++vis[s2];
		f(s1) , f(s2);
    }
	if(!(vis["00:00:00"])) st.insert("00:00:00");
	if(!(vis["23:59:59"])) st.insert("23:59:59");
	for(auto i : st) {
		++j;
		cout << i;
		j & 1 ? cout << " - " : cout << endl;
	}
	return 0;
}
静静的推荐
#include<iostream>
using namespace std;
int a[1000];
int main()
{
	int n,k,grad,num=0;
	cin>>n>>k>>grad;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		if(x>=175)
		{
			if(y>=grad) num++;        //特殊的不受批次影响
			else if(a[x]<k)
			{
				a[x]++;
				num++;                //普通的受批次影响的
			}
		}
	}
	cout<<num;
	return 0;
 }

猜帽子
#include<bits/stdc++.h>
using namespace std;
int n, k, x;
int main() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    while(k--) {
        int cnt = 0, wa = 0;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            if(!x) continue;
            ++cnt;
            if(x != a[i]) ++wa;
        }
        if(cnt && !wa) puts("Da Jiang!!!");
        else puts("Ai Ya");
    }
	return 0;
}
剪切粘贴
#include<bits/stdc++.h>
using namespace std;
string s, s1, s2, s3;
int n, a, b;
int main() {
	cin >> s >> n;
	while(n--) {
		cin >> a >> b >> s1 >> s2;
		s3 = s.substr(a - 1, b - a + 1);
		s.erase(s.begin() + a - 1, s.begin() + b);
		int len = s1.length();
		s1 += s2;
        int pos = s.find(s1);
		if(pos != s.npos) s.insert(pos + len, s3);
		else s.insert(s.length(), s3);
	}
	cout << s;
	return 0;
}

分寝室
#include<bits/stdc++.h>
using namespace std;
int n0, n1, n, flag0, flag1, res = INT_MAX;
vector<int> N0, N1;
int main() {
	cin >> n0 >> n1 >> n;
	for(int i = 2; i <= min(n0, n1); ++i) {
		if(!(n0 % i)) N0.emplace_back(i);
		if(!(n1 % i)) N1.emplace_back(i);
	}
	for(int i = 0; i < N0.size(); ++i) {
		for(int j = 0; j < N1.size(); ++j) {
			if(n0 / N0[i] + n1 / N1[j] == n && fabs(N0[i] - N1[j]) < res) {
				res = fabs(N0[i] - N1[j]), flag0 = n0 / N0[i], flag1 = n1 / N1[j];
			}
		}
	}
	if(res == INT_MAX) puts("No Solution");
	else cout << flag0 << " " << flag1;
	return 0;
}

谁管谁叫爹
#include<bits/stdc++.h>
using namespace std;
long long n, na, nb, sa, sb;
long long sum(long long x) {
	long long cnt = 0;
	while(x) {
		cnt += (x % 10), x /= 10;
	}
    return cnt;
}
int main() {
	cin >> n;
	while(n--) {
		cin >> na >> nb, sa = sum(na), sb = sum(nb);
		if(!(na % sb) && !(nb % sa) || na % sb && nb % sa) cout << (na < nb ? "B\n" : "A\n");
		else if(!(na % sb)) cout << "A\n";
		else cout << "B\n";
	}
	return 0;
}
推宝塔
#include<bits/stdc++.h>
using namespace std;
int n, c, cnt, maxx;
stack<int> a, b;
int main() {
	cin >> n >> c;
	a.emplace(c);
	for(int i = 1; i < n; ++i) {
		cin >> c;
		if(c < a.top()) a.emplace(c);
		else if(b.empty() || c > b.top()) b.emplace(c);
		else {
			++cnt, maxx = max(maxx, (int)a.size());
			while(!a.empty()) a.pop();
			while(!b.empty() && b.top() > c) a.emplace(b.top()), b.pop();
			a.emplace(c);
		}
	}
	++cnt, maxx = max(maxx, (int)a.size());
	if(!b.empty()) ++cnt, maxx = max(maxx, (int)b.size());
	cout << cnt << " " << maxx;
	return 0;
}

天梯赛的赛场安排
#include<bits/stdc++.h>
using namespace std;
int n, c, res, cnt, a[5005], x;
string s;
priority_queue<int> Q;
int main() {
	cin >> n >> c;
	while(n--) {
		cin >> s >> x;
		cout << s << " " << ceil(1.0 * x / c) << endl;
		res += (x / c);
		if(x % c) Q.emplace(x % c);
	}
	while(!Q.empty()) {
		x = Q.top(), Q.pop();
		bool flag = true;
		for(int i = 0; i < cnt; ++i) {
			if(a[i] + x <= c) {
				a[i] += x, flag = false;
				break;
			}
		}
		if(flag) a[cnt++] = x;
	}
	cout << cnt + res;
	return 0;
}
锦标赛#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
int k, x;
int res[N], id[N][20], tr[N][20];
bool flag = true;
int main() {
	cin >> k;
	for(int j = 1; j <= k; ++j) {
		for(int i = 1; i <= (1 << (k - j)); ++i) {
			cin >> x;
			if(j == 1) res[i * 2] = x, id[i][1] = i * 2 - 1, tr[i][1] = x;
			else if(tr[i * 2 - 1][j - 1] > x && tr[i * 2][j - 1] > x) flag = false;
			else {
				if(tr[i * 2 - 1][j - 1] <= x) res[id[i * 2 - 1][j - 1]] = x, id[i][j] = id[i * 2][j - 1];
				else res[id[i * 2][j - 1]] = x, id[i][j] = id[i * 2 - 1][j - 1];
				tr[i][j] = max({x, tr[i * 2 - 1][j - 1], tr[i * 2][j - 1]});
			}
		}
	}
	cin >> x;
	if(x < tr[1][k]) flag = false;
	else res[id[1][k]] = x;
	if(!flag) puts("No Solution");
	else for(int i = 1; i <= (1 << k); ++i) cout << res[i] << " \n"[i == (1 << k)];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n, m, cnt1, cnt2;
bool flag;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, 1, -1, 0};
int main() {
	cin >> n >> m, getchar();
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			a[i][j] = (getchar() - '0');
		}
		getchar();
	}
	function<void(int, int)> dfs = [&](int x, int y) {
		if(a[x][y] != 1) flag = true;
		a[x][y] = 0;
		for(int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny]) dfs(nx, ny);
		}
	};
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(a[i][j]) {
				++cnt1;
				flag = false;
				dfs(i, j);
				if(flag) ++cnt2;
			}
		}
	}
	cout << cnt1 << " " << cnt2;
	return 0;
}
紧急救援
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, c1, c2;
int dis[510], weight[510], e[510][510], num[510], w[510], pre[510];
bool visit[510];
const int inf = 99999999;
void printPath(int v) {
    if(v == c1) {
        printf("%d", v);
        return ;
    }
    printPath(pre[v]);
    printf(" %d", v);
}
int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    int a, b, c;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = c;
        e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                    pre[v] = u;
                } else if(dis[u] + e[u][v] == dis[v]) {
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
    printf("%d %d\n", num[c2], w[c2]);
    printPath(c2);
    return 0;
}
链表去重.
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct NODE {
    int address, key, next, num;
}node[maxn];
bool exist[maxn];
int cmp1(NODE a, NODE b){
    return a.num < b.num;
}
int main() {
    int begin, n, cnt1 = 0, cnt2 = 0, a;
    scanf("%d%d", &begin, &n);
    for(int i = 0; i < maxn; i++) {
        node[i].num = 2 * maxn;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        scanf("%d%d", &node[a].key, &node[a].next);
        node[a].address = a;
    }
    for(int i = begin; i != -1; i = node[i].next) {
        if(exist[abs(node[i].key)] == false) {
            exist[abs(node[i].key)] = true;
            node[i].num = cnt1;
            cnt1++;
        }
        else {
            node[i].num = maxn + cnt2;
            cnt2++;
        }
    }
    sort(node, node + maxn, cmp1);
    int cnt = cnt1 + cnt2;
    for(int i = 0; i < cnt; i++) {
        if(i != cnt1 - 1 && i != cnt - 1) {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
        } else {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }
    return 0;
}
月饼
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct mooncake{
    float num, price, unit;
};
int cmp(mooncake a, mooncake b) {
    return a.unit > b.unit;
}
int main() {
    int n, need;
    cin >> n >> need;
    vector<mooncake> a(n);
    for (int i = 0; i < n; i++) scanf("%f", &a[i].num);
    for (int i = 0; i < n; i++) scanf("%f", &a[i].price);
    for (int i = 0; i < n; i++) a[i].unit = a[i].price / a[i].num;
    sort(a.begin(), a.end(), cmp);
    float result = 0.0;
    for (int i = 0; i < n; i++) {
        if (a[i].num <= need) {
            result = result + a[i].price;
        } else {
            result = result + a[i].unit * need;
            break;
        }
        need = need - a[i].num;
    }
    printf("%.2f",result);
    return 0;
}

 这是二叉搜索树吗

#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}

集合相似度

#include <set>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    int n, m, k, temp, a, b;
    scanf("%d", &n);
    vector<set<int>> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        set<int> s;
        for(int j = 0; j < m; j++) {
            scanf("%d", &temp);
            s.insert(temp);
        }
        v[i] = s;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        int nc = 0, nt = v[b-1].size();
        for(auto it = v[a-1].begin(); it != v[a-1].end(); it++) {
            if(v[b-1].find(*it) == v[b-1].end()) 
                nt++;
            else
                nc++;
        }
        double ans = (double)nc / nt * 100;
        printf("%.2f%%\n", ans);
    }
    return 0;
}
树的遍历
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<int> post, in;
map<int, int> level;
void pre(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    int n;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    auto it = level.begin();
    printf("%d", it->second);
    while(++it != level.end()) printf(" %d", it->second);
    return 0;
}

 家庭房产

#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
    int id, fid, mid, num, area;
    int cid[10];
}data[1005];
struct node {
    int id, people;
    double num, area;
    bool flag = false;
}ans[10000];
int father[10000];
bool visit[10000];
int find(int x) {
    while(x != father[x])
        x = father[x];
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;
}
int cmp1(node a, node b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main() {
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)
        father[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visit[data[i].id] = true;
        if(data[i].fid != -1) {
            visit[data[i].fid] = true;
            Union(data[i].fid, data[i].id);
        }
        if(data[i].mid != -1) {
            visit[data[i].mid] = true;
            Union(data[i].mid, data[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &data[i].cid[j]);
            visit[data[i].cid[j]] = true;
            Union(data[i].cid[j], data[i].id);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }
    for(int i = 0; i < n; i++) {
        int id = find(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = true;
    }
    for(int i = 0; i < 10000; i++) {
        if(visit[i])
            ans[find(i)].people++;
        if(ans[i].flag)
            cnt++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp1);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    return 0;
}

 最长对称子串

#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int maxvalue = 0, temp;
    int len = s.length();
    for(int i = 0; i < len; i++) {
        temp = 1;
        for(int j = 1; j < len; j++) {
            if(i - j < 0 || i + j >= len || s[i - j] != s[i + j])
                break;
            temp += 2;
        }
        maxvalue = temp > maxvalue ? temp : maxvalue;
        temp = 0;
        for(int j = 1; j < len; j++) {
            if(i - j + 1 < 0 || i + j >= len || s[i - j + 1] != s[i + j])
                break;
            temp += 2;
        }
        maxvalue = temp > maxvalue ? temp : maxvalue;
    }
    cout << maxvalue;
    return 0;
}
抢红包

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id, total, getnum;
};
bool cmp1(node a, node b) {
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.getnum != b.getnum)
        return a.getnum > b.getnum;
    else
        return a.id < b.id;
}
int main() {
    int n, k, a, b;
    scanf("%d", &n);
    vector<node> v(n + 1);
    for(int i = 1; i <= n; i++) {
        v[i].id = i;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d %d", &a, &b);
            v[a].total += b;
            v[a].getnum++;
            v[i].total -= b;
        }
    }
    sort(v.begin()+1, v.end(), cmp1);
    for(int i = 1; i <= n; i++) {
        double temp = (double)(v[i].total * 1.0 / 100);
        printf("%d %.2f\n", v[i].id, temp);
    }
    return 0;
}

 排座位

#include <cstdio>
#include <vector>
using namespace std;
vector<int> fri;
int enemy[101][101];
int findfri(int x) {
    while(x != fri[x])
        x = fri[x];
    return x;
}
void Union(int a, int b) {
    int fria = findfri(a);
    int frib = findfri(b);
    if(fria != frib)
        fri[fria] = frib;
}
int main() {
    int n, m, k, a, b, c;
    scanf("%d %d %d", &n, &m, &k);
    fri.resize(n + 1);
    for(int i = 1; i <= n; i++)
        fri[i] = i;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(c == 1)
            Union(a, b);
        else {
            enemy[a][b] = 1;
            enemy[b][a] = 1;
        }
    }
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        if(findfri(a) == findfri(b) && enemy[a][b] == 0)
            printf("No problem\n");
        else if(findfri(a) != findfri(b) && enemy[a][b] == 0)
            printf("OK\n");
        else if(findfri(a) == findfri(b) && enemy[a][b] == 1)
            printf("OK but...\n");
        else if(enemy[a][b] == 1)
            printf("No way\n");
    }
    return 0;
}

玩转二叉树

#include <cstdio>
#include <vector>
using namespace std;
vector<int> in, pre, level(100000, -1);
void post(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    level[index] = pre[root];
    post(root + 1, start, i - 1, 2 * index + 2);
    post(root + 1 + i - start, i + 1, end, 2 * index + 1);
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    in.resize(n);
    pre.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
    post(0, 0, n-1, 0);
    for(int i = 0; i < level.size(); i++) {
        if(level[i] != -1 && cnt != n - 1) {
            printf("%d ", level[i]);
            cnt++;
        } else if(level[i] != -1){
            printf("%d", level[i]);
            break;
        }
    }
    return 0;
}

关于堆的判断
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v;
int n;
void upAdjust(int i) {
    if(i == 1) return ;
    while(i != 1) {
        if(v[i] < v[i / 2]) {
            swap(v[i], v[i / 2]);
            i = i / 2;
        } else {
            break;
        }
    }
}
void judge1(int a) {
    if(v[1] == a) printf("T\n");
    else printf("F\n");
}
void judge2(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if(indexa > indexb) swap(indexa, indexb);
    if(indexa % 2 == 0 && indexb - indexa == 1) printf("T\n");
    else printf("F\n");
}
void judge3(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if((2 * indexa) == indexb || (2 * indexa) + 1 == indexb) printf("T\n");
    else printf("F\n");
}
void judge4(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if(indexa == indexb * 2 || indexa == 2 * indexb + 1) printf("T\n");
    else printf("F\n");
}
int main() {
    int k, a, b;
    char c[100];
    scanf("%d%d", &n, &k);
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        upAdjust(i);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d%s", &a, c);
        if(strcmp(c, "and") == 0) {
            scanf("%d%s%s", &b, c, c);
            judge2(a, b);
        } else {
            scanf("%s", c);
            if(strcmp(c, "a") == 0) {
                scanf("%s%s%d", c, c, &b);
                judge4(a, b);
            } else {
                scanf("%s", c);
                if(strcmp(c, "root") == 0) {
                    judge1(a);
                } else {
                    scanf("%s%d", c, &b);
                    judge3(a, b);
                }
            }
        }
    }
    return 0;
}

 红色警报
#include <cstdio>
#include <algorithm>
using namespace std;
bool visit[510];
int e[510][510], n, m, k;
void dfs(int node) {
    visit[node] = true;
    for(int i = 0; i < n; i++) {
        if(visit[i] == false && e[node][i] == 1)
            dfs(i);
    }
}
int countcnt() {
    int cnt = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        if(visit[i] == false) {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d", &n, &m);
    int a, b, city;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    int cnt = countcnt();
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &city);
        for(int j = 0; j < n; j++) {
            if(e[city][j] == 1) {
                e[city][j] = 0;
                e[j][city] = 0;
            }
        }
        int tempcnt = countcnt();
        if(tempcnt > cnt + 1)
            printf("Red Alert: City %d is lost!\n", city);
        else
            printf("City %d is lost.\n", city);
        cnt = tempcnt;
        if(i == n - 1) printf("Game Over.\n");
    }
    return 0;
}
列车调度.
#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, t;
    cin >> n;
    set<int> s;
    s.insert(0);
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t < *s.rbegin()) {
            s.erase(*(s.upper_bound(t)));
        }
        s.insert(t);
    }
    cout << s.size() - 1;
    return 0;
}

 互评成绩.
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int cmp1(double a, double b) {return a > b;}
int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector<double> total;
    for(int i = 0; i < n; i++) {
        vector<double> v(k);
        double maxn = -1, minn = 101, average = 0.0;
        for(int j = 0; j < k; j++) {
            scanf("%lf", v[j]);
            maxn = max(maxn, v[j]);
            minn = min(minn, v[j]);
            average += v[j];
        }
        average = average / (k - 2);
        total.push_back(average);
    }
    sort(total.begin(), total.end(), cmp1);
    if(m != 0)
        printf("%.3f", total[m - 1]);
    for(int i = m - 2; i >= 0; i--)
        printf(" %.3f", total[i]);
    return 0;
}

愿天下有情人都是失散多年的兄妹

#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    int f, m, sex;
};
node v[100010];
int level[100010];
bool exist[100010];
int main() {
    int n, m, id, father, mother, a, b;
    scanf("%d", &n);
    char c;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d %d", &id, &c, &father, &mother);
        v[id].f = father, v[id].m = mother;
        if(c == 'M') v[id].sex = 0;
        else v[id].sex = 1;
        exist[id] = true;
        v[father].sex = 0;
        v[mother].sex = 1;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        fill(level, level + 100010, 0);
        scanf("%d%d", &a, &b);
        if(v[a].sex == v[b].sex) {
            printf("Never Mind\n");
            continue;
        }
        queue<int> q;
        q.push(a);
        q.push(b);
        level[a] = 1;
        level[b] = 1;
        set<int> s;
        int flag = 0;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            int size = s.size();
            s.insert(top);
            if(size == s.size()) {
                printf("No\n");
                flag = 1;
                break;
            }
            if(exist[top] == false) continue;
            if(level[top] <= 4) {
                int fa = v[top].f;
                int mo = v[top].m;
                if(fa != -1) {
                    q.push(fa);
                    level[fa] = level[top] + 1;
                }
                if(mo != -1) {
                    q.push(mo);
                    level[mo] = level[top] + 1;
                }
            }
        }
        if(flag == 0) printf("Yes\n");
    }
    return 0;
}

人以群分
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, sum = 0, half = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n / 2; i++)
        half += v[i];
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", (n + 1) / 2, n / 2, sum - 2 * half);
    return 0;
}

 多项式A除以B

#include <cstdio>
#include <cmath>
using namespace std;
int nonNegativeNum(double c[], int start) {
    int cnt = 0;
    for (int i = start; i >= 0; i--)
        if (abs(c[i]) + 0.05 >= 0.1) cnt++;
    return cnt;
}
void printPoly(double c[], int start) {
    printf("%d", nonNegativeNum(c, start));
    if (nonNegativeNum(c, start) == 0) printf(" 0 0.0");
    for (int i = start; i >= 0; i--)
        if (abs(c[i]) + 0.05 >= 0.1)
            printf(" %d %.1f", i, c[i]);
}
double c1[3000], c2[3000], c3[3000];
int main() {
    int m = 0, n = 0, t = 0, max1 = -1, max2= -1;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        max1 = max1 > t ? max1 : t;
        scanf("%lf", &c1[t]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        max2 = max2 > t ? max2 : t;
        scanf("%lf", &c2[t]);
    }
    int t1 = max1, t2 = max2;
    while (t1 >= t2) {
        double c = c1[t1] / c2[t2];
        c3[t1 - t2] = c;
        for (int i = t1, j = t2; j >= 0; j--, i--) c1[i] -= c2[j] * c;
        while (abs(c1[t1]) < 0.000001) t1--;
    }
    printPoly(c3, max1 - max2);
    printf("\n");
    printPoly(c1, t1);
    return 0;
}

悄悄关注
#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
    int N, M, sum = 0, cnt, flag = 0;
    string str;
    cin >> N;
    set<string> s;
    for (int i = 0; i < N; i++) {
        cin >> str;
        s.insert(str);
    }
    cin >> M;
    map<string, int> m;
    for (int i = 0; i < M; i++) {
        cin >> str >> cnt;
        m[str] = cnt;
        sum += cnt;
    }
    sum /= M;
    for (auto it : m) {
        if (it.second > sum && s.find(it.first) == s.end()) {
            cout << it.first << endl;
            flag = 1;
        }
    }
    if (flag == 0) cout << "Bing Mei You";
    return 0;
}
 功夫传人	

 #include <cstdio>
#include <vector>
using namespace std;
vector<vector<int> > v;
int n, k;
double z, r, result = 0.0;
bool visit[100010];
void dfs(int index, double power) {
    if (visit[index] == true) {
        result += power * v[index][0];
        return;
    }
    for (int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], power * (1 - r/100));
}
int main() {
    scanf("%d%lf%lf", &n, &z, &r);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        int temp;
        if (k == 0) {
            scanf("%d", &temp);
            v[i].push_back(temp);
            visit[i] = true;
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &temp);
            v[i].push_back(temp);
        }
    }
    dfs(0, z);
    printf("%d", (int)result);
    return 0;
}
点赞狂魔	

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct stu{
    string name;
    int sum, cnt;
};
bool cmp(stu a, stu b){
    if(a.cnt != b.cnt)  return a.cnt > b.cnt;
    return 1.0 * a.sum / a.cnt < 1.0 * b.sum / b.cnt;
}
bool a[10000010];
int main() {
    int n;
    cin >> n;
    vector<stu> ans(n);
    for(int i = 0; i < n; i++) {
        memset(a, false, sizeof(a));
        int m, t, cnt = 0;
        string name;
        cin >> name >> m;
        for(int j = 0; j < m; j++) {
            cin >> t;
            if(a[t] == false) {
                a[t] = true;
                cnt++;
            }
        }
        ans[i] = {name, m, cnt};
    }
    int nn = min(n, 3);
    partial_sort(ans.begin(),ans.begin() + nn, ans.end(), cmp);
    for(int i = 0; i < nn; i++) {
        if(i != 0) cout << " ";
             cout << ans[i].name;
    }
    for(int i = 0; i < 3 - n; i++)
        cout << " " <<  "-";
    return 0;
}
重排链表.
#include <iostream>
#include <vector>
using namespace std;
struct node{
    int id, data, next;
};
int main() {
    int begin, n;
    cin >> begin >> n;
    node a[100010];
    vector<node> v, ans;
    for(int i = 0; i < n; i++) {
        int tbegin, tdata, tnext;
        cin >> tbegin >> tdata >> tnext;
        a[tbegin] = {tbegin, tdata, tnext};
    }
    while(begin != -1) {
        v.push_back(a[begin]);
        begin = a[begin].next;
    }
    int l = 0, r = v.size() - 1;
    while(1) {
        ans.push_back(v[r]);
        r--;
        if((r + 1) - (l - 1) == 1) break;
        ans.push_back(v[l]);
        l++;
        if((r + 1) - (l - 1) == 1) break;
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i != ans.size() - 1)
            printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i+1].id);
        else
            printf("%05d %d -1\n", ans[i].id, ans[i].data);
    }
    return 0;
}

图着色问题.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m, k, num;
vector<vector<int>> v(510);
vector<int> color(510);
bool f(int i) {
    for(int j = 0; j < v[i].size(); j++)
        if(color[i] == color[v[i][j]])
            return false;
    return true;
}
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    cin >> num;
    while(num--) {
        int flag = 0;
        set<int> s;
        for(int i = 1; i <= n; i++) {
            cin >> color[i];
            s.insert(color[i]);
        }
        if(s.size() != k ) {
            flag = 1;
            cout << "No\n";
        }else {
            for(int i = 1; i <= n; i++) {
                if(f(i) == false) {
                    cout << "No\n";
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0)  cout << "Yes\n";
    }
    return 0;
}
 部落

L2-024 部落（25 分）
在一个社区里，每个人都有自己的小圈子，还可能同时属于很多不同的朋友圈。我们认为朋友的朋友都算在一个部落里，于是要请你统计一下，在一个给定社区中，到底有多少个互不相交的部落？并且检查任意两个人是否属于同一个部落。

输入格式：
输入在第一行给出一个正整数N（<= 10^4^），是已知小圈子的个数。随后N行，每行按下列格式给出一个小圈子里的人：
K P[1] P[2] ... P[K]
其中K是小圈子里的人数，P[i]（i=1, .., K）是小圈子里每个人的编号。这里所有人的编号从1开始连续编号，最大编号不会超过10^4^。
之后一行给出一个非负整数Q（<= 10^4^），是查询次数。随后Q行，每行给出一对被查询的人的编号。

输出格式：
首先在一行中输出这个社区的总人数、以及互不相交的部落的个数。随后对每一次查询，如果他们属于同一个部落，则在一行中输出“Y”，否则输出“N”。

输入样例：
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
输出样例：
10 2
Y
N


#include <cstdio>
#include <set>
using namespace std;
int father[10010];
int findFather(int x) {
    while (x != father[x])
        x = father[x];
    return x;
}
set<int> total;
void unionFather(int a, int b) {
    total.insert(a);
    total.insert(b);
    int fa = findFather(a), fb = findFather(b);
    if (fa < fb) father[fb] = fa;
    else father[fa] = fb;
}
int main() {
    for (int i = 0; i <= 10000; i++) father[i] = i;
    int n, k, t, s, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &k, &t);
        if (k == 1) unionFather(t, t);
        for (int j = 1; j < k; j++) {
            scanf("%d",&s);
            unionFather(t, s);
        }
    }
    set<int> cnt;
    for (auto it = total.begin(); it != total.end(); it++) 
        cnt.insert(findFather(*it));
    printf("%lu %lu\n", total.size(), cnt.size());
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &t, &s);
        printf("%c\n", findFather(t) == findFather(s) ? 'Y' : 'N');
    }
    return 0;
}

分而治之
#include <iostream>
#include <vector>
using namespace std;
int n, m, k, aa[10010] = {0}, a[10010];
void check() {
    for(int i = 1; i <= n; i++) {
        if(a[i] > 0) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    return ;
}
int main(){
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    while(m--) {
        int c1, c2;
        cin >> c1 >> c2;
        aa[c1]++;
        aa[c2]++;
        v[c1].push_back(c2);
        v[c2].push_back(c1);
    }
    cin >> k;
    while(k--) {
        int cnt, num;
        cin >> cnt;
        for(int i = 1; i <= n; i++)
            a[i] = aa[i];
        for(int i = 0; i < cnt; i++) {
            cin >> num;
            a[num] = 0;
            for(int j = 0; j < v[num].size(); j++)
                a[v[num][j]]--;
        }
        check();
    }
    return 0;
}
小字辈

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct peo{
    int id, level;
};
int main(){
    int n, temp, maxlevel = -1;
    queue<peo> q;
    vector<peo> ans;
    cin >> n;
    vector<vector<int>> v(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        if(temp == -1) temp = 0;
        v[temp].push_back(i);
    }
    q.push({0,0});
    while(!q.empty()) {
        peo p  = q.front();
        int id = p.id, level = p.level;
        if(p.level > maxlevel) maxlevel = p.level;
        ans.push_back(p);
        q.pop();
        for(int i = 0; i < v[id].size(); i++)
            q.push({v[id][i], level + 1});
    }
    cout << maxlevel << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].level == maxlevel) {
            cout << ans[i].id;
            if(i != ans.size() - 1) cout << " ";
        }
    }
    return 0;
}

名人堂与代金券

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct peo{
    string name;
    int sco;
};
bool cmp(peo a, peo b) {
    if(a.sco != b.sco) return a.sco > b.sco;
    return a.name < b.name;
}
int main(){
    int n, g, k, sum = 0, rank[10001] = {0};
    cin >> n >> g >> k;
    vector<peo> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].sco;
        if(v[i].sco >= 60) sum += 20;
        if(v[i].sco >= g) sum += 30;
    }
    sort(v.begin(), v.end(), cmp);
    rank[0] = 1;
    for(int i = 1; i < n; i++) {
        if(v[i].sco == v[i-1].sco)
            rank[i] = rank[i-1];
        else
            rank[i] = i + 1;
    }
    cout << sum << endl;
    for(int i = 0; rank[i] <= k && i < n; i++)
        printf("%d %s %d\n", rank[i], v[i].name.c_str(), v[i].sco);
    return 0;
}

 特立独行的幸福

#include <bits/stdc++.h>
using namespace std;
int A, B, flag, num[10001], notIndep[10001];
bool isPrime(int a) {
    if (a == 1) return false;
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0) return false;
    return true;
}
bool isIndep(int x) {
    set<int> mark;
    int X = x, temp1, temp2;
    while (X != 1) {
        mark.insert(X);
        temp1 = 0;
        while (X) {
            temp2 = X % 10;
            X /= 10;
            temp1 += temp2 * temp2;
        }
        num[x]++;
        notIndep[temp1] = 1;
        X = temp1;
        if (mark.count(X)) return false;
    } 
    return true;
}
int main() {
    cin >> A >> B;
    vector<int> ans;
    for (int i = A; i <= B; i++)
        if (isIndep(i)) ans.push_back(i);
    for (int i = 0; i < ans.size(); i++) {
        if (isPrime(ans[i])) num[ans[i]] <<= 1;
        if (!notIndep[ans[i]]) {
            cout << ans[i] << ' ' << num[ans[i]] << endl;
            flag = 1;
        }
    }
    if (!flag) cout << "SAD"; 
    return 0;
}

冰岛人

#include <bits/stdc++.h>
using namespace std;
#define pis pair<int, string>
int N, M;
string fName, sName, temp;
map<string, pis> Record;
string check(string a, string b) {
    int cnt1 = 0, cnt2;
    while (a != "") {
        cnt2 = 0;
        string b2 = b;
        while (b2 != "") {
            if (a == b2 && (cnt1 < 4 || cnt2 < 4)) return "No\n";
            if (cnt1 >= 4 && cnt2 >= 4) return "Yes\n";
            b2 = Record[b2].second;
            cnt2++;
        }
        a = Record[a].second;
        cnt1++;
    }
    return "Yes\n";
}
int main() {
    cin >> N;
    while(N--){
        cin >> fName >> sName;
        if (sName.back() == 'n') Record[fName] = {1, sName.substr(0, sName.length() - 4)};
        else if (sName.back() == 'r') Record[fName] = {0, sName.substr(0, sName.length() - 7)};
        else if (sName.back() == 'm') Record[fName].first = 1;
        else Record[fName].first = 0;
    }
    cin >> M;
    while(M--){
        cin >> fName >> temp >> sName >> temp;
        if (!Record.count(fName) || !Record.count(sName)) cout << "NA\n";
        else if(Record[fName].first == Record[sName].first) cout << "Whatever\n";
        else cout << check(fName, sName);
    }
    return 0;
}

深入虎穴

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int N, K, D, one, vis[100001];
vector<int> Edge[100001];
queue<int> Q;
int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> K;
        while(K--) {
            cin >> D;
            Edge[D].push_back(i);
            Edge[i].push_back(D);
        }
    }
    Q.push(1);
    vis[1] = 1;
    while(!Q.empty()) {
        one = Q.front();
        Q.pop();
        for (auto v:Edge[one]) {
            if (vis[v]) continue;
            vis[v] = 1;
            Q.push(v);
        }
    }
    cout << one;
    return 0;
}

彩虹瓶

#include <bits/stdc++.h>
using namespace std;
int N, M, K, temp, need, num, Stack[1002];
int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        need = 1, num = 1;
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == need) {
                need++;
                while (Stack[num - 1] == need) need++, num--;
            } else if (num <= M) Stack[num++] = temp;
        }
        printf("%s\n", num == 1 ? "YES" : "NO");
    }
    return 0;
}

简单计算器
#include <bits/stdc++.h>
using namespace std;
int n, In[1000], Sum;
char oper, Record[100];
int main() {
    cin >> n;
    for (int i = n - 1; i >= 0; i--) cin >> In[i];
    for (int i = n - 1; i > 0; i--) cin >> Record[i];
    Sum = In[0];
    for (int i = 1; i < n; i++) {
        oper = Record[i];
        if (oper == '+') Sum = In[i] + Sum;
        else if (oper == '-') Sum = In[i] - Sum; 
        else if (oper == '*') Sum = In[i] * Sum;
        else {
            if (Sum == 0) {
                cout << "ERROR: " << In[i] << "/0";
                return 0;
            }
            Sum = In[i] / Sum;
        }
    }
    cout << (int)Sum;
    return 0;
}
 口罩发放

#include <bits/stdc++.h>
using namespace std;
struct node {
    string name, id, Time;
    int illness, order;
};
bool isIllegal(const string &ss) {
    if (ss.size() != 18) return true;
    for (char i:ss) if (i < '0' || i > '9') return true;
    return false;
}
bool cmp (const node &a,const node &b) {
    if (a.Time != b.Time) return a.Time < b.Time;
    return a.order < b.order;
}
vector<node> Record, ill;
int D, P, t, s, providedNum;
map<string, int> lastGet;
set<string> gotten;
int main() {
    cin >> D >> P;
    for (int i = 1; i <= D; i++) {
        cin >> t >> s;
        Record.resize(t);
        providedNum = 0;
        for (int j = 0; j < t; j++) {
            cin >> Record[j].name >> Record[j].id >> Record[j].illness >> Record[j].Time;
            Record[j].order = j;
            if (isIllegal(Record[j].id)) Record[j].name = "";
            else {
                if (!lastGet.count(Record[j].id)) lastGet[Record[j].id] = -30;
                if (Record[j].illness == 1 && !gotten.count(Record[j].id)) {
                    ill.push_back(Record[j]);
                    gotten.insert(Record[j].id);
                }
            }
        }
        sort(Record.begin(), Record.end(), cmp);
        for (int j = 0; j < t && providedNum < s; j++) {
            if (Record[j].name != "" && i - lastGet[Record[j].id] > P) {
                lastGet[Record[j].id] = i;
                providedNum++;
                cout << Record[j].name << ' ' << Record[j].id << endl;
            }
        }
    }
    for (node i:ill) cout << i.name << ' ' << i.id << '\n';
    return 0;
}

 完全二叉树的层序遍历

#include <bits/stdc++.h>
using namespace std;
int n, cnt, In[32], dfs[32];
void Func(int index) {
    if (index > n) return;
    Func(index << 1);
    Func(index << 1 | 1);
    dfs[index] = In[cnt++];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> In[i];
    Func(1);
    cout << dfs[1];
    for (int i = 2; i <= n; i++) cout << ' ' << dfs[i];
    return 0;
}
 网红点打卡攻略
#include <bits/stdc++.h>
using namespace std;
int N, M, K, u, v, w, n, flag, cost, Ansnum, Ansid, Anscost = INT_MAX, Edge[201][201], Path[202], Has[201];
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        Edge[u][v] = Edge[v][u] = w;
    }
    cin >> K;
    for (int i = 1; i <= K; i++) {
        fill(Has, Has + N + 1, 0);
        Path[N + 1] = flag = cost = 0;
        cin >> n;
        for (int j = 1; j <= n; j++){
            cin >> Path[j];
            if(Has[Path[j]]) Has[0] = 1;
            Has[Path[j]] = 1;
        }
        if (Has[0] || n != N) continue;
        for (int j = 1; j <= n + 1; j++) {
            if (Edge[Path[j-1]][Path[j]] == 0) {
                flag = 1;
                break;
            }
            cost += Edge[Path[j - 1]][Path[j]];
        }
        if (!flag) {
            Ansnum++;
            if(cost < Anscost) Ansid = i, Anscost = cost;
        }
    }
    cout << Ansnum << '\n' << Ansid << ' ' << Anscost;
    return 0;
}




包装机包装机
#include <bits/stdc++.h>
using namespace std;
int n, m, s, c;
queue<char> Q[1005];
stack<char> St;
int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < m; j++) Q[i].push(t[j]);
    }
    while (cin >> c) {
        if (c == -1) break;
        if (c == 0) {
            if (St.empty()) continue;
            cout << St.top();
            St.pop();
        } else {
            if (Q[c].empty()) continue;
            if (St.size() == s) {
                cout << St.top();
                St.pop();
            }
            St.push(Q[c].front());
            Q[c].pop();
        }
    }
    return 0;
} 
病毒溯源
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int ,int>
int n, k, t, S, Long = 0,  ans, in[10005], pa[10005];
vector<int> F, Edge[10005];
queue<pii> Q;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            in[t]++;
            pa[t] = i;
            Edge[i].push_back(t);
        }
        sort(Edge[i].begin(), Edge[i].end());
    }
    for (int i = 0; i < n; i++) if (in[i] == 0) S = i;
    while(!Q.empty()) Q.pop();
    Q.push({S, 1});
    while (!Q.empty()) {
        int now = Q.front().first, D = Q.front().second;
        Q.pop();
        if (D > Long) {
            Long = D;
            ans = now;
        }
        for (auto nex : Edge[now]) Q.push({nex, D + 1});
    }
    cout << Long << '\n';
    while (ans != S) {
        F.push_back(ans);
        ans = pa[ans];
    }
    F.push_back(S);
    for (int i = F.size() - 1; ~i; --i) {
        cout << F[i];
        if (i != 0) cout << ' ';
    }
    return 0;
} 

清点代码库

#include <bits/stdc++.h>
using namespace std;
int n, m, t;
vector<int> temp;
map<vector<int>, int> A;
multimap<int, vector<int>, greater<int> > B;
int main() {
    scanf("%d%d", &n, &m);
    temp.resize(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &temp[j]);
        A[temp]++;
    }
    for (auto it : A) B.insert({it.second, it.first});
    printf("%d\n", A.size());
    for (auto it : B) {
        printf("%d", it.first);
        for (auto it2 : it.second) printf(" %d", it2);
        printf("\n");
    }
    return 0;
}
哲哲打游戏
#include <bits/stdc++.h>
using namespace std;
struct node {
    int pos;
    vector<int> Path;
};
int n, m, now = 1;
vector<int> temp, Edge[100005];
vector<node> Save(105);
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int t2;
            scanf("%d", &t2);
            Edge[i].push_back(t2);
        }
    }
    temp.push_back(1);
    for (int i = 1; i <= m; i++) {
        int c, J;
        scanf("%d%d", &c, &J);
        if (c == 0) {
            temp.push_back(Edge[now][J-1]);
            now = Edge[now][J - 1];
        } else if (c == 1) {
            Save[J].pos = now;
            Save[J].Path = temp;
            printf("%d\n", now);
        } else {
            now = Save[J].pos;
            temp = Save[J].Path;
        }
    }
    printf("%d", temp.back());
    return 0;
}

凑零钱
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010];
int w[10010];
bool choice[10010][10010];
int cmp1(int a, int b){return a > b;}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            if(dp[j] <= dp[j-w[i]] + w[i]) {
                choice[i][j] = true;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}
堆栈
#include <cstdio>
#include <stack>
#define lowbit(i) ((i) & (-i))
const int maxn = 100010;
using namespace std;
int c[maxn];
stack<int> s;
void update(int x, int v) {
    for(int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}
int getsum(int x) {
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if(str[1] == 'o') {
            if(!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("Invalid\n");
            }
        } else {
            if(!s.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }
    return 0;
}
社交集群
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father, isRoot;
int cmp1(int a, int b){
    return a > b;
}
int findFather(int x) {
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
        father[faA] = faB;
}
int main() {
    int n, k, t, cnt = 0;
    int course[1001] = {0};
    scanf("%d", &n);
    father.resize(n + 1);
    isRoot.resize(n + 1);
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            if(course[t] == 0)
                course[t] = i;
            Union(i, findFather(course[t]));
        }
    }
    for(int i = 1; i <= n; i++)
        isRoot[findFather(i)]++;
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0)
            cnt++;
    }
    printf("%d\n", cnt);
    sort(isRoot.begin(), isRoot.end(), cmp1);
    for(int i = 0; i < cnt; i++) {
        printf("%d", isRoot[i]);
        if(i != cnt - 1) printf(" ");
    }
    return 0;
}



肿瘤诊断
#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int x, y, z;
};
int m, n, l, t;
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int arr[1300][130][80];
bool visit[1300][130][80];
bool judge(int x, int y, int z) {
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
    if(arr[x][y][z] == 0 || visit[x][y][z] == true) return false;
    return true;
}
int bfs(int x, int y, int z) {
    int cnt = 0;
    node temp;
    temp.x = x, temp.y = y, temp.z = z;
    queue<node> q;
    q.push(temp);
    visit[x][y][z] = true;
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        cnt++;
        for(int i = 0; i < 6; i++) {
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            int tz = top.z + Z[i];
            if(judge(tx, ty, tz)) {
                visit[tx][ty][tz] = true;
                temp.x = tx, temp.y = ty, temp.z = tz;
                q.push(temp);
            }
        }
    }
    if(cnt >= t)
        return cnt;
    else
        return 0;
    
}
int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                scanf("%d", &arr[j][k][i]);
    int ans = 0;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(arr[j][k][i] == 1 && visit[j][k][i] == false)
                    ans += bfs(j, k, i);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
垃圾箱分布
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int inf = 999999999;
int n, m, k, ds, station;
int e[1020][1020], dis[1020];
bool visit[1020];
int main() {
    fill(e[0], e[0] + 1020 * 1020, inf);
    fill(dis, dis + 1020, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    for(int i = 0; i < k; i++) {
        int tempdis;
        string s, t;
        cin >> s >> t >> tempdis;
        int a, b;
        if(s[0] == 'G') {
            s = s.substr(1);
            a = n + stoi(s);
        } else {
            a = stoi(s);
        }
        if(t[0] == 'G') {
            t = t.substr(1);
            b = n + stoi(t);
        } else {
            b = stoi(t);
        }
        e[a][b] = tempdis;
        e[b][a] = tempdis;
    }
    int ansid = -1;
    double ansdis = -1, ansaver = inf;
    for(int index = n + 1; index <= n + m; index++) {
        double mindis = inf, aver = 0;
        fill(dis, dis + 1020, inf);
        fill(visit, visit + 1020, false);
        dis[index] = 0;
        for(int i = 0; i < n + m; i++) {
            int u = -1, minn = inf;
            for(int j = 1; j <= n + m; j++) {
                if(visit[j] == false && dis[j] < minn) {
                    u = j;
                    minn = dis[j];
                }
            }
            if(u == -1) break;
            visit[u] = true;
            for(int v = 1; v <= n + m; v++) {
                if(visit[v] == false && dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
        for(int i = 1; i <= n; i++) {
            if(dis[i] > ds) {
                mindis = -1;
                break;
            }
            if(dis[i] < mindis) mindis = dis[i];
            aver += 1.0 * dis[i];
        }
        if(mindis == -1) continue;
        aver = aver / n;
        if(mindis > ansdis) {
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        } else if(mindis == ansdis && aver < ansaver) {
            ansid = index;
            ansaver = aver;
        }
    }
    if(ansid == -1)
        printf("No Solution");
    else {
        printf("G%d\n", ansid - n);
        printf("%.1f %.1f", ansdis, ansaver);
    }
    return 0;
}

迎风一刀斩
#include <bits/stdc++.h>
using namespace std;
int n, k1, k2, SLength, LLength, SWidth, LWidth, res, dif, D1, D2, a, b;
vector<pair<int, int>> A(10), B(10);
void deal(const vector<pair<int, int>> &C, const int &l) {
    res = SLength = LLength = SWidth = LWidth = 0;
    for (int i = 0; i < l; i++) {
        if (C[i].first == C[(i + 1) % l].first) {
            res++;
            dif = abs(C[i].second - C[(i + 1) % l].second);
            if (dif > LLength) SLength = LLength, LLength = dif;
            else SLength = dif;
        } else if (C[i].second == C[(i + 1) % l].second) {
            res++;
            dif = abs(C[i].first - C[(i + 1) % l].first);
            if (dif > LWidth) SWidth = LWidth, LWidth = dif;
            else SWidth = dif;
        }
    }
}
string judge() {
    if (k1 > 5 || k2 > 5) return "NO";
    if (k1 == 4 && k2 == 4) {
        deal(A, k1);
        if (res == 4) {
            D1 = LLength, D2 = LWidth;
            deal(B, k2);
            if (res != 4) return "NO";
            if (D1 == LLength || D2 == LWidth || D2 == LLength || D1 == LWidth) return "YES";
        } else if (res == 3) {
            if (SWidth == 0) D1 = LWidth, D2 = LLength - SLength;
            else  D1 = LLength, D2 = LWidth - SWidth;
            deal(B, k2);
            if (res != 3) return "NO";
            if (SWidth == 0 && D1 == LWidth && D2 == LLength - SLength) return "YES";
            else if (SLength == 0 && D1 == LLength && D2 == LWidth - SWidth) return "YES";

        }
        return "NO";
    }
    if (k2 > k1) swap(k1, k2), swap(A, B);
    deal(A, k1);
    if (res != k1 - 1) return "NO";
    D1 = LLength - SLength, D2 = LWidth - SWidth;
    deal(B, k2);
    if (res != k2 - 1) return "NO";
    if ((D1 == LLength  && D2 == LWidth) || (D2 == LLength && D1 == LWidth)) return "YES";
    return "NO";
}
int main() {
    cin >> n;
    while (n--) {
        cin >> k1;
        for (int i = 0; i < k1; i++) cin >> A[i].first >> A[i].second;
        cin >> k2;
        for (int i = 0; i < k2; i++) cin >> B[i].first >> B[i].second;
        cout << judge() << '\n';
    }
    return 0;
}

天梯地图
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 999999999;
int dis[510], Time[510], e[510][510], w[510][510], Timepre[510], weight[510];
bool visit[510];
vector<int> Timepath, dispath, temppath, dispre[510];
int st, fin, minnode = inf;
void dfsTimepath(int v) {
    Timepath.push_back(v);
    if(v == st) {
        return ;
    }
    dfsTimepath(Timepre[v]);
}
void dfsdispath(int v) {
    temppath.push_back(v);
    if(v == st) {
        if(temppath.size() < minnode) {
            minnode = temppath.size();
            dispath = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < dispre[v].size(); i++) {
        dfsdispath(dispre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag, len, t;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if(flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d %d", &st, &fin);
    Time[st] = 0;
    for(int i = 0; i < n; i++) {
        Timepre[i] = i;
    }
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && Time[j] < minn) {
                u = j;
                minn = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && w[u][v] != inf) {
                if(w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    Timepre[v] = u;
                    weight[v] = weight[u] + e[u][v];
                } else if(w[u][v] + Time[u] == Time[v] && weight[v] > weight[u] + e[u][v]) {
                    weight[v] = weight[u] + e[u][v];
                    Timepre[v] = u;
                }
            }
        }
    }
    dfsTimepath(fin);
    fill(visit, visit + 510, false);
    dis[st] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && minn > dis[j]) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    dispre[v].clear();
                    dispre[v].push_back(u);
                } else if(e[u][v] + dis[u] == dis[v]) {
                    dispre[v].push_back(u);
                }
            }
        }
    }
    dfsdispath(fin);
    printf("Time = %d", Time[fin]);
    if(dispath == Timepath) {
        printf("; Distance = %d: ", dis[fin]);
    } else {
        printf(": ");
        for(int i = Timepath.size() - 1; i >= 0; i--) {
            printf("%d", Timepath[i]);
            if(i != 0) printf(" => ");
        }
        printf("\n");
        printf("Distance = %d: ", dis[fin]);
    }
    for(int i = dispath.size() - 1; i >= 0; i--) {
        printf("%d", dispath[i]);
        if(i != 0) printf(" => ");
    }
    return 0;
}
喊山
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v(10010);
int book[10010];
int main() {
    int n, m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d", &a);
        queue<int> q;
        fill(book, book + 10010, 0);
        q.push(a);
        int level[10010];
        int ans = 10010, maxlevel = 0;
        book[a] = 1;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            if(level[top] > maxlevel) {
                maxlevel = level[top];
                ans = 10010;
            }
            if(top != a)
                ans = min(ans, top);
            for(int j = 0; j < v[top].size(); j++) {
                if(book[v[top][j]] == 0) {
                    q.push(v[top][j]);
                    book[v[top][j]] = 1;
                    level[v[top][j]] = level[top] + 1;
                }
            }
        }
        if(ans != 10010) printf("%d\n", ans);
        else printf("0\n");
    }
    return 0;
}

长城
#include <bits/stdc++.h>
using namespace std;
long long n, top, ans, X[100005], Y[100005], tower[100005], vis[100005];
bool isConcave (const int &l, const int &mid, const int &r) {
    return (Y[r] - Y[l]) * (X[mid] - X[l]) >= (Y[mid] - Y[l]) * (X[r] - X[l]);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        if (top) {
            while (top > 1 && isConcave(i, tower[top], tower[top - 1])) top--;
            if (top != 1 && !vis[tower[top]]) vis[tower[top]] = 1, ans++;
        }
        tower[++top] = i;
    }
    cout << ans;
    return 0;
}

 是否完全二叉搜索树

#include <cstdio>
using namespace std;
int tree[1<<20];
int num;
void BST(int a) {
    if(tree[a] == 0)
        tree[a] = num;
    else if(tree[a] < num)
        BST(a<<1);
    else
        BST(a<<1|1);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        BST(1);
    }
    bool flag = true;
        for(int cnt = 1, k = 1; cnt <= n; k++) {
            if(tree[k] == 0)
                flag = false;
            else {
                printf("%d", tree[k]);
                if(cnt++ != n) printf(" ");
            }
        }
    if(flag) printf("\nYES");
    else printf("\nNO");
    return 0;
}

直捣黄龙

#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, dis;
    bool friend operator < (const node &a, const node &b) {
        return a.dis > b.dis;
    }
};
int n, k, s, t, cnt, d, num[205], Num[205], path[205], Dis[205], vis[205], sum[205], liberation[205];
map<string, int> ntoi;
map<int, string> iton;
vector<pair<int, int>> E[205];
vector<int> ans;
string S, T, u, v;
void Dijskra() {
    fill(Dis, Dis + 205, 1e9);
    Dis[s] = 0;
    sum[s] = 1;
    priority_queue<node> Q;
    Q.push(node{s, 0});
    while (!Q.empty()) {
        int Now = Q.top().id, D = Q.top().dis;
        Q.pop();
        if (vis[Now]) continue;
        vis[Now] = 1;
        for (auto it : E[Now]) {
            int V = it.first, DIS = it.second;
            if (Dis[V] > D + DIS) {
                Num[V] = Num[Now] + num[V];
                sum[V] = sum[Now];
                liberation[V] = liberation[Now] + 1;
                Dis[V] = D + DIS;
                Q.push(node{V, Dis[V]});
                path[V] = Now;
            } else if (Dis[V] == D + DIS) {
                sum[V] += sum[Now];
                if (liberation[V] < liberation[Now] + 1) {
                    liberation[V] = liberation[Now] + 1;
                    Num[V] = Num[Now] + num[V];
                    Q.push(node{V, Dis[V]});
                    path[V] = Now;
                } else if (liberation[V] == liberation[Now] + 1) {
                    if (Num[V] < Num[Now] + num[V]) {
                        Num[V] = Num[Now] + num[V];
                        Q.push(node{V, Dis[V]});
                        path[V] = Now;
                    }
                }
                
            }
        }
    }
}
int main() {
    cin >> n >> k >> S >> T;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> d;
        ntoi[u] = ++cnt;
        iton[cnt] = u;
        num[cnt] = d;
    }
    ntoi[S] = 0, iton[0] = S, t = ntoi[T];
    for (int i = 0; i < k; i++) {
        cin >> u >> v >> d;
        E[ntoi[u]].push_back({ntoi[v], d});
        E[ntoi[v]].push_back({ntoi[u], d});
    }
    Dijskra();
    d = t;
    while(d) {
        ans.push_back(d);
        d = path[d];
    }
    cout << iton[0];
    for (int i = ans.size() - 1; i >= 0; i--) cout << "->" << iton[ans[i]];
    cout << '\n' << sum[t] << ' ' << Dis[t] << ' ' << Num[t] << '\n';
    return 0;
}


水果忍者
#include <bits/stdc++.h>
using namespace std;
struct node {
    double x, y1, y2;
    bool friend operator < (const node &a, const node &b) {
        return a.x < b.x;
    }
}Fruit[10000];
int n, hx, hy;
double kmax, kmin, tkmax, tkmin;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> Fruit[i].x >> Fruit[i].y1 >> Fruit[i].y2;
    sort(Fruit, Fruit + n);
    for (int i = 0, j; i < n; i++) {
        kmax = 1e9, kmin = -1e9;
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            if (i < j) {
                tkmax = (Fruit[j].y1 - Fruit[i].y2) / (Fruit[j].x - Fruit[i].x);
                tkmin = (Fruit[j].y2 - Fruit[i].y2) / (Fruit[j].x - Fruit[i].x);
            } else {
                tkmax = (Fruit[i].y2 - Fruit[j].y2) / (Fruit[i].x - Fruit[j].x);
                tkmin = (Fruit[i].y2 - Fruit[j].y1) / (Fruit[i].x - Fruit[j].x);
            }
            if (tkmax < kmin || tkmin > kmax) break;
            if (tkmax < kmax) {
                kmax = tkmax;
                hx = Fruit[j].x;
                hy = Fruit[j].y1;
            }
            kmin = max(kmin, tkmin);
        }
        if (j == n) {
            cout << hx << ' ' << hy << ' ' << (int)Fruit[i].x << ' ' << (int)Fruit[i].y2;
            break;
        }
    }
    return 0;
}

非常弹的球


#include <cstdio>
int main() {
    double w, p, v2, s = 0;
    scanf("%lf%lf", &w, &p);
    v2 = 2 * 1000 * 100 / w;
    while (v2 > 0.000001) {
        s += v2 / 9.8;
        v2 *= (100 - p) * 0.01;
    }
    printf("%.3f", s);
    return 0;
}
周游世界

#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> v(10000);
int line[10000][10000], visit[10000];
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]][a[i]] != preLine) cnt++;
        preLine = line[a[i-1]][a[i]];
    }
    return cnt;
}
void dfs(int node, int end, int cnt, int &minCnt, int &minTransfer) {
    if (node == end && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end) return;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], end, cnt + 1, minCnt, minTransfer);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre][temp] = line[temp][pre] = i + 1;
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        int minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(a);
        visit[a] = 1;
        dfs(a, b, 0, minCnt, minTransfer);
        visit[a] = 0;
        if (minCnt == 99999) {
            printf("Sorry, no line is available.\n");
            continue;
        }
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = a;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]][path[j]] != preLine) {
                if (preLine != 0) printf("Go by the line of company #%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]][path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Go by the line of company #%d from %04d to %04d.\n", preLine, preTransfer, b);
    }
    return 0;
}

 球队“食物链”

#include <cstdio>
using namespace std;
int n, flag = 0;
int result[21];
bool v[21][21], visit[21];
void dfs(int index, int num) {
    if (flag == 1) return;
    result[index] = num;
    if (index == n && v[num][1] == true) {
        flag = 1;
        return;
    }
    if (index == n) return;
    bool cut = false;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && v[i][1] == true)
            cut = true;
    }
    if (cut == false) return;
    visit[num] = true;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && v[num][i] == true)
            dfs(index + 1, i);
    }
    visit[num] = false;
}
int main() {
    scanf("%d", &n);
    char s[21];
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            if (s[j] == 'W') v[i][j] = true;
            if (s[j] == 'L') v[j][i] = true;
        }
    }
    dfs(1, 1);
    if (flag == 1) {
        for (int i = 1; i <= n; i++)
            printf("%s%d", i == 1 ? "" : " ", result[i]);
    } else {
        printf("No Solution");
    }
    return 0;
}

二叉搜索树的结构

#include <bits/stdc++.h>
using namespace std;
struct node {
    int num, lchild, rchild, parent, level;
    node() {
        lchild = rchild = parent = -1;
    }
}Tree[128];
int n, m, a, b, in, cnt, root = 1, f;
map<int, int> Find;
string t;
void insert(int x) {
    int now = root;
    while(Tree[now].num != x) {
        if (x < Tree[now].num) {
            if (Tree[now].lchild == -1) {
                Tree[cnt].num = x;
                Tree[cnt].level = Tree[now].level + 1;
                Tree[cnt].parent = now;
                Tree[now].lchild = cnt;
            }
            now = Tree[now].lchild;
        } else {
            if (Tree[now].rchild == -1) {
                Tree[cnt].num = x;
                Tree[cnt].level = Tree[now].level + 1;
                Tree[cnt].parent = now;
                Tree[now].rchild = cnt;
            }
            now = Tree[now].rchild;
        }
    }
}
int main() {
    cin >> n >> in;
    Tree[++cnt].num = in;
    Find[in] = cnt;
    for (int i = 1; i < n; i++) {
        cin >> in;
        Find[in] = ++cnt;
        insert(in);
    }
    cin >> m;
    while (m--) {
        f = 0;
        cin >> a >> t;
        if (t == "is") {
            cin >> t >> t;
            if (t == "root") {
                if (Find[a] == root) f = 1;
            } else if (t == "parent") {
                cin >> t >> b;
                if (Tree[Find[b]].parent == Find[a]) f = 1;
            } else if (t == "left") {
                cin >> t >> t >> b;
                if (Tree[Find[b]].lchild == Find[a]) f = 1;
            } else {
                cin >> t >> t >> b;
                if (Tree[Find[b]].rchild == Find[a]) f = 1;
            }
        } else {
            cin >> b >> t >> t;
            if (t == "siblings") {
                if (Find[a] && Find[b] && Tree[Find[a]].parent == Tree[Find[b]].parent) f = 1;
            } else {
                cin >> t >> t >> t;
                if (Find[a] && Find[b] && Tree[Find[a]].level == Tree[Find[b]].level) f = 1;
            }
        }
        cout << (f ? "Yes" : "No") << '\n';
    }
    return 0;
}
2022
插松枝
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    queue<int>q;
    stack<int>st;
    
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        q.push(x);
    }
    
    while(q.size() || st.size())
    {
        int cnt = 0, last = 100;
        bool first = true;
        while(cnt < k)
        {
            if(st.size() && st.top() <= last)
            {
                if(first)
                {
                    first = false;
                    cout << st.top();
                }
                else cout << ' ' << st.top();
                last = st.top();
                st.pop();
                cnt ++ ;
            }
            
            else if(q.size())
            {
                int t = q.front();
                if(t <= last)
                {
                    if(first) 
                    {
                        cout << t;
                        first = false;
                    }
                    else cout << ' ' << t;
                    last = t;
                    q.pop();
                    cnt ++ ;
                }
                else if(st.size() < m)
                {
                    st.push(t);
                    q.pop();
                }
                else break;
            }
            else break;
        }
        cout << endl;
    }
    return 0;
}

龙龙送外卖

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int d[N];
int fa[N];
int sum, mx;

int dfs(int u)
{
    if(fa[u] == -1 || d[u]) return d[u];  // 到根节点了或u被搜过了
    sum ++ ;  // 边数加一，因为没有搜过
    d[u] = dfs(fa[u]) + 1;
    return d[u];
}

int main()
{
    cin >> n >> m;
    
    for(int i = 1; i <= n; i ++ ) cin >> fa[i];
    
    while(m -- )
    {
        int x;
        cin >> x;
        mx = max(mx, dfs(x));
        cout << sum * 2 - mx << endl;
    }
    return 0;
}
大众情人

#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n;
char sex[N];
int d[N][N];

int main()
{
    cin >> n;
    memset(d, 0x3f, sizeof d);
    for(int i = 1; i <= n; i ++ ) d[i][i] = 0;
    
    for(int i = 1; i <= n; i ++ )
    {
        cin >> sex[i];
        int k;
        cin >> k;
        while(k -- )
        {
            int id, dist;
            scanf("%d:%d", &id, &dist);
            d[i][id] = dist;
        }
    }
    
    for(int k = 1; k <= n; k ++ )
        for(int i = 1; i <= n; i ++ )
            for(int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                
                
    for(auto c: string("FM"))
    {
        int mn = 0x3f3f3f3f;
        for(int i = 1; i <= n; i ++ )
            if(sex[i] == c)
            {
                int mx = 0;
                for(int j = 1; j <= n; j ++ )
                    if(sex[i] != sex[j])
                        mx = max(mx, d[j][i]);  // 最无感的距离
                
                mn = min(mn, mx);  // 1/d最大，所以d要最小
            }
            
        bool first = true;
        for(int i = 1; i <= n; i ++ )
            if(sex[i] == c)
            {
                int mx = 0;
                for(int j = 1; j <= n; j ++ )
                    if(sex[i] != sex[j])
                        mx = max(mx, d[j][i]);
                
                if(mx == mn)
                {
                    if(first)
                    {
                        cout << i;
                        first = false;
                    }
                    else cout << ' ' << i;
                }
            }
            
        cout << endl;
    
    }
    return 0;
}

谁能进图书馆

#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,p,q,cnt=0;scanf("%d%d%d%d",&x,&y,&p,&q);
    if(p>=x) cnt++;
    if(q>=x) cnt++;
    if(cnt==2) printf("%d-Y %d-Y\nhuan ying ru guan",p,q);
    else if(cnt==0) printf("%d-N %d-N\nzhang da zai lai ba",p,q);
    else{
        int older=(p>=x)?p:q;
        if(older>=y) printf("%d-Y %d-Y\nqing %d zhao gu hao %d",p,q,(older==p)?1:2,(older==p)?2:1);
        else if(p>=x) printf("%d-Y %d-N\n1: huan ying ru guan",p,q);
        else printf("%d-N %d-Y\n2: huan ying ru guan",p,q);
    }
}

试试手气
#include<bits/stdc++.h>
using namespace std;
int A[10],vis[10][10];
int main(){
    for(int i=0;i<6;++i) cin>>A[i],vis[i][A[i]]=1;
    int n;cin>>n;
    for(int k=1;k<=n;++k)
        for(int i=0;i<6;++i)
            for(int j=6;j>0;--j)
                if(!vis[i][j]) {A[i]=j,vis[i][j]=1;break;}
    cout<<A[0];
    for(int i=1;i<6;++i) cout<<' '<<A[i];
}


斯德哥尔摩火车上的题

#include<bits/stdc++.h>
using namespace std;
string Solve(string str){
    string ans="";int len=str.length();
    for(int i=1;i<len;++i) 
        if(str[i]%2==str[i-1]%2) ans+=max(str[i],str[i-1]);
    return ans;
}
int main(){
    string str1,str2;cin>>str1>>str2;
    string ans1=Solve(str1),ans2=Solve(str2);
    if(ans1==ans2) cout<<ans1;
    else cout<<ans1<<"\n"<<ans2;
}

机工士姆斯塔迪奥
#include<bits/stdc++.h>
#define close ios::sync_with_stdio(false)
const int maxn=1e5+100;
int hor[maxn],ver[maxn];
using namespace std;
int main(){
    close;int N,M,Q;cin>>N>>M>>Q;
    for(int i=0;i<Q;++i){
        int op,x;cin>>op>>x;
        if(op==0) hor[x]=1;
        else ver[x]=1;
    }
    int ans=0;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
            if(!hor[i] && !ver[j]) ans++;
    cout<<ans;
}
老板的作息表
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
struct Interval{
    int sta,fin;
    bool operator <(const Interval&a)const{
        return fin<a.fin;
    }
}intv[maxn];
void Print(int s,int f){
    printf("%02d:%02d:%02d - %02d:%02d:%02d\n",s/3600,s%3600/60,s%3600%60,f/3600,f%3600/60,f%3600%60);
}
int main(){
    int N,h1,h2,m1,m2,s1,s2;scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        intv[i].sta=3600*h1+60*m1+s1;
        intv[i].fin=3600*h2+60*m2+s2;
    }
    sort(intv,intv+N);int last=0;
    for(int i=0;i<N;++i){
        if(intv[i].sta!=last) Print(last,intv[i].sta);
        last=intv[i].fin;
    }
    if(last!=24*60*60-1) Print(last,24*60*60-1);
}   

千手观音
#include<bits/stdc++.h>
#define close ios::sync_with_stdio(false)
using namespace std;
int tot=0;
unordered_map<string,int> mp;
const int maxn=1e4+100;
vector<int> rec[maxn];
string name[maxn];
int id[maxn],deg[maxn];
vector<string> Solve(string s){
    string cur="";
    vector<string> ans;
    for(char u:s){
        if(u!='.') cur+=u;
        else{
            ans.push_back(cur);
            if(mp.count(cur)==0) mp[cur]=++tot,name[tot]=cur;
            cur="";
        }
    }
    ans.push_back(cur);
    if(mp.count(cur)==0) mp[cur]=++tot,name[tot]=cur;
    return ans;
}

int main(){
    close;int N;cin>>N;
    string str;cin>>str;
    vector<string> now1=Solve(str);
    for(int i=2;i<=N;++i){
        cin>>str;
        vector<string> now2=Solve(str);
        int s1=now1.size(),s2=now2.size();
        if(s1==s2){
            for(int i=0;i<s1;++i){
                if(now1[i]!=now2[i]){
                    rec[mp[now1[i]]].push_back(mp[now2[i]]);
                    deg[mp[now2[i]]]++;
                    break;
                }
            }
        }
        now1=move(now2);
    }
    vector<string> ans;
    priority_queue<string,vector<string>,greater<string>> Q;
    for (int i=1;i<=tot;i++) if (deg[i]==0) Q.push(name[i]);
    while(!Q.empty()) {
        string cur=Q.top();Q.pop();
        int root=mp[cur];
        ans.push_back(cur);
        for(int u:rec[root]){
            deg[u]--;
            if(deg[u]==0) Q.push(name[u]);
        }
    }
    cout<<ans[0];
    for(int i=1;i<ans.size();++i) cout<<'.'<<ans[i];
}

关于深度优先搜索和逆序对的题应该不会很难吧这件事
#include<bits/stdc++.h>
#define close ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const int maxn=3e5+100;
const int mod=1e9+7;
vector<int> v[maxn];
vector<int> dep[maxn];
ll f[maxn],chd[maxn],ans=0,tot=1,C;
int tree[maxn],n,r,maxnum=0;
int lowbit(int x){return x&(-x);}
void update(int loc,int d){
    while(loc<=n){
        tree[loc]+=d;
        loc+=lowbit(loc);
    }
}
int query(int loc){
    int ans=0;
    while(loc){
        ans+=tree[loc];
        loc-=lowbit(loc);
    }
    return ans;
}
int DFS(int root,int fa,int d){
    dep[d].push_back(root);
    if(d>maxnum) maxnum=d;
    int x=query(root),cnt=0,sum=0;
    for(int u:v[root]){
        if(u==fa) continue;
        cnt++;sum+=DFS(u,root,d+1);
    }
    ans=(ans+(query(root)-x)*2%mod)%mod;
    update(root,1);
    if(cnt==0) {chd[root]=0;return 1;}
    else{
        chd[root]=sum;
        tot=tot*f[cnt]%mod;
        return 1+sum;
    }
}
ll qpow(ll base,ll x){
    ll ans=1;
    while(x){if(x&1) ans=ans*base%mod;base=base*base%mod;x>>=1;}
    return ans;
}
int main(){
    close;cin>>n>>r;
    f[0]=1;C=qpow(2,mod-2);
    for(int i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
    for(int i=1;i<n;++i){
        int x,y;cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(r,-1,0);
    for(int i=1;i<=maxnum;++i){
        ll cur_sum=0,cur_cnt=dep[i].size();
        for(int id:dep[i]) cur_sum+=chd[id];
        ans=((ans+cur_sum*(cur_cnt-1)%mod)%mod+cur_cnt*(cur_cnt-1)%mod*C%mod)%mod;
    }
    cout<<ans*tot%mod*C%mod;
}

什么是机器学习
#include<bits/stdc++.h>
using namespace std;
int a, b;
int main() {
    cin >> a >> b, a += b;
    cout << a - 16 << endl << a - 3 << endl << a - 1 << endl << a;
	return 0;
}

程序员买包子
#include<bits/stdc++.h>
using namespace std;
int n, m, k;
string x;
int main() {
    cin >> n >> x >> m >> k;
    if(k == n) cout << "mei you mai " << x << " de";
    else if(k == m) cout << "kan dao le mai " << x << " de";
    else cout << "wang le zhao mai " << x << " de";
	return 0;
}

进化论
#include<bits/stdc++.h>
using namespace std;
int n, a, b, c;
int main() {
    cin >> n;
    while(n--) {
        cin >> a >> b >> c;
        if(c == a * b) puts("Lv Yan");
        else if (c == a + b) puts("Tu Dou");
        else puts("zhe du shi sha ya!");
    }
	return 0;
}

猜帽子游戏
#include<bits/stdc++.h>
using namespace std;
int n, k, x;
int main() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    while(k--) {
        int cnt = 0, wa = 0;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            if(!x) continue;
            ++cnt;
            if(x != a[i]) ++wa;
        }
        if(cnt && !wa) puts("Da Jiang!!!");
        else puts("Ai Ya");
    }
	return 0;
}

剪切粘贴

#include<bits/stdc++.h>
using namespace std;
string s, s1, s2, s3;
int n, a, b;
int main() {
	cin >> s >> n;
	while(n--) {
		cin >> a >> b >> s1 >> s2;
		s3 = s.substr(a - 1, b - a + 1);
		s.erase(s.begin() + a - 1, s.begin() + b);
		int len = s1.length();
		s1 += s2;
        int pos = s.find(s1);
		if(pos != s.npos) s.insert(pos + len, s3);
		else s.insert(s.length(), s3);
	}
	cout << s;
	return 0;
}
分寝室

#include<bits/stdc++.h>
using namespace std;
int n0, n1, n, flag0, flag1, res = INT_MAX;
vector<int> N0, N1;
int main() {
	cin >> n0 >> n1 >> n;
	for(int i = 2; i <= min(n0, n1); ++i) {
		if(!(n0 % i)) N0.emplace_back(i);
		if(!(n1 % i)) N1.emplace_back(i);
	}
	for(int i = 0; i < N0.size(); ++i) {
		for(int j = 0; j < N1.size(); ++j) {
			if(n0 / N0[i] + n1 / N1[j] == n && fabs(N0[i] - N1[j]) < res) {
				res = fabs(N0[i] - N1[j]), flag0 = n0 / N0[i], flag1 = n1 / N1[j];
			}
		}
	}
	if(res == INT_MAX) puts("No Solution");
	else cout << flag0 << " " << flag1;
	return 0;
}
堆宝塔
#include<bits/stdc++.h>
using namespace std;
int n, c, cnt, maxx;
stack<int> a, b;
int main() {
	cin >> n >> c;
	a.emplace(c);
	for(int i = 1; i < n; ++i) {
		cin >> c;
		if(c < a.top()) a.emplace(c);
		else if(b.empty() || c > b.top()) b.emplace(c);
		else {
			++cnt, maxx = max(maxx, (int)a.size());
			while(!a.empty()) a.pop();
			while(!b.empty() && b.top() > c) a.emplace(b.top()), b.pop();
			a.emplace(c);
		}
	}
	++cnt, maxx = max(maxx, (int)a.size());
	if(!b.empty()) ++cnt, maxx = max(maxx, (int)b.size());
	cout << cnt << " " << maxx;
	return 0;
}
天梯赛的赛场安排
#include<bits/stdc++.h>
using namespace std;
int n, c, res, cnt, a[5005], x;
string s;
priority_queue<int> Q;
int main() {
	cin >> n >> c;
	while(n--) {
		cin >> s >> x;
		cout << s << " " << ceil(1.0 * x / c) << endl;
		res += (x / c);
		if(x % c) Q.emplace(x % c);
	}
	while(!Q.empty()) {
		x = Q.top(), Q.pop();
		bool flag = true;
		for(int i = 0; i < cnt; ++i) {
			if(a[i] + x <= c) {
				a[i] += x, flag = false;
				break;
			}
		}
		if(flag) a[cnt++] = x;
	}
	cout << cnt + res;
	return 0;
}
锦标赛
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
int k, x;
int res[N], id[N][20], tr[N][20];
bool flag = true;
int main() {
	cin >> k;
	for(int j = 1; j <= k; ++j) {
		for(int i = 1; i <= (1 << (k - j)); ++i) {
			cin >> x;
			if(j == 1) res[i * 2] = x, id[i][1] = i * 2 - 1, tr[i][1] = x;
			else if(tr[i * 2 - 1][j - 1] > x && tr[i * 2][j - 1] > x) flag = false;
			else {
				if(tr[i * 2 - 1][j - 1] <= x) res[id[i * 2 - 1][j - 1]] = x, id[i][j] = id[i * 2][j - 1];
				else res[id[i * 2][j - 1]] = x, id[i][j] = id[i * 2 - 1][j - 1];
				tr[i][j] = max({x, tr[i * 2 - 1][j - 1], tr[i * 2][j - 1]});
			}
		}
	}
	cin >> x;
	if(x < tr[1][k]) flag = false;
	else res[id[1][k]] = x;
	if(!flag) puts("No Solution");
	else for(int i = 1; i <= (1 << k); ++i) cout << res[i] << " \n"[i == (1 << k)];
	return 0;
}
寻宝图
#include<bits/stdc++.h>
using namespace std;
int n, m, cnt1, cnt2;
bool flag;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, 1, -1, 0};
int main() {
	cin >> n >> m, getchar();
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			a[i][j] = (getchar() - '0');
		}
		getchar();
	}
	function<void(int, int)> dfs = [&](int x, int y) {
		if(a[x][y] != 1) flag = true;
		a[x][y] = 0;
		for(int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny]) dfs(nx, ny);
		}
	};
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(a[i][j]) {
				++cnt1;
				flag = false;
				dfs(i, j);
				if(flag) ++cnt2;
			}
		}
	}
	cout << cnt1 << " " << cnt2;
	return 0;
}

