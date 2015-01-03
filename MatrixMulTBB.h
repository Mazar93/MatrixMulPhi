#ifndef MATRIXMULTBB_H
#define MATRIXMULTBB_H


class MatrixMulTBB
{
public:
	MatrixMulTBB(void);
	~MatrixMulTBB(void);
	void setDim(int);
	void start();

private:
     int dim;
	
};

#endif

