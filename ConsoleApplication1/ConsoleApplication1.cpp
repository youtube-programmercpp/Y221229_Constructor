#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdexcept>
class A/*型名、構造体名、クラス名*/ {
	FILE* fp;
public:
	//コンストラクタは関数
	// 
	//オブジェクトが構築されようとしているとき
	//コンストラクタが呼び出される
	A(FILE* fp)
		: fp(fp)
	{
	}
	//デストラクタも関数
	//オブジェクトが破棄されようとしているとき
	//デストラクタが呼び出される
	~A()
	{
		fclose(fp);
	}
	int read_int()
	{
		int n;
		if (fscanf(fp, "%d", &n) == 1)
			return n;
		else
			throw std::runtime_error("fscanf失敗");
	}
};
int main()
{
	try {
		FILE* const fp = fopen(__FILE__, "r");
		if (fp) {
			A    x(fp);
			x.read_int();//ここで例外発生
			//ここには来ない
			printf("終了\n");
		}
	}
	catch (const std::exception& e) {
		fprintf(stderr, "%s\n", e.what());
	}
}
