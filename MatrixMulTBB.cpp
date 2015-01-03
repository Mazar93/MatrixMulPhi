#include "MatrixMulTBB.h"
#include <iostream>
#include <string>
#include <time.h>
#include <tbb\parallel_for.h>
#include <chrono>

using namespace std;


MatrixMulTBB::MatrixMulTBB(void)
{
}


MatrixMulTBB::~MatrixMulTBB(void)
{
}

void MatrixMulTBB::setDim(const int dim){

	this->dim = dim;
}


 void MatrixMulTBB::start(){

	string opt;
	cout << "optimiert? (andere Schleifenanordnung) yes/no" << endl;
	cin >> opt;


  int **aMatrix = new int*[dim];
  for( int i(0); i < dim; i++ ) 
	  aMatrix[i] = new int[dim];

  int **bMatrix = new int*[dim];
  for( int i(0); i < dim; i++ ) 
	  bMatrix[i] = new int[dim];

  int **eMatrix = new int*[dim];
  for( int i(0); i < dim; i++ ) 
	  eMatrix[i] = new int[dim];

 
 /* vector<vector<int> > aMatrix;

  // Set up sizes. (HEIGHT x WIDTH)
  aMatrix.resize(HEIGHT);
  for (int i = 0; i < HEIGHT; ++i)
    aMatrix[i].resize(WIDTH);

   vector<vector<int> > bMatrix;

  // Set up sizes. (HEIGHT x WIDTH)
  bMatrix.resize(HEIGHT);
  for (int i = 0; i < HEIGHT; ++i)
    bMatrix[i].resize(WIDTH);


   vector<vector<int> > eMatrix;

  // Set up sizes. (HEIGHT x WIDTH)
  eMatrix.resize(HEIGHT);
  for (int i = 0; i < HEIGHT; ++i)
    eMatrix[i].resize(WIDTH); */
	srand(time(0));
 
        int a = 1;
        for(int b = 0; b<dim; b++)
        {
            for(int c = 0; c<dim; c++)
            {
                aMatrix[b][c]=rand() % 2 + 0;
				bMatrix[b][c]=rand() % 2 + 0;
 
                a++;
            }
        }

	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

 	if (opt == "no"){
       
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				for (int k = 0; k < dim; k++) {
					  
            
                eMatrix[i][j] += aMatrix[i][k] * bMatrix[k][j];
            }
            //std::cout << eMatrix[i][j] << "  ";
        }
        //std::cout << "\n";
    }
}//if

	else if (opt == "yes"){
       
			for (int i = 0; i < dim; i++) {
				for (int k = 0; k < dim; k++) {
				 for (int j = 0; j < dim; j++) {
					  
            
                eMatrix[i][j] += aMatrix[i][k] * bMatrix[k][j];
            }
            //std::cout << eMatrix[i][j] << "  ";
        }
        //std::cout << "\n";
    }
}//else if

	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	cout << std::chrono::duration<double>(end-start).count() << endl;

   


	getchar();
	



}
