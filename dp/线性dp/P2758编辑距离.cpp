//这也能dp
//设A和B是两个字符串。我们要用最少的字符操作次数，将字符串A转换为字符串B。这里所说的字符操作共有三种：1、删除一个字符；2、插入一个字符；3、将一个字符改为另一个字符；
//思路：每次只对末尾操作，求出dp【i-1】【j-1】与dp[i][j]关系
#include <bits/stdc++.h>
using namespace std;
char s1[2005], s2[2005];
int dp[2005][2005]; //dp[i][j]表示a前i个变为b前j个的最小次数
int Min(int a,int b,int c){
    return min(a,min(b,c));
}
int main()
{
    cin >> s1 >> s2;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 1; i <= len1; i++){ //长度为0都为i步
        dp[i][0] = i;
    }
    for (int i = 1; i <= len2; i++){
        dp[0][i] = i;
    }
    for (int i = 1; i <= len1; i++) { //a
        for(int j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];//末位相同则抵消 不变
            }
            else{
                dp[i][j]=Min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);//分别对应*末位删除，插入，替换
            }                               //删除：最后一位不同删除——>a前i-1位变为b前j位次数+1
        }                                   //插入****：a末尾添加与b[j]相同的字符——>a前i位变为**b前j-1位**（第j位与a插入的抵消）
    }                                        //替换：a第i位改  为b第j位，-->a前i-1变为b前j-1次数+1 ，末位抵消
cout<<dp[len1][len2]<<endl;

    return 0;
}
