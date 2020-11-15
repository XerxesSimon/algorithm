# 基础算法

[toc]

通用思维：正向，逆行

计算机思维：有条理的  枚举 + 模拟

有条理：
- 减少变量
- 降维
- 先暴力，后优化
- 问题抽象话，转化为可以算法套用的

**贪心**，**二分**，枚举，模拟，搜索

### 时间复杂度
在竞赛中，我们认为计算机一秒能执行 $5\times 10^8$ 次计算，如果题目给出的时间限制为 $1s$，那么你选择的算法执行的计算次数最多应该在 $10^8$ 量级才有可能解决这个题目。

- $\mathcal{O}(1)$   
- $\mathcal{O}(\log n)$
  - 快速幂
- $\mathcal{O}(n)$          （$n$ 的数据范围一般是 $n \le 10^8$）
  - 数组中元素的查找，删除
- $\mathcal{O}(n \log n)$   （$n$ 的数据范围一般是 $n \le 10^6$）
  - 快排（贪心）
  - 质数筛思想
- $\mathcal{O}(n \sqrt{n})$  （$n$ 的数据范围一般是 $n \le 10^5$）
  - 判断一个数是否是质数
- $\mathcal{O}(n^2)$  （$n$ 的数据范围一般是 $n \le 5000$）
  - 冒泡排序
- $\mathcal{O}(n^3)$  （$n$ 的数据范围一般是 $n \le 300$）
  - 三层 for 循环（弗洛里得算法）
- $\mathcal{O}(2^n)$ （$n$ 的数据范围一般是 $n \le 25$）
  - 二进制枚举
- $\mathcal{O}(n!)$  （$n$ 的数据范围一般是 $n \le 11$）
  - 全排列

### 枚举
先假设答案，然后校验
- [百钱买百鸡](https://nanti.jisuanke.com/t/T1372)
- [鸡兔同笼](https://nanti.jisuanke.com/t/T1191)
- [滑雪课程设计](https://nanti.jisuanke.com/t/T1893)

### 模拟
- [青蛙爬井](https://nanti.jisuanke.com/t/T1376)
- [七桥问题](https://nanti.jisuanke.com/t/T1545)
- [汽水瓶](https://nanti.jisuanke.com/t/T1509)
- ![](https://oitiku.sh1a.qingstor.com/11.jpg)
- 日期问题
  - date 数组
  - dx，dy
- 表达式求值

### 二分
- 二分查找
- 二分答案
  - [跳石头](https://nanti.jisuanke.com/t/T2028)



### 贪心
- 会议安排
- 最小的名字
- [均分纸牌](https://nanti.jisuanke.com/t/T2158)

### 数组的使用
- 桶排序
- [校门外的树](https://nanti.jisuanke.com/t/T2128)
- 纸牌游戏
- 大数加法、减法、乘法
- 大数取模
- [懒人标记](https://blog.csdn.net/qq276291420/article/details/9347655)
- 前缀和
- 打表法——质数筛 （预处理）(极端：本地打表)
- 环上的问题

### 基础数学
- 最大公约数，最小公倍数及其相关性质
- 同余定理
- 质数问题
- 快速幂
- 进制转换
- 欧拉函数




### 小技巧
- 初始值  0x3f3f3f3f，最大值 0x3f3f3f3f
- while(~scanf())
- o(2) 优化
- scanf / printf
```
scanf();   printf();

string s;
cin.tie(0);
cin.sync_with_stdio(false);


int  %d
long long %lld
double %f
char %c  // 会接收空格，回车
char* %s // 不会接收空格回车
scanf("%c.%c\n", &c, &c);  // 这了可以抵消

a + 0.5
printf(".2f\n", a);
printf("%2d%2d\n", a, a);  // 右对齐
printf("%-2d%-2d\n", a, a);// 左对齐
printf("%02d%02d\n", a, a);// 占两位，不足补零

#define p(x) printf(#x" = %d\n", x)

sprintf()
```

- OJ 反馈结果
```
1：Compiling：正在编译
2：Accepted：正确通过
3：Wrong Answer：答案错误
4：Time Limit Exceeded：超时          （：代码运行效率太低，循环写死，递归写死
5：Memory Limit Exceeded：超内存      （：数组开的太大，或者递归写死
6：Output Limit Exceeded：输出超限    （：循环写死，或者打印日志没有删除
7：Segmentation Fault：段错误         （：数组访问越界（可能有数据没有初始化），有时候也可能数组太大，递归写死
8：Compilation Error：编译错误        （：自己看编译错误信息
9：Presentation Error：格式错误       （：答案正确，可能多输出空格
```

- Debug
```cpp
打印中间变量（打印日志）

1：先根据反馈结果推断（段错误）
2：猜测自己是哪里错误，仔细看看（再读一读代码）
3：确定题目没有读错，判断读入是否有问题（先保证，Debug 前面的代码是正确的）
4：开始 打印日志 Debug（）

二分 Debug 中间添加 return 0 查看
```

- 编译错误
```
1：先看哪一行错误,找问题
2：看编译错误信息，比如说 \357, 那么就应该是中英文符号问题
3：百度翻译编译错误信息，
4：百度返回的错误信息
5：再问别人，给错误信息
```

### 搜索
```
出口、标记、枚举
#include <bits/stdc++.h>
using namespace std;
char mp[10][10];/* 
S**.
....
***T
*/
int vis[10][10];
       //    u d  l  r
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
int dfs(int x, int y) {
    if (mp[x][y] == 'T') {//  出口 并不是每次都有
        return 1;
    }
    vis[x][y] = 1;  //   两种标记方式 标记 mp[x][y] = '*'; 
    for (int i = 0; i < 4; i++) { // 枚举，朝各个方向枚举
        int tx = x + dx[i]; // 更新状态
        int ty = y + dy[i]; // 更新状态
        if (tx >= 0 && tx < n && ty >= 0 && ty < m &&  // 没出边界
            mp[tx][ty] != '*' && vis[tx][ty] == 0) { // 这个点没有走过、并且可以走
            int flag = dfs(tx, ty); // 循环 (tx, ty) 是否可以走到终点
            if (flag == 1) { // 如果可以走 1    如果不能走到终点 0
                return 1;
            }
        }
    }
    return 0;
}
```


- 倍增（快进多少倍）
- 随机化
- 离散化
- 分块
- 精度问题

https://blog.csdn.net/qq_39861188/article/details/84191528

https://www.cnblogs.com/zxjhaha/p/11231914.html