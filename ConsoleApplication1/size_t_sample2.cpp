#include <stdio.h>
int main()
{
	// zu を使う size_t 型だから
	printf("%zu\n", sizeof(int));
	printf("%d\n", (int)sizeof(int));
	printf("%u\n", (unsigned)sizeof(int));
	void (*p)();
	char buf[256];
	void (*q)();
	char buf2[256];
	scanf_s("%s", buf, (unsigned)sizeof buf);
	scanf("%s", buf);

	//C99 標準規格で定められた関数
}
