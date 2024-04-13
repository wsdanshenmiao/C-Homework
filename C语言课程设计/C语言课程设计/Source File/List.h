/*
	Versions1 实现通用链表的基本操作
*/
/*
	Versions2 修改链表结构，模拟析构函数，并增加 Clear 方法清理链表，和 Destroy 方法销毁链表
*/

#ifndef __LIST__H__
#define __LIST__H__

#include "GlobalVariable.h"

typedef struct Node
{
	struct Node* m_Pre;
	struct Node* m_Next;
	void* m_Data;
}Node;

typedef struct List
{
	Node* m_Head;
	size_t m_Size;
	void (*deallocate)(void*);
}List;

bool IsEmpty(const List* const list);
List* InitList(void deallocate(void*));
void PushFront(List* list, const void* const pValue);
void PushBack(List* list, const void* const pValue);
void PopFront(List* list);
void PopBack(List* list);
void DefaultDeallocate(void* pValue);
Node* Insert(List* list, Node* pos, const void* const pValue);
Node* Erase(List* list, Node* pos);
Node* Find(List* list, bool findFunc(void*));
void TraversalOperation(List* list, void operation(void*));
void Clear(List* list);
List* Destroy(List* list);


#endif // !__LIST__H__

