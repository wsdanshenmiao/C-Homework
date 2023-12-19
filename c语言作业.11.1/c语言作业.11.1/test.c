#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[100] = { 0 };
	char s2[] = { "CLANNAD" };
	int n = strlen(s2);
	int i;
	for (i = 0; i < n+1; i++)
	{
		s1[i] = s2[i];
	}
	printf("%s", s1);
	return 0;
}

//int main()
//{
//	char arr1[100] = {"Christmas "};
//	char arr2[100] = {"Tina;)"};
//	int n1 = strlen(arr1);
//	int n2 = strlen(arr2);
//	int i;
//	for(i = 0; i < n2; i++)
//	{
//		arr1[n1 + i] = arr2[i];
//	}
//	printf("%s", arr1);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int i;
//	int arr[100] = { 0,1,2,3,4,5,6,7,8,9 };
//	scanf("%d", &a);
//	arr[10] = a;
//	for (i = 10; i > 0; i--)
//	{
//		if (arr[i] < arr[i-1])
//		{
//			int temp = arr[i];
//			arr[i] = arr[i - 1];
//			arr[i - 1] = temp;
//		}
//	}
//	for (i = 0; i < 11; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[3][3] = { 0 };
//	int i, j;
//	int a;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入第%d行的数据.\n", i + 1);
//		for (j = 0; j < 3; j++)
//		{
//			scanf("%d", &a);
//			arr[i][j] = a;
//		}
//	}
//	int sum = arr[0][0] + arr[0][2] + arr[1][1] + arr[2][0] + arr[2][2];
//	printf("%d", sum);
//	return 0;
//}