#pragma once
class MatrixMulOMP
{
public:
	MatrixMulOMP(void);
	~MatrixMulOMP(void);
	void setHeigth(int);
	void setWidth(int);
	void start();

private:

	int height;
	int width;
};

