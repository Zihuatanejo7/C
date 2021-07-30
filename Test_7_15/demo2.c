// 1. 猜数字 

//# include <stdio.h>
//int main()
//{
//	int a = 0;
//	scanf_s("%d", &a);
//	int min = 0;
//	int max = 100;
//	while (min <= max)
//	{
//		int mid = (min + max) / 2;
//		if (a < mid)
//		{
//			max = mid - 1;
//		}
//		else if (a > mid)
//		{
//			min = mid + 1;
//		}
//		else
//		{
//			printf("找到了，值为%d\n", mid);
//			break;
//		}
//	}
//	if (min > max)
//		printf("没找到");
//	return 0;
//}


// 2.写代码可以在整型有序数组中查找想要的数字
//# include <stdio.h>
//int bin_search(int arr[], int num,int target)
//{
//	int left = 0, right = num - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (target < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (target > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;
//	}
//	if (left > right)
//		return -1;
//}
//int main()
//{
//	int target = 0;
//	scanf_s("%d", &target);
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	if (bin_search(arr, num, target)>=0)
//		printf("该目标下标为%d", bin_search(arr, num, target));
//	else
//		printf("数组中无此元素");
//	return 0;
//}

// 3.编写代码模拟三次密码输入的场景
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char password[10] = { 0 };               //定义一个数组来存放密码，此时的密码是个字符串
//    int i = 0;
//    for (i = 0; i < 3; i++)
//    {
//        printf("请输入密码: ");
//        gets(password);
//        if (0 == strcmp(password, "123456")) //判断字符串是否相等
//        {
//            printf("登录成功\n");
//            break;
//        }
//        else
//        {
//            printf("密码错误，请重新输入\n");
//        }
//    }
//    if (3 == i)
//    {
//        printf("登录失败\n");
//    }
//    return 0;
//}

// 4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
//# include <stdio.h>
//int main()
//{
//	int ch = 0;
//	printf("请输入字符 : >");
//	while (1)
//	{
//		ch = getchar();
//		if ((ch >= 'a') && (ch <= 'z'))
//		{
//			putchar(ch - 32);
//			printf("\n");
//		}
//		else if ((ch >= 'A') && (ch <= 'Z'))
//		{
//			putchar(ch + 32);
//			printf("\n");
//		}
//		else if ((ch >= '0') && (ch <= '9'))
//			continue;
//	}
//	return 0;
//}


// 5. 实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//# include <stdio.h>
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	int i = 0;
//	for (i = 1; i <= input; i++)
//	{
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%2d * %2d = %2d		", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}


// 6.  创建一个数组，实现函数init（）初始化数组、实现empty（）清空数组、实现reverse（）函数完成数组元素的逆置
//# include <stdio.h>
//void Init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = i;
//	}
//}
//void Empty(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 2*i;
//	}
//}
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[10] = {0};
//	Init(arr, 10);
//	Empty(arr, 10);
//	reverse(arr, 10);
//	return 0;
//}

// 7. 判断一个数是不是素数
//# include <stdio.h>
//#include <math.h>
//int is_prime(input)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(input); i++)
//	{
//		if (input % i== 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	if (is_prime(input))
//		printf("%d 不是质数", input);
//	else	
//		printf("%d 是质数", input);
//	return 0;
//}


// 8. 递归和非递归分别实现求第n个斐波那契数  F(n) = F(n-1)+F(n-2)
// 递归法
//# include <stdio.h>
//int F(int n)
//{
//	if ((1 == n) || (2 == n))
//		return 1;
//	else
//		return F(n - 1) + F(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d",F(n));
//}


// 非递归法
//# include <stdio.h>
//int F(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int i = 2;
//	while (i < n)
//	{
//		c = a+b;
//		b = a;
//		a = c;	
//		i++;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d",F(n));
//}

// 9.调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
//# include <stdio.h>
//int DigitSum(int n)
//{
//	int sum = 0;
//	while (n)
//	{
//		sum += n % 10;
//		n =n / 10;
//	}
//	return sum;
//}
//int main()
//{
//	/*int input = 0;
//	scanf_s("%d", &input);*/
//	int a = DigitSum(1729);
//	printf("%d", a);
//}


//递归
//#include<stdio.h>
//#include<stdlib.h>
////写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和.
////例  1729 1+7+2+9 = 19
//int DigitSum(int n)
//{
//	int sum = 0;
//	int m = 0;
//	if (n)
//	{
//		m = n % 10;
//		n = n / 10;
//		sum = m + DigitSum(n);
//	}
//	return sum;
//}
//int main()
//{
//	int a;
//	printf("输入一个整数:\n");
//	scanf_s("%d", &a);
//	printf("Sum= %d\n", DigitSum(a));
//	return 0;
//}


// 10 编写一个函数 reverse_string(char * string)（递归实现）
//# include <stdio.h>
//void reverse_string(char* string)
//{
//	if (*string != '\0')
//	{
//		reverse_string(++string);
//		printf("%c", *(--string));
//	}
//}
//int main()
//{
//	char *p = "i am kobeBtyant";
//	reverse_string(p);
//	printf("\n");
//	return 0;
//}


// 11. 写一个函数返回参数二进制中 1 的个数
# include <stdio.h>
//int  count_one_bits1(unsigned int value)
//{
//	 返回 1的位数
//	int count = 0;
//	while (value)
//	{
//		if (value % 2 == 1)
//		{
//			value /= 2;
//			count++;
//		}	
//		else
//			value /= 2;
//	}
//	return count;
//}

//int  count_one_bits2(unsigned int value)
//{
//	// 返回 1的位数
//	int b=1;
//	int count = 0;
//	while (b <= (int)value)
//	{
//		if ((b & value) != 0)
//		{
//			b = b << 1;
//			count++;
//		}
//		else
//			b = b << 1;
//	}
//	return count;
//}
//int main()
//{
//	unsigned int a = 15;
//	//int num = count_one_bits1(a);
//	int num = count_one_bits2(a);
//	printf("%d", num);
//	return 0;
//}

// 12.输出整数的每一位
//# include <stdio.h>
//int main()
//{
//	int n = 1234;
//
//	while (n)
//	{
//		printf("%d ", n % 10);
//		n = n / 10;
//	}
//	return 0;
//}

// 13 两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？  1999 2299  输出例子 : 7
//# include <stdio.h>
//int main()
//{
//	int m = 1999;
//	int n = 2299;
//	int i = 0;
//	int b = 1;
//	int count = 0;
//	for (i = 1; i <= 32; i++)
//	{
//		if ((n & b) != (m & b))
//		{
//			count++;
//		}
//		b = b << 1;
//	}
//	printf("%d", count);
//	return 0;
//}

// 14 .获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
//# include <stdio.h>
//int main()
//{
//	int n = 1999;
//	int i = 0;
//	int tmp = 0;
//	for (i = 30;i>=0; i = i-2)
//	{
//		tmp = (n >> i) & 1;
//		printf("%d", tmp);   // 奇数位
//	}
//	printf("\n");
//	for (i = 31; i >= 0; i = i - 2)
//	{
//		tmp = (n >> i) & 1;
//		printf("%d", tmp);   // 偶数位
//	}
//	return 0;
//}