#include <iostream>
#include <fstream>
#include "Matrice.h"
#include <vector>

using namespace std;

Matrice imageToMatrice(Matrice M,char name[100]){
    FILE *pFile;
    pFile = fopen(name,"wb");
    if(pFile){
    vector<vector<double>> tab = M.getTab();
    }
    else{
        char error[124];
        sprintf(error,"could not write the file %s",name);
        perror("could not write the file");
        //here
    }
}