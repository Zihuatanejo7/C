#define _CRT_SECURE_NO_WARNINGS 1

// �ַ��������� + �ڴ��������
// һ �ַ���������
//1 . strlen  �����ַ������ַ����� size_t strlen( const char *string)
# include <stdio.h>
# include <string.h>
int main()
{
	char arr[] = "wo xiang chi huoguo";
	printf("%d", strlen(arr));
	return 0;
}

//2. my_strlen �Զ���
# include <stdio.h>
# include <assert.h>
int my_strlen(const char* ps)
{
	assert(ps != NULL);    //����ָ����Ч��
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

// 3. strcpy:���ַ���1������,��ֵ���ַ���2�У��ַ���2�����㹻�Ŀռ�����1��char *strcpy( char *dest, const char *src) 
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

// 4.strcpy  �Զ���
# include <stdio.h>
# include <assert.h>
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);

	char* ret = dest;

	while ((*dest++ = *src++) != '\0');  // ��arr1�Ķ�ӦԪ�ط��뵽arr2��

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

//5. strcat:���ַ���2�����ݼӵ��ַ���1�����ݺ��� char *strcat( char *dest, const char *src)
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


//6. strcat �Զ���
# include <stdio.h>
# include <assert.h>
char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);
	char* start = dest;

	// 1. �ҵ�destָ����ַ�������λ��
	while (*dest != '\0')
	{
		dest++;
	}
	// 2.src��Ӧλ�õ����ݸ�ֵ��dest��Ӧλ����
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

//7. strcmp:���ַ���1�����ݺ��ַ��������ݽ��бȽ� int strcmp( const char *string1, const char *string2 ) �⺯�� 
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

// 8.my_strcmp �Զ���
# include <stdio.h>
# include <assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);

	while (!(*str1 - *str2))  // ���*str1 = *str2 ��ѭ��
	{
		if (!(*str1))         // �жϵ�ǰ�Ƿ�Ϊ�ַ����Ľ�����־
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

// 9. my_strncpy  �Զ���
# include <stdio.h>
# include <assert.h>
char* my_strcpy(char* dest, const char* src,size_t num)
{
	assert(dest != NULL && src != NULL);

	char* ret = dest;

	while (num--&& ((*dest++ = *src++) != '\0'));  // ��arr1�Ķ�ӦԪ�ط��뵽arr2��

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

10. my_strncat �Զ���
# include <stdio.h>
# include <assert.h>
char* my_strcat(char* dest, const char* src,size_t num)
{
	assert(dest != NULL && src != NULL);
	char* start = dest;
	// 1. �ҵ�destָ����ַ�������λ��
	while (*dest != '\0')
	{
		dest++;
	}
	// 2.src��Ӧλ�õ����ݸ�ֵ��dest��Ӧλ����
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


//11. my_strncmp  �Զ���
# include <stdio.h>
# include <assert.h>
int my_strcmp(const char* str1, const char* str2,size_t num)
{
	assert(str1 != NULL && str2 != NULL);

	while (!(*str1 - *str2))  // *str1 = *str2 ��ѭ��
	{
		if (!num--)           // num = 0 ���ж�
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


// 12. strstr ���ַ���1�в����ַ���2������  char *strstr( const char *str1, const char *str2);
# include <stdio.h>
# include <assert.h>
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 !=NULL && p2 != NULL);

	char* s1 = (char*) p1;
	char* s2 = (char*) p2;
	char* cur = (char*)p1;

	// �����ҵ��ַ�������Ϊ��
	if (!*p2)   // ����   if (*p2=='\0')
	{
		return (char*)p1;
	}
	// 
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2; 
		while (*s1 && *s2 && !(*s1-*s2)) // ����while((*p1 == '\0')&&(*p2 == '\0')&&(*s1 == *s2)) 
		{
			s1++;
			s2++;
		}
		if (!*s2)
		{
			return cur;   // �ҵ��ִ�
		}
		if (!*s1)
		{
			return NULL;   // �ҵ��ִ�
		}
		cur++;
	}
	return NULL;   //�Ҳ����ִ�
}
int main()
{
	char* p1 = "abcdefdfghjk";
	char* p2 = "defq";
	char *ret = my_strstr(p1, p2);
	if (ret == NULL)
	{
		printf("�Ҳ���");
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

	// �и�buffer�е��ַ���
	char* ret = NULL;

	for (ret = strtok(arr, p); ret; ret = strtok(NULL, p))   // strtok�״ε���(arr,p),�Ժ���(NULL,p)
	{
		printf("%s\n", ret);
	}

	return 0;
}


// �� �ڴ�ȽϺ���
//14 . memcpy:���ڴ��е�ַ2�����ݸ��Ƶ���ַ1�������� 
# include <stdio.h>
# include <string.h>
struct S
{
	char name[20];
	int age;
};
int main()
{
	struct S arr3[] = { {"����",20},{"����",22} };
	struct S arr4[3] = { 0};

	memcpy(arr4, arr3, sizeof(arr3));
	printf("%d ", arr4[0].age);
	printf("%d ", arr4[1].age);
	return 0;
}

// 15. my_memcpy �Զ���
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


//memcpy:�����ص����ڴ濽��
//memmove �����ص��ڴ�Ŀ���



// 16. my_memmove   �Զ���
//(1)���src�ĵ�ַ>dest�ĵ�ַ,��ǰ���copy  
//(2)���src�ĵ�ַ<dest�ĵ�ַ,�Ӻ���ǰcopy 
# include <assert.h>
# include <stdio.h>
void* my_memmove(void* dest, const void* src, size_t num) 
{
	assert(dest != NULL && src != NULL);

	if ((char*)dest > (char*)src)	
	{	// �Ӻ���ǰcopy
		while (num--)  
		{
			*((char*)dest + num) = *((char*)src + num);
		}
		return (char*)dest;
	}
	else
	{   //��ǰ���copy
		char* ret = dest;   // ��ֵ��ı�dest�ĵ�ַ���ȴ洢����󷵻�dest��ַ
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

// 17. memcmp���Ƚ��ڴ���N���ֽ��е��ַ���С int memcmp(const void* buf1, const void* buf2, size_t count)  size_t count�� �Ƚϵ��ֽڸ���
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

// 18. my_memcmp �Զ���
# include <stdio.h>
# include <assert.h>
int my_memcmp(const void* dest, const void* src, size_t num)
{
	assert(dest != NULL && src != NULL);

	while ((num--) && (!(*(char*)dest - *(char*)src))) // num�Լ�,��*dest==*src��ѭ��
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

//19. memset :�ڴ����ú���  void* memset(void* dest, int c, size_t count)
# include <stdio.h>
struct S
{
	int book;
	int age;
};
int main()
{
	
	struct S user[10];
	printf("struct S ������ռ���ֽڴ�СΪ = %d\n", sizeof(struct S));
	memset(user, '#', 8);   //һ���ֽڵ�����
	printf("%d  ", user[0].book);
	printf("%d\n ", user[0].age);
	return 0;
}


