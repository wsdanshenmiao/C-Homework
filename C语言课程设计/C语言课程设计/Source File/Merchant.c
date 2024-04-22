#define _CRT_SECURE_NO_WARNINGS

#include "Merchant.h"

#define MALLOC(T) ((T*)malloc(sizeof(T)))


void MerchantCatalogue()
{
	printf("**************   0.������һ����   ********************\n");
	printf("**************   1.�����Ʒ       ********************\n");
	printf("**************   2.�鿴��Ʒ       ********************\n");
	printf("**************   3.�޸���Ʒ��Ϣ   ********************\n");
	printf("**************   4.�޸Ķ�����Ϣ   ********************\n");
}


// ��������
Commodity* NewProduct(const char* name, size_t price)
{
	Commodity* commodity = MALLOC(Commodity);
	if (!commodity) {
		return NULL;
	}
	strncpy(commodity->m_CommodityName, name, sizeof(commodity->m_CommodityName));
	commodity->m_CommodityPrices = price;
	return commodity;
}

// ���ֲ��Һ���
bool FindName(void* pValue, void* cmpValue)
{
	Commodity* commodity = (Commodity*)pValue;
	return strncmp(commodity->m_CommodityName, (char*)cmpValue, sizeof((char*)cmpValue)) == 0;
}

// �����Ʒ
void AddProducts()
{
	printf("��������Ʒ���ƣ�\n");
	char name[20];
	int erromes = scanf("%s", name);
	CleanBuffer();
	if (StrInputFailure(erromes, name, sizeof(name))) {
		printf("�������\n");
		return;
	}

	printf("��������Ʒ�۸�\n");
	size_t price;
	erromes = scanf("%zu", &price);
	CleanBuffer();
	printf("��ӳɹ�\n");
	if (NumInputFailure(erromes)) {
		printf("�������\n");
		return;
	}
	Commodity* commodity = NewProduct(name, price);	//�������
	if (!commodity) {
		return;
	}
	PushFront(g_Commodity, commodity);	//�������
}



// ѡ���޸ĵ���Ʒ
Node* ChooseProduct()
{
	printf("������Ҫ�޸���Ʒ�����֣�\n");
	char name[20];
	int erromes = scanf("%s", name);
	CleanBuffer();
	if (StrInputFailure(erromes, name, sizeof(name))) {
		return NULL;
	}
	return Find(g_Commodity, FindName, name);
}

// �޸���Ʒ
void ModifyProducts()
{
	Node* node = ChooseProduct();
	if (!node) {
		printf("δ�д���Ʒ��\n");
		return;
	}
	system("cls");
	enum Modify {
		EXIT, NAME, PRICE
	};
	enum Modify select;
	printf("��ѡ��Ҫ�޸ĵĳ�Ա:\n");
	printf("0.ȡ���޸�\t\t1.����\t\t2.�۸�\n");
	scanf("%d", &select);
	CleanBuffer();
	switch (select) {
	case EXIT: {	// �˳�
		break;
	}
	case NAME: {
		printf("�������µ����֣�\n");
		char name[20];
		int erromes = scanf("%s", name);
		CleanBuffer();
		if (StrInputFailure(erromes, name, sizeof(name))) {
			printf("�������\n");
			return;
		}
		Commodity* commodity = (Commodity*)(node->m_Data);
		strncpy(commodity->m_CommodityName, name, sizeof(commodity->m_CommodityName));
		printf("�޸ĳɹ���\n");
		break;
	}
	case PRICE: {
		printf("�������µļ۸�\n");
		size_t price;
		int erromes = scanf("%lld", &price);
		CleanBuffer();
		if (NumInputFailure(erromes)) {
			printf("�������\n");
			return;
		}
		((Commodity*)(node->m_Data))->m_CommodityPrices = price;
		printf("�޸ĳɹ���\n");
		break;
	}
	default: {
		printf("�������\n");
		getchar();
		break;
	}
	}
}





// ���Һ���
bool FindOrderForm(void* pValue, void* cmpValue)
{
	OrderForm* orderForm = (OrderForm*)pValue;
	return orderForm->m_OrderNumber == *((size_t*)cmpValue);
}

// ѡ�񶩵�
Node* ChooseOrderForm()
{
	printf("������Ҫ����Ķ�����ţ�\n");
	size_t orderNum;
	int erromes = scanf("%zu", &orderNum);
	CleanBuffer();
	if (NumInputFailure(erromes)) {
		return NULL;
	}
	return Find(g_OrderForm, FindOrderForm, &orderNum);
}

// ��������״̬
void ManageDistribute()
{
	TraversalOperation(g_OrderForm, PrintOrderForm, NULL);
	Node* node = ChooseOrderForm();
	if (!node) {
		printf("δ�д˶�����\n");
		return;
	}
	enum Modify {
		EXIT, INDELIVERY, HAVEBEENDELIVERED
	};
	enum Modify select;
	printf("��ѡ��Ҫ�޸ĵĳ�Ա:\n");
	printf("0.ȡ���޸�\t\t1.������\t\t2.���ʹ�\n");
	scanf("%d", &select);
	CleanBuffer();
	system("cls");
	switch (select) {
	case EXIT: {	// �˳�
		break;
	}
	case INDELIVERY: {
		strncpy(((OrderForm*)node->m_Data)->m_OrderStatus, "������", sizeof("������"));
		printf("�޸ĳɹ���\n");
		break;
	}
	case HAVEBEENDELIVERED: {
		strncpy(((OrderForm*)node->m_Data)->m_OrderStatus, "���ʹ�", sizeof("���ʹ�"));
		printf("�޸ĳɹ���\n");
		break;
	}
	default: {
		printf("�������\n");
		getchar();
		break;
	}
	}
}





void MerchantUI()
{
	if (!MerchantLogin()) {	//��¼ʧ�����˳�
		return;
	}
	enum MerchantMenu{
		EXIT,
		ADDPRODUCTS,
		VIEWPRODUCTS,
		MODIFYPRODUCTS,
		MANAGEDISTRIBUTE
	};
	enum MasterMenu select;
	do {
		system("cls");
		MerchantCatalogue();	//��ӡĿ¼
		printf("��ѡ��:");
		scanf("%d", &select);
		CleanBuffer();
		system("cls");
		switch (select) {
		case EXIT: {	// �˳�
			SaveCommodity();
			SaveOrderForm();
			break;
		}
		case ADDPRODUCTS: {	// �����Ʒ
			AddProducts();
			SaveCommodity();
			getchar();
			break;
		}
		case VIEWPRODUCTS: {	//�鿴��Ʒ
			TraversalOperation(g_Commodity, PrintCommofity, NULL);
			getchar();
			break;
		}
		case MODIFYPRODUCTS: {
			ModifyProducts();
			SaveCommodity();
			getchar();
			break;
		}
		case MANAGEDISTRIBUTE: {
			ManageDistribute();
			SaveOrderForm();
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

