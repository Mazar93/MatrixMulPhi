#include "MatrixMulTBB.h"
#include <iostream>
#include <string>
#include <time.h>
#include <tbb\parallel_for.h>

using namespace std;


MatrixMulTBB::MatrixMulTBB(void)
{
}


MatrixMulTBB::~MatrixMulTBB(void)
{
}

void MatrixMulTBB::setHeigth(const int height){

	this->height = height;
}

void MatrixMulTBB::setWidth(const int width){

	this->width = width;
}

 void MatrixMulTBB::start(){


  clock_t start, end;
  start = clock();

  int **aMatrix = new int*[height];
  for( int i(0); i < height; i++ ) 
	  aMatrix[i] = new int[width];

  int **bMatrix = new int*[height];
  for( int i(0); i < height; i++ ) 
	  bMatrix[i] = new int[width];

  int **eMatrix = new int*[height];
  for( int i(0); i < height; i++ ) 
	  eMatrix[i] = new int[width];

 
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
        for(int b = 0; b<height; b++)
        {
            for(int c = 0; c<width; c++)
            {
                aMatrix[b][c]=rand() % 2 + 0;
				bMatrix[b][c]=rand() % 2 + 0;
 
                a++;
            }
        }



    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < height; k++) {
                eMatrix[i][j] += aMatrix[i][k] * bMatrix[k][j];
            }
            //std::cout << eMatrix[i][j] << "  ";
        }
        //std::cout << "\n";
    }

   end = clock();
   printf("Die Programmlaufzeit betrug %.2f Sekunden\n",
   (float)(end-start) / CLOCKS_PER_SEC);



	getchar();
	



}
