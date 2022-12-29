#include <stdlib.h>
int main()
{
	char* const p = malloc(256);
	//malloc が失敗すると p は NULL になる
	if (p) {
		//割り付けられた領域の先頭（１バイト）に Null 文字を書く
		*p = '\0';
	}
	free(p);
}
