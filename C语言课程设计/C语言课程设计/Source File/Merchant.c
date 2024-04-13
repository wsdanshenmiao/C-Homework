#define _CRT_SECURE_NO_WARNINGS

#include "Merchant.h"


enum MerchantMenu
{
	EXIT
};

void MerchantCatalogue()
{
	printf("*****************0.EXIT********************\n");
}



void MerchantUI()
{
	if (!MerchantLogin()) {
		return;
	}
	enum MasterMenu select;
	do {
		MerchantCatalogue();	//打印目录
		printf("请选择:");
		scanf("%d", &select);
		CleanBuffer();
		system("cls");
		switch (select) {
		case EXIT:

			break;
		default: {
			printf("输入错误。\n");
			getchar();
			break;
		}
		}
		system("cls");
	} while (select);
}

