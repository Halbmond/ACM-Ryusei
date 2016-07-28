# acm


## 浮点数

### double的输出

```cpp
double x = 3.14159;
printf("%.3f\n", x);
```

[Correct format specifier for double in printf](http://stackoverflow.com/questions/4264127/correct-format-specifier-for-double-in-printf)


### 负零
`printf("%.2f\n", -0.0000000001);`会输出`-0.00`。
有时这样的结果是错误的。在没有Special Judge的题目要求四舍五入时，不要忘记对负零进行特殊判断。


## Builtin Usage

1. `#define LOG2(x) (31 - __builtin_clz(x))`
2. `#define PARITY(x) __builtin_parity(x)`
3. `#define POPCOUNT(x) __builtin_popcount(x)`  //returns the number of non-zero bits in x



## 错位排列递推公式
F(n) = (n - 1) * (F(n - 1) + F(n - 2))
F(n) = n * F(n - 1) + (-1) ^ n



## 其他

- C++ 检测乘法是否溢出
- [JAVA 读入优化](http://www.tuicool.com/articles/VZ32a2i)



