## 2-sat

### 一元限制

xi = true:  xi' ->xi

xi =false  xi->xi'

### 二元限制

1. u->v  : u则v 

   命题 和 逆否命题都要连**     u->v   v'->u'

2.  u or v =true     u' ->v    v'->u    (一个0另一个必为1)

3. u or v =false    u->u'    v->v'  (两个都为0)

4. u and v =false    u->v'   v->u'    (不能同时为1)

5. u and v = true     u' ->u      v'->v           (全1)

6. u==v   u->v  u'->v'  v->u    v'->u'   都要连

7. 7.u!=v     u->v'   u'->v  v->u'   v'->u

   

   判断有解：若 存在i 和 i'  在同一强连通分量 则 no,否则yes

## 求可行解：（对称）（成对出现）

若一个连通分量（a,b,c）则有另一个（a',b',c'） 要选都选

tarjan 缩点    按拓扑排序的反序输出 （每对选拓扑序靠后的（被指向为true）） u'->u

即对于 i   i'     如果id[i]>id[i']   取  i

