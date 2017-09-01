#pragma once
//最长回文字串
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

