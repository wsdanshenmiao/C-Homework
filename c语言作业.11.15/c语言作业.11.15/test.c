#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Compute(int year, int month, int day)
{
	int i;
	int ret = 0;
	for (i = 1; i < month; i++) {
		if (i == 2) {
			int y = Judge_leap(year);
			ret += (28 + y);
		}
		else if (i % 2 != 0 && i != 9 && i != 11 || i == 8)
			ret += 31;
		else
			ret += 30;
	}
	ret += day;
	return ret;
}

int Judge_leap(int year)
{
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
		return 1;
	else
		return 0;
}

int main()
{
	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);
	int ret = Compute(year, month, day);
	printf("%d", ret);
	return 0;
}

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//
//int Change(char hexadecimal[100000], int num)
//{
//	int ret = 0;
//	int i;
//	for (i = num - 1; i >= 0; i--) {
//		if (48 <= hexadecimal[i] && hexadecimal[i] <= 57) {
//			ret += (hexadecimal[i] - 48) * pow(16, num - i - 1);
//		}
//		else {
//			switch (hexadecimal[i]) {
//			case'a':
//			case'A':ret += 10 * pow(16, num - i - 1); break;
//			case'b':
//			case'B':ret += 11 * pow(16, num - i - 1); break;
//			case'c':
//			case'C':ret += 12 * pow(16, num - i - 1); break;
//			case'd':
//			case'D':ret += 13 * pow(16, num - i - 1); break;
//			case'e':
//			case'E':ret += 14 * pow(16, num - i - 1); break;
//			case'f':
//			case'F':ret += 15 * pow(16, num - i - 1); break;
//			case'x':break;
//			}
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	char hexadecimal[100000] = {0};
//	gets(hexadecimal);
//	int num = strlen(hexadecimal);
//	int ret = Change(hexadecimal,num);
//	printf("%d", ret);
//	return 0;
//}

//#include <stdio.h>
//
//double Legendre(int n, double x)
//{
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return x;
//	else
//		return ((2 * n - 1) * x - Legendre(n - 1, x) - (n - 1) * Legendre(n - 2, x))/n;
//}
//
//int main()
//{
//	int n;
//	double x;
//	scanf("%d%lf", &n, &x);
//	for (; n < 0;) {
//		scanf("%d%lf", &n, &x);
//	}
//	double ret = Legendre(n, x);
//	printf("%lf", ret);
//	return 0;
//}