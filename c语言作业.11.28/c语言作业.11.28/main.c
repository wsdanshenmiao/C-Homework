#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int* Remove(int* arr, int n, int count, int a)//�Ƴ��ֵ�3�������������������
{
	int i;
	if (a >= 3) {//���������Ͻ��в���
		a = 0;//aΪʣ�����ĸ�����ÿ�θ�������Ϊ0
		for (i = 0; i < n; i++) {
			if (*(arr + i) == 0) {
				continue;//�����Ƴ�����
			}
			else {
				if (count == 3) {
					*(arr + i) = 0;//�ǵ�3�����Ƴ�������0
					count = 1;//���¿�ʼ����
				}
				if (*(arr + i) != 0) {//�Ƴ���󲻽��в���
					count++;//����
					a++;
				}
			}
		}
	}
	else//ʣ������������ʱ�����ݹ�
	{
		return arr;
	}
	Remove(arr, n, count, a);
}

Initialize(int* arr, int n)//��1-n��������Ž�������
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
	Initialize(&arr[0], n);//��1-n��������Ž�������
	for (int i = 0; i < n; i++) {
		if (*(Remove(&arr[0], n, 1, 3) + i) != 0) {//��ʣ�����������ӡ����
			printf("%d\n", *(Remove(&arr[0], n, 1, 3) + i));
		}
	}
	return 0;
}

//#include <stdio.h>
//
//void Output(int* arr)//���
//{
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", *(arr + i));
//	}
//
//}
//
//void Dispose(int* arr)//��һ������С�Ļ��������һ�������Ļ���
//{
//	int i;
//	int m = 0;
//	int a = *arr;
//	for (i = 0; i < 10; i++, arr) {
//		if (*(arr + i) < a) {
//			a = *(arr + i);
//			m = i;//��m��������С��
//		}
//	}
//	int temp = *arr;//����
//	*arr = a;
//	*(arr + m) = temp;
//	int b = *arr;
//	for (i = 0; i < 10; i++, arr) {
//		if (*(arr + i) > b) {
//			b = *(arr + i);
//			m = i;//��m����������
//		}
//	}
//	temp = *(arr + 9);//����
//	*(arr + 9) = b;
//	*(arr + m) = temp;
//}
//
//void Input(int* arr)//����10����
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
//	Input(&arr[0]);//����10����
//	Dispose(&arr[0]);//��һ������С�Ļ��������һ�������Ļ���
//	Output(&arr[0]);//���
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
//	printf("Сд��ĸ��%d��\n", a);
//	printf("��д��ĸ��%d��\n", b);
//	printf("������%d��\n", c);
//	printf("�ո���%d��\n", d);
//	printf("����������%d��\n", e);
//	return 0;
//}