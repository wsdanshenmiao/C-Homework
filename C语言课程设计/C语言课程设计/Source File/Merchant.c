#define _CRT_SECURE_NO_WARNINGS

#include "Merchant.h"

#define MALLOC(T) ((T*)malloc(sizeof(T)))


void MerchantCatalogue()
{
	printf("*****************0.EXIT		2.ADDPRODUCTS*******************\n");
	printf("*****************1.VIEWPRODUCTS			3.MODIFYPRODUCTS********************\n");
	printf("*****************4.MANAGEDISTRIBUTE		********************\n");

}

// ��ӡ��Ʒ����
void PrintProducts(void* pValue)
{
	Commodity* commodity = (Commodity*)pValue;
	printf("%s\t%lld\n", commodity->m_CommodityName, commodity->m_CommodityPrices);
}

// ��������
Commodity* NewProduct(const char* name, size_t price)
{
	Commodity* commodity = MALLOC(Commodity);
	if (!commodity) {
		return NULL;
	}
	strncpy(commodity->m_CommodityName, name, sizeof(name));
	commodity->m_CommodityPrices = price;
	return commodity;
}

// �����Ʒ
void AddProducts()
{
	printf("��������Ʒ���ƣ�\n");
	char name[20];
	int erromes = scanf("%s", name);
	CleanBuffer();
	if (StrInputFailure(erromes, name)) {
		printf("�������\n");
		return;
	}

	printf("��������Ʒ�۸�\n");
	size_t price;
	erromes = scanf("%lld", &price);
	CleanBuffer();
	if (NumInputFailure(erromes)) {
		printf("�������\n");
		return;
	}
	Commodity* commodity = NewProduct(name, price);	//�������
	if (!commodity) {
		return;
	}
	PushFront(g_Commofity, commodity);	//�������
}



// ���ֲ��Һ���
bool FindName(void* pValue, void* cmpValue)
{
	Commodity* commodity = (Commodity*)pValue;
	return strncmp(commodity->m_CommodityName, (char*)cmpValue, sizeof((char*)cmpValue)) == 0;
}

// ѡ���޸ĵ���Ʒ
Node* ChooseProduct()
{
	printf("������Ҫ�޸���Ʒ�����֣�\n");
	char name[20];
	int erromes = scanf("%s", name);
	CleanBuffer();
	if (StrInputFailure(erromes, name)) {
		return NULL;
	}
	return Find(g_Commofity, FindName, name);
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
	//system("cls");
	switch (select) {
	case EXIT: {	// �˳�
		break;
	}
	case NAME: {
		printf("�������µ����֣�\n");
		char name[20];
		int erromes = scanf("%s", name);
		CleanBuffer();
		if (StrInputFailure(erromes, name)) {
			printf("�������\n");
			return;
		}
		strncpy(((Commodity*)(node->m_Data))->m_CommodityName, name, sizeof(name));
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



// ��ӡ��������
void PrintOrderForm(void* pValue)
{
	OrderForm* orderForm = (OrderForm*)(pValue);
	printf("%lld\t%s\t%lld\t%lld\t%s\t%s\t%s\t%s\n",
		orderForm->m_OrderNumber, orderForm->m_CommodityName,
		orderForm->m_CommodityNum, orderForm->m_CommodityPrices,
		orderForm->m_UserName, orderForm->m_UserPhoneNum,
		orderForm->m_UserAddress, orderForm->m_OrderStatus);
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
	int erromes = scanf("%lld", &orderNum);
	CleanBuffer();
	if (NumInputFailure(erromes)) {
		return NULL;
	}
	return Find(g_OrderForm, FindOrderForm, &orderNum);
}

// ��������״̬
void ManageDistribute()
{
	TraversalOperation(g_OrderForm, PrintOrderForm);
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




void SaveOrderForm(void* pValue)
{
	FILE* pfw = fopen("OrderForm.dat", "wb");	//�����ļ�
	if (pfw == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	fwrite(pValue, sizeof(OrderForm), 1, pfw);
	fclose(pfw);
}

void SaveCommodity(void* pValue)
{
	FILE* pfw = fopen("Commodity.dat", "wb");	//�����ļ�
	if (pfw == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	fwrite(pValue, sizeof(Commodity), 1, pfw);
	fclose(pfw);
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
		MerchantCatalogue();	//��ӡĿ¼
		printf("��ѡ��:");
		scanf("%d", &select);
		CleanBuffer();
		system("cls");
		switch (select) {
		case EXIT: {	// �˳�
			TraversalOperation(g_OrderForm, SaveOrderForm);
			TraversalOperation(g_Commofity, SaveCommodity);
			break;
		}
		case ADDPRODUCTS: {	// �����Ʒ
			AddProducts();
			getchar();
			break;
		}
		case VIEWPRODUCTS: {	//�鿴��Ʒ
			TraversalOperation(g_Commofity, PrintProducts);
			getchar();
			break;
		}
		case MODIFYPRODUCTS: {
			ModifyProducts();
			getchar();
			break;
		}
		case MANAGEDISTRIBUTE: {
			ManageDistribute();
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

