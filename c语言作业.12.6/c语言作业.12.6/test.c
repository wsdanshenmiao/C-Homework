#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int month;
	char* English[12] = { "January","February","March","April","May","June","July","August","September","October","November","December"};
	scanf("%d", &month);
	printf("%s", English[month - 1]);
	return 0;
}

//#define ROW 10
//
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int cmp_arr(const void* e1, const void* e2)
//{
//	return strcmp((char*)e1, (char*)e2);
//}
//
//void Bubble_sort(void* arr, int sz, int width, int (*cmp_arr)(const void*, const void*))
//{
//	qsort(arr, sz, width, cmp_arr);
//}
//
//int main()
//{
//	int i;
//	char arr[ROW][1000] = { 0 };
//	for (i = 0; i < ROW; i++) {
//		gets(arr[i]);
//	}
//	for (i = 0; arr[0][i]; i++);
//	Bubble_sort(arr, ROW,sizeof(arr[0]),cmp_arr);
//	for (i = 0; i < ROW; i++) {
//		printf("%s\n", arr[i]);
//	}
//	return 0;
//}