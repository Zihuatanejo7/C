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
//	// �����ҵ��ַ�������Ϊ��
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
//		while (*s1 && *s2 && !(*s1-*s2)) // ����while((*p1 == '\0')&&(*p2 == '\0')&&(*s1 == *s2)) 
//		{
//			s1++;
//			s2++;
//		}
//		if (!*s2)
//		{
//			return cur;   // �ҵ��ִ�
//		}
//		if (!*s1)
//		{
//			return NULL;   // �ҵ��ִ�
//		}
//		cur++;
//	}
//	return NULL;   //�Ҳ����ִ�
//}
//int main()
//{
//	char* p1 = "abccdefdfghjk";
//	char* p2 = "cde";
//	char *ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�Ҳ���");
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
//	// �и�buffer�е��ַ���
//	char* ret = NULL;
//	for (ret = strtok(arr, p); ret; ret = strtok(NULL, p))   // strtok�״ε���(arr,p),�Ժ���(NULL,p)
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

// ��С���ֽ���
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
//		printf("С��");
//	else
//		printf("���");
//	return 0;
//}

// ��̬�ڴ����
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
//	// ������Ķ�̬�ռ䲻��ʹ�õ�ʱ��Ӧ��free���ͷţ��ռ�
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
//	free(p); // �����ͷŶ�̬���ٵĿռ�
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int* p = (int*)malloc(10);
//	int* ptr = realloc(p, 40);   // ��һ���µı���������realloc�����ķ���ֵ
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
//	free(p); //�����ͷŶ�̬���ٵĿռ�
//	p = NULL;
//
//	return 0;
//}

//struct S
//{
//	int n;
//	int arr[];  // ���������Ա
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
//	int *arr;   //����һ��ָ��
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
//    fwrite(&a, 4, 1, pf);  //�����Ƶ���ʽд���ļ���
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//int main()
//{
//	// ���ļ�д����
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
//	// ���ļ�������
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
//	//fgets(buf,30,stdin);   // �ӱ�׼��������ȡ
//	//fputs(buf, stdout);    // �������׼�����
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
//	// ��ʽ����ʽд
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
//	// ��ʽ����ʽд
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


//�����ƶ���

//�����ƶ���
//struct S 
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	struct S s = { "����",20,55.6 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (NULL == pf)
//	{
//		return 0;
//	}
//	//��������ʽд�ļ�
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
//	//��������ʽ���ļ�
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
//	// 1.��λ�ļ�ָ��
//	fseek(pf, -2, SEEK_END);
//	// 2.��ȡ�ļ�
//	printf("%c", fgetc(pf));
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

// fprintf
//# include <stdio.h>
//int main()
//{
//	printf("%s\n", __FILE__);    // �ļ�����
//	printf("%d\n", __LINE__);    //  �к�
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//
//	// д��־�ļ�
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
//    int c;          // ע�⣺int����char��Ҫ����EOF
//    while ((c = fgetc(fp)) != EOF) 
//    {
//        putchar(c);
//    }
//    fclose(fp);
//    fp = NULL;
//    return 0;
//}
