#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 6
#define COL ROW

#include <stdio.h>

void PRINT(int arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

}

//void PRINT1(int arr[ROW/2][COL/2], int row, int col)
//{
//	int i, j;
//	for (i = 0; i < row; i++) {
//		for (j = 0; j < col; j++) {
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}

void ODD1(int arr[ROW][COL], int a, int n)
{
	int i = 1;
	int j = COL / 2 - 1;
	int i1, j1;
	for (; a <= n; a++) {
		i1 = i;
		j1 = j;
		i--;
		j++;
		if (i < 0)
			i = ROW-1;
		if (j == COL)
			j = 0;
		if (arr[i][j] != 0) {
			i = i1 + 1;
			j = j1;
		}
		arr[i][j] = a;
	}
}

void ODD2(int arr[ROW/2][COL/2], int a, int n)
{
	int i = 1;
	int j = COL / 4 - 1;
	int i1, j1;
	for (; a <= n; a++) {
		i1 = i;
		j1 = j;
		i--;
		j++;
		if (i < 0)
			i = ROW/2 - 1;
		if (j == COL/2)
			j = 0;
		if (arr[i][j] != 0) {
			i = i1 + 1;
			j = j1;
		}
		arr[i][j] = a;
	}
}

void DOUBLEEVEN(int arr[ROW][COL], int row, int col)
{
	int i, j;
	int a;
	for (a = 1, i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			arr[i][j] = a;
			a++;
		}
	}
	for (a = 1, i = row - 1; i >= 0; i--) {
		for (j = col-1; j >= 0; j--) {
			if (i % 4 == j % 4||(i+j)%4==3)//斜对角线
				arr[i][j] = a;
			a++;
		}
	}
}

void ZH(int arr[ROW][COL], int arr1[ROW / 2][COL / 2], int arr2[ROW / 2][COL / 2], int arr3[ROW / 2][COL / 2], int arr4[ROW / 2][COL / 2])
{
	int i, j;
	for (i = 0; i < ROW / 2; i++) {
		for (j = 0; j < COL / 2; j++) {
			arr[i][j] = arr1[i][j];
		}
	}
	for (i = 0; i < ROW / 2; i++) {
		for (j = 0; j < COL / 2; j++) {
			arr[i+ROW/2][j+COL/2] = arr2[i][j];
		}
	}
	for (i = 0; i < ROW / 2; i++) {
		for (j = 0; j < COL / 2; j++) {
			arr[i][j + COL / 2] = arr3[i][j];
		}
	}
	for (i = 0; i < ROW / 2; i++) {
		for (j = 0; j < COL / 2; j++) {
			arr[i + ROW / 2][j] = arr4[i][j];
		}
	}
}

void CHANGE(int arr[ROW][COL], int k)
{
	int temp;
	int i, j;
	for (i = 0; i < k; i++) {
		temp = arr[ROW / 4][COL / 4 + i];
		arr[ROW / 4][COL / 4 + i] = arr[ROW * 3 / 4][COL / 4 + i];
		arr[ROW * 3 / 4][COL / 4 + i] = temp;
	}
	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[i+ROW / 2][j];
			arr[i + ROW / 2][j] = temp;
			temp = arr[i + ROW / 4 + 1][j];
			arr[i + ROW / 4 + 1][j] = arr[i + ROW * 3 / 4 + 1][j];
			arr[i + ROW * 3 / 4 + 1][j] = temp;
		}
	}
	for (i = 0; i < ROW/2; i++) {
		for (j = 0; j < k-1; j++) {
			temp = arr[i][j + COL * 3 / 4-1];
			arr[i][j + COL * 3 / 4-1] = arr[i + ROW / 2][j + COL * 3 / 4-1];
			arr[i + ROW / 2][j + COL * 3 / 4-1] = temp;
			//PRINT(arr, ROW, COL);
		}
	}
}

void EVEN(int arr[ROW][COL], int row, int col, int n)
{
	int k = (ROW - 2) / 4;
	int arr1[ROW / 2][COL / 2] = { 0 };
	ODD2(arr1, 1, n / 4);
	//PRINT1(arr1, ROW/2, COL/2);
	int arr2[ROW / 2][COL / 2] = { 0 };
    ODD2(arr2, n/4+1, n / 2);
	//PRINT1(arr2, ROW/2, COL/2);
	int arr3[ROW / 2][COL / 2] = { 0 };
	ODD2(arr3, n/2+1, n*3 / 4);
	//PRINT1(arr3, ROW/2, COL/2);
	int arr4[ROW / 2][COL / 2] = { 0 };
	ODD2(arr4, n*3/4+1, n);
	//PRINT1(arr4, ROW/2, COL/2);
	ZH(arr, arr1, arr2, arr3, arr4);//ABCD区整合成一个
	//PRINT(arr, ROW, COL);
	CHANGE(arr,k);//AD,BC区元素调换
}

int main(){
	int arr[ROW][COL] = { 0 };
	int a = 1;
	int n = ROW * COL;
	if (ROW % 4 == 0){//双偶阶魔方阵
		DOUBLEEVEN(arr, ROW, COL);
		PRINT(arr, ROW, COL);
	}
	else if(ROW%2==1){//奇数阶魔方阵
		ODD1(arr, a, n);
		PRINT(arr, ROW, COL);
	}
	else {
		EVEN(arr, ROW, COL, n);//单偶阶幻方
		PRINT(arr, ROW, COL);
	}
	return 0;
}

//#include <stdio.h>
//
//void COUNT(int* c,int* d,int* e,int* b,char arr[])
//{
//	int i;
//	for (i = 0; arr[i] != '\0'; i++) {
//		if (arr[i] <= 'z' && arr[i] >= 'a')
//			*c+=1;
//		else if (arr[i] <= 'Z' && arr[i] >= 'A')
//			*d+=1;
//		else if (arr[i] <= '9' && arr[i] >= '0')
//			*b+=1;
//		else if (arr[i] = ' ')
//			*e+=1;
//	}
//}
//
//int main()
//{
//	char arr[] = {"CLANNAD is No1 in my heard"};
//	int c = 0, d = 0, e = 0, b = 0;
//	COUNT(&c, &d, &e, &b, arr);
//	printf("大写字母有%d个\n", d);
//	printf("小写字母有%d个\n", c);
//	printf("数字有%d个\n", b);
//	printf("空格有%d个\n", e);
//	return 0;
//}

//void my_stract(char arr[20], char arr2[], int n1, int n2)
//{
//	for (int i = 0; i < n2; i++) {
//		arr[n1 + i] = arr2[i];
//	}
//}
//
//int main()
//{
//	char arr[20] = { "Christmas" };
//	char arr1[] = { "Christmas" };
//	char arr2[] = { "Tina;)" };
//	int n1 = sizeof(arr1) / sizeof(arr1[0]);
//	int n2 = sizeof(arr2) / sizeof(arr2[0]);
//	my_stract(arr, arr2, n1, n2);
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//void DOUBLE(int a, int b, int d, double x1, double x2)
//{
//	x1 = (-b + sqrt(d)) / (2 * a);
//	x2 = (-b - sqrt(d)) / (2 * a);
//	printf("有两个根%f,%f\n", x1, x2);
//}
//
//void ODD(int a, int b, int d, double x1, double x2)
//{
//	x1 = (-b + sqrt(d)) / (2 * a);
//	printf("有一个根%f\n", x1);
//}
//
//void NO()
//{
//	printf("无根\n");
//}
//
//int main()
//{
//	//int x;
//	double x1 = 0, x2 = 0;
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	//a* x* x + b * x + c == 0;
//	int d = b * b - 4 * a * c;
//	if (d > 0)
//		DOUBLE(a, b, d, x1, x2);
//	else if (d == 0)
//		ODD(a, b, d, x1, x2);
//	else
//		NO();
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char arr[3][8] = { {"s98 g8D"},{"65 8fa"},{"sfd4sDF"}};
//	int c = 0, d = 0, e = 0, b = 0;
//	int i, j;
//	for (i = 0; i < 3; i++) {
//		for (j = 0; arr[i][j] != '\0'; j++) {
//			if (arr[i][j] <= 'z' && arr[i][j] >= 'a')
//				c++;
//			else if (arr[i][j] <= 'Z' && arr[i][j] >= 'A')
//				d++;
//			else if (arr[i][j] <= '9' && arr[i][j] >= '0')
//				b++;
//			else if (arr[i][j] = ' ')
//				e++;
//		}
//	}
//	printf("大写字母有%d个\n", d);
//	printf("小写字母有%d个\n", c);
//	printf("数字有%d个\n", b);
//	printf("空格有%d个\n", e);
//	return 0;
//}