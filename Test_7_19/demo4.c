#define _CRT_SECURE_NO_WARNINGS 1

// 字符串处理函数 + 内存操作函数
// 一 字符串处理函数
//1 . strlen  计算字符串中字符个数 size_t strlen( const char *string)
# include <stdio.h>
# include <string.h>
int main()
{
	char arr[] = "wo xiang chi huoguo";
	printf("%d", strlen(arr));
	return 0;
}

//2. my_strlen 自定义
# include <stdio.h>
# include <assert.h>
int my_strlen(const char* ps)
{
	assert(ps != NULL);    //检验指针有效性
	char* strat = ps;

	while (*ps++);

	return ps - strat - 1;
}
int main()
{
	char arr[] = "wo xiang chi huoguo";
	printf("%d", my_strlen(arr));
	return 0;
}

// 3. strcpy:将字符串1的内容,赋值到字符串2中（字符串2具有足够的空间容纳1）char *strcpy( char *dest, const char *src) 
# include <stdio.h>
# include <string.h>
int main()
{
	char arr1[] = "wo xiang chi huoguo";
	char arr2[50] = " ";
	strcpy(arr2, arr1);
	printf("%s", arr2);
	return 0;
}

// 4.strcpy  自定义
# include <stdio.h>
# include <assert.h>
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);

	char* ret = dest;

	while ((*dest++ = *src++) != '\0');  // 将arr1的对应元素放入到arr2中

	return ret;
}
int main()
{
	char arr1[] = "wo xiang chi huoguo";
	char arr2[50] = " ";
	my_strcpy(arr2, arr1);
	printf("%s", arr2);
	return 0;
}

//5. strcat:将字符串2的内容加到字符串1的内容后面 char *strcat( char *dest, const char *src)
# include <stdio.h>
# include <string.h>
int main()
{
	char arr1[] = "wo xiang chi huoguo";
	char arr2[50] = "jin tian tian qi zhen hao,";
	strcat(arr2, arr1);
	printf("%s", arr2);
	return 0;
}


//6. strcat 自定义
# include <stdio.h>
# include <assert.h>
char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);
	char* start = dest;

	// 1. 找到dest指向的字符串结束位置
	while (*dest != '\0')
	{
		dest++;
	}
	// 2.src对应位置的内容赋值到dest对应位置上
	while ((*dest++ = *src++) != '\0');

	return start;
}
int main()
{
	char arr1[] = "wo xiang chi huoguo";
	char arr2[50] = "jin tian tian qi zhen hao,";
	my_strcat(arr2, arr1);
	printf("%s", arr2);
	return 0;
}

//7. strcmp:将字符串1的内容和字符串的内容进行比较 int strcmp( const char *string1, const char *string2 ) 库函数 
# include <stdio.h>
# include <string.h>
int main()
{
	char arr1[] = "woxiangchihuoguo";
	char arr2[] = "woxiangchiHuoguo";
	int ret = strcmp(arr2, arr1);
	if (!ret)
		printf("arr2 = arr1");
	else
	{
		if (ret > 0)
		{
			printf("arr2 > arr1");
		}
		else
			printf("arr2 < arr1");
	}
	return 0;
}

// 8.my_strcmp 自定义
# include <stdio.h>
# include <assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);

	while (!(*str1 - *str2))  // 如果*str1 = *str2 进循环
	{
		if (!(*str1))         // 判断当前是否为字符串的结束标志
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 > * str2 ?  1:  -1;
}
int main()
{
	char arr1[] = "woxiangchihuoguo";
	char arr2[] = "woxiangchiHuoguo";
	int ret = my_strcmp(arr2, arr1);
	if (!ret)
		printf("arr2 = arr1");
	else
	{
		if (ret > 0)
		{
			printf("arr2 > arr1");
		}
		else
			printf("arr2 < arr1");
	}
	return 0;
}

// 9. my_strncpy  自定义
# include <stdio.h>
# include <assert.h>
char* my_strcpy(char* dest, const char* src,size_t num)
{
	assert(dest != NULL && src != NULL);

	char* ret = dest;

	while (num--&& ((*dest++ = *src++) != '\0'));  // 将arr1的对应元素放入到arr2中

	return ret;
}
int main()
{
	char arr1[] = "wo xiang chi huoguo";
	char arr2[50] = " ";
	int n = 10;
	my_strcpy(arr2, arr1,n);
	printf("%s", arr2);
	return 0;
}

10. my_strncat 自定义
# include <stdio.h>
# include <assert.h>
char* my_strcat(char* dest, const char* src,size_t num)
{
	assert(dest != NULL && src != NULL);
	char* start = dest;
	// 1. 找到dest指向的字符串结束位置
	while (*dest != '\0')
	{
		dest++;
	}
	// 2.src对应位置的内容赋值到dest对应位置上
	while (num--&&((*dest++ = *src++) != '\0'));

	return start;
}
int main()
{
	char arr1[] = "wo xiang chi huoguo";
	char arr2[50] = "jin tian tian qi zhen hao,";
	int n = 10;
	my_strcat(arr2, arr1,n);
	printf("%s", arr2);
	return 0;
}


//11. my_strncmp  自定义
# include <stdio.h>
# include <assert.h>
int my_strcmp(const char* str1, const char* str2,size_t num)
{
	assert(str1 != NULL && str2 != NULL);

	while (!(*str1 - *str2))  // *str1 = *str2 进循环
	{
		if (!num--)           // num = 0 进判断
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 > * str2 ?  1:  -1;
}
int main()
{
	char arr1[] = "woxiangchihuoguo";
	char arr2[] = "woxiangchiHuoguo";
	int ret = my_strcmp(arr2, arr1,3);
	if (!ret)
		printf("arr2 = arr1");
	else
	{
		if (ret > 0)
		{
			printf("arr2 > arr1");
		}
		else
			printf("arr2 < arr1");
	}
	return 0;
}


// 12. strstr 在字符串1中查找字符串2的内容  char *strstr( const char *str1, const char *str2);
# include <stdio.h>
# include <assert.h>
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 !=NULL && p2 != NULL);

	char* s1 = (char*) p1;
	char* s2 = (char*) p2;
	char* cur = (char*)p1;

	// 被查找的字符串不能为空
	if (!*p2)   // 等于   if (*p2=='\0')
	{
		return (char*)p1;
	}
	// 
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2; 
		while (*s1 && *s2 && !(*s1-*s2)) // 等于while((*p1 == '\0')&&(*p2 == '\0')&&(*s1 == *s2)) 
		{
			s1++;
			s2++;
		}
		if (!*s2)
		{
			return cur;   // 找到字串
		}
		if (!*s1)
		{
			return NULL;   // 找到字串
		}
		cur++;
	}
	return NULL;   //找不到字串
}
int main()
{
	char* p1 = "abcdefdfghjk";
	char* p2 = "defq";
	char *ret = my_strstr(p1, p2);
	if (ret == NULL)
	{
		printf("找不到");
	}
	else
		printf("%s", ret);
	return 0;
}

// 13. strtok 
# include <stdio.h>
#include <string.h>
int main()
{
	char arr[] = "xxxxxxxxx@gmail.com";
	char* p = "@.";

	// 切割buffer中的字符串
	char* ret = NULL;

	for (ret = strtok(arr, p); ret; ret = strtok(NULL, p))   // strtok首次调用(arr,p),以后都是(NULL,p)
	{
		printf("%s\n", ret);
	}

	return 0;
}


// 二 内存比较函数
//14 . memcpy:将内存中地址2的内容复制到地址1的内容中 
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

// 15. my_memcpy 自定义
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


//memcpy:处理不重叠的内存拷贝
//memmove 处理重叠内存的拷贝



// 16. my_memmove   自定义
//(1)如果src的地址>dest的地址,从前向后copy  
//(2)如果src的地址<dest的地址,从后向前copy 
# include <assert.h>
# include <stdio.h>
void* my_memmove(void* dest, const void* src, size_t num) 
{
	assert(dest != NULL && src != NULL);

	if ((char*)dest > (char*)src)	
	{	// 从后向前copy
		while (num--)  
		{
			*((char*)dest + num) = *((char*)src + num);
		}
		return (char*)dest;
	}
	else
	{   //从前向后copy
		char* ret = dest;   // 赋值会改变dest的地址，先存储，最后返回dest地址
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
		return ret;
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1, arr1+2, 5*sizeof(arr1[0]));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d  ", arr1[i]);
	}
	return 0;
}

// 17. memcmp：比较内存中N个字节中的字符大小 int memcmp(const void* buf1, const void* buf2, size_t count)  size_t count： 比较的字节个数
# include <stdio.h>
# include<string.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,5,4,3 };
	if (!memcmp(arr1, arr2, 8))
	{
		printf("arr1 = arr2");
	}	
	else
	{
		if (memcmp(arr1, arr2, 4) < 0)
		{
			printf("arr1 < arr2");
		}
		else
		{
			printf("arr1 < arr2");
		}	
	}	
	return 0;
}

// 18. my_memcmp 自定义
# include <stdio.h>
# include <assert.h>
int my_memcmp(const void* dest, const void* src, size_t num)
{
	assert(dest != NULL && src != NULL);

	while ((num--) && (!(*(char*)dest - *(char*)src))) // num自减,当*dest==*src进循环
	{
		++*(char*)src;
		++*(char*)dest;
	}

	if (!num)
	{
		return 0;
	}
	else
	{
		return (*(char*)dest > *(char*)src) ? 1 : -1;
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,5,4,3 };
	int n = 10;
	int ret = my_memcmp(arr1, arr2, n);
	if (!ret)
	{
		printf("arr1 = arr2");
	}
	else
	{
		if (ret < 0)
		{
			printf("arr1 < arr2");
		}
		else
		{
			printf("arr1 < arr2");
		}
	}
	return 0;
}

//19. memset :内存设置函数  void* memset(void* dest, int c, size_t count)
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


