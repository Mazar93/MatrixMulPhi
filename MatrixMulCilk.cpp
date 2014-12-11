#include "MatrixMulCilk.h"
#include <iostream>
#include <string>
#include <time.h>
#include <cilk\cilk.h>
#include <cilk\cilk_api.h>

using namespace std;

MatrixMulCilk::MatrixMulCilk(void)
{
}


MatrixMulCilk::~MatrixMulCilk(void)
{
}

void MatrixMulCilk::setHeigth(const int height){

	this->height = height;
}

void MatrixMulCilk::setWidth(const int width){

	this->width = width;
}

 void MatrixMulCilk::start(){


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



    cilk_for (int i = 0; i < height; i++) {
        cilk_for (int j = 0; j < height; j++) {
            cilk_for (int k = 0; k < height; k++) {
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
