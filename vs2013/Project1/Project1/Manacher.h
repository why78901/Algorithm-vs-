#pragma once
//������ִ�
class Manacher
{
public:
	Manacher();
	~Manacher();
	void Init();

private:
	int min(int a, int b);
	void GetManacher(char str[], int p[]);
};

