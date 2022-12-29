#include <stdlib.h>
#include <stdexcept>
struct A {
	size_t n;//�̈�̑傫��
	char*  p;//�̈�̐擪�A�h���X (����������t���Ɏ��s�����Ƃ��� nullptr)
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
	//�R�s�[�R���X�g���N�^
	A(const A& r)
		: n(r.n)
		, p(static_cast<char*>(malloc(r.n)))
	{
		if (p)
			memcpy(p, r.p, r.n);
		else
			throw std::bad_alloc();
	}
	//������Z�q�̃I�[�o�[���[�h
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
		//�܂��Ar ���������g���ǂ���������
		//this �͎������g�̃A�h���X
		if (this == &r) {
			//���̏ꍇ�A�������Ȃ�
		}
		else {
			//���̏ꍇ�Ɍ���R�s�[�����{
			if (const auto new_p = static_cast<char*>(malloc(r.n))) {
				//��nullptr
				memcpy(new_p, r.p, r.n);
				//���A�������g�������Ă��郁�����̈�����
				free(p);
				p = new_p;
				n = r.n;
			}
			else
				throw std::bad_alloc();
		}
		return *this;//�������g�ɑ΂���Q�Ƃ�Ԃ�
	}
	//�ړ��R���X�g���N�^
	A(A&& r) noexcept
		: n(r.n)
		, p(r.p)
	{
		r.n = 0;
		r.p = nullptr;
	}
	//�ړ�������Z�q
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

