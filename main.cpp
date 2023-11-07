#include  <iostream>
#include "Matrice.h"
#include "Images.cpp"
#include <vector>
using namespace std;


int main(){
    printf("yo\n");
    Matrice A = randomMatrice(250000,1);
    //NeuralNet net = NeuralNet({250000,250,125,2});
    A.print();
    A.freeConectedMatrice();
    return 0;
}