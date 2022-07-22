  #include<string.h>
  //最长子序列问题，思路：动态规划

//   若我们已对数组的前n个数即第一个，第二个   第n个  分别求出以第一个，第二个， 第n个结尾的最长连续递减序列 ，长度记为len[n] 
//    那么，当我们输入第n+1个数时我们只需依次往前比较，找到每个比第n+1位小的数 ，记做第X（X>N）位  ，
//   由于我们已经得到多个以第X位为结尾的最长连续递增子序列的长度（记做Y） 
//    所以  我们的以n+1位位结尾的最长连续递增子序列即为Y+1 
//  我们依次向前对比 前n项中能以n+1结尾的子序列长度  求得最大值记为len[n+1] 
//所以我们从第一位往后直到遍历结束   就可以得出以每一位为结尾的最长连续递增子序列的长度。 再求len的最大值即可 
 #include<stdio.h>
    #include<string.h>
   int main(){

 int n;
	int maxlenf();
	int len[20];	
	int temp,maxi;
 int a[20]={0};

scanf("%d",&a[0]);//input 
 	for(n=1;getchar()!='\n';n++)scanf("%d",&a[n]);//回车结束输入，n位个数 

//	printf("%d",n);








for(int i=0;i<n;i++)
			 {
			    len[i]=1;  /*初始每一个序列点作为最右端时的最大序列长度为1*/
			 }
			len[0]=1;
			 	 for(int i=1;i<n;i++)//求每项 结尾最大长度 
			       {if(a[i]==0)continue;
			         temp=1;
				    	for(int j=0;j<i;j++)
						{ /*与其前面的每一个进行比较*/
				    	  if(a[i]<a[j]&&a[j])
							  { /*如果数据比前面的某一个的值小*/
					        	if(len[j]+1>temp)
								{ /*若a[j]加入以a[i]结尾后长度最大，则更新aj结尾最大子序列长度*/
					          	temp=len[j]+1;
						        } 
						      }
					    }
			    		len[i]=temp;
					}
			  temp=0;
			  for(int i=1;i<n;i++)//比较每项求得最长值 
			  {
				    if(len[i]>temp)
					{
				      temp=len[i];
				      maxi=i;
				    }
			  }	
	printf("%d",temp);		  
}
