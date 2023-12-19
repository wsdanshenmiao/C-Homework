#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//void Conversion(long long n, char arr[], int i)
//{
//	if (n >= 1) {
//		arr[i] = n % 10;
//		i++;
//		Conversion(n / 10, arr, i);
//	}
//}
//
//int main()
//{
//	long long n;
//	int i = 0, count = 0;
//	char arr[1000000];
//	scanf("%lld", &n);
//	Conversion(n,arr,i);
//	for (i = 0; 0 <= arr[i] && arr[i] <= 9; i++) {
//		count++;
//	}
//	for(;count>0;count--)
//	printf("%d", arr[count-1]);
//	return 0;
//}

////写一个函数，用“起泡法”对输入的10个字符按由小到大顺序排列 
//#include <stdio.h>
//int main(){
//	void sort_xzf(int array[],int n);
//	void sort_qpf(int array[],int n);
//	printf("enter array:\n");
////	int a[10];
////	for(i=0;i<10;i++)
////		scanf("%d",&a[i]);
////	int a[]={,34,51,86,97,12,45,19,76,56};
//	int a[]={'y','K','4',' ','8','&','?','i','H','@'};
//	sort_qpf(a,10);
//	printf("The sorted array:\n");
//	for(int i=0;i<10;i++)
//		printf("%c ",a[i]);
//	printf("\n");
//	return 0;
//} 
//
//void sort_qpf(int array[],int n){
//	int i,j,k,t;
//	for(j=0;j<9;j++)                        // 进行9次循环，实现9趟比较
//		for(i=0;i<9-j;i++)                     // 在每一趟中进行9-j次比较                  
//			if(array[i]>array[i+1]){                     // 相邻两个数比较 
//		 		t=array[i];array[i]=array[i+1];array[i+1]=t;
//			}
// }
//void sort_xzf(int array[],int n){
//	int i,j,k,t;
//	for(i=0;i<n-1;i++){
//		k=i;
//		for(j=i+1;j<n;j++)
//			if(array[j]<array[k])
//				k=j;
//		t=array[k];array[k]=array[i];array[i]=t;
//	}
//}


//#define NUM 10
//
//#include <stdio.h>
//
//typedef struct worker//职工数据
//{
//	char name[10];
//	int job_num;//工号不可过大，过大的话可用数组，但我懒得换了
//}worker;
//
//void Collect_data(worker w[])
//{
//	int i;
//	for (i = 0; i < NUM; i++)
//		scanf("%s%d", &w[i].name, &w[i].job_num);
//}
//
//void Change_name(worker w[], int j)
//{
//	int i;
//	char temp[10] = { 0 };
//	for (i = 0; i < NUM; i++)
//		temp[i] = w[j].name[i];
//	for (i = 0; i < NUM; i++)
//		w[j].name[i] = w[j + 1].name[i];
//	for (i = 0; i < NUM; i++)
//		w[j + 1].name[i] = temp[i];
//}
//
//void Sort(worker w[])
//{
//	int i, j;
//	for (i = 0; i < NUM; i++) {
//		int b = 1;
//		for (j = 0; j < NUM - 1; j++) {
//			if (w[j].job_num > w[j + 1].job_num) {//工号大则往后排
//				int temp = w[j].job_num;
//				w[j].job_num = w[j + 1].job_num;
//				w[j + 1].job_num = temp;
//				Change_name(w,j);//换名字
//				b = 0;
//			}
//		}
//		if (b == 1){
//			int i;
//			for (i = 0; i < NUM; i++)
//				printf("%s %d\n", w[i].name, w[i].job_num);//检测排序是否成功
//			break;
//		}
//	}
//}
//
//int Search(int n, worker w[])
//{
//	int left = 0;
//	int right = NUM - 1;
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (w[mid].job_num < n)
//			left = mid + 1;
//		else if (w[mid].job_num > n)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	return 0;
//}
//
//int main()
//{
//	int n;
//	worker w[NUM] = { {0},0 };
//	Collect_data(w);//输入职工数据
//	Sort(w);//对数据进行排序
//	int a = 1;
//	do {
//		scanf("%d", &n);//输入工号
//		int i;
//		for (i = 0; i < NUM; i++) {
//			if (w[i].job_num == n) {
//				a = 0;
//				break;
//			}
//		}
//	} while (a);
//	int ret = Search(n, w);//查找职工
//	printf("%s",w[ret].name);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//void Blistering_method(int len, char arr[11])
//{
//	int i, j;
//	for (i = 0; i < len; i++) {
//		int b = 1;
//		for (j = 0; j < len - 1; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//		if (b == 0)
//			break;
//	}
//}
//
//int main()
//{
//	char arr[11] = { 0 };
//	gets(arr);
//	int len = strlen(arr);
//	Blistering_method(len, arr);
//	printf("%s", arr);
//	return 0;
//}

//用递归法将一个整数n转换成字符串。例如，输入483，应输出字符串“483”。n位数不确定，可以是任意位数的整数。 
#include <stdio.h>
void intToStr(int n) {
    if (n == 0) {
        return;
    }
    intToStr(n / 10);
    printf("%d", n % 10);//每次调用此函数都肯定输出一个输入值的个位值 
}
int main() {
    int num;
    printf("请输入一个整数：");
    scanf("%d", &num);
	printf("整数 %d 转换成字符串：", num);
    intToStr(num);
    printf("\n");
    return 0;
}