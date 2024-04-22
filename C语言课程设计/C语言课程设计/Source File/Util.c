#define _CRT_SECURE_NO_WARNINGS

#include "Util.h"

void CleanBuffer()
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

bool StrInputFailure(int erromes, char* name, size_t size)
{
	if (!name) {
		return true;
	}
	size_t len = strnlen(name, size);
	if (!erromes || erromes == EOF || len == 0 || len >= size) {
		return true;
	}
	return false;
}

// 数字输入检测，输入失败返回true
bool NumInputFailure(int erromes)
{
	if (!erromes || erromes == EOF) {
		return true;
	}
	return false;
}



void SaveUserinfoFunc(void* pValue, void* operateValue)
{
	FILE* pfw = (FILE*)operateValue;
	fwrite(pValue, sizeof(Userinfo), 1, pfw);
}
//保存账号信息
void SaveUserinfo()
{
	FILE* pfw = fopen("Userinfo.dat", "wb");	//创建文件
	if (pfw == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	TraversalOperation(g_Userinfo, SaveUserinfoFunc, pfw);
	fclose(pfw);
}

// 保存订单
void SaveOrderFormFunc(void* pValue, void* operateValue)
{
	FILE* pfw = (FILE*)operateValue;
	fwrite(pValue, sizeof(OrderForm), 1, pfw);
}
void SaveOrderForm()
{
	FILE* opfw = fopen("OrderForm.dat", "wb");	//创建文件
	if (opfw == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	TraversalOperation(g_OrderForm, SaveOrderFormFunc, opfw);
	fclose(opfw);
}

// 保存商品信息
void SaveCommodityFunc(void* pValue, void* operateValue)
{
	FILE* pfw = (FILE*)operateValue;
	fwrite(pValue, sizeof(Commodity), 1, pfw);
}
void SaveCommodity()
{
	FILE* cpfw = fopen("Commodity.dat", "wb");	//创建文件
	if (cpfw == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	TraversalOperation(g_Commodity, SaveCommodityFunc, cpfw);
	fclose(cpfw);
}


// 打印订单链表
void PrintOrderForm(void* pValue, void* operateValue)
{
	OrderForm* orderForm = (OrderForm*)(pValue);
	printf("%zu\t%s\t%zu\t%zu\t%s\t%s\t%s\t%s\n",
		orderForm->m_OrderNumber, orderForm->m_CommodityName,
		orderForm->m_CommodityNum, orderForm->m_CommodityPrices,
		orderForm->m_UserName, orderForm->m_UserPhoneNum,
		orderForm->m_UserAddress, orderForm->m_OrderStatus);
}

// 打印商品
void PrintCommofity(void* pValue, void* operateValue)
{
	Commodity* commofity = (Commodity*)(pValue);
	printf("%s\t%zu\n",
		commofity->m_CommodityName,
		commofity->m_CommodityPrices);
}

// 打印全部账号信息
void PrintUserAll(void* pValue, void* operateValue)
{
	Userinfo* userinfo = (Userinfo*)pValue;
	printf("%s\t%s\t%s\t%s\t%zu\n",
		userinfo->m_Username,
		userinfo->m_Password,
		userinfo->m_UserPhoneNum,
		userinfo->m_Address,
		userinfo->m_Balance);
}

// 打印账号信息,这里没有显示账号的密码
void PrintUser(void* pValue, void* operateValue)
{
	Userinfo* userinfo = (Userinfo*)pValue;
	printf("%s\t%s\t%s\t%lld\n",
		userinfo->m_Username,
		userinfo->m_UserPhoneNum,
		userinfo->m_Address,
		userinfo->m_Balance);
}
