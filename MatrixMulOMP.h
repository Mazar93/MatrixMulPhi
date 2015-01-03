#ifndef MATRIXMULOMP_H
#define MATRIXMULOMP_H

class MatrixMulOMP
{
public:
	MatrixMulOMP(void);
	~MatrixMulOMP(void);
	void setDim(int);
	void start();

private:

	int dim;
};

#endif

