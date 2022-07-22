#include<bits/stdc++.h>
#include<windows.h>
//运行一遍另外三个程序exe，将数据生成器生成的数据放在data.txt中，标程与暴力分别读入数据，并进行比较，若不同，则直接跳出，此时t未减到0，故最后判断出错误，因为“fc”函数，会将两个程序的输出打印出来。 
using namespace std;
int main(){
	int t=500;
	while(t--){//一直循环 
		system("data.exe>data.in");//造数据的exe,传入data.in 
		system("1.exe<data.in>1.out");//程序1号 
		system("main.exe<data.in>2.out");//程序2号
		if(system("fc 1.out 2.out")){//fc是比较指令
			printf("error!!\n");
			system("pause");
		}
	}
	return 0;
}

