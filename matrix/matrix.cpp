/*

Changed on: April, 2016
       Author: Guilherme Malfatti - guimalfatti76@gmail.com

Util:
build arm gem5:
arm-linux-gnueabi-g++ -o2 -static matrix.cpp -o matrix.arm
build x86 gem5:
g++ matrix.cpp -o matrix.x86 -static

 objdump -D matrix.x86 > apagarDump.txt

exec x86 in gem5
./build/X86/gem5.fast configs/example/se.py  --cpu-type=detailed --caches --l2cache --l1d_size='32kB' --l1i_size='32kB' --l2_size='1MB' --cmd /home/malfatti/git/benchmarks/matrix/matrix.arm
or
./build/X86/gem5.fast configs/myScripts/MySimulation.py -c "/home/malfatti/git/benchmarks/matrix/40matrix.x86"
exec arm in gem5
 ./build/ARM/gem5.debug configs/example/se.py  --cpu-type=detailed --caches --l2cache --l1d_size='32kB' --l1i_size='32kB' --l2_size='1MB' --cmd /home/malfatti/git/benchmarks/matrix/matrix.arm
*/
#include <stdio.h>
#include <iostream>
 #include <stdlib.h>
#include <time.h>
#define SIZE 10 //|| 50 //tamanho da minha tabela de armazenamento é de size^3
volatile int BEGIN_ROI = 3;
volatile int END_ROI = 4;
int myVar;

int multiplication(int a, int b){
  myVar = BEGIN_ROI;
  //printf("Numero : %d\n", rand()% 50);
  //printf("%d               a:%d b:%d\n", a*b, a, b);
  int res = a * b;
  return res;
}

int main(int argc, char *argv[])
{ int linha;
  int coluna;
  int i;

  int somaprod;
int mat1[SIZE][SIZE], mat2[SIZE][SIZE];

for (int c = 0; c < SIZE; c++)
{
  for (int d = 0; d < SIZE; d++)
  {
    mat1[c][d] = rand()% 50;
    mat2[c][d] = rand()% 50;
  }
}

  //printf("intervalo da rand: [0,%d]\n", RAND_MAX);
  int mat3[SIZE][SIZE];
  int M1L=SIZE, M1C=SIZE, M2L=SIZE, M2C=SIZE;
for(linha=0; linha<M1L; linha++)
    for(coluna=0; coluna<M2C; coluna++){
      somaprod=0;
      for(i=0; i<M1L; i++) {

        somaprod += multiplication(mat1[linha][i], mat2[i][coluna]);

        myVar = END_ROI;
      }
      mat3[linha][coluna]=somaprod;
    }
  //
  //imprime mat3
  //
  printf("\nDone!\n");
  for(linha=0; linha<M1L; linha++){
    for(coluna=0; coluna<M2C; coluna++){
      //printf("%d ", mat3[linha][coluna]);
    }
    //printf("\n");
  }
  /*
 printf("\n");

  for(linha=0; linha<M1L; linha++){
    for(coluna=0; coluna<M2C; coluna++){
      printf("%d ", mat2[linha][coluna]);
    }
    printf("\n");
  }
 printf("\n");
  for(linha=0; linha<M1L; linha++){
    for(coluna=0; coluna<M2C; coluna++){
      printf("%d ", mat1[linha][coluna]);
    }
    printf("\n");
  }*/

  return 0;
}
