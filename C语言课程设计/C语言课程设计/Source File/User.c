#define _CRT_SECURE_NO_WARNINGS

#include"User.h"
#include"windows.h"

#define MALLOC(T) ((T*)malloc(sizeof(T)))
#define ASSERTPOINTER(T) if (!(T)) {return NULL;}



//�绰���Һ�������ֹ�ظ��绰
bool FindPhoneNum(void* pValue, void* cmpValue)
{
    Userinfo* userinfo = (Userinfo*)pValue;
    return strncmp(userinfo->m_UserPhoneNum, (char*)cmpValue, sizeof((char*)cmpValue)) == 0;
}

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
    Userinfo* userinfo = (Userinfo*)(userMes->m_Data);
    int amount;
    printf("��ǰ��%zu\n", userinfo->m_Balance);
    printf("�������ֵ��\n");
    int error = scanf("%d", &amount); // ��ȡ�û�����ĳ�ֵ���
    CleanBuffer();
    if (amount < 0) {
        printf("����������������롣\n");
        Sleep(1000);
        return;
    }
    if (NumInputFailure(error)) { // ��������Ƿ�ʧ��
        printf("����������������롣\n");
        Sleep(1000);
        return;
    }

    userinfo->m_Balance += amount;   // ����û��Ҫд�ɺ���
    printf("��ֵ�ɹ�����ǰ��%zu\n", userinfo->m_Balance); // ��ֵ�ɹ�����ӡ��ǰ���
    Sleep(1000);
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
    if (StrInputFailure(error, name, sizeof(name))) { // ��������Ƿ�ʧ��
        printf("����������������롣\n");
        Sleep(1000);
        return NULL; // ����ʧ��ʱ���� NULL
    }
    Node* node = Find(g_Commodity, FindProduct, name); // ����Ʒ�����в�����Ʒ
    if (!node) {
        printf("δ�ҵ�����Ʒ��\n"); // ��δ�ҵ���Ʒ�������ʾ
        Sleep(1000);
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
    srand(time(0));
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
    TraversalOperation(g_Commodity, PrintCommofity, NULL);
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
    if (userinfo->m_Balance >= (commodity->m_CommodityPrices * quantity)) {
        userinfo->m_Balance = userinfo->m_Balance - (commodity->m_CommodityPrices * quantity);
    }
    else{
        printf("���㣬����ʧ��");
        Sleep(1000);
        return;
    }
    OrderForm* order = CreateOrder(commodity, userinfo, quantity); // ��������
    if (!order) {
        printf("��������ʧ�ܡ�\n"); // �����������ʧ�ܣ������ʾ
        Sleep(1000);
        return;
    }
    PushFront(g_OrderForm, order); // ���������붩������          ���û��Ҫд�ɺ�����
    printf("�����ύ�ɹ��������ţ�%zu\n", order->m_OrderNumber); // ��������ύ�ɹ���Ϣ��������
    Sleep(1000);
}




bool CompareArrays(const char* arr1, const char* arr2) {
    // ������������ÿ���ַ��Ƿ���ȣ�ֱ���������ַ� '\0'
    while (*arr1 != '\0' && *arr2 != '\0') {
        if (*arr1 != *arr2) {
            return false;
        }
        ++arr1;
        ++arr2;
    }
    // ����������鶼��������ĩβ�����ַ� '\0'��������Ϊ��ȣ�������Ϊ�����
    return (*arr1 == '\0' && *arr2 == '\0');
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
        if (StrInputFailure(erromes, name, sizeof(name))) {
            printf("�������\n");
            Sleep(1000);
            return;
        }

        if (Find(g_Userinfo, FindUser, name)) {
            printf("�û����Ѿ�����\n");
            Sleep(1000);
            return;
        }

        strncpy(userinfo->m_Username, name, sizeof(name));
        printf("�޸ĳɹ���\n");
        Sleep(1000);
        break;
    }
    case PASSWORD: {
        printf("�������µ����룺\n");
        char password1[20];
        int erromes = scanf("%s", password1);
        CleanBuffer();
        if (StrInputFailure(erromes, password1, sizeof(password1)) || !IsAllAlphaNumeric(password1, sizeof(password1))) {
            printf("��������ϸ�ʽҪ�������1��\n");
            Sleep(1000);
            return;
        }
        printf("��ȷ���µ����룺\n");
        char password2[20];
        erromes = scanf("%s", password2);
        CleanBuffer();
        if (StrInputFailure(erromes, password2, sizeof(password2)) || !IsAllAlphaNumeric(password2, sizeof(password1))) {
            printf("��������ϸ�ʽҪ�������2��\n");
            Sleep(1000);
            return;
        }
        if (strncmp(password1, password2, sizeof(password1))) {
            strncpy(userinfo->m_Password, password2, sizeof(password2));
            printf("�޸ĳɹ���\n");
            Sleep(1000);
        }
        else {
            printf("���벻��ͬ��\n");
            Sleep(1000);
            return;
        }
        break;
    }
    case PHONENUMBER: {
        printf("�������µ��ֻ��ţ�\n");
        char phoneNum[20];
        int erromes = scanf("%s", phoneNum);
        CleanBuffer();
        
        if (StrInputFailure(erromes, phoneNum, sizeof(phoneNum)) || IsNumber(phoneNum, sizeof(phoneNum))) {
            printf("��������ϸ�ʽҪ��ĵ绰���롣\n");
            Sleep(1000);
            return;
        }
        if (strlen(phoneNum) != 11) {
            printf("��������ϳ���Ҫ��ĵ绰���롣\n");
            Sleep(1000);
            return;
        }
        if (Find(g_Userinfo, FindPhoneNum, phoneNum)) {
            printf("�õ绰�ѱ�ע��\n");
            Sleep(1000);
            return;
        }
        strncpy(userinfo->m_UserPhoneNum, phoneNum, sizeof(phoneNum));
        printf("�޸ĳɹ���\n");
        Sleep(1000);
        break;
    }
    case ADDRESS: {
        printf("�������µ����֣�\n");
        char address[40];
        int erromes = scanf("%s", address);
        CleanBuffer();
        if (StrInputFailure(erromes, address, sizeof(address))) {
            printf("�������\n");
            Sleep(1000);
            return;
        }
        strncpy(userinfo->m_Address, address, sizeof(address));
        printf("�޸ĳɹ���\n");
        Sleep(1000);
        break;
    }
    default: {
        printf("�������\n");
        Sleep(1000);
        getchar();
        break;
    }
    }
}



void UserCatalogue()
{
    printf("*****************  0.����������      ********************\n");
    printf("*****************  1.������Ʒ        ********************\n");
    printf("*****************  2.�˻���ֵ        ********************\n");
    printf("*****************  3.�����޸�        ********************\n");
    printf("*****************  4.�鿴����        ********************\n");
}


void UserUI()
{

    Node* UserMes = UserLoginUI();
    if (!UserMes) {
        return;
    }
    enum UserMenu {
        EXIT, PURCHASEPRODUCT, RECHARGE, INFORMCHANGE, CheckMaterial
    };
	enum MasterMenu select;
	do {
        system("cls");
        UserCatalogue();	//��ӡĿ¼
        printf("��ѡ��:");
		scanf("%d", &select);
		CleanBuffer();
		system("cls");
		switch (select) {
        case EXIT: {
            SaveUserinfo();
            SaveOrderForm();
            break;
        }
        case PURCHASEPRODUCT: { //������Ʒ
            PurchaseProduct(UserMes);
            SaveOrderForm();
            break;
        }
        case RECHARGE: {    //��ֵ
            Recharge(UserMes);
            SaveUserinfo();
            break;
        }
        case INFORMCHANGE: {    //�޸ĸ�����Ϣ
            PrintUserAll(UserMes->m_Data, NULL);
            InformChange(UserMes);
            SaveUserinfo();
            break;
        }
        case CheckMaterial: {   // �鿴������Ϣ
            PrintUserAll(UserMes->m_Data, NULL);
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

