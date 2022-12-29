#include <stdlib.h>
#include <stdexcept>
struct A {
	size_t n;//領域の大きさ
	char*  p;//領域の先頭アドレス (メモリ割り付けに失敗したときは nullptr)
	A(size_t n)
		: n(n)
		, p(static_cast<char*>(malloc(n)))
	{
		if (p == nullptr)
			throw std::bad_alloc();
		else
			memset(p, 0, n);
	}
	~A()
	{
		free(p);
	}
	//コピーコンストラクタ
	A(const A& r)
		: n(r.n)
		, p(static_cast<char*>(malloc(r.n)))
	{
		if (p)
			memcpy(p, r.p, r.n);
		else
			throw std::bad_alloc();
	}
	//代入演算子のオーバーロード
	A& operator=(size_t n)
	{
		if (const auto new_p = static_cast<char*>(malloc(n))) {
			memset(new_p, 0, n);
			free(p);
			p = new_p;
			this->n = n;
			return *this;
		}
		else
			throw std::bad_alloc();	
	}

	A& operator=(const A& r)
	{
		//まず、r が自分自身かどうかを見る
		//this は自分自身のアドレス
		if (this == &r) {
			//この場合、何もしない
		}
		else {
			//この場合に限りコピーを実施
			if (const auto new_p = static_cast<char*>(malloc(r.n))) {
				//非nullptr
				memcpy(new_p, r.p, r.n);
				//今、自分自身が抱えているメモリ領域を解放
				free(p);
				p = new_p;
				n = r.n;
			}
			else
				throw std::bad_alloc();
		}
		return *this;//自分自身に対する参照を返す
	}
	//移動コンストラクタ
	A(A&& r) noexcept
		: n(r.n)
		, p(r.p)
	{
		r.n = 0;
		r.p = nullptr;
	}
	//移動代入演算子
	A& operator=(A&& r) noexcept
	{
		if (this != &r) {
			free(p);
			p = r.p;
			n = r.n;
			r.p = nullptr;
			r.n = 0;
		}
		return *this;
	}

};
int main()
{
	A x = 256;
	A y = x;
	x = 512;
	x = (A&&)(y);
}

