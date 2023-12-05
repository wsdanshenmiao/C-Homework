#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int* Remove(int* arr, int n, int count, int a)//移除轮到3的数，保留最后两个数
{
	int i;
	if (a >= 3) {//两个数以上进行操作
		a = 0;//a为剩余数的个数，每次个数重置为0
		for (i = 0; i < n; i++) {
			if (*(arr + i) == 0) {
				continue;//跳过移除的数
			}
			else {
				if (count == 3) {
					*(arr + i) = 0;//记到3的数移除，即变0
					count = 1;//重新开始计数
				}
				if (*(arr + i) != 0) {//移除完后不进行操作
					count++;//计数
					a++;
				}
			}
		}
	}
	else//剩两个数或以下时结束递归
	{
		return arr;
	}
	Remove(arr, n, count, a);
}

Initialize(int* arr, int n)//将1-n个数有序放进数组内
{
	int i;
	for (i = 0; i < n; i++) {
		*(arr + i) = i + 1;
	}
}

int main()
{
	int n;
	int arr[100000] = { 0 };
	scanf("%d", &n);
	Initialize(&arr[0], n);//将1-n个数有序放进数组内
	for (int i = 0; i < n; i++) {
		if (*(Remove(&arr[0], n, 1, 3) + i) != 0) {//把剩余的两个数打印出来
			printf("%d\n", *(Remove(&arr[0], n, 1, 3) + i));
		}
	}
	return 0;
}

//#include <stdio.h>
//
//void Output(int* arr)//输出
//{
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", *(arr + i));
//	}
//
//}
//
//void Dispose(int* arr)//第一个与最小的互换，最后一个与最大的互换
//{
//	int i;
//	int m = 0;
//	int a = *arr;
//	for (i = 0; i < 10; i++, arr) {
//		if (*(arr + i) < a) {
//			a = *(arr + i);
//			m = i;//第m个数是最小的
//		}
//	}
//	int temp = *arr;//互换
//	*arr = a;
//	*(arr + m) = temp;
//	int b = *arr;
//	for (i = 0; i < 10; i++, arr) {
//		if (*(arr + i) > b) {
//			b = *(arr + i);
//			m = i;//第m个数是最大的
//		}
//	}
//	temp = *(arr + 9);//互换
//	*(arr + 9) = b;
//	*(arr + m) = temp;
//}
//
//void Input(int* arr)//输入10个数
//{
//	int i;
//	for (i = 0; i < 10; i++) {
//		scanf("%d", arr++);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	Input(&arr[0]);//输入10个数
//	Dispose(&arr[0]);//第一个与最小的互换，最后一个与最大的互换
//	Output(&arr[0]);//输出
//	return 0;
//}

//#include <stdio.h>
//
//void Interchange(int* x, int* y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void Ordination(int* a, int* b, int* c)
//{
//	if (*a > *b) {
//		Interchange(a, b);
//	}
//	if (*a > *c) {
//		Interchange(a, c);
//	}
//	if (*b > *c) {
//		Interchange(b, c);
//	}
//}
//
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	Ordination(&a, &b, &c);
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

//#include <stdio.h>
//
//void COUNT(int* a, int* b, int* c, int* d, int* e, char arr[])
//{
//	int i;
//	for (i = 0; arr[i] != '\0'; i++) {
//		if (arr[i] <= 'z' && arr[i] >= 'a')
//			*a += 1;
//		else if (arr[i] <= 'Z' && arr[i] >= 'A')
//			*b += 1;
//		else if (arr[i] <= '9' && arr[i] >= '0')
//			*c += 1;
//		else if (arr[i] = ' ')
//			*d += 1;
//		else
//			*e += 1;
//	}
//}
//
//int main()
//{
//	char arr[] = {"CLANNAD is No1 in my heard"};
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	COUNT(&a, &b, &c, &d, &e ,arr);
//	printf("小写字母有%d个\n", a);
//	printf("大写字母有%d个\n", b);
//	printf("数字有%d个\n", c);
//	printf("空格有%d个\n", d);
//	printf("其他符号有%d个\n", e);
//	return 0;
//}