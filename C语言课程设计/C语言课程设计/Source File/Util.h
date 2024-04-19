#ifndef __UTIL__H__
#define __UTIL__H__

#include <string.h>
//��Ÿ�������

inline void CleanBuffer()
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

// �ַ��������⣬����ʧ�ܷ���true
inline bool StrInputFailure(int erromes, char* name)
{
	if (!name) {
		return true;
	}
	size_t len = strnlen_s(name, sizeof(name));
	if (!erromes || erromes == EOF || len == 0 || len >= sizeof(name)) {
		return true;
	}
	return false;
}

// ���������⣬����ʧ�ܷ���true
inline bool NumInputFailure(int erromes)
{
	if (!erromes || erromes == EOF) {
		return true;
	}
	return false;
}


#endif // !__HELLPFUNC__H__

