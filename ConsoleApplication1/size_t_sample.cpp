/*
* size_t �� unsigned long ��A�X�ɑ傫�ȕ������������^
*/
// 32�r�b�g�������������^�ŕ\���ł���l 4GB
// 32�r�b�g�ł� Windows �ł� size_t �� unsigned long �^�ŗǂ�����
// typedef unsigned long size_t;
// 64�r�b�g�ł� Windows �ł� long �^�� 32 �r�b�g�̂܂�
// typedef unsigned long long size_t; ����� 64 �r�b�g

// size_t �͕����������������A���ꂪ int �^�̕��Along �^�̕��Along long �^�̕�
// size_t �̓������̑傫���A�܂��͂���Ɋ֌W���鉽�炩�̃f�[�^
// ptrdiff_t �͕����t���Ń|�C���^�̍���\���^

template<size_t n>void f(int(&a)[n])
{
}
#include <stdint.h>
#include <string.h>
int main()
{
	const char s[] = "ABCDEFG";
	const auto p = strchr(s, 'D');
	const auto x = p - s;
	



	
}


