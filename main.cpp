/*
g++ -fdiagnostics-color=always -g /home/corentin/C++/digitRecognition/main.cpp Matrice.cpp -o /home/corentin/C++/digitRecognition/main && ./main
*/
#include  <iostream>
#include "Matrice.h"
#include "Images.cpp"
#include <vector>
using namespace std;

//c

Matrice randomMatrice(unsigned int I, unsigned int J){
    vector<vector<double>> tab;
    for (unsigned int i = 0; i < I; ++i) {
        tab.push_back({});
        for (unsigned int j = 0; j < J; ++j) {
                 tab[i].push_back(rand()%100 -50);
        }
    }return {tab};
}

int main(){
    printf("yo\n");
    Matrice A = randomMatrice(250000,1);
    //NeuralNet net = NeuralNet({250000,250,125,2});
    A.print();
    A.freeConectedMatrice();
    return 0;
}