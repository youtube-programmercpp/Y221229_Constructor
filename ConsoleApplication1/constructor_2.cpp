#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct A {
	FILE* fp;
	A(FILE* fp)
		: fp(fp)
	{
	}
	~A()
	{
		if (fp)
			fclose(fp);
	}
};
int main()
{
	A x(fopen(__FILE__, "r"));
	A y(x);
	//ìÒèdÇÃ fclose Ç™î≠ê∂
}

