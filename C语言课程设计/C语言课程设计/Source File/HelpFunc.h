#ifndef __HELLPFUNC__H__
#define __HELLPFUNC__H__

//´æ·Å¸¨Öúº¯Êý

void CleanBuffer()
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

#endif // !__HELLPFUNC__H__

