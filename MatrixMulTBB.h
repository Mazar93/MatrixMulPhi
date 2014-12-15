#ifndef MATRIXMULTBB_H
#define MATRIXMULTBB_H

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

#endif
