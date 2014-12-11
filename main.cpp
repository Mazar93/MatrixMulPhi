
#include <iostream>
#include <string>
#include <time.h>
#include "MatrixMulOMP.h"
#include "MatrixMulCilk.h"
#include "MatrixMulTBB.h"


#define MAX 20

using namespace std;

int main() {


	int height, width;
	string form;
	 

	cout << "Zeilen der Matrix eingeben:  ";
	cin >> height;
	cout << "Spalten der Matrix eingeben:  ";
	cin >> width;

	cout << "Bitte eingeben:" << endl;
	cout << "1 fuer OpenMP" << endl;
	cout << "2 fuer Cilk" << endl;
	cout << "3 fuer TBB" << endl;
	cin >> form;


	
	if (form == "1"){
			MatrixMulOMP omp;
			omp.setHeigth(height);
			omp.setWidth(width);
			omp.start();
		}
	else if (form == "2"){
			MatrixMulCilk cilk;
			cilk.setHeigth(height);
			cilk.setWidth(width);
			cilk.start();
		}
	else if (form == "3"){
			MatrixMulTBB tbb;
			tbb.setHeigth(height);
			tbb.setWidth(width);
			tbb.start();
		}


		getchar();
		return 0;




}