kmp算法总结

https://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html

![img](https://www.ruanyifeng.com/blogimg/asset/201305/bg2013050107.png)

思想：每次从头匹配不止向后移动一位 ， 利用已知信息移动多位

一个基本事实是，当空格与D不匹配时，你其实知道前面六个字符是"ABCDAB"。KMP算法的想法是，设法利用这个已知信息，不要把"搜索位置"移回已经比较过的位置，继续把它向后移，这样就提高了效率。

![image-20240515225058848](C:\Users\86172\AppData\Roaming\Typora\typora-user-images\image-20240515225058848.png)

![image-20240515225117324](C:\Users\86172\AppData\Roaming\Typora\typora-user-images\image-20240515225117324.png)

![image-20240515225131793](C:\Users\86172\AppData\Roaming\Typora\typora-user-images\image-20240515225131793.png)