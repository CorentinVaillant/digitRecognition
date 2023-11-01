#include "NeuralNet.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>



using namespace std;

NeuralNet::NeuralNet(vector<unsigned int> shape) {
    m_shape = std::move(shape);
    columnNumber = m_shape.size();
    std::vector<Matrice> weights({}), biases({});
    for (int i = 0; i < m_shape.size()-1; ++i) {
        weights.push_back(randomMatrice(m_shape[i + 1], m_shape[i]));
        biases.push_back(randomMatrice(m_shape[i + 1], 1));
    }
    m_weights = weights;
    m_biases = biases;
}

//void NeuralNet::cacheNet() {
    //ofstream
//}

double NeuralNet::relu(double x) {
    if(x>0) return x;
    return 0;}

Matrice NeuralNet::relu(Matrice M) {
    vector<vector<double>> tab(M.getTab());
    for (vector<double> & i : tab) {
        relu(i[0]);}
    return {tab};
}

vector<double> NeuralNet::compute(vector<double> inputs) {
    if(inputs.size() == m_shape[0]){
        Matrice Mat = Matrice({inputs}).getTranspose();
        for (int k = 0; k < m_shape.size()-1; ++k) {
            Mat = relu(m_weights[k]*Mat+m_biases[k]);
        }return Mat.getColumn(0);
    }
    else{cout << "ERROR : invalid input's shape !"<< endl; return {};}
}

void NeuralNet::displayBiases() {
    for (auto & bias : m_biases) {
        bias.print();
        cout<<endl;}
}

void NeuralNet::displayWeights() {
    for (auto & m_weight : m_weights) {
        m_weight.print();
        cout<<endl;}
}

Matrice NeuralNet::randomMatrice(unsigned int I, unsigned int J){
    vector<vector<double>> tab;
    for (int i = 0; i < I; ++i) {
        tab.push_back({});
        for (int j = 0; j < J; ++j) {
                 tab[i].push_back(rand()%100 -50);
        }
    }return {tab};
}
