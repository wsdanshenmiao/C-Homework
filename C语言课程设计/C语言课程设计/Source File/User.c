#define _CRT_SECURE_NO_WARNINGS

#include"User.h"

#define MALLOC(T) ((T*)malloc(sizeof(T)))
#define ASSERTPOINTER(T) if (!(T)) {return NULL;}



// �û���ֵ
bool RechargeUserAccount(Userinfo* user, size_t amount) {
    if (user == NULL || amount == 0) {
        return false; // ����û������ڻ��ֵ���Ϊ0���򷵻�ʧ��
    }
    user->m_Balance += amount; // �����û����
    return true;
}

// �û���ֵ
void Recharge(Node* userMes) 
{
    // �û���Ϣ�ڵ�¼ʱ���ҵ��ˣ�����������    

    size_t amount;
    printf("�������ֵ��\n");
    int error = scanf("%zu", &amount); // ��ȡ�û�����ĳ�ֵ���
    CleanBuffer();
    if (NumInputFailure(error)) { // ��������Ƿ�ʧ��
        printf("����������������롣\n");
        return;
    }

    Userinfo* userinfo = (Userinfo*)(userMes->m_Data);
    userinfo->m_Balance += amount;   // ����û��Ҫд�ɺ���
    printf("��ֵ�ɹ�����ǰ��%zu\n", userinfo->m_Balance); // ��ֵ�ɹ�����ӡ��ǰ���
}




void PrintCommofity(void* pValue)
{
    Commodity* commofity = (Commodity*)(pValue);
    printf("%s\t%lld\n",
        commofity->m_CommodityName,
        commofity->m_CommodityPrices);
}

bool FindProduct(void* pValue, void* cmpValue)
{
    Commodity* commodity = (Commodity*)pValue;
    return strncmp(commodity->m_CommodityName, (char*)cmpValue, sizeof((char*)cmpValue)) == 0;
}

// �û�ѡ����Ʒ
Node* SelectProduct() {
    printf("��������Ʒ���ƣ�\n"); // ��ʾ�û�������Ʒ����
    char name[20]; // �洢�������Ʒ����
    int error = scanf("%s", name); // ��ȡ�û�����
    CleanBuffer(); // ������뻺����
    if (StrInputFailure(error, name)) { // ��������Ƿ�ʧ��
        printf("����������������롣\n");
        return NULL; // ����ʧ��ʱ���� NULL
    }
    Node* node = Find(g_Commodity, FindProduct, name); // ����Ʒ�����в�����Ʒ
    if (!node) {
        printf("δ�ҵ�����Ʒ��\n"); // ��δ�ҵ���Ʒ�������ʾ
    }
    return node; // �����ҵ�����Ʒ�ڵ�
}

// �û����빺������
size_t GetUserQuantity() {
    printf("�����빺��������\n"); // ��ʾ�û����빺������
    size_t quantity; // �洢��������
    int error = scanf("%zu", &quantity); // ��ȡ�û����������
    CleanBuffer(); // ������뻺����
    if (NumInputFailure(error) || quantity <= 0) { // ��������Ƿ�ʧ��
        printf("���������0�����֡�\n");
        return 0; // ����ʧ�ܷ���0
    }
    return quantity; // �������������
}

// ��������
OrderForm* CreateOrder(Commodity* commodity, Userinfo* userinfo, size_t quantity)
{
    OrderForm* order = MALLOC(OrderForm); // �����ڴ������
    ASSERTPOINTER(order);
    order->m_OrderNumber = rand();  // ������ɶ�����
    order->m_CommodityNum = quantity; // ���ù�������
    order->m_CommodityPrices = commodity->m_CommodityPrices * quantity; // �����ܼ۸�
    strncpy(order->m_UserName, userinfo->m_Username, sizeof(order->m_UserName)); // �����û���
    strncpy(order->m_UserPhoneNum, userinfo->m_UserPhoneNum, sizeof(order->m_UserPhoneNum)); // �����û��绰����
    strncpy(order->m_CommodityName, commodity->m_CommodityName, sizeof(order->m_CommodityName)); // ������Ʒ����
    strncpy(order->m_UserAddress, userinfo->m_Address, sizeof(order->m_UserAddress)); // �����û���ַ
    strncpy(order->m_OrderStatus, "������", sizeof("������")); // ���ö���״̬Ϊ����������
    return order; // ���ش����Ķ���
}

// �û�������Ʒ
void PurchaseProduct(Node* userMes)
{
    TraversalOperation(g_Commodity, PrintCommofity);
    Node* selectedProduct = SelectProduct(); // �û�ѡ����Ʒ
    if (!selectedProduct) {
        return; // �����Ʒѡ��ʧ�ܣ�����
    }
    size_t quantity = GetUserQuantity(); // ��ȡ�û�����Ĺ�������
    if (quantity == 0) {
        return; // ������������Ϊ0������
    }
    Commodity* commodity = (Commodity*)(selectedProduct->m_Data);
    Userinfo* userinfo = (Userinfo*)(userMes->m_Data);  //�û���Ϣ�ڵ�¼ʱ�Ϳ����ҵ�
    OrderForm* order = CreateOrder(commodity, userinfo, quantity); // ��������
    if (!order) {
        printf("��������ʧ�ܡ�\n"); // �����������ʧ�ܣ������ʾ
        return;
    }
    PushFront(g_OrderForm, order); // ���������붩������          ���û��Ҫд�ɺ�����
    printf("�����ύ�ɹ��������ţ�%zu\n", order->m_OrderNumber); // ��������ύ�ɹ���Ϣ��������
}

void UserCatalogue()
{
	printf("*****************0.EXIT ********************\n");
    printf("*****************1.PURCHASEPRODUCT ********************\n");
}




bool IsNumber(const char* str, size_t num)
{
    for (int i = 0; i < num; ++i) {
        if (!isalnum(str[i])) {
            return false;
        }
    }
    return true;
}

void InformChange(Node* userMes)
{
    enum Modify {
        EXIT, NAME, PASSWORD, PHONENUMBER, ADDRESS
    };
    enum Modify select;
    Userinfo* userinfo = (Userinfo*)(userMes->m_Data);
    printf("��ѡ��Ҫ�޸ĵ���Ϣ:\n");
    printf("0.ȡ���޸�\t\t1.����\t\t2.����\t\t3.�ֻ���\t\t4.��ַ\n");
    scanf("%d", &select);
    CleanBuffer();
    system("cls");
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
        strncpy(userinfo->m_Username, name, sizeof(name));
        printf("�޸ĳɹ���\n");
        break;
    }
    case PASSWORD: {
        printf("�������µ����룺\n");
        char password1[20];
        int erromes = scanf("%s", password1);
        CleanBuffer();
        if (StrInputFailure(erromes, password1) || !IsNumber(password1, sizeof(password1))) {
            printf("�������\n");
            return;
        }
        printf("��ȷ���µ����룺\n");
        char password2[20];
        int erromes = scanf("%s", password2);
        CleanBuffer();
        if (StrInputFailure(erromes, password2) || !IsNumber(password2, sizeof(password2))) {
            printf("�������\n");
            return;
        }
        if (strncmp(password1, password2, sizeof(password1) == 0)) {
            strncpy(userinfo->m_Password, password2, sizeof(password2));
            printf("�޸ĳɹ���\n");
        }
        else {
            printf("���벻��ͬ��\n");
            return;
        }
        break;
    }
    case PHONENUMBER: {
        printf("�������µ��ֻ��ţ�\n");
        char phoneNum[20];
        int erromes = scanf("%s", phoneNum);
        CleanBuffer();
        if (StrInputFailure(erromes, phoneNum) || !IsNumber(phoneNum, sizeof(phoneNum))) {
            printf("�������\n");
            return;
        }
        strncpy(userinfo->m_UserPhoneNum, phoneNum, sizeof(phoneNum));
        printf("�޸ĳɹ���\n");
        break;
    }
    case ADDRESS: {
        printf("�������µ����֣�\n");
        char address[40];
        int erromes = scanf("%s", address);
        CleanBuffer();
        if (StrInputFailure(erromes, address)) {
            printf("�������\n");
            return;
        }
        strncpy(userinfo->m_Address, address, sizeof(address));
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




void UserUI()
{

    Node* UserMes = UserLogin();
    if (!UserMes) {
        return;
    }

    enum UserMenu {
        EXIT, PURCHASEPRODUCT, RECHARGE, INFORMCHANGE
    };
	enum MasterMenu select;
	do {
		UserCatalogue();	//��ӡĿ¼
		printf("��ѡ��:");
		scanf("%d", &select);
		CleanBuffer();
		system("cls");
		switch (select) {
        case EXIT: {
            break;
        }
        case PURCHASEPRODUCT: {
            PurchaseProduct(UserMes);
            break;
        }
        case RECHARGE: {
            Recharge(UserMes);
            break;
        }
        case INFORMCHANGE: {
            InformChange(UserMes);
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

