#ifndef __USER__H__
#define __USER__H__

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "LoginSystem.h"
#include "GlobalVariable.h"
#include "List.h"
#include "Util.h"


void UserUI();
void PurchaseProduct(Node* userMes);
void Recharge(Node* userMes);
bool IsNumber(const char* str, size_t num);
bool FindPhoneNum(void* pValue, void* cmpValue);


#endif // !__USER__H__

