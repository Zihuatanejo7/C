# define _CRT_SECURE_NO_WARNINGS 1
  
// 1.����ָ����Ϊ�����β� 

# include <stdio.h>
# include <assert.h>

void print2(int(*p)[5], int row, int col)
{	
	assert(NULL != p);

	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf("%d ", p[i][j]); 
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print2(arr, 3, 5);
	return 0;
}

// 2. ����ָ������(ת�Ʊ�)

# include <stdio.h>

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x/y;
}

int main()
{
	int (*p[4])(int, int) = { add,sub,mul,div };   // ����ָ������
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d \n", p[i](2, 3));
	}
	return 0;
}


// 3. ����ָ������ʵ��
# include <stdio.h>

void menu()
{
	printf("****    1. add        2.sub    ****\n");
	printf("****    3. mul        4.div    *****\n");
	printf("****          0.exit           *****\n");
}

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul (int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

int main(void)
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	int (*pf[5])(int,int)= {0, add, sub, mul, div};
	do
	{
		menu();
		printf("�����������:");
		scanf("%d", &input);

		if (!input)   // if (input == 0)
		{
			printf("�������������ϵͳ�˳�!!!\n");
			break;
		}
		else if ((input > 0) && (input < 5))
		{
			printf("����������������:");
			scanf("%d %d", &x, &y);
			ret = pf[input](x, y);
			printf("%d\n", ret);
		}
		else
		{
			printf("�����������������������!!!\n");
		}
	} while (input);
	return 0;
}


//4 .ð������
# include <stdio.h>

void bubble_sort(int arr[], int sz)
{
	// ȷ������
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		// ȷ��ÿ�˱ȽϵĴ���
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main(void) 
{
	int arr[] = { 6,7,8,9,10,1,2,3,4,5, };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	bubble_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


// 5. �⺯���е�qsort����
// qsort()
// ����1���������������Ԫ�ص�ַ
// ����2�������������Ԫ�ظ���
// ����3�������������ÿ��Ԫ�ش�С 
// ����4������ָ�룬�Ƚ�����Ԫ�����õĺ����ĵ�ַ��user�Լ����壩
// ����5������ָ�����������ǣ����Ƚϵ�����Ԫ�صĵ�ַ
# include <stdio.h>
# include <string.h>
# include <assert.h>

struct stu
{
	char ID[12];
	int age;
	char sex[7];
	double weight;
};

// ����ѧ��������
int ID_cmp(const void* e1, const void* e2)
{
	assert(NULL != e1);
	assert(NULL != e2);
	return strcmp(((struct stu*)e1)->ID, ((struct stu*)e2)->ID);
}

// �����Ա�������
int Sex_cmp(const void* e1, const void* e2)
{
	assert(NULL != e1);
	assert(NULL != e2);
	return strcmp(((struct stu*)e1)->sex, ((struct stu*)e2)->sex);
}

// ��������������
int Age_cmp(const void* e1, const void* e2)
{
	assert(NULL != e1);
	assert(NULL != e2);
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

// ��������������
int Weight_cmp(const void* e1, const void* e2)
{
	assert(NULL != e1);
	assert(NULL != e2);
	return (int)((struct stu*)e1)->weight - ((struct stu*)e2)->weight;
}

int main(void)
{
	int i = 0;

	struct stu s[4] = { {"1910310010",24,"male",59.9}, {"1910310005",21,"female",48.2}, {"1910310007",22,"female",55.0}, {"1910310009",23,"male",57.0} };

	// ����ָ������
	int (*pf[4])(const void*, const void*) = { ID_cmp,Sex_cmp,Age_cmp,Weight_cmp };
	
	for (i = 0; i < 4; i++)
	{
		qsort(s, sizeof(s) / sizeof(s[0]), sizeof(struct stu), pf[i]);
	}
	return 0;
}



// 6.����ð�����򷽷����������͵����ݽ�������
# include <stdio.h>
# include <assert.h>

int int_cmp(const void* e1, const void* e2)
{
	assert(NULL != e1);
	assert(NULL != e2);

	return *(int*)e1 - *(int*)e2;
}

void _swap(const void* p1, const void* p2, size_t len)
{
	int i = 0;
	for (i = 0; i < len - 1; i++)
	{
		char tmp = *((char*)p1+i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void bubble(void* base, size_t num, size_t width, int (*pf)(const void*e1,const void*e2))
{
	int i = 0;
	//ȷ������
	for (i = 0; i < num - 1; i++)
	{
		// ȷ��ÿ�˱ȽϵĴ���
		int j = 0;
		for (j = i; j <= num  - 1; j++)
		{
			if ((*pf)(((int*)base + i), ((int*)base + j)) > 0)
			{
				_swap(((int*)base + i), ((int*)base + j),4);
			}	
		}
	}
}

int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int),int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}


//7.����ð�����򷽷���5�нṹ��ѧ�Ž�������
# include <stdio.h>
# include <string.h>
# include <assert.h>

struct stu
{
	char ID[12];
	int age;
	char sex[7];
	double weight;
};

// ����ѧ��������
int ID_cmp(const void* e1, const void* e2)
{
	assert(NULL != e1);
	assert(NULL != e2);

	return strcmp(((struct stu*)e1)->ID, ((struct stu*)e2)->ID);
}

void _swap(const void* p1, const void* p2,int num)
{
	assert(NULL != p1);
	assert(NULL != p2);

	int i = 0;
	for (i = 0; i < num; i++)
	{
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void bubble_sort(void *base, size_t num, size_t width, int (*pf)(const void* e1, const void* e2))
{
	assert(NULL != base);

	int i = 0;
	for (i = 0; i < num; i++)
	{
		int j = 0;
		for (j = i; j <= num - 1; j++)
		{
			// ����Ԫ�����
			if (ID_cmp(((struct stu*)base + i), ((struct stu*)base + j)) > 0)
			{
				_swap(((struct stu*)base + i), ((struct stu*)base + j), width);
			}
		}
	}
}

int main(void)
{

	struct stu s[4] = { {"1910310010",24,"male",59.9}, {"1910310005",21,"female",48.2}, {"1910310007",22,"female",55.0}, {"1910310009",23,"male",57.0} };

	bubble_sort(s, sizeof(s)/sizeof(s[0]), sizeof(struct stu), ID_cmp);

	return 0;
}

// 8. ��2-ά������ �����ض���ֵ
# include <stdio.h>

int find_target(int arr[], int sz, int target)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (target < arr[mid])
		{
			right = mid - 1;
		}
		else if (target > arr[mid])
		{
			left = mid + 1;
		}
		else
			return 1;
	}
	return 0;
}

int main()
{
	int arr[4][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	int target = 7;
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (find_target(arr[i], 4, target))     // һ���ȴ�һ��һά��������
			printf("true \n");
		else
			printf("false \n");
	}
	return 0;
}

// 9. ��һ�������е�������������ǰ��
# include <stdio.h>

void adjust_order(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		//������ǰ����ż��
		if (arr[i] % 2 == 0)
		{
			int j = sz - 1;
			//���������������
			for (j = sz - 1;j>i; j--)
			{
				if (arr[j] % 2 != 0)
				{
					// ����
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
					break;
				}
			}
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	adjust_order(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}



// 10.һ�����־���ÿ�д������ҵ������������µ���
# include <stdio.h>

int FindNum(int arr[3][3], int k, int *px, int* py)
{
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	// �Ҳ���
	return 0;
}

int main()
{
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int k = 7;		        //target
	int x = 3;
	int y = 3;
	int ret = FindNum(arr, k, &x, &y);
	if (1 == ret)
	{
		printf("�ҵ���	,�±�Ϊ:%d %d", x, y);
	}
	else
	{
		printf("�Ҳ�����");
	}
	return 0;
}