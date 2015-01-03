#ifndef MATRIXMULCILK_H
#define MATRIXMULCILK_H

class MatrixMulCilk
{
public:
	MatrixMulCilk(void);
	~MatrixMulCilk(void);
	void setDim(int);
	void start();

private:

	int dim;
};

#endif