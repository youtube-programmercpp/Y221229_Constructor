#include <stdio.h>
void f(FILE* fp)
{
	for (;;) {
		const int ch = fgetc(fp);
		if (ch == EOF)
			break;
		else {
			putchar(ch);
			continue;
		}
	}
}
int main()
{
	FILE* const fp = fopen(__FILE__, "r");
	if (fp) {
		f(fp);
		//�g���I�������N���[�Y
		fclose(fp);
	}
}
