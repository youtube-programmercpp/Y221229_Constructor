#include <stdlib.h>
int main()
{
	char* const p = malloc(256);
	//malloc �����s����� p �� NULL �ɂȂ�
	if (p) {
		//����t����ꂽ�̈�̐擪�i�P�o�C�g�j�� Null ����������
		*p = '\0';
	}
	free(p);
}
