#define _CRT_SECURE_NO_WARNINGS 1


// my_strstr
//# include <stdio.h>
//#include <string.h>
//#include <assert.h>
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(NULL != p1);
//	assert(NULL != p2);
//
//	char* s1 = (char*) p1;
//	char* s2 = (char*) p2;
//	char* cur = (char*)p1;
//
//	// 被查找的字符串不能为空
//	if (!*p2)   //    if (*p2=='\0')
//	{
//		return (char*)p1;
//	}
//
//	// 
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char*)p2; 
//		while (*s1 && *s2 && !(*s1-*s2)) // 等于while((*p1 == '\0')&&(*p2 == '\0')&&(*s1 == *s2)) 
//		{
//			s1++;
//			s2++;
//		}
//		if (!*s2)
//		{
//			return cur;   // 找到字串
//		}
//		if (!*s1)
//		{
//			return NULL;   // 找到字串
//		}
//		cur++;
//	}
//	return NULL;   //找不到字串
//}
//int main()
//{
//	char* p1 = "abccdefdfghjk";
//	char* p2 = "cde";
//	char *ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("找不到");
//	}
//	else
//		printf("%s", ret);
//	return 0;
//}

//strtok
//# include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = "zhaozhiyang1997@gmail.com";
//	char* p = "@.";
//	char buffer[1024] = { 0 };
//	strcpy(buffer, arr);
//	// 切割buffer中的字符串
//	char* ret = NULL;
//	for (ret = strtok(arr, p); ret; ret = strtok(NULL, p))   // strtok首次调用(arr,p),以后都是(NULL,p)
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

// 大小端字节序
//int check()
//{
//	union un
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//
//int main() 
//{
//	int a = 1;
//	if (check())
//		printf("小端");
//	else
//		printf("大端");
//	return 0;
//}

// 动态内存管理
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
//
//int main()
//{
//	int *p = (int *)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			p[i] = i;
//			printf("%d ", p[i]);
//		}
//	}
//
//	// 当申请的动态空间不再使用的时候，应该free（释放）空间
//	free(p);
//	p = NULL;  
//	return 0;
//}

# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
//int main()
//{
//	int* p =(int*)calloc(10, sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", p[i]);
//		}
//	}
//	free(p); // 用于释放动态开辟的空间
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int* p = (int*)malloc(10);
//	int* ptr = realloc(p, 40);   // 用一个新的变量来接受realloc函数的返回值
//
//	if (NULL != ptr)
//	{
//		p = ptr;
//		int i = 0;
//		for (i = 5; i < 10; i++)
//		{
//			printf("%d ", (p[i]=i));
//		}
//
//	}
//
//	free(p); //用于释放动态开辟的空间
//	p = NULL;
//
//	return 0;
//}

//struct S
//{
//	int n;
//	int arr[];  // 柔性数组成员
//};
//int main()
//{
//	// printf("%d", sizeof(struct S));
//	struct S* p = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	p->n = 100;
//	int i = 0;
//	for(i = 0; i < 10; i++)
//	{
//		p->arr[i] = i;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	int *arr;   //定义一个指针
//};
//
//int main()
//{
//	printf("%d", sizeof(struct S));
//	int i = 0;
//	struct S* p = (struct S*)malloc(sizeof(struct S));
//	p->n = 100;
//	p->arr = (int*)malloc(10 * sizeof(int));
//
//	for (i = 0; i < 10; i++)
//	{
//		p->arr[i] = i;
//	}
//
//	free(p->arr); 
//	p->arr = NULL;
//	free(p);
//	p = NULL;
//	return 0;
//}

//# include <stdlib.h>
//# include <string.h>
//# include <errno.h>
//# include <stdio.h>
//struct M
//{
//	char c;
//	int a[];
//};
//int main()
//{
//	struct M m = {0};
//	int i = 0;
//	struct M* p = (struct M*)malloc(sizeof(struct M) + 10 * sizeof(int));
//	if (p != NULL)
//	{
//		p->c = 'c';
//		for (i = 0; i < 10; i++)
//		{
//			p->a[i] = i;
//			printf("%d ", p->a[i]);
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//    int a = 10000;
//    FILE* pf = fopen("test.txt", "wb");
//    fwrite(&a, 4, 1, pf);  //二进制的形式写到文件中
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//int main()
//{
//	// 向文件写数据
//	FILE* pf = fopen("test.txt", "w");
//	fputc('b', pf);
//	fputc(' ', pf);
//	fputc('a', pf);
//	fputc('t', pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	// 向文件读数据
//	FILE* pf = fopen("test.txt", "r");
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//# include <stdio.h>
//# include <errno.h>
//# include <string.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (NULL == pf)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//# include <stdio.h>
//# include <errno.h>
//# include <string.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	char buf[30] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	fgets(buf, 30, pf);
//	printf("%s", buf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char buf[30] = { 0 };
//	//fgets(buf,30,stdin);   // 从标准输入流读取
//	//fputs(buf, stdout);    // 输出到标准输出流
//
//	gets(buf);
//	puts(buf);
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14f,"hello" };
//	FILE* pf = fopen("test.txt","w");
//	if (NULL == pf)
//	{
//		return 0;
//	}
//	// 格式化形式写
//	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 0 };
//	//FILE* pf = fopen("test.txt","r");
//	// 格式化形式写
//	/*fscanf(pf, "%d%f%s", &s.n, &s.score, s.arr);
//	printf("%d %f %s", s.n, s.score, s.arr);*/
//
//	fscanf(stdin, "%d %f %s", &s.n, &s.score, s.arr);
//
//	fprintf(stdout,"%d %f %s", s.n, s.score, s.arr);
//	//fclose(pf);
//	//pf = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14f,"abcdef"};
//	struct S tmp = { 0 };
//	char buf[30] = { 0 };
//	sprintf(buf,"%d %f %s", s.n, s.score, s.arr);
//	printf("%s\n", buf);
//
//	sscanf(buf, "%d %f %s",&tmp.n,&tmp.score,tmp.arr);
//	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
//	return 0;
//}


//二进制读入

//二进制读出
//struct S 
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	struct S s = { "张三",20,55.6 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (NULL == pf)
//	{
//		return 0;
//	}
//	//二进制形式写文件
//	fwrite(&s,sizeof(struct S),1,pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "rb");
//	if (NULL == pf)
//	{
//		return 0;
//	}
//	//二进制形式读文件
//	fread(&s, sizeof(struct S), 1, pf);
//	printf("%s %d %lf", s.name, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		return 0;
//	}
//	// 1.定位文件指针
//	fseek(pf, -2, SEEK_END);
//	// 2.读取文件
//	printf("%c", fgetc(pf));
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

// fprintf
//# include <stdio.h>
//int main()
//{
//	printf("%s\n", __FILE__);    // 文件名称
//	printf("%d\n", __LINE__);    //  行号
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//
//	// 写日志文件
//	int i = 0;
//	int arr[10] = { 0 };
//	FILE* pf = fopen("log.txt", "w");
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		fprintf(pf, "file : %s line : %d date : %s time : %s i = %d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
//	}
//	fclose(pf);
//	pf = NULL;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d",arr[i]);
//	}
//	return 0;
//}

// fgetc
//#include <stdio.h>
//#include <stdlib.h>
//int main(void)
//{
//    FILE* fp = fopen("test.txt", "r");
//    if (fp == NULL) 
//    {
//        perror("File opening failed : ");
//        return 0;
//    }
//
//    int c;          // 注意：int，非char，要求处理EOF
//    while ((c = fgetc(fp)) != EOF) 
//    {
//        putchar(c);
//    }
//    fclose(fp);
//    fp = NULL;
//    return 0;
//}
