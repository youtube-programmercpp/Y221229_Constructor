struct A {
	int d;
	//�������������R���X�g���N�^
	//�f�t�H���g�R���X�g���N�^
	A()
		: d()//d �� 0 �ɂȂ�
	{
	}
	//�R�s�[�R���X�g���N�^
	A(const A& r)
		: d(r.d)
	{
	}
	//�ϊ��R���X�g���N�^
	A(int d)
		: d(d)
	{
	}
	//���������Q�ȏ゠��R���X�g���N�^
	A(int i, int j)
		: d(i + j)
	{
	}
};
int main()
{
	A x(12345);
	A y(x);
	A z(10, 20);

	x = A(500);//A �^�̐V���ȃI�u�W�F�N�g���쐬

}
