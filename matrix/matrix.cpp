/*

Changed on: April, 2016
       Author: Guilherme Malfatti - guimalfatti76@gmail.com

Util:
build arm gem5:
arm-linux-gnueabi-g++ -o2 -static matrix.cpp -o matrix.arm
build x86 gem5:
g++ matrix.cpp -o matrix.x86 -static
exec x86 in gem5
../build/X86/gem5.fast configs/example/se.py  --cpu-type=detailed --caches --l2cache --l1d_size='32kB' --l1i_size='32kB' --l2_size='1MB' --cmd /home/malfatti/git/class/matrix/matrix.arm
or
./build/X86/gem5.fast configs/myScripts/MySimulation.py -c "/home/malfatti/git/class/matrix/40matrix.x86"
exec arm in gem5
 ./build/ARM/gem5.debug configs/example/se.py  --cpu-type=detailed --caches --l2cache --l1d_size='32kB' --l1i_size='32kB' --l2_size='1MB' --cmd /home/malfatti/git/class/matrix/matrix.arm
*/
#include <stdio.h>
#include <iostream>
#define SIZE 40 //|| 50

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
    mat1[c][d] = d;
    mat2[c][d] = d;
  }
}

  int mat3[SIZE][SIZE];
  int M1L=SIZE, M1C=SIZE, M2L=SIZE, M2C=SIZE;
for(linha=0; linha<M1L; linha++)
    for(coluna=0; coluna<M2C; coluna++){
      somaprod=0;
      for(i=0; i<M1L; i++) somaprod+=mat1[linha][i]*mat2[i][coluna];
        mat3[linha][coluna]=somaprod;
    }
  //
  //imprime mat3
  //
    printf("\nDone!\n");

  /*for(linha=0; linha<M1L; linha++){
    for(coluna=0; coluna<M2C; coluna++)
      printf("%d ", mat3[linha][coluna]);
    printf("\n");
  }*/

  return 0;
}
