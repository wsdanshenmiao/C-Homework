#define _CRT_SECURE_NO_WARNINGS

#include "LoginSystem.h"

#define MALLOC(T) ((T*)malloc(sizeof(T)))


//�û���¼
Node* UserLogin()
{
	Userinfo e; //�û���Ϣ�ṹ��
	int erromes;
	Node* node= NULL;

	printf("�������¼���û�����\n");
	erromes = scanf("%s", e.m_Username);
	CleanBuffer();
	if (StrInputFailure(erromes, e.m_Username, sizeof(e.m_Username))) {
		printf("�û����������\n");
		return NULL;
	}

	node = Find(g_Userinfo, FindUser, e.m_Username);
	if ( node == NULL ) {
		printf("�û���������\n");
		return NULL;
	}

	printf("�������¼�����룺\n");
	erromes = scanf("%s", e.m_Password);
	CleanBuffer();
	if (StrInputFailure(erromes, e.m_Password, sizeof(e.m_Password))) {
		printf("�����������\n");
		return NULL;
	}

	if ( strncmp(((Userinfo*)(node->m_Data))->m_Password , e.m_Password , sizeof(e.m_Password)) != 0 ) {
		printf("���벻ƥ��\n");
		return NULL;
	}

	return node;
}




// ��ʾ�˺���Ϣ,����û����ʾ�˺ŵ�����
void PrintUser(void* pValue)
{
	Userinfo* userinfo = (Userinfo*)pValue;
	printf("%s\t%s\t%s\t%lld\n", userinfo->m_Username, userinfo->m_UserPhoneNum, userinfo->m_Address,
		userinfo->m_Balance);
}

//�������
Userinfo* NewUser(Userinfo e)
{
	Userinfo* userinfo = MALLOC(Userinfo);
	if (!userinfo) {
		return NULL;
	}
	strncpy(userinfo->m_Username, e.m_Username, sizeof(e.m_Username));
	strncpy(userinfo->m_Password, e.m_Password, sizeof(e.m_Password));
	strncpy(userinfo->m_UserPhoneNum, e.m_UserPhoneNum, sizeof(e.m_UserPhoneNum));
	strncpy(userinfo->m_Address, e.m_Address, sizeof(e.m_Address));
	userinfo->m_Balance = e.m_Balance;
	return userinfo;
}

//�û�ע��
void UserRegister()
{
	Userinfo e; //�û���Ϣ�ṹ��
	int erromes;

	printf("������ע����û�����\n");
	erromes = scanf("%s", e.m_Username);
	CleanBuffer();
	if (StrInputFailure(erromes, e.m_Username, sizeof(e.m_Username))) {
		printf("�������\n");
		return;
	}

	if (Find(g_Userinfo, FindUser, e.m_Username)) {
		printf("�û����Ѿ�����\n");
		return;
	}

	printf("������ע������룺\n");
	erromes = scanf("%s", e.m_Password);
	CleanBuffer();
	if (StrInputFailure(erromes, e.m_Password, sizeof(e.m_Password))) {
		printf("�������\n");
		return;
	}

	printf("������ע����û��ֻ��ţ�\n");
	erromes = scanf("%s", e.m_UserPhoneNum);
	CleanBuffer();
	if (StrInputFailure(erromes, e.m_UserPhoneNum, sizeof(e.m_UserPhoneNum))) {
		printf("�������\n");
		return;
	}

	printf("������ע����û���ַ��\n");
	erromes = scanf("%s", e.m_Address);
	CleanBuffer();
	if (StrInputFailure(erromes, e.m_Address, sizeof(e.m_Address))) {
		printf("�������\n");
		return;
	}

	printf("������ע����û���\n");
	erromes = scanf("%lld", &e.m_Balance);
	CleanBuffer();
	if (NumInputFailure(erromes)) {
		printf("�������\n");
		return;
	}

	Userinfo* userinfo = NewUser(e);	//�������
	if (!userinfo) {
		return;
	}
	PushFront(g_Userinfo, userinfo);	//�������
}

// �˺Ų��Һ���,��ֹ�ظ��˺�
bool FindUser(void* pValue, void* cmpValue)
{
	Userinfo* userinfo = (Userinfo*)pValue;
	return strncmp(userinfo->m_Username, (char*)cmpValue, sizeof((char*)cmpValue)) == 0;
}

//�����˺���Ϣ
void SaveUserinfo(void* pValue, void* operateValue)
{
	FILE* pfw = (FILE*)operateValue;
	fwrite(pValue, sizeof(Userinfo), 1, pfw);
}

void UserLoginCatalogue()
{
	printf("*****************0.�˳�********************\n");
	printf("*****************1.�û�ע�� ********************\n");
	printf("*****************2.�û���¼ ****************\n");
}

Node* UserLoginUI()
{
	enum UserMenu {
		EXIT, USERREGISTER, USERLOGIN
	};
	enum MasterMenu select;
	do {
		UserLoginCatalogue();	//��ӡĿ¼
		printf("��ѡ��:");
		scanf("%d", &select);
		CleanBuffer();
		system("cls");
		switch (select) {
		case EXIT: {	//�����û���Ϣ���˳�
			FILE* pfw = fopen("Userinfo.dat", "wb");	//�����ļ�
			if (pfw == NULL) {
				printf("%s", strerror(errno));
				return;
			}
			TraversalOperation(g_Userinfo, SaveUserinfo, pfw);
			fclose(pfw);
			break;
		}
		case USERREGISTER: {  //�û�ע��
			UserRegister();
			getchar();
			break;
			}
		case USERLOGIN: {//�û���¼

			Node* node = UserLogin();
			if (!node) {
				printf("��¼ʧ��\n");
			}
			else {
				printf("��¼�ɹ�\n");
				return node;
			}
			getchar();
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


//�̼ҵ�¼
bool MerchantLogin()
{
	FILE* pfr;
	if (_access("Merchant.dat", 0)) {
		pfr = fopen("Merchant.dat", "wb");
	}
	else {
		pfr = fopen("Merchant.dat", "rb");
	}
	char correctPassword[20];
	fread(correctPassword, sizeof(correctPassword), 1, pfr);

	printf("���������룺\n");
	char password[20];
	int erromes = scanf("%s", password);
	CleanBuffer();
	if (StrInputFailure(erromes, password, sizeof(password))) {
		printf("�������\n");
		return;
	}
	if (strncmp(correctPassword, password, sizeof(password)) == 0) {
		printf("��¼�ɹ���\n");
		return true;
	}
	else {
		printf("��¼ʧ�ܡ�\n");
		return false;
	}
}

