#pragma once
class MatrixMulTBB
{
public:
	MatrixMulTBB(void);
	~MatrixMulTBB(void);
	void setHeigth(int);
	void setWidth(int);
	void start();

private:

	int height;
	int width;
};

