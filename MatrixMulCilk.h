#ifndef MATRIXMULCILK_H
#define MATRIXMULCILK_H

class MatrixMulCilk
{
public:
	MatrixMulCilk(void);
	~MatrixMulCilk(void);
	void setHeigth(int);
	void setWidth(int);
	void start();

private:

	int height;
	int width;
};

#endif
