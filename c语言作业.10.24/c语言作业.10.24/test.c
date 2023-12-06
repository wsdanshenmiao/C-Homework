#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int b = 7;
//	char arr[] = "       ";
//	for (int i = 0;i<7;i++,b--)
//	{
//		if (i < 4)
//		{
//			arr[3 - i] = arr[3 + i] = '*';
//			printf("%s\n", arr);
//		}
//		else
//		{
//			arr[3-b] = arr[3+b] = ' ';
//			printf("%s\n", arr);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int i;
//	for (i = 0; i < 9; i++)
//	{
//		a=(a+1)*2;
//	}
//	printf("%d", a);
//	return 0;
//}

//int FB(int n)//求第n项斐波那契数列
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	for (; n > 2; n--)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//}
//
//int main()
//{
//	double sum = 0;
//	int n = 2;
//	int x;
//	scanf("%d", &x);
//	for (int i = 0; i < x; i++,n++)
//	{
//	    double s1 = FB(n);
//		double s2 = FB(n + 1);
//		double sl = s2 / s1;
//		sum=sum+sl;//x项求和
//	}
//	printf("%f", sum);
//	return 0;
//}