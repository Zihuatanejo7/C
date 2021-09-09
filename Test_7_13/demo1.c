// 1. 打印100-200之间的质数
#include<stdio.h>
#include<math.h>
int main() 
{
	int i = 0;
	int flag = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		for (int j = 2; j <= (int)sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			flag = 0;
		}
		else
			printf("%d是质数\n", i);
	}
	return 0;
}


// 2.输出乘法口诀表
# include <stdio.h>
int main()
{
	int i = 0;
	for (i = 1; i <= 9; i++)
	{
		int j = 1;
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d = %d ", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}

// 3. 判断1000年-2000年之间的闰年
# include <stdio.h>
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		{
			printf("%d年是闰年\n", year);
		}
	}
	return 0;
}

// 4.交换两个整型变量的值
# include <stdio.h>
void Swap(int* pn, int* pm)
{
	int tmp = *pn;
	*pn = *pm;
	*pm = tmp;
}
int main()
{
	int n = 0, m = 0;
	printf("输入两个数值>:");
	scanf_s("%d %d", &n, &m);
	printf("交换之前n = %d ,m = %d\n", n, m);
	Swap(&n, &m);
	printf("交换之后n = %d ,m = %d\n", n, m);
}

// 5.不创建临时变量，交换两个数的内容(异或的方法)
#include<stdio.h>
int main()
{
	int n = 0, m= 0;
	n = 5;
	m = 7;
	printf("交换之前n = %d ,m = %d\n", n, m);
	n = n ^ m;
	m = n ^ m;
	n = n ^ m;
	printf("交换之后n = %d ,m = %d\n", n, m);
	return 0;
}

//6.求10个整数中最大值
# include <stdio.h>
int main()
{
	int arr[] = { 1,3,6,7,8,2,10,5,6,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);  //求得数组元素个数
	int i = 0;
	int max = arr[0];                      // 先给max初始化，遍历数组和max比大小
	for (i = 1; i < sz; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("max = % d", max);
	return 0;
}

// 7.求两个数的最大公约数
# include <stdio.h>
int main()
{
	int x = 0, y = 0;
	scanf_s("%d %d", &x, &y);
	int i = 0;
	for (i = (x < y) ? x : y;i>=1 ; i--)
	{
		if (1==i)
			printf("%d和%d无公约数", x, y);
		else if ((x % i == 0) && (y % i) == 0)
		{
			printf("%d是%d和%d的最大公约数\n", i, x, y);
			break;
		}
	}
	return 0;
}

8. 将数组A中的内容和数组B中的内容进行交换
# include <stdio.h>
void Swap_array(int arr1[], int arr2[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = arr1[i];
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	printf("交换前的arr1:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	Swap_array(arr1, arr2, sz);
	printf("\n交换后的arr1:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}

// 9.计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
# include <stdio.h>
int main()
{
	double sum = 0.0;
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i%2!=0)
			sum += 1.0 / i;
		else
			sum -= 1.0 / i;
	}
	printf("%lf", sum);
	return 0;
}

//10. 编写程序数一下 1到 100 的所有整数中出现多少个数字9
# include <stdio.h>
int main()
{
	int i = 0;
	for (i = 0; i <= 100; i ++ )
	{
		if ((i % 10 == 9) || (i / 10 == 9))
			printf("%d \n", i);
	}
	return 0;
}

// 11.在屏幕上输出菱形
# include <stdio.h>
int main()
{
	int line = 19;
	//scanf_s("%d", &n);
   int i = 0;
   for (i = 1; i <= line ; i++)
   {
       if (i <= line / 2 + 1)
       {
           int j = 0;
           for (j = 1; j <= line; j++)
           {
               if (j >= ((line + 1) / 2 + 1 - i) && j <= ((line + 1) / 2 + 1 - i + 2 * i - 2))   //上半部分*的起始位置，及每行打印个数为2*i-1
                   printf("*");
               else
                   printf(" ");
           }
           printf("\n");
       }
       else
       {
           int j = 0;
           for (j = 1; j <= line; j++)
           {
               if (j >= (i -(line+1)/2+1) && j <= (i- (line + 1) / 2 +1+2*(line+1-i)-2))  //下半部分*的起始位置，及每行打印个数为2*(line+1-i)-1
                   printf("*");
               else
                   printf(" ");
           }
           printf("\n");
       }
   }
	return 0;
}

// 12 求出0～999之间的所有“水仙花数”并输出
# include <stdio.h>
# include <math.h>
int main()
{
	int i = 0;
	
	for (i = 100; i < 1000; i++)
	{
		int ret = i;
		int tmp = 0;
		int sum = 0;
		while (ret)
		{
			int tmp = ret % 10;
			sum += (int)pow(tmp, 3);
			ret /= 10;
		}
		if (sum == i)
		{
			printf("%d是水仙花数\n", i);
		}
	}
	return 0;
}

// 13.  求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
# include <stdio.h>
#include <math.h>
int main()
{
	int a = 2;
	int n = 4;
	int i = 0;
	int ret = 0;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		//加n个数
		ret = 10 * ret+ a;
       printf("%d+", ret);
		sum += ret;
	}
	printf(" = %d", sum);
	return 0;
}
