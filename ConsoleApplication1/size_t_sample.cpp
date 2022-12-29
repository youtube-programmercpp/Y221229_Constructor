/*
* size_t は unsigned long や、更に大きな符号無し整数型
*/
// 32ビット符号無し整数型で表現できる値 4GB
// 32ビット版の Windows では size_t は unsigned long 型で良かった
// typedef unsigned long size_t;
// 64ビット版の Windows では long 型は 32 ビットのまま
// typedef unsigned long long size_t; これは 64 ビット

// size_t は符号無し整数だが、それが int 型の幅、long 型の幅、long long 型の幅
// size_t はメモリの大きさ、またはそれに関係する何らかのデータ
// ptrdiff_t は符号付きでポインタの差を表す型

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


