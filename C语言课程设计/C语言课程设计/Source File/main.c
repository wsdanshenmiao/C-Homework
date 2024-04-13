//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string.h>
//#include "User.h"
//#include "Merchant.h"
//#include "HelpFunc.h"
//#include "List.h"
//#include "Test.c"
//
//#define MALLOC(T) ((T*)malloc(sizeof(T)))
//
//enum MasterMenu
//{
//	EXIT,
//	USER,
//	MERCHANT
//};
//
//void MasterCatalogue()
//{
//	printf("*****************0.EXIT         1.USER********************\n");
//	printf("*****************2.MERCHANT *****************\n");
//}
//
//inline int MyScanf(const char* const format, ...)
//{
//	return scanf(format);
//}
//
//
//void MasterUI()
//{
//	enum MasterMenu select;
//	do {
//		MasterCatalogue();	//¥Ú”°ƒø¬º
//		printf("«Î—°‘Ò:");
//		MyScanf("%d", &select);
//		CleanBuffer();
//		system("cls");
//		switch (select) {
//		case EXIT:
//
//			break;
//		case USER: {
//			UserUI();
//			break;
//		}
//		case MERCHANT: {
//			MerchantUI();
//			break;
//		}
//		default: {
//			printf(" ‰»Î¥ÌŒÛ°£\n");
//			getchar();
//			break;
//		}
//		}
//		system("cls");
//	} while (select);
//}
//
//int main()
//{
//	MasterUI();
//	return 0;
//}