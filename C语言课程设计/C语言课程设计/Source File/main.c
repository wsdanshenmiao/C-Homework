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
	printf("*****************0.EXIT         ********************\n");
	printf("*****************1.USER         ********************\n");
	printf("*****************2.MERCHANT     ********************\n");
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

void* InitOrderForm()
{
	return MALLOC(OrderForm);
}

void* InitUserinfo()
{
	return MALLOC(Userinfo);
}

void* InitCommodity()
{
	return MALLOC(Commodity);
}

bool InitInformation()
{
	g_OrderForm = InitList(DefaultDeallocate);
	g_Userinfo = InitList(DefaultDeallocate);
	g_Commodity = InitList(DefaultDeallocate);

	List** pList[3] = {
		&g_OrderForm,
		&g_Userinfo,
		&g_Commodity
	};
	const char* fileName[3] = {
		"OrderForm.dat",
		"Userinfo.dat",
		"Commodity.dat"
	};
	void* (*func[3])() = {
		InitOrderForm,
		InitUserinfo,
		InitCommodity
	};
	size_t size[3] = {
		sizeof(OrderForm),
		sizeof(Userinfo),
		sizeof(Commodity)
	};
	for (int i = 0; i < 3; i++) {
		List** list = pList[i];
		FILE* pfr;
		if (_access(fileName[i], 0)) {
			pfr = fopen(fileName[i], "wb");
		}
		else {
			pfr = fopen(fileName[i], "rb");
		}
		void* value = func[i]();
		if (!value) {
			return false;
		}
		for (; fread(value, size[i], 1, pfr); PushFront(*list, value));
		fclose(pfr);
	}
	return true;
}

int main()
{
	if (!InitInformation()) {
		return 0;
	}
	MasterUI();
	return 0;
}