//二分答案
//最小值最大化，（左闭右开）   （求得最大值仍满足合法区间）
//希望答案尽可能大，所以我们需要确保左区间L点符合题目条件（最小），至于R是否符合条件是不确定的
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