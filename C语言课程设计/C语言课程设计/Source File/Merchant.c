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
		MerchantCatalogue();	//��ӡĿ¼
		printf("��ѡ��:");
		scanf("%d", &select);
		CleanBuffer();
		system("cls");
		switch (select) {
		case EXIT:

			break;
		default: {
			printf("�������\n");
			getchar();
			break;
		}
		}
		system("cls");
	} while (select);
}

