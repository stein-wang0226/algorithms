//二分答案--整数
//最小值最大化，（左闭右开）   （求得最大值仍满足合法区间）
//希望答案尽可能大，所以我们需要确保左区间L点符合题目条件（最小），至于R是否符合条件是不确定的，最终l==r(最后一个符合条件的位置)
//所以ok (mid)  ->   l=mid ->l必为合法  
int l = min_ans, r = max_ans;
while (l < r) {
	int mid = (l + r + 1) / 2;   //   偏右  +1避免 r == l + 1 时mid一直等于l，从而死循环
	if (ok(mid))	//符合条件返回True
		l = mid;
	else
		r = mid - 1;
}

//最大值最小化   相反
int l = min_ans, r = max_ans;
while (l < r) {
	int mid = (l + r) / 2;//偏左   避免死循环
	if (ok(mid))	//符合条件返回True
		r = mid;
	else
		l = mid + 1;
}


lower_bound( begin,end,num)：//从数组的begin位置到end-1位置二分查找第一个*大于或等于*num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
//对递增序列取最小值（合法）的最大值
upper_bound( begin,end,num)：//从数组的begin位置到end-1位置二分查找第一个*大于*num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
//对递增序列取最大值（合法）的最小值



// 浮点数二分模板

bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}














//不单调方程的根（e.g二次函数），三分
val()---> 求函数值   
double solve(double l,double r){
    double eps = 1e-7;
    while(l + eps < r){
        double lmid = l + (r-l)/3,rmid = r - (r-l)/3;
        if(val(lmid) < val(rmid)){
            r = rmid;
        }else{
            l = lmid;
        }
    }
    return val(l);
