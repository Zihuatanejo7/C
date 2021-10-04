# C/Cplusplus

# C 语言



## 一 概论

### C语言结构特点：

**1. 一个Ｃ语言源程序(project)可以由一个或多个源文件(.c)组成**

 **2. 每个源文件可由一个或多个函数组成**

 **3. 一个源程序不论由多少个文件组成，都有一个且只能有一个main函数，即主函数**

 **4. 源程序中可以有预处理命令(include 命令仅为其中的一种)，预处理命令通常应放在源文件或源程序的最前面**

 **5. 程序中使用的各种变量都应该先定义，后使用**



## 二  数据类型

>数据类型有两种：
>**1. 基本数据类型(short, int, long,double,float)**
>**2. 构造型数据类型( struct, enum, union)**

|                  |                                           | 字节数(在VS2019编译器下) |
| :--------------: | :---------------------------------------: | :----------------------: |
|   **字符类型**   |         **unsigned char,  char **         |       **1个字节**        |
|    **短整型**    |      **unsigned short **,  **short**      |       **2个字节**        |
|     **整型**     |           **unsigned int, int**           |       **4个字节**        |
|    **长整型**    |        **unsigned long** ,**long**        |       **4个字节**        |
|  **更长的整型**  | **unsigned long long int**, **long long** |       **8个字节**        |
| **单精度浮点数** |                 **float**                 |       **4个字节**        |
| **双精度浮点数** |                **double**                 |       **8个字节**        |



###  1. 整型数据在内存中的存储

>**整形在内存中的存储**

|      |                                  |
| :--: | :------------------------------: |
| 原码 |     直接将十进制数写为2进制      |
| 反码 | 符号位不变，其他位置按位取反即可 |
| 补码 |              反码+1              |

>**对于正整数而言，原码= 反码 =补码**
>
>**对于负整数而言，计算机以补码形式存储**
>
>**计算机中的整数的存储均是以补码的形式，只要类型不包含unsigned，则其类型为有符号数**

```C
	char arr1[] = "ABCDE";                              
	char arr2[] = { "ABCDE" };
	char arr3[] = { 'A','B','C','D','E'};
	printf("%d\n", sizeof(arr1) / sizeof(arr1[0]));
	printf("%d\n", sizeof(arr2) / sizeof(arr2[0]));
	printf("%d\n", sizeof(arr3) / sizeof(arr3[0]));
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", arr3);
```

![结果](C:\Users\Administrator\Pictures\Markdown\微信截图_20210629212212.png)

> arr1和arr2是相同的的，都是字符串数组，字符串结束标志为''\0'；但是arr3是单个字符组成的数组。
>
> 所以，arr3比arr1、arr2少一个字符输出。
>
> **（printf arr3造成这样的输出，%s把\0当作字符串结束标志）**



### 2. 大小端存储模式

|                  |                                                              |
| :--------------: | ------------------------------------------------------------ |
| **大端存储模式** | **低字节内容存储在高地址，高字节内容存储在低地址**           |
| **小端存储模式** | **低字节内容存储在低地址，高字节内容存储在高地址** (VS2019是小端存储模式) |

```c
// 判断当前编译器大小端存储模式
#include <stdio.h>
int check_sys()
{
	int i = 1;
	return (*(char*)&i);    // 1. &i 对i取地址 2.（char*）&i ：强制类型转换  3.*（char*）&i， 输出i的低字节的内容 
}

int main()
{
	int ret = check_sys();  
	if (ret)
    {
      	printf("小端\n");  
    }	
	else
    {
     	printf("大端\n");   
    }
	return 0;
}

```



### 3. 常量

> 生活中，有些值是固定不变的，比如圆周率，光速

```c
// 1. 数值常量
1.2 200 3.0
    
// 2. 标识符常量 or 符号常量
# define symbol1 100   //相当于 symbol1 = 100,（但是#dfine symbol1是常量啊）   symbol1（变量） = 100
    
// 3. 字符常量    
//1.注意:' '表示为单字符，" "为一个字符串
//2.字符常量只能是单个字符，不能是字符串。
 'A' 'a' 'B'  
    
// 4. 字符串常量
"abc";
int a1 = sizeof(c)/sizeof(c[0])-1;  //-1相当于字符串结束标志\0减去
int a2 = strlen(c);
// 1. 可以把一个字符常量赋予一个字符变量，但不能把一个字符串常量赋予一个字符变量
 //2. 注意 c为一个字符数组，但不是字符串变量（C语言中无字符串变量）
// 3. 注意 c占用的字节数为sizeof（a）=4,因为字符串结束有\0;a1=a2=真正字符个数
// 4.  注意 char a =5; char b = '5';二者不同
```



### 4. 变量



#### 4.1 分类

>**变量包括全局变量和局部变量**（一定要区分不同类型变量的作用域和生命周期）

|          |                |                 作用域                 |
| :------: | :------------: | :------------------------------------: |
| 局部变量 | 定义在函数内部 | 在函数内部其发挥作用，出去函数就销毁了 |
| 全局变量 | 定义在函数外部 |           整个工程都可以使用           |



#### 4.2 命名规则

> 1 .  变量的命名由字母、数字、下划线组成
>
> 2. 首字符不能为数字
> 3. 先定义，后使用
> 4. 不同类别的变量要注意其作用域（全局变量，局部变量）



#### 4.3 变量的初值 

```c
	int a = 1;                 // 1. 在内存中开辟以个4个字节的存储单元存储a
	int* p = &a;               // 2. 定义指针变量p->a,p的数据类型为int *，其数据类型长度为4或者8
	printf("%d\n", a);         // 1
	printf("%p\n", &a);        // a的存储首地址
	printf("%d\n", *p);        // 1
```


#### 4.4 变量类型转换

```c
// 1
# include <stdio.h>
void main() 
{
	int a = 0;
	int b = 49;
	char c = a + b;    // c 是一个char类型，字节为1  所以，a+b运算结束后，要进行类型转换
} 

// 2
#include <stdio.h>
int main()
{
    char a= -1;
    signed char b=-1;
    unsigned char c=-1;
    printf("a=%d,b=%d,c=%d",a,b,c); // -1 -1 255
    return 0;
}

// 3 
#include <stdio.h>
int main()
{
    char a = -128;
    char b = 128;
    printf("%u %u\n",a,b);  // 1111 1111 1111 1111 1111 1111 1000 0000   ,  1111 1111 1111 1111 1111 1111 1000 0000
    return 0;
}

// 4  注意
int main()
{
    char a[1000];
    int i;
    for(i=0; i<1000; i++)
    {
        a[i] = -1-i;
    }
    printf("%d",strlen(a));    // 256 strlen():是从首元素开始，其找'\0'或者0（字符串结束标志）
    return 0;
}
```

```c
// 强制转换   (数据类型)变量
void main() 
{
  float f=5.75;
  printf("(int)f=%d",(int)f);
}
```


### 5. 运算符

|              |                                |
| :----------: | :----------------------------: |
| 1.算术运算符 | +		-   *   /   %  ++  -- |
| 2.关系运算符 |  >    <     >=   <=   ==  !=   |
| 3.逻辑运算符 |          &&  \|\|  !           |
| 4.移位操作符 |         & \| ^ ~ >> <<         |
| 5.赋值运算符 |        =  +=  /=  *= %=        |
| 6.条件运算符 |      (条件)?  语句1:语句2      |
| 7.指针运算符 |     &(取地址)    *(取内容)     |
| 8.字节运算符 |             sizeof             |



#### 5.1  整型与 0 值的比较

```c
if (flag) // if (!flag)
{
    ;
}
```



#### 5.2  BOOL型与 0 值的比较

```c
if (bool)  // if (!bool)
{
    ;
}
```



#### 5.3 指针类型与 0（NULL） 值的比较

```c
if (p == NULL);if (p != NULL)
```



#### 5.4  操作符应用

```c
// 1.不增加临时变量，实现两个变量内容交换# include <stdio.h>int main()    // 实现两个变量的数值交换{	int a = 3;	int b = 5;	//a = a + b;	//b = a - b;	//a = a - b;	a = a ^ b;	b = a ^ b;	a = a ^ b;}//2 .统计一个数转化为二进制中 1 的个数# include <stdio.h>int main(){	int num = 0;	int count = 0;	scanf("%d", &num);	for (int i = 0; i < 32; i++)	{		if (1==((num >> i) & 1))        {            count++;        }	}	printf("%d", count);    return 0;}// 左移运算符：左边丢弃，右边补0// 右移运算符：右边丢弃，左补符号位
```



#### 5.5 运算优先级

![](C:\Users\Administrator\Pictures\Markdown\微信截图_20210724175521.png)

<img src="C:\Users\Administrator\Pictures\Markdown\微信截图_20210724175537.png" style="zoom:50%;" />



### 6. 转义字符与格式化输出

| 转义字符 |     意义      |
| :------: | :-----------: |
|    \n    |     换行      |
|    \t    |      tab      |
|   \\'    |    单引号     |
|   \\\    |    反斜线     |
|   \\"    |    双引号     |
|   \ddd   |  1-3位八进制  |
|   \xhh   | 1-2位十六进制 |

```C
	printf("%d",n)      // 输出带符号十进制整数	printf("%s",n)      // 输出字符串	printf("%c",n)      // 输出单个字符	printf("%p",&n)     // 输出n的地址	printf("%f",n)      // 输出n的小数部分    printf("%x",n)      // 十六进制输出
```



## 三 分支程序设计（选择程序设计）

<img src="C:\Users\Administrator\Pictures\Markdown\微信截图_20210717124353.png" style="zoom:50%;" />

### 1. if 语句实现选择结构

```c
// 第一种if语句
if (条件)
{
   语句; 
}

// 第二种if 语句
if (条件)
{
    语句1;
}
else
{
    语句2;
}
	
// 等同于
if (条件) 语句1;else 语句 2;
// 等同于
(条件)? 语句1:语句2;

// 第三种if语句
if (条件1)
{
    语句1;          // 语句结束必须+;
    语句2;          // 如果if条件要执行的语句超过1条，需要加{ }
}
else if (条件2)
{
    语句3;
    语句4;   
}
else
{
    语句5;
    语句6;
}
//为了避免这种二义性，else 总是与前面最近的if配对
```



### 2. switch 语句实现选择

> **switch语句也是一种多分支语句**

```c
// 
switch(常量表达式)
{ 
	case常量表达式1: 语句1;break;   // 常量表达式包括：整型常量+字符常量
	case常量表达式2: 语句2; break;
	… 
	case常量表达式n: 语句n; break;
	default : 语句n+1;break; 
} 
//其语义是：计算表达式的值并逐个与其后的常量表达式值相比较，当表达式的值与某个常量表达式的值相等时， 执行其语句，然后不再进行判断。如表达式的值与所有case后的常量表达式均不相同时，则执行default后的语句。

# include <stdio.h>
void main()
{
	int a=1;
	switch (a)
    {	case 1:printf("Monday\n");
		case 2:printf("Tuesday\n");
		case 3:printf("Wednesday\n");
		case 4:printf("Thursday\n");
		case 5:printf("Friday\n");
		case 6:printf("Saturday\n");
		case 7:printf("Sunday\n");
		default:printf("error\n");
	}
}
// 结果如下图所示,a为1，执行语句1，后无break，则程序不跳出；一直执行到default,程序结束。所以,语句记得break.
```

![结果](C:\Users\Administrator\Pictures\Markdown\微信截图_20210702102155.png)





## 四 循环程序设计

>**key words ：for while do-while break continue goto**
>
>在多重循环中，**应长循环放在内层，短循环放在外层，以减少CPU跨层次数**



### 1. for

```c
int i = 0;
for ( i = 0; i<=n; i++)      
{
    语句1;
    语句2;
}
/*   for循环执行流程
1. int i= 0; 
2. 判断i<n; 
3.语句1; 
4.语句2; 
5.i++
*/
```



### 2. while

```c
int i = 0;
while (i<n)
{
    语句1;
    语句2;
}
/*  while 执行流程
1. 判断i<n; 
2.语句1; 
3.语句2;       
注意: while中如果i<n不成立，则一次循环也不执行
*/
```



### 3. do-while

```c
do
{
    语句1;
    语句2;
} while(i<n);  //结束 有一个 ;
/*  do-while 执行流程
1.语句1; 
2.语句2; 
3.判断i<n          
注意:在do-while中，至少会执行一次语句1,语句2
*/
```



### 4. break

```c
    for (int i = 0; i <= 3; i++)   // 循环1     {        if (i == 0)        {            printf("我是%d,但我就是退出，就是玩\n", i);            break;                //直接跳出循环,不会在执行哇塞        }        printf("哇塞");    }  
```

![结果](C:\Users\Administrator\Pictures\Markdown\微信截图_20210702104825.png)



### 5. continue

```c
    for (int i = 0; i <= 3; i++)   // 循环1     {        if (i == 0)        {            printf("我是%d,但我就是退出，就是玩\n", i);            continue;                //直接跳出当前i=0的一次循环,继续执行i=1 i=2 i=3 因此,哇塞应该被打印三次        }        printf("哇塞");    }  
```

![](C:\Users\Administrator\Pictures\Markdown\微信截图_20210702105656.png)



### 6. goto 

>**1. 谨慎使用  C语言顺序性结构语言  goto容易打乱main()函数中语句的执行顺序**
>
>**2. goto 适用于从深度嵌套中 跳出**

```c
	int a = 0;again:                           // 1    if (a != 3)    {        a++;        printf("%d\n", a);        goto again;             //  2   如果a不等于3，转到1执行    }	printf("haha")//  代码含义 当a=3，printf("haha")
```



### 7. 练习

```c
// 1. 模拟三次输入密码，
# include <stdio.h>
# include <string.h>

int main()
{
	char password[10] = {0};
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; ++i)
	{
		printf("输入密码:");
		scanf("%s", password);
		if (strcmp(password, "password") == 0)
			break;
	}
	if (i == 3)
		printf("三次输入错误，系统退出\n");
	else
		printf("登录成功\n");
	return 0;
}


// 2.折半查找
# include <stdio.h>

int main()
{
	int input = 0;
	scanf("%d", &input);
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = num - 1;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (input < arr[mid])
		{
			right = mid - 1;
		}
		else if (input > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			printf("输入的值为%d,下标为：%d", arr[mid],mid);
			break;
		}	
	}
	return 0;
}

// 3.猜数字游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
    printf("**********************************\n");
    printf("          1.猜数字游戏开始          \n");
    printf("            0.游戏退出             \n");
    printf("**********************************\n");
}

void game()
{
    srand((unsigned)time(NULL));
    int random_num = rand() % 100 + 1;
    int input = 0;
    while (1)
    {
        printf("请输入猜的数字>:");
        scanf("%d", &input);
        if (input > random_num)
        {
            printf("猜大了\n");
        }
        else if (input < random_num)
        {
            printf("猜小了\n");
        }
        else
        {
        printf("恭喜你，猜对了\n");
        break;
        }
    }
}

int main()
{
    int input = 0;
    do
    {
        menu();
        printf("请选择>:");
        scanf_s("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            break;
        default:
            printf("选择错误,请重新输入!\n");
            break;
        }
    } while (input);
    return 0;
}
```



## 五  数组

> **数组：用于存放相同类型数据的集合 （数值数组 字符数组 指针数组 结构体数组）**



###  1. 一维数组

```c
int arr1[10];
char arr3[10];
float arr4[1];
double arr5[20];

//代码2  这是一个错误实例
int count = 10;
int arr2[count];//# define count 10，可以使用count创建数组 

# include <stdio.h>
# include <string.h>
int main()
{
	char arr1[] = "abc";
	char arr2[] = { 'a','b','c' };    // 不是一个字符串数组
	printf("%d\n", sizeof(arr1));     // 4
	printf("%d\n", sizeof(arr2));     // 3
	printf("%d\n", strlen(arr1));     // 3
	printf("%d\n", strlen(arr2));     // 随机值
	return 0;
}
```

>**（1）数组在创建的时候如果想不指定数组的确定的大小就得初始化。数组的元素个数根据初始化的内容来确定**
>**（2）数组在内存中是连续存放的**



### 2. 数组中的二分查找

```c
// 二分查找# include <stdio.h># include <assert.h>int bin_search (int* arr, int len){	assert(arr != NULL);   	// 待查找对象	int inp = 0;	scanf("%d", &inp);	int left = 0;	int right = len - 1;	while (left <= right)	{		int mid = (left + right) / 2;		if (inp < arr[mid])		{			right = mid - 1;		}		else if (inp > arr[mid])		{			left = mid + 1;		}		else		{			return mid;   //找到了		}	}	return -1;}int main(){	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };	int len = sizeof(arr1) / sizeof(arr1[0]);	int ret = bin_search(arr1, len);	if (ret >= 0)	{		printf("找到了,数组下标为%d,值为%d", ret,arr1[ret]);	}	else	{		printf("找不到");	}	return 0;}
```



### 3. 二维数组

```c
//数组创建int arr[3][4];char arr[3][5];double arr[2][4];//数组初始化int arr[3][4] = {1,2,3,4};int arr[3][4] = {{1,2},{4,5}};int arr[][4] = {{2,3},{4,5}};   // 行可以省略，列不可以省略
```

> **二维数组在内存中也是连续存储**
> ![](C:\Users\Administrator\Pictures\Markdown\微信截图_20210717213353.png)



## 六  字符串函数和内存操作函数



### 1.  字符串库函数



#### 1.1 strlen

```c
size_t strlen ( const char * str );
```

> **(1) 字符串已经'\0'作为结束标志，strlen函数返回的是在字符串中'\0'前面出现的字符个数（不包含'\0')。
> 	(2)参数指向的字符串必须要以'\0'结束
> 	(3)注意库函数的返回值为size_t (unsigned int)**

```c
# include<string.h>
# include <stdio.h>

int main()
{
	printf("%d\n", strlen("c:\test\32\test.c"));  //   \32 \t 是转义字符 
	return 0;
}

#include <stdio.h>
int main()
{
    const char*str1 = "tianjin";   //  7
    const char*str2 = "xiqing";     // 6  
    if(strlen(str2)-strlen(str7)>0)
    {
        printf("str2>str1\n");
    } 
    else
    {
        printf("srt1>str2\n");
    }
    return 0;
}
```

<img src="C:\Users\Administrator\Pictures\Markdown\微信截图_20210717214923.png" style="zoom:67%;" />

> **(1)strlen返回值是unsigned int,    **
>
> **(2)strlen(str2)-strlen(str1)=-1 **
>
> **(3)(-1的补码)=11111111 11111111 11111111 11111111的十进制就是4294967295**



#### 1.2 strcpy / strncpy

```c
char* strcpy(char * dest, const char * src );char *strncpy( char *dest, const char *src, size_t count );    //size_t = unsigned int
```

>**(1) 将源字符串中的'\0'拷贝到目标空间
>	(2) 目标空间必须足够大，以确保能存放源字符串
>	(3) 目标空间必须可变**

```c
# include <stdio.h>int main(void){	char st1[25] = "my name is ";	char st2[5] = "zzy";	strcpy(st1,st2);   //格式： strcpy(字符数组名1，字符数组名2) 功能：把字符数组2中的字符串复制到字符数组1    // strncpy(str1,str2,2); // strcpy(字符数组名1，字符数组名2,n) 功能：把字符数组2中的字符串的前n个字符复制到字符数组1	printf("%s\n", st1);	return 0;}
```



#### 1.3 strcat /  strncat

```c
char * strcat ( char * dest, const char * src );char *strncat( char *dest, const char *src, size_t count ); //size_t = unsigned int
```

>**字符串连接函数strcat**
>
>**(1) 源字符串要以'\0'结束**
>
>**(2)目标空间必须够大，能容纳源字符串的内容**
>
>**(3)目标空间必须可修改**

```c
int main(void){	char st1[25] = "my name is ";	char st2[5] = "zzy";	strcat(st1,st2);   //格式： strcat(字符数组名1，字符数组名2) 功能：把字符数组2中的字符串连接到字符数组1 中字符串的后面    // strncat(st1,st2，n);   //格式： strcat(字符数组名1，字符数组名2) 功能：把字符数组2中的前n（n<strlen（str2））个字符连接到字符数组1的后面	printf("%s\n", st1);	return 0;}
```



#### 1.4 strcmp / strncmp

```c
int strcmp( const char *string1, const char *string2 );int strncmp( const char *string1, const char *string2, size_t count );
```

>**(1) 字符串比较函数
>// **格式： strcmp(字符数组名1，字符数组名2) 功能：按照ASCII码顺序比较两个数组中的字符串，并由函数返回值返回比较结果**
>//如果字符串1＝字符串2，返回0；
>//如果字符串2>字符串2，返回值>0；
>//如果字符串1<字符串2，返回值<0。

```c
void main(){	char st1[] = "my name is "; 	char st2[] = "zzy";	int ret = strcmp(st1, st2);    // int ret = strncmp(st1, st2,n);  比较st1和str2的前n个字符 	if (ret == 0)         printf("st1=st2\n");	if (ret > 0)         printf("st1>st2\n");	if (ret < 0)         printf("st1<st2\n");}
```



#### 1.5 strstr

> **strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。**
>
> **如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL**

```c
# include <stdio.h>#include <string.h>#include <assert.h>char* my_strstr(const char* p1, const char* p2){	assert(p1 !=NULL);    assert(p2 != NULL);    	char* s1 = (char*) p1;	char* s2 = (char*) p2;	char* cur = (char*)p1;	// 被查找的字符串不能为空	if (!(*p2)   // 等于   if (*p2=='\0')	{		return (char*)p1;	}	// 	while (*cur)	{		s1 = cur;		s2 = (char*)p2; 		while (*s1 && *s2 && !(*s1-*s2)) // 等于while((*p1 == '\0')&&(*p2 == '\0')&&(*s1 == *s2)) 		{			s1++;			s2++;		}		if (!*s2)		{			return cur;   // 找到字串		}		if (!*s1)		{			return NULL;   // 找到字串		}		cur++;	}	return NULL;   //找不到字串}        int main(){	char* p1 = "abcdefdfghjk";	char* p2 = "defq";	char *ret = my_strstr(p1, p2);	if (ret == NULL)	{		printf("找不到");	}	else		printf("%s", ret);	return 0;}
```



#### 1.6 strtok

> **分解字符串为一组字符串。s为要分解的字符，delim为分隔符字符（如果传入字符串，则传入的字符串中每个字符均为分割符）。首次调用时，s指向要分解的字符串，之后再次调用要把s设成NULL。在头文件#include<string.h>中。**

 ```c
char *strtok( char *str, const char *Deli ) //Deli: 分隔符
 ```

```c
# include <stdio.h>#include <string.h>int main(){	char arr[] = "xxxxxxxxx@gmail.com";	char* p = "@.";	// 切割buffer中的字符串	char* ret = NULL;	for (ret = strtok(arr, p); ret; ret = strtok(NULL, p))   // strtok首次调用(arr,p),以后都是(NULL,p)	{		printf("%s\n", ret);	}	return 0;}
```

<img src="C:\Users\Administrator\Pictures\Markdown\微信截图_20210719210756.png" style="zoom:50%;" />



### 2. 内存操作函数

#### 2.1 memcpy

```c
void *memcpy( void *dest, const void *src, size_t num);   
```

> **memcpy函数是把容器1中的num个字节内容，复制给容器2(容器1的num个内容所在的地址和容器2的num个内容所在的地址无重叠)**

```c
// 库函数
# include <stdio.h>
# include <string.h>

struct S
{
	char name[20];
	int age;
};
int main()
{
	struct S arr3[] = { {"张三",20},{"李四",22} };
	struct S arr4[3] = { 0};

	memcpy(arr4, arr3, sizeof(arr3));

	printf("%d ", arr4[0].age);
	printf("%d ", arr4[1].age);
	return 0;
}

// 自己定义
# include <stdio.h>
# include <assert.h>
void* my_memcpy(void* dest, const void* src, size_t num) 
{
	assert(dest != NULL && src != NULL);

	void* ret = dest;

	while(num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}

	return (char*)ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	for(int i = 0; i < 5; i++)
	{
		printf("%d", arr2[i]);
	}
	return 0;
}
```



#### 2.2 memmove(功能和memcpy差不多,处理的是容器1和容器2有重叠情况下的数据拷贝)

```c
void *memmove( void *dest, const void *src, size_t num)
```

```c
//系统自带#include<stdio.h>#include<string.h>int main(){	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };	memmove(arr1, arr1+2, 5*sizeof(arr1[0]));	int i = 0;	for (i = 0; i < 10; i++)	{		printf("%d  ", arr1[i]);	}	return 0;}//自定义# include <assert.h># include <stdio.h>void* my_memmove(void* dest, const void* src, size_t num) {	assert(dest != NULL && src != NULL);	if ((char*)dest > (char*)src)		// 从后向前copy	{		while (num--)  // 进入循环就自减1		{			*((char*)dest + num) = *((char*)src + num);		}		return (char*)dest;	}	else	{   //从前向后copy		char* ret = dest;   // 赋值会改变dest的地址，先存储，最后返回dest地址		while (num--)		{			*(char*)dest = *(char*)src;			++(char*)dest;			++(char*)src;		}		return ret;	}}int main(){	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };	my_memmove(arr1, arr1+2, 5*sizeof(arr1[0]));	int i = 0;	for (i = 0; i < 10; i++)	{		printf("%d  ", arr1[i]);	}	return 0;}
```



#### 2.3 memcmp

> **memcmp函数是比较内存前N个字节**

 ```c
int memcmp(const void* buf1, const void* buf2, size_t count)  size_t count： 比较的字节个数
 ```

 ```c
 # include <stdio.h> # include<string.h> int main() { 	int arr1[] = { 1,2,3,4,5 }; 	int arr2[] = { 1,2,5,4,3 };	if (!memcmp(arr1, arr2, 8)) 	{ 		printf("arr1 = arr2"); 	}	 	else 	{ 		if (memcmp(arr1, arr2, 4) < 0) 		{ 			printf("arr1 < arr2"); 		} 		else 		{ 			printf("arr1 < arr2"); 		}	 	}	 	return 0; }
 ```

 ```c
 // my_memcmp 自己实现 # include <stdio.h> # include <assert.h> int my_memcmp(const void* dest, const void* src, size_t num) { 	assert(dest != NULL && src != NULL); 	while ((num--) && (!(*(char*)dest - *(char*)src))) // num自减,当*dest==*src进循环 	{ 		++*(char*)src; 		++*(char*)dest; 	}  	if (!num) 	{ 		return 0; 	} 	else 	{ 		return (*(char*)dest > *(char*)src) ? 1 : -1; 	} } int main() { 	int arr1[] = { 1,2,3,4,5 }; 	int arr2[] = { 1,2,5,4,3 }; 	int n = 10; 	int ret = my_memcmp(arr1, arr2, n); 	if (!ret) 	{ 		printf("arr1 = arr2"); 	} 	else 	{ 		if (ret < 0) 		{ 			printf("arr1 < arr2"); 		} 		else 		{ 			printf("arr1 < arr2"); 		} 	} 	return 0; }
 ```




#### 2.4 memset

> **把一段内存空间全部设置为某个字符，一般用在对定义的字符串进行初始化为‘ ’或‘/0’**

```c
void* memset(void* dest, int c, size_t count) //size_t= unsigned int
     
# include <stdio.h>
    
struct S
{
	int book;
	int age;
};

int main()
{
	
	struct S user[10];
	printf("struct S 类型所占的字节大小为 = %d\n", sizeof(struct S));
	memset(user, '#', 8);   //一个字节的设置
	printf("%d  ", user[0].book);
	printf("%d\n ", user[0].age);
	return 0;
}
```

![](C:\Users\Administrator\Pictures\Markdown\微信截图_20210719202109.png)



## 七 构造数据类型

### 1. struct

> **struct 可以将一些相关联的数据打包为一个整体**

```  c
# include <stdio.h>
struct Book   // 书的类型
{
	char name[20]; //
	short int price; //
};
int main()
{
	// 利用结构体类型创建一个该类型的结构体变量
	struct Book b1 = {"C语言程序设计",55};
	struct Book* pd = &b1;
	b1.price = 15; // 修改对象b1的name属性
	printf("%s\n", b1.name);
	printf("%d\n", b1.price);
	printf("%s\n", (*pd).name);
	printf("%d\n", (*pd).price);
	printf("%s\n", pd->name);
	printf("%d\n", pd->price);  // pd指向的对象的price属性
	return 0;
}
```



### 2. 柔性数组

> **结构体中最后一个元素允许是未知大小的数组，这叫柔性数组成员，柔性数组成员前面必须至少一个其他成员**

```c
struct std{  int n;  int a[0];  // 或者int a[]     };//code1定义了一个可变长的结构体   利用柔性数组# include <stdlib.h># include <stdio.h>struct M{	char c;	int a[];};int main(){	struct M m = {0};	int i = 0;	struct M* p = (struct M*)malloc(sizeof(struct M) + 10 * sizeof(int));	if (p != NULL)	{		p->c = 'c';		for (i = 0; i < 10; i++)		{			p->a[i] = i;			printf("%d ", p->a[i]);		}	}	free(p);	p = NULL;	return 0;}//code2 定义了一个可变长的结构体   利用指针# include <stdlib.h># include <stdio.h>struct M{	char c;	int *pa;};int main(){	struct M m = { 0 };	int i = 0;	struct M* p = (struct M*)malloc(sizeof(struct M));	p->c = 'c';	p->pa = (int*)malloc(10 * sizeof(int));	if (NULL != (p->pa))	{		int i = 0;		for (i = 0; i < 10; i++)		{			p->pa[i] = i;		}	}	free(p->pa);	p->pa = NULL;	free(p);	p = NULL;	return 0;}
```


### 3. union

>**union维护足够的空间来存放多个数据成员中的一种，而不是为每一个数据成员配置空间**

```c
# include <stdio.h>union M{	char c;	short s;	int a;	double d;};int main(){	printf("%d", sizeof(union M));	return 0;}
```

```c
// 利用union判断当前编译器大小端存储模式# include <stdio.h>int check_sys(){    union un    {        char c;        int i;    }u;    u.i = 1;    return u.c;}int main(){	int ret = check_sys();    if (ret)    {        printf("小端\n");    }    else    {        printf("大端\n");    }    return 0;	return 0;}
```


### 4. enum

```c
enum color{    red;    green;    blue}
```



###  5. enum 和 #define标识符 的区别

> **(1) #define 宏常量是在预编译阶段进行简单替换**
>
> **(2)枚举常量则是在编译的时候确定其值**
>
> **(3)一般在编译器里，可以调试枚举常量，但是不能调试宏常量**
>
> **(4)枚举可以一次定义大量相关的常量，而#define 宏一次只能定义一个**



## 八 函数



### 1. 基本概念

> **函数 = 库函数(系统自带)+自定义函数(用户定义)  **
>
> **作用：增加代码复用性**
>
> **函数声明：函数要满足先声明后使用的原则，函数声明就是告诉编译器有一个函数叫fun，参数为int parameter，返回值类型为int（ ）**  
>
> 举例:int fun(int parameter)
>
> **函数定义：函数功能的实现方式**

|     函数类型     |               定义方式                |          例子          |
| :--------------: | :-----------------------------------: | :--------------------: |
| 无返回值，无形参 |          void  fun_name( );           |     void  fun1 ( )     |
| 无返回值，有形参 |   void  fun_name(type  parameter);    |   void  fun2(int a)    |
| 有返回值，无形参 |       return_type  fun_name();        |      int fun3 ( )      |
| 有返回值，有形参 | return_type fun_name(type parameter); | int fun4 (int a,int b) |

```c
// 1. 无返回值，无形参 
void Hello()
{
	printf ("Hello,world \n");
}
// 只要调用hello()函数，就打印一次 Hello,world 

//2. 无返回值，有形参
void n_add(int n)
{
	n++;
}
// 调用n_add实现n自加

// 3. 有返回值，无形参
char fun ()
{
    char a = 1;                    // 这个为a中存放的是ASCII数值1对应的符号
    char b ='1';                   // 这个为b中存放的为字符1
    return a;
}
// 这个fun，个人并没有觉得有什么实际意义,但是需要记住本函数中的a 和 b却不同啊

// 4. 有返回值，有形参
int get_max(int a,int b)
{
    if (a>b) return a;else return b;
}
// 调用get_max，输出两个整型的最大值
```

> **1.实参可以是常量、变量、表达式、函数等， 无论实参是何种类型的量，在进行函数调用时，它们都必须具有确定的值， 以便把这些值传送给形参。 因此应预先用赋值，输入等办法使实参获得确定值。**

> **2.实参和形参在数量上，类型上，顺序上应严格一致。**



### 2. 传值调用和传址调用(极其重要)

```C
# include <stdio.h>
void swap1(int a, int b)           // swap2形参接收的是值，进入swap1时，在栈区为a b分配了新的内存单元，函数结束，形参消失（本函数也无返回值，不可能对实参进行修改）
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;                        
}
void swap2(int* a, int* b)          // swap2 形参接收的是地址，所有要用指针   通过地址寻址直接修改该地址快中的值，并不借用变量名
{
	int tmp ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int x = 10, y = 20;
	swap1(x, y);                     // 实参为x，y的值 = 传值调用
	printf("swap1 : x = %d y = %d\n", x, y);
	swap2(&x, &y);                   // 实参为x,y的地址 = 传址调用
	printf("swap2 : x = %d y = %d", x, y);
	return 0;
}
```

![结果](C:\Users\Administrator\Pictures\Markdown\微信截图_20210704103408.png)

> **1.形参只有在被调用时才分配栈区内存单元，在调用结束时， 即刻释放所分配的内存单元。因此，形参只有在自己函数内部有效。**

> **2.函数调用中发生的数据传送是单向的。 即只能把实参的值传送给形参，而不能把形参的值反向地传送给实参。 因此在函数调用过程中，形参的值发生改变，而实参中的值不会变化。**



### 3. 数组名做函数参数

```c
// 1. # include <stdio.h>void my_test(char* str)      //  地址需要指针来接收，char* str{	printf("str :%p %p\n", str,str+1);  //str接受的为数组首元素地址}int main(){	char arr[] = "University";	printf("%d\n", sizeof(arr));   // 输出为11，因为字符串结束标志\0也占用一个字节    printf("%d\n", strlen(arr));   // 输出为10，因为只输出\0前的字符个数	printf("arr:%p  %p\n", &arr,&arr+1);      // &arr为存放的数组地址，其大小为一个连续的11字节的存储单元 所以，&arr+1 = &arr的地址+12	my_test(arr);            // 数字名字=数字首元素地址，因此此刻实参为数组首元素的地址	return 0;}
```

![结果](C:\Users\Administrator\Pictures\Markdown\微信截图_20210704111920.png)

```c
 # include <stdio.h> # include <assert.h> void bubble_sort(int* pa, int len) { 	assert(pa != NULL);  	// 数组是否有序的标志 	int flag = 1;    	// 确定要比较多少趟 	int i = 0; 	for (i = 0; i < len - 1; i++) 	{ 		int j = 0; 		// 确定一趟中要比较次数 		for (j = 0; j < len - 1 - i; j++) 		{ 			if (pa[j] > pa[j + 1]) 			{ 				int temp = pa[j]; 				pa[j] = pa[j + 1]; 				pa[j + 1] = temp; 				flag = 0; 			} 			else 			{ 				; 			} 			 		} 		if (1 == flag) 		{ 			break; 		} 	} }  int main() { 	int arr1[] = { 9,8,5,4,3,7,6,2,1,0 }; 	int sz = sizeof(arr1) / sizeof(arr1[0]);  	bubble_sort(arr1, sz); //冒泡排序函数  	for (int i = 0; i < sz; i++) 	{ 		printf("%d ", arr1[i]); 	} 	return 0; } // 3. qsort排序 # include <stdlib.h> # include <stdio.h> int cmp(const void* pa, const void* pb) { 	int* a = (int*)pa;     	int* b = (int*)pb; 	return *a - *b; }  int main() { 	int arr1[] = { 9,7,8,6,4,8,1,5,3,2}; 	int sz = sizeof(arr1) / sizeof(arr1[0]);  	// 定义函数指针 *pf 指向cmp函数的地址 	int (*pf)(const void*, const void*) = &cmp;  	qsort(arr1, sz,sizeof(arr1[0]),pf);   	for (int i = 0; i < sz; i++) 	{ 		printf("%d ", arr1[i]); 	} 	return 0; }
```


 **1. C语言中出现数组名均等于数组首元素的地址，除了sizeof(数组名)和&(数组名)**

 **2. sizeof(数组名 )=数组在内存单元所占的存储空间大小**

 **3. &(数组名) = 整个数组的地址**

 **4.在用数组名作函数参数时，不是进行值的传送，即不是把实参数组的每一个元素的值都赋予形参数组的各个元素。**

 **5. 数组名作函数参数时所进行的传送只是地址的传送， 也就是说把实参数组的首地址赋予形参数组名。形参数组名取得该首地址之后，也就等于有了实在的数组。实际上是形参数组和实参数组为同一数组，共同拥有一段内存空间。**

 **6. 数组名作函数参数，一般要my_test(arr , k),其中k为数组元素个数**



### 4. 函数嵌套

> **在函数体1中，调用函数2**

```C
# include <stdio.h>void new_line(){	printf("天津欢迎你\n");}void new_line2(){	for (int i = 0; i < 3; i++)		new_line();}int main(){	new_line2();	return 0;}
````



### 5. 函数链式访问

>**把一个函数的返回值作为另外一个函数的参数**

```c
#include <stdio.h>int main(){    printf("%d", printf("%d", printf("%d", 43)));    return 0;}// printf的函数返回值表示的是其返回的字符长度，所以printf("%d",printf("%d",printf("%d",43)))打印4321，// printf("%d",43)返回字符长度2// printf("%d",printf("%d",43))返回字符长度1// 如果在外面再加一个printf打印即printf("%d",printf("%d",printf("%d",printf("%d",43))))打印值43211
```



### 6. 函数递归

> **一个函数在它的函数体内调用它自身称为递归调用**
>
> **递归的两个必要条件 :**
>
> 1. 存在限制条件(不能无限递归下去)
> 2. 每次递归之后更加接近这个限制

```C
// 1.使用循环计算阶乘,不考虑溢出
#include <stdio.h>
int calc(int n)
{
	int acc = 1;
	for (int i = 1; i <= n; i++)
	{
		acc = acc * i;
	}
	return acc;

}
int main()
{
	int n = 10;
	int num = calc(n);
	printf("%d", num);
	return 0;
}

// 2. 使用递归计算阶乘,不考虑溢出
#include <stdio.h>
int calc(int n)
{
	if (1 == n)
		return n;
	else
		return n * calc(n - 1);   //自己调用自己 = 递归
}
int main()
{
	int n = 10;
	int num = calc(n);
	printf("%d", num);
	return 0;
}
```

> 例子：计算斐波那契数列 

```c
#include <stdio.h>
int Fib(int n)
{
	if (1 == n|| 2==n)       // if (1==n) 等同于 if(n==1)
		return 1;
	else
		return Fib(n-1) + Fib(n - 2);     //这种方法计算比较复杂 因为要递归多次，使用效率差
}
int main()
{
	int n = 10;
	int num = Fib(n);
	printf("%d", num);
	return 0;
}
```



### 7. 变量作用域



#### 7.1 局部变量  　

 >　 　   　 　1. 主函数中定义的变量也只能在主函数中使用，不能在其它函数中使用。同时，主函数中也不能使用其它函数中定义的变量。因为主函数也是一个函数，它与其它函数是平行关系。
 >　 　  　 　2. 允许在不同的函数中使用相同的变量名，它们代表不同的对象，分配不同的单元。
 >　 　  　 　3. 在复合语句中也可定义变量，其作用域只在复合语句范围内。



#### 7.2 全局变量  

>  1. 在函数外部定义的变量，其作用域是整个工程。
>  1. 对于局部变量的定义和说明，可以不加区分。而对于外部变量则不然，外部变量的定义和外部变量的说明并不是一回事。外部变量定义必须在所有的函数之外，且只能定义一次，外部变量说明出现在要使用该外部变量的各个函数内
>  1. 外部变量在定义时就已分配了内存单元， 外部变量定义可作初始赋值，外部变量说明不能再赋初始值，  只是表明在函数内要使用某外部变量。
>  1. 在同一源文件中，允许全局变量和局部变量同名。在局部变量的作用域内，全局变量不起作用。



#### 7.3 静态存储和动态存储

> 静态存储变量通常是在变量定义时就分定存储单元并一直保持不变，  直至整个程序结束。  
>
> 动态存储变量是在程序执行过程中，用户分配存储单元， 使用完毕由用户释放.  

|   auto   | 动态存储 |     自动变量      |
| :------: | :------: | :---------------: |
| register | 动态存储 |    寄存器变量     |
|  extern  | 静态存储 | 全局变量/外部变量 |
|  static  | 静态存储 |     静态变量      |




> ```c
> //    在前面各章的程序中所定义的变量凡未加存储类型说明符的都是自动变量int j ,j ,k;        // autochar c;             // auto
> ```
>
> 外部变量外部变量的类型说明符为extern  
>
> 1. 外部变量和全局变量是对同一类变量的两种不同角度的提法。全局变是是从它的作用域提出的，外部变量从它的存储方式提出的，表示了它的生存期。 
> 2. 当一个源程序由若干个源文件组成时， 在一个源文件中定义的外部变量在其它的源文件中也有效。
>
> 静态变量的类型说明符是static   
>
> 1.  静态局部变量在函数内定义，但不象自动变量那样，当调用时就存在，退出函数时就消失。静态局部变量始终存在着，也就是说它的生存期为整个源程序。 
> 2.  **静态局部变量的生存期虽然为整个源程序，但是其作用域仍与自动变量相同，即只能在定义该变量的函数内使用该变量。退出该函数后，  尽管该变量还继续存在，但不能使用它。 **
> 3.  静态全局变量 　这两者的区别虽在于非静态全局变量的作用域是整个源程序， 当一个源程序由多个源文件组成时，非静态的全局变量在各个源文件中都是有效的。** 而静态全局变量则限制了其作用域， 即只在定义该变量的源文件内有效，  在同一源程序的其它源文件中不能使用它**由于静态全局变量的作用域局限于一个源文件内，只能为该源文件内的函数公用，  因此可以避免在其它源文件中引起错误。从以上分析可以看出，  把局部变量改变为静态变量后是改变了它的存储方式即改变了它的生存期。把全局变量改变为静态变量后是改变了它的作用域， 限制了它 的使用范围。因此static  这个说明符在不同的地方所起的作用是不同的。 
>
> 寄存器变量    　
>
> 1. 这种变量存放在CPU的寄存器中，使用时不需要访问内存，而直接从寄存器中读写，  这样可提高效率；寄存器变量的说明符是register。
> 2. 只有局部自动变量和形式参数才可以定义为寄存器变量。因为寄存器变量属于动态存储方式。凡需要采用静态存储方式的量不能定义为寄存器变量。  



## 九. 指针



### 1. 基本概念

>**定义指针的目的是为了通过地址去访问该存储单元的内容**
>
>**指针的大小在32位平台是4个字节，在64位平台是8个字节**
>
>```c
>// 定义指针int* p1=&a;      // 整型指针char* p2=&b;     // 字符指针float* p3=&c;    // 浮点数指针// 指针的类型决定了该指针能访问的字节单元 char*的指针解引用就只能访问一个字节 int*的指针的解引用就能访问四个字节
>```



### 2. 野指针

> **野指针：就是指针指向的位置是不确定的**
>
> 1. 指针未初始化
> 2. 指针越界访问，造成指针指向的地址不确定

```c
// 1.指针未初始化#include <stdio.h>int main(){       int *p;         //指针p未初始化，默认为随机值     *p = 20;    return 0;}// 2.指针越界访问#include <stdio.h>int main(){	int arr[10] = {0};	int *p = arr;	int i = 0;	for(i=0; i<=11; i++)	{		*(p++) = i;  //当指针指向的范围超出数组arr的范围时，p就是野指针	}	return 0;}
```



### 3. 字符指针

>一般使用

```c
# include <stdio.h>int main(){	char ch = 'w';            	char *pc = &ch;           // pc存放ch的地址	*pc = 'w';	return 0;}
```

>还有一种使用方式

```c
# include <stdio.h>int main(){	char* pstr = "hello world";   //常量字符串的首字符 h 的地址存放到指针变量 pstr 中	printf("%s\n", pstr);	return 0;}
```

```c
#include <stdio.h>
int main()
{
	char str1[] = "hello world.";
	char str2[] = "hello world.";
	char *str3 = "hello world.";
	char *str4 = "hello world.";
    if(str1 ==str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if(str3 ==str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	return 0;
}
```

![](C:\Users\Administrator\Pictures\Markdown\微信截图_20210715224535.png)

> **这里str3和str4指向的是一个同一个常量字符串。C/C++会把常量字符串存储到单独的一个内存区域(可读存储区)。
> 但是用相同的常量字符串去初始化不同的数组的时候就会开辟出不同的内存块（栈区）。**
>
> **所以str1和str2不同，str3和str4不同。**



### 4. 数组指针

>**数值指针，本质是一个指针，指针指向一个数组**

```c
int *p[10]      //定义指针数组p，里面有10个元素，每个元素的类型为int*int (*p)[10]    //定义数组指针p，p指向一个大小为10个int类型的数组int* (*p)[10]   //定义数组指针p，p指向一个大小为10个int*类型的数组
```

> **&数组名VS数组名**
>
> **1. arr是数组名，数组名表示数组首元素的地址**
> **2. &arr表示整个数组的地址，而不是首元素的地址** 

 ```c
#include <stdio.h>int main(){	int arr[] = { 1,2,3 };	printf("arr = %p\n", arr);	printf("&arr = %p\n", &arr);	printf("arr + 1 = %p\n", arr+1);	printf("&arr + 1 = %p\n", &arr+1);	return 0;}
 ```

 ![](C:\Users\Administrator\Pictures\Markdown\微信截图_20210716085947.png)

> **注意: &arr表示数组地址，指针的类型决定了其一次可以访问多大的存储空间，数组指针一次可以访问一个数组大小的内存，所以 &arr+1 = arr向后偏移12个字节（整个数组大小 = 12字节）**

 ```c
int arr [10];      // arr 是一个整型数组int *p1[10];      //  p1是一个整型指针数组，数组中有10个元素，每个元素是一个整型指针int (*p2)[10];    //  p2是一个数组指针，p2指向 int [10](int [10]是一个数组类型)int (*p3[10])[20];  // p3是一个指针数组，p3中有10个元素，每个元素的类型为 int (* )[20] (数组指针)，等价于p3是一个数组，数组内每个元素是一个数组指针
 ```



### 5. 一级指针作为函数形参

```c
# include <stdio.h>void print1(int* pa, int sz){    int i = 0;    for (i = 0; i < sz; i++)    {        printf("%d ", pa[i]);    }}void print2(int* pa, int sz){    int i = 0;    for (i = 0; i < sz; i++)    {        printf("%d ", pa[i]);    }}int main(){    int arr[10] = { 1,2,3,4,5,6,7,8,9 };    int* p = arr;    int sz = sizeof(arr) / sizeof(arr[0]);    print1(arr, sz);                       // 传地址            printf("\n");    print2(p, sz);                         // 传一级指针    return 0;}
```

![](C:\Users\Administrator\Pictures\Markdown\微信截图_20210716095658.png)



### 6. 二级指针作为函数形参

```c
#include <stdio.h>void test1(int** ptr){	printf("num = %d\n", **ptr);}void test2(int** ptr){	printf("num = %d\n", **ptr);}void test3(int** ptr){	printf("num = %d\n", **ptr);}int main(){	int n = 10;	int* p = &n;	int** pp = &p;	int* arr[] = { &n };	test1(pp);     //传二级指针	test2(&p);     //传一级指针的地址	test3(arr);   // 传指针数组的数组名	return 0;}
```

> ![](C:\Users\Administrator\Pictures\Markdown\微信截图_20210716100402.png)



### 7. 函数指针

> **用于存放函数地址的指针**

```c
#include <stdio.h>void test(){    printf("hehe\n");}int main(){    printf("%p\n", test);    printf("%p\n", &test);    return 0;}
```

<img src="C:\Users\Administrator\Pictures\Markdown\微信截图_20210716100830.png" style="zoom:50%;" />

> **输出的结果：输出的是两个地址，这两个地址是 test 函数的地址**



### 8. 函数指针数组 

> **函数指针数组将函数的地址存放到一个数组中**
> 使用函数指针数组的实现：

 ```c
#include <stdio.h>int add(int a, int b){	return a + b;}int sub(int a, int b){	return a - b;}int mul(int a, int b){	return a * b;}int div(int a, int b){	return a / b;}int main(){	int x, y;	int input = 1;	int ret = 0;	int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //函数指针数组	while (input)	{		printf("*************************\n");		printf(" 1:add 2:sub \n");		printf(" 3:mul 4:div \n");		printf("*************************\n");		printf("请选择：");		scanf_s("%d", &input);		if ((input <= 4 && input >= 1))		{			printf("输入操作数：");			scanf_s("%d %d", &x, &y);			ret = (*p[input])(x, y);		}		else			printf("输入有误\n");		printf("ret = %d\n", ret);	}	return 0;}
 ```



### 9. 回调函数

**回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数**

```c
// qsort函数
//qosrt函数的使用者得实现一个比较函数
int int_cmp(const void * p1, const void * p2)
{
      return (*( int *)p1 - *(int *) p2);
}

int main()
{
    int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    int i = 0;
    
    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);
    for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)
    {
       printf( "%d ", arr[i]);
    }
    printf("\n");
    return 0;
}


//使用回调函数，模拟实现qsort（采用冒泡的方式）
# include <stdio.h>

int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}

void _swap(void* p1, void* p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}

int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
```



### 10. 指针和数组笔试题解析

>**数组名的意义：**

>1. **sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小**

>2. **&数组名，这里的数组名表示整个数组，取出的是整个数组的地址**

>3. **除此之外所有的数组名都表示首元素的地址**

```c
# include <stdio.h>  int main()  {  	int a[5] = { 1, 2, 3, 4, 5 };  	int *ptr = (int *)(&a + 1);  	printf( "%d,%d", *(a + 1), *(ptr - 1));   // 2   5  	return 0;  }
```

```c
# include <stdio.h>//假设结构体的大小是20个字节  struct Test  {  	int Num;  	char *pcName;  	short sDate; 	char cha[2];  	short sBa[4];  }*p;  //假设p 的值为0x100000。 如下表表达式的值分别为多少？  int main()  {  	printf("%p\n", p + 0x1);             // 0x100000+20 = 0x100014  	printf("%p\n", (unsigned long)p + 0x1);  // 0x100001  	printf("%p\n", (unsigned int*)p + 0x1);  // 0x100004 或者 0x100008   	return 0;  }
```

```c
# include <stdio.h>  int main()  {  	int a[4] = { 1, 2, 3, 4 };  	int *ptr1 = (int *)(&a + 1);  	int *ptr2 = (int *)((int)a + 1);  	printf( "%x,%x", ptr1[-1], *ptr2);  // 4  0x02000000  	return 0;  }
```

```c
  int main()  {  	int a[5][5]; 	 int(*p)[4];  	p = a;  	printf( "%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);  	return 0;  }
```

![111](C:\Users\Administrator\Pictures\Markdown\微信截图_20210716194724.png)

```c
# include <stdio.h>
int main()
  {
  	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  	int *ptr1 = (int *)(&aa + 1);
  	int *ptr2 = (int *)(*(aa + 1));
  	printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1));   // 10 5
  	return 0;
  }
```

```c
  #include <stdio.h>
  int main()
  {
  char *a[] = {"work","at","alibaba"};
  char**pa = a;
  pa++;
  printf("%s\n", *pa);   //at
  return 0;
  }
```

```c
#include <stdio.h>  int main()  {  char *c[] = {"ENTER","NEW","POINT","FIRST"};  char**cp[] = {c+3,c+2,c+1,c};  char***cpp = cp;  printf("%s\n", **++cpp);    //POINT  printf("%s\n", *--*++cpp+3);   //ER  printf("%s\n", *cpp[-2]+3);    //ST  printf("%s\n", cpp[-1][-1]+1);  //EW  return 0;  }
```

![](C:\Users\Administrator\Pictures\Markdown\微信截图_20210716194609.png)



## 十 动态内存管理



### 1. malloc

> **此函数向内存申请一块连续可用的空间，并返回该内存块其起始地址**

```c
void *malloc( size_t size );  // 向堆区申请一块size大小字节的空间#include <stdio.h># include <stdlib.h>int main(){	int* p = (int*)malloc(10 * sizeof(int));  //利用malloc开辟10个字节大小的空间	if (NULL != p)                            // 如果p = NULL ，则说明p开辟空间未成功	{		int i = 0;		for (i = 0; i < 10; i++)		{			p[i] = i;			printf("%d ", p[i]);		}	}	free(p);                                 // 空间释放                     	p = NULL;                            	return 0;}
```



### 2. calloc

> **calloc函数是开辟num个大小为size的动态空间，并未空间内的每个字节初始化为0**

```c
void *calloc( size_t num, size_t size );

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int* p = calloc(10, sizeof(int));   
    if (NULL != p)
    {
        int i = 0;
        for (i = 0; i < 10; i++)
        {
            printf("%d ", p[i]);
        }
    }
    free(p);
    p = NULL;
    return 0;
}
```



### 3. realloc

> **realloc用于调整空间大小**
>
> **realloc的参数：第一个：地址，第二个：字节数
>   对于 realloc 的第一个参数：
>     如果指向空，那么此时realloc 就和 malloc 是一样的；
>     如果不为空，那么就将即将要申请的空间与原空间进行比较。
>         如果要申请的空间比原空间小，就将原空间缩小，并返回原空间首地址
>         如果要申请的空间比原空间大，那么分两种情况：
>         第一种：新旧空间之差小于原空间大小，直接在原空间进行延伸，并返回原空间的首地址。
>         第二种：新旧空间之差大于原空间的大小，那么直接开辟新空间，并将原空间的数据拷贝到新空间，并返回新空间首地址。**

```c
void *realloc( void *ptr, size_t size );  //ptr是待调整的内存地址  size:调整之后的新大小  #include <stdio.h># include <stdlib.h>int main(){    int* p = malloc(100);    if (NULL != p)    {        ;    }    //扩展容量    int * ptr = realloc(p, 1000);       if (NULL != ptr)    {        p = ptr;    }    free(p);    p = NULL;    return 0;}
```



### 4. 动态内存错误

>**(1) 对NULL指针的解引用操作，开辟空间未成功造成NULL指针**
>
>**(2)对动态开辟空间的越界访问**
>
>**（3）对非动态开辟内存使用free释放**
>
>**（4）使用free释放一块动态开辟内存的一部分**
>
>**（5）空间开辟却忘记释放（内存泄漏）**




## 十一 关键字 

### 1. static

> **static修饰全局变量：限定全局变量的作用域，只在变量被定义的.c的文件可以使用，其他.c文件可以通过extern声明去使用**

>**static修饰局部变量:延长局部变量的声明周期，static 修饰的变量存在内存的静态区，所以即使这个函数运行结
>束，这个静态变量的值还是不会被销毁，函数下次使用时仍然能用到这个值**
>
>**static修饰函数: static 使得函数成为静态函数,只可在函数被定义的文件中使用**

```c
# include <stdio.h>static int j;       //静态全局变量void fun1(){	static int i = 0;   // 静态局部变量	i++;}void fun2(){	j = 0;	j++;}int main(){	int k = 0;	for (k = 0; k < 10; k++)	{		fun1();		fun2();	}	return 0;}//  i j 的值最后为 10 1运用debug工具可以查看i,j
```

### 2. return

> **return 用来中止函数并返回返回值**

```c
char * Func(void)
{
	char str[30] = {0};
	return str;
}

//这是一个严重错误：str是函数在栈区创建的对象，函数执行结束，该对象就释放了 return str，相当于把一个已经空间释放后的变量返回，会造成 越界访问的错误
```

### 3. const

> **(1) const 修饰只读变量**
>
> **(2)const修饰变量，不为修饰的变量分配存储空间，而是将它们保存在符号表中**
>
> **(3) const修饰数组**
>
> **(4) const修饰指针**
>
> **(5) const修饰函数参数**
>
> **(6) const修饰函数返回值**

```c
// (1) const 修饰只读变量  （存储在只读存储区）
const char *p = "abcd";

//(2)const修饰变量
const int a = 3;  //# define a 3

//(3) const修饰数组
int const a[3] = {1,2,3};  //数组a是一个可读数组
const int a[3] = {1,2,3};

//(4) const修饰指针
const int *p;    // const 修饰*p (p指向的内存地址中的值)，*p不能被修改
int const *p;	
int* const p;    // const 修饰 p（地址）,不能赋给p其他的地址值，但可以修改p指向的值
const int* const p;   //p所指向的对象的值以及它的地址本身都不能被改变

//(5) const修饰函数参数
void fun(const int i)  //i在函数体内不能被修改
    
// (6)const修饰函数返回值
const int fun(void) //返回值不能被修改

```


## 十二 文件操作



### 1. 文件

>**程序文件：源文件(.c文件)，目标文件（windows系统中的.obj文件   Linux系统下的.o文件，可执行程序(.exe文件)**
>**数据文件：程序运行过程读写的数据**


### 2.文件缓冲区

文件缓冲区是操作系统在内存中为程序中使用的文件开辟一块“文件缓冲区”。从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上；如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），然后再从缓冲区逐个地将数据送到程序数据区。



### 3. fopen / fclose

```c
FILE *fopen( const char *filename, const char *mode );// 1. filename:文件名字// 2. mode : 访问模式// 3. 返回类型FILE* 
```

| 模式字符串 |              含义              | 如果文件已经存在 | 如果文件不存在 |
| :--------: | :----------------------------: | :--------------: | :------------: |
|  **"r"**   |         读（读取文件）         | 从起始位置开始读 |    打开失败    |
|  **"w"**   |      写（对文件进行修改）      | 销毁原始文件内容 | 建立一个新文件 |
|  **"a"**   | append（在原始文件上，加内容） |     写到结尾     | 建立一个新文件 |
|  **"r+"**  |              读写              | 从起始位置开始读 |    打开失败    |
|  **"w+"**  |              读写              | 销毁原始文件内容 | 建立一个新文件 |
|  **"a+"**  |              读写              |     写到结尾     | 建立一个新文件 |

```c
fgetc函数:  int fgetc( FILE *stream );  从输入流中读取一个字符，并返回其ASCII值EOF : 文件结束标志
```

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) 
    {
        perror("File opening failed : ");
        return 0;
    }

    int c;          // 注意：int，非char，要求处理EOF
    while ((c = fgetc(fp)) != EOF) 
    {
        putchar(c);
    }
    fclose(fp);
    fp = NULL;
    return 0;
}
```



### 4.fgetc / fputc

```c
fgetc函数:  int fgetc( FILE *stream );  从输入流中读取一个字符，并返回其ASCII值
fputc函数： int fputc( int c, FILE *stream );  
```

```c
# include <stdio.h>
int main()
{
	FILE* pf = fopen("test.txt", "r");
	int c = fgetc(pf);
	putchar(c);
	return 0;
}


# include <stdio.h>
int main()
{
	FILE* pf = fopen("test.txt", "w");
	int a = fputc(97,pf);         //把ASCII值为97对应的字符写道pf中
	if (!a)
	{
		printf("写入错误");
	}
	else
	{
		printf("写入成功");
	}
	return 0;
}
```



### 5.fgets / fputs

```c
char *fgets( char *string, int n, FILE *stream );
int fputs( const char *string, FILE *stream );
```

```c
# include <stdio.h>
int main()
{
	char *ps = "i am in tianjin";
	FILE* pf = fopen("test1.txt", "w");
	fputs(ps,pf);                //将字符串内容 放到test1.txt中
	fclose(pf);
	pf = NULL;
	return 0;
}


# include <stdio.h>
int main()
{
	char str[15] = { 0 };
	FILE* pf = fopen("test1.txt", "r");
	fgets(str, 10, pf);                // 将pf中的前（n-1）个内容放入到str中
	printf("%s\n", str);
	fclose(pf);
	pf = NULL;
	return 0;
}
```



### 6.fscanf / fprintf

```c
int fscanf( FILE *stream, const char *format [, argument ]... );
int fprintf( FILE *stream, const char *format [, argument ]...);
```

```c
int main()
{
	int a = 0;
	char name[15] = { 0 };
	int b = 0;
	FILE* pf = fopen("test.txt", "r");
	fscanf(pf, "%d %s %d", &a, name, &b);   
	printf("%d %s %d",a, name, b);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct S
{
	char name[15];
	double price;
	double weight;
	int num;
};
int main()
{
	struct S s = { "C language",39.4,0.88,200 };
	FILE* pf = fopen("test.txt", "w");
	fprintf(pf,"%s %lf %lf %d",s.name,s.price,s.weight,s.num);
	return 0;
}
```



### 7.scanf / fscanf /sscanf    printf/fprintf/sprintf

```c
int scanf( const char *format [,argument]... );    //读数据从标准输入流中
int fscanf( FILE *stream, const char *format [, argument ]... );    // 从文件流中读数据
int sscanf( const char *buffer, const char *format [, argument ] ... ); // 从字符串中读数据，并格式化

int printf( const char *format [, argument]... );  // 输出数据到标准输出流
int fprintf( FILE *stream, const char *format [, argument ]...);    //输出数据到问文件流中
int sprintf( char *buffer, const char *format [, argument] ... );   // 输出数据到字符串中
```
