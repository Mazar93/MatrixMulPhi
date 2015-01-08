
#include <iostream>
#include <string>
#include <time.h>
#include "MatrixMul.h"
#include "MatrixMulOMP.h"
#include "MatrixMulCilk.h"
#include "MatrixMulTBB.h"



#define MAX 20

using namespace std;

int main() {


	int dim;
	string form;
	 

	cout << "Dimension der Matrix eingeben:  ";
	cin >> dim;
	

	cout << "Bitte eingeben:" << endl;
	cout << "1 fuer normal" << endl;
	cout << "2 fuer OpenMP" << endl;
	cout << "3 fuer Cilk" << endl;
	cout << "4 fuer TBB" << endl;
	cin >> form;


	if (form == "1"){
			MatrixMul none;
			none.setDim(dim);
			none.start();
		}
	else if (form == "2"){
			MatrixMulOMP omp;
			omp.setDim(dim);
			omp.start();
		}
	else if (form == "3"){
			MatrixMulCilk cilk;
			cilk.setDim(dim);
			cilk.start();
		}
	else if (form == "4"){
			MatrixMulTBB tbb;
			tbb.setDim(dim);
			tbb.start();
		}


		getchar();
		return 0;




}