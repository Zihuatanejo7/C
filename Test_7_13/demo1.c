// 1. ��ӡ100-200֮�������
//#include<stdio.h>
//#include<math.h>
//int main() 
//{
//	int i = 0;
//	int flag = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		for (int j = 2; j <= (int)sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag)
//		{
//			flag = 0;
//		}
//		else
//			printf("%d������\n", i);
//	}
//	return 0;
//}


// 2.����˷��ھ���
# include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d = %d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

// 3. �ж�1000��-2000��֮�������
//# include <stdio.h>
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//		{
//			printf("%d��������\n", year);
//		}
//	}
//	return 0;
//}

// 4.�����������ͱ�����ֵ
//# include <stdio.h>
//void Swap(int* pn, int* pm)
//{
//	int tmp = *pn;
//	*pn = *pm;
//	*pm = tmp;
//}
//int main()
//{
//	int n = 0, m = 0;
//	printf("����������ֵ>:");
//	scanf_s("%d %d", &n, &m);
//	printf("����֮ǰn = %d ,m = %d\n", n, m);
//	Swap(&n, &m);
//	printf("����֮��n = %d ,m = %d\n", n, m);
//}

// 5.��������ʱ����������������������(���ķ���)
//#include<stdio.h>
//int main()
//{
//	int n = 0, m= 0;
//	n = 5;
//	m = 7;
//	printf("����֮ǰn = %d ,m = %d\n", n, m);
//	n = n ^ m;
//	m = n ^ m;
//	n = n ^ m;
//	printf("����֮��n = %d ,m = %d\n", n, m);
//	return 0;
//}

//6.��10�����������ֵ
//# include <stdio.h>
//int main()
//{
//	int arr[] = { 1,3,6,7,8,2,10,5,6,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);  //�������Ԫ�ظ���
//	int i = 0;
//	int max = arr[0];                      // �ȸ�max��ʼ�������������max�ȴ�С
//	for (i = 1; i < sz; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//	printf("max = % d", max);
//	return 0;
//}

// 7.�������������Լ��
//# include <stdio.h>
//int main()
//{
//	int x = 0, y = 0;
//	scanf_s("%d %d", &x, &y);
//	int i = 0;
//	for (i = (x < y) ? x : y;i>=1 ; i--)
//	{
//		if (1==i)
//			printf("%d��%d�޹�Լ��", x, y);
//		else if ((x % i == 0) && (y % i) == 0)
//		{
//			printf("%d��%d��%d�����Լ��\n", i, x, y);
//			break;
//		}
//	}
//	return 0;
//}

//8. ������A�е����ݺ�����B�е����ݽ��н���
//# include <stdio.h>
//void Swap_array(int arr1[], int arr2[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = arr1[i];
//	}
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 6,7,8,9,10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	printf("����ǰ��arr1:");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	Swap_array(arr1, arr2, sz);
//	printf("\n�������arr1:");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

// 9.����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ
//# include <stdio.h>
//int main()
//{
//	double sum = 0.0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i%2!=0)
//			sum += 1.0 / i;
//		else
//			sum -= 1.0 / i;
//	}
//	printf("%lf", sum);
//	return 0;
//}

//10. ��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
//# include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100; i ++ )
//	{
//		if ((i % 10 == 9) || (i / 10 == 9))
//			printf("%d \n", i);
//	}
//	return 0;
//}

// 11.����Ļ���������
//# include <stdio.h>
//int main()
//{
//	int line = 19;
//	//scanf_s("%d", &n);
//    int i = 0;
//    for (i = 1; i <= line ; i++)
//    {
//        if (i <= line / 2 + 1)
//        {
//            int j = 0;
//            for (j = 1; j <= line; j++)
//            {
//                if (j >= ((line + 1) / 2 + 1 - i) && j <= ((line + 1) / 2 + 1 - i + 2 * i - 2))   //�ϰ벿��*����ʼλ�ã���ÿ�д�ӡ����Ϊ2*i-1
//                    printf("*");
//                else
//                    printf(" ");
//            }
//            printf("\n");
//        }
//        else
//        {
//            int j = 0;
//            for (j = 1; j <= line; j++)
//            {
//                if (j >= (i -(line+1)/2+1) && j <= (i- (line + 1) / 2 +1+2*(line+1-i)-2))  //�°벿��*����ʼλ�ã���ÿ�д�ӡ����Ϊ2*(line+1-i)-1
//                    printf("*");
//                else
//                    printf(" ");
//            }
//            printf("\n");
//        }
//    }
//	return 0;
//}

// 12 ���0��999֮������С�ˮ�ɻ����������
//# include <stdio.h>
//# include <math.h>
//int main()
//{
//	int i = 0;
//	
//	for (i = 100; i < 1000; i++)
//	{
//		int ret = i;
//		int tmp = 0;
//		int sum = 0;
//		while (ret)
//		{
//			int tmp = ret % 10;
//			sum += (int)pow(tmp, 3);
//			ret /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d��ˮ�ɻ���\n", i);
//		}
//	}
//	return 0;
//}

// 13.  ��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ������
//# include <stdio.h>
//#include <math.h>
//int main()
//{
//	int a = 2;
//	int n = 4;
//	int i = 0;
//	int ret = 0;
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		//��n����
//		ret = 10 * ret+ a;
//        printf("%d+", ret);
//		sum += ret;
//	}
//	printf(" = %d", sum);
//	return 0;
//}
