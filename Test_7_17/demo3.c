# define _CRT_SECURE_NO_WARNINGS 1
  
// 1.数组指针作为函数形参 

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

// 2. 函数指针数组(转移表)

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
	int (*p[4])(int, int) = { add,sub,mul,div };   // 函数指针数组
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d \n", p[i](2, 3));
	}
	return 0;
}


// 3. 函数指针数组实例
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
		printf("请输入操作符:");
		scanf("%d", &input);

		if (!input)   // if (input == 0)
		{
			printf("操作符输入错误，系统退出!!!\n");
			break;
		}
		else if ((input > 0) && (input < 5))
		{
			printf("请输入两个操作数:");
			scanf("%d %d", &x, &y);
			ret = pf[input](x, y);
			printf("%d\n", ret);
		}
		else
		{
			printf("操作符输入错误，请重新输入!!!\n");
		}
	} while (input);
	return 0;
}


//4 .冒泡排序
# include <stdio.h>

void bubble_sort(int arr[], int sz)
{
	// 确定趟数
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		// 确定每趟比较的次数
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


// 5. 库函数中的qsort函数
// qsort()
// 参数1：待排序数组的首元素地址
// 参数2：待排序数组的元素个数
// 参数3：待排序数组的每个元素大小 
// 参数4：函数指针，比较两个元素所用的函数的地址（user自己定义）
// 参数5：函数指针两个参数是：带比较的两个元素的地址
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

// 按照学号排序函数
int ID_cmp(const void* e1, const void* e2)
{
	assert(NULL != e1);
	assert(NULL != e2);
	return strcmp(((struct stu*)e1)->ID, ((struct stu*)e2)->ID);
}

// 按照性别排序函数
int Sex_cmp(const void* e1, const void* e2)
{
	assert(NULL != e1);
	assert(NULL != e2);
	return strcmp(((struct stu*)e1)->sex, ((struct stu*)e2)->sex);
}

// 按照年龄排序函数
int Age_cmp(const void* e1, const void* e2)
{
	assert(NULL != e1);
	assert(NULL != e2);
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

// 按照体重排序函数
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

	// 函数指针数组
	int (*pf[4])(const void*, const void*) = { ID_cmp,Sex_cmp,Age_cmp,Weight_cmp };
	
	for (i = 0; i < 4; i++)
	{
		qsort(s, sizeof(s) / sizeof(s[0]), sizeof(struct stu), pf[i]);
	}
	return 0;
}



// 6.利用冒泡排序方法对所有类型的数据进行排序
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
	//确定趟数
	for (i = 0; i < num - 1; i++)
	{
		// 确定每趟比较的次数
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


//7.利用冒泡排序方法对5中结构体学号进行排序
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

// 按照学号排序函数
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
			// 两个元素相比
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

// 8. 在2-维数组中 查找特定数值
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
		if (find_target(arr[i], 4, target))     // 一次先从一个一维数组中找
			printf("true \n");
		else
			printf("false \n");
	}
	return 0;
}

// 9. 把一个数组中的奇数放在数组前面
# include <stdio.h>

void adjust_order(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		//从数组前面找偶数
		if (arr[i] % 2 == 0)
		{
			int j = sz - 1;
			//从数组后面找奇数
			for (j = sz - 1;j>i; j--)
			{
				if (arr[j] % 2 != 0)
				{
					// 交换
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



// 10.一个数字矩阵，每行从左向右递增，从上往下递增
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
	// 找不到
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
		printf("找到了	,下标为:%d %d", x, y);
	}
	else
	{
		printf("找不到了");
	}
	return 0;
}