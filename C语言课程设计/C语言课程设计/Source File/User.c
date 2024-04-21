#define _CRT_SECURE_NO_WARNINGS

#include"User.h"

#define MALLOC(T) ((T*)malloc(sizeof(T)))
#define ASSERTPOINTER(T) if (!(T)) {return NULL;}



// 用户充值
bool RechargeUserAccount(Userinfo* user, size_t amount) {
    if (user == NULL || amount == 0) {
        return false; // 如果用户不存在或充值金额为0，则返回失败
    }
    user->m_Balance += amount; // 更新用户余额
    return true;
}

// 用户充值
void Recharge(Node* userMes) 
{
    // 用户信息在登录时就找到了，不用再输了    

    size_t amount;
    printf("请输入充值金额：\n");
    int error = scanf("%zu", &amount); // 获取用户输入的充值金额
    CleanBuffer();
    if (NumInputFailure(error)) { // 检查输入是否失败
        printf("输入错误，请重新输入。\n");
        return;
    }

    Userinfo* userinfo = (Userinfo*)(userMes->m_Data);
    userinfo->m_Balance += amount;   // 这里没必要写成函数
    printf("充值成功，当前余额：%zu\n", userinfo->m_Balance); // 充值成功，打印当前余额
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

// 用户选择商品
Node* SelectProduct() {
    printf("请输入商品名称：\n"); // 提示用户输入商品名称
    char name[20]; // 存储输入的商品名称
    int error = scanf("%s", name); // 读取用户输入
    CleanBuffer(); // 清除输入缓冲区
    if (StrInputFailure(error, name)) { // 检查输入是否失败
        printf("输入错误，请重新输入。\n");
        return NULL; // 输入失败时返回 NULL
    }
    Node* node = Find(g_Commodity, FindProduct, name); // 在商品链表中查找商品
    if (!node) {
        printf("未找到该商品。\n"); // 若未找到商品，输出提示
    }
    return node; // 返回找到的商品节点
}

// 用户输入购买数量
size_t GetUserQuantity() {
    printf("请输入购买数量：\n"); // 提示用户输入购买数量
    size_t quantity; // 存储购买数量
    int error = scanf("%zu", &quantity); // 读取用户输入的数量
    CleanBuffer(); // 清除输入缓冲区
    if (NumInputFailure(error) || quantity <= 0) { // 检查输入是否失败
        printf("请输入大于0的数字。\n");
        return 0; // 输入失败返回0
    }
    return quantity; // 返回输入的数量
}

// 创建订单
OrderForm* CreateOrder(Commodity* commodity, Userinfo* userinfo, size_t quantity)
{
    OrderForm* order = MALLOC(OrderForm); // 分配内存给订单
    ASSERTPOINTER(order);
    order->m_OrderNumber = rand();  // 随机生成订单号
    order->m_CommodityNum = quantity; // 设置购买数量
    order->m_CommodityPrices = commodity->m_CommodityPrices * quantity; // 计算总价格
    strncpy(order->m_UserName, userinfo->m_Username, sizeof(order->m_UserName)); // 设置用户名
    strncpy(order->m_UserPhoneNum, userinfo->m_UserPhoneNum, sizeof(order->m_UserPhoneNum)); // 设置用户电话号码
    strncpy(order->m_CommodityName, commodity->m_CommodityName, sizeof(order->m_CommodityName)); // 设置商品名称
    strncpy(order->m_UserAddress, userinfo->m_Address, sizeof(order->m_UserAddress)); // 设置用户地址
    strncpy(order->m_OrderStatus, "待发货", sizeof("待发货")); // 设置订单状态为“待发货”
    return order; // 返回创建的订单
}

// 用户购买商品
void PurchaseProduct(Node* userMes)
{
    TraversalOperation(g_Commodity, PrintCommofity);
    Node* selectedProduct = SelectProduct(); // 用户选择商品
    if (!selectedProduct) {
        return; // 如果商品选择失败，返回
    }
    size_t quantity = GetUserQuantity(); // 获取用户输入的购买数量
    if (quantity == 0) {
        return; // 如果输入的数量为0，返回
    }
    Commodity* commodity = (Commodity*)(selectedProduct->m_Data);
    Userinfo* userinfo = (Userinfo*)(userMes->m_Data);  //用户信息在登录时就可以找到
    OrderForm* order = CreateOrder(commodity, userinfo, quantity); // 创建订单
    if (!order) {
        printf("订单创建失败。\n"); // 如果订单创建失败，输出提示
        return;
    }
    PushFront(g_OrderForm, order); // 将订单加入订单链表          这就没必要写成函数了
    printf("订单提交成功！订单号：%zu\n", order->m_OrderNumber); // 输出订单提交成功信息及订单号
}

void UserCatalogue()
{
	printf("*****************0.EXIT ********************\n");
    printf("*****************1.PURCHASEPRODUCT ********************\n");
}



void UserUI()
{

    Node* UserMes = UserLogin();
    if (!UserMes) {
        return;
    }

    enum UserMenu {
        EXIT, PURCHASEPRODUCT, RECHARGE
    };
	enum MasterMenu select;
	do {
		UserCatalogue();	//打印目录
		printf("请选择:");
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
		default: {
			printf("输入错误。\n");
			getchar();
			break;
		}
		}
		system("cls");
	} while (select);
}

