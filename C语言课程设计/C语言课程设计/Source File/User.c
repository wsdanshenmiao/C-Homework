#define _CRT_SECURE_NO_WARNINGS

#include"User.h"


enum UserMenu
{
	EXIT
};


void UserCatalogue()
{
	printf("*****************0.EXIT ********************\n");
}



void UserUI()
{
	if (!UserLogin()) {
		return;
	}
	enum MasterMenu select;
	do {
		UserCatalogue();	//��ӡĿ¼
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

