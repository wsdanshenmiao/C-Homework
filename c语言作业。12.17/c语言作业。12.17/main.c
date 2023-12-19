#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STU 10

struct stu
{
	long long ID;
	char name[10];
	int score[4];
};
struct stu stu[STU] = { 0 };

int str_cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void average_Score()
{
	for (int i = 0; i < STU; i++) {
		stu[i].score[3] = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;
	}
}

int main()
{
	int i = 0;
	for (i = 0; i < STU; i++) {
		scanf("%lld%s", &stu[i].ID, &stu[i].name);
		for (int j = 0; j < 3; j++) {
			scanf("%d", &stu[i].score[j]);
		}
	}
	average_Score();
	qsort(stu, sizeof(stu) / sizeof(stu[0]), sizeof(stu[0]), str_cmp);
	for (i = 0; i < STU; i++) {
		printf("%d\n", stu[i].score[3]);
	}
	printf("%lld %s %d\n", stu[0].ID, stu[0].name, stu[0].score[3]);
	return 0;
}

//#include <stdio.h>
//
//struct date
//{
//	int year;
//	int month;
//	int day;
//};
//
//int Judge_leap_year(int y)
//{
//	return (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);
//}
//
//int days(int y, int m, int d)
//{
//	int monthday[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int days = 0;
//	for (int i = 0; i < m; i++) {
//		days += monthday[i];
//	}
//	if (m > 2 || (m == 2 && d >= 29)) {
//		days += Judge_leap_year(y);
//	}
//	return days + d;
//}
//
//int main()
//{
//	struct date date;
//	scanf("%d%d%d", &date.year, &date.month, &date.day);
//	int ret = days(date.year, date.month, date.day);
//	printf("%d", ret);
//	return 0;
//}