## 线段树+区间和并实现 LICS

区别  ：pushup函数实现区间和并

update几乎不变

query函数 除了将求和--->max ，还要注意截取区间：

ans = max(ans, min(mid - L + 1, segtree[rt << 1].rmax) +

​           min(segtree[rt << 1 | 1].lmax, R - mid));

