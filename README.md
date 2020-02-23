### 一.杭电OJ刷题分类
#### 主流算法
1.搜索（回溯） 2.DP（动态规划）3.贪心 4.图论（Dijkstra、最小生成树、网络流) 5.数论 6.计算几何 7.组合数学  8.模拟 9.数据结构 10.博弈论
#### 分治法 特点：子问题相互独立
##### 排序问题的分治法
B1066 简单分治法
B1067 根下2的近似解 (给定一个定义在[L, R]上的单调函数f(x), 求方程f(x)=0的根)
B1068 快排(数列接近有序) 此时最坏的时间复杂度为O(n^2), 原因是主元没有把当前区间划分为两个长度接近的子区间。 
##### 组合问题的分治法
最大子段和   棋盘覆盖    循环赛日程安排
##### 几何问题的分治法
最近点  凸包

#### DP
##### DP经典问题
c0001 数塔问题、c0002 最大连续子序列和、
1003、

#### 搜索





### 二. 算法笔记练习
##### 简单模拟 
B1001

##### 图形输出
B1036 （c实现和py实现）

##### 散列

#### 递归与分治
B1002 全排列
##### 记忆化技术

#### 贪心
##### GreedySelector经典问题 有：活动安排问题、最优装载、哈夫曼编码、单源最短路径、最小生成树、多机调度问题
B1020 月饼  B1040 区间不相交

#### 二分法
##### 简单二分法
B1066
##### 拓展二分法
B1067 根下2的近似解 (给定一个定义在[L, R]上的单调函数f(x), 求方程f(x)=0的根)
####快速排序（当序列中的元素接近有序时）
此时最坏的时间复杂度为O(n^2), 原因是主元没有把当前区间划分为两个长度接近的子区间。
B1068 快排(数列接近有序)

#### 动态链表   静态链表
静态链表的实现原理是hash，即通过建立一个结构体数组，并令数组的下标直接表示结点的地址. 前提：地址范围小
B1070 sharing(静态链表)     B1071 

#### 搜索
DFS   BFS
B1080 迷宫   B1081 背包问题（另一种解法DFS）
#### 回溯法(求解目标：找出解空间中满足约束条件的所有解)
##### 经典问题：  (八皇后,骑士走马,处理机调度)
回溯法简介.md
批处理作业调度  n后问题 0-1背包问题 最大团问题 图的m着色问题 旅行售货员问题  圆排列问题

#### 分支限界法(求解目标：找出满足约束条件的一个解，或是在满足约束条件的解中找出使某一目标函数值达到极大或极小的解，某种意义下的最优解)
##### 经典问题：
分支限界法简介.md

在手机上看视频介绍

### 三. 武理复试
#### 文件相关
文件的打开与关闭（fopen()\fclose()）、读取文件指定内容、修改文件指定内容、删除文件指定内容
文件更名与删除rename() remove()、文本文件与二进制文件、流式文件读写、内存映射文件
**文本模式**:  标准I/O函数都是面向文本的，用于处理字符和字符串
**二进制模式**  把数据存储在一个与程序具有相同表示方法的文件中 fread()  fwrite() 比如结构体数组
B0015 文件压缩     B0020 结构体数组存储到文件并读出

#### 进程与线程(linux为例)
进程简介

线程简介









