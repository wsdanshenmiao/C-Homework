#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "User.h"
#include "Merchant.h"
#include "Util.h"
#include "List.h"
#include "GlobalVariable.h"

#define MALLOC(T) ((T*)malloc(sizeof(T)))

void MasterCatalogue()
{
	printf("*****************0.EXIT         1.USER********************\n");
	printf("*****************2.MERCHANT *****************\n");
}

void MasterUI()
{
	enum MasterMenu {
		EXIT, USER, MERCHANT
	};
	enum MasterMenu select;
	do {
		MasterCatalogue();	//��ӡĿ¼
		printf("��ѡ��:");
		scanf("%d", &select);
		CleanBuffer();
		system("cls");
		switch (select) {
		case EXIT:

			break;
		case USER: {
			UserUI();
			break;
		}
		case MERCHANT: {
			MerchantUI();
			break;
		}
		default: {
			printf("�������\n");
			getchar();
			break;
		}
		}
		system("cls");
	} while (select);
}

int main()
{
	g_OrderForm = InitList(DefaultDeallocate);
	g_Userinfo = InitList(DefaultDeallocate);
	g_Commodity = InitList(DefaultDeallocate);
	MasterUI();
	return 0;
}