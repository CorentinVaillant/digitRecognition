#ifndef DEEPLEARNING_NEURALNET_H
#define DEEPLEARNING_NEURALNET_H
#include <vector>
#include "Matrice.h"

class NeuralNet {
public:
    std::vector<double> compute(std::vector<double> inputs);
    NeuralNet(std::vector<unsigned int> shape);
    void displayBiases();
    void displayWeights();
    //void cacheNet();
private:

    std::vector<unsigned int> m_shape;
    unsigned int columnNumber;

    std::vector<Matrice> m_weights, m_biases;

    double relu(double x);
    Matrice relu(Matrice M);
    Matrice randomMatrice(unsigned int i, unsigned int j);
};



#endif //DEEPLEARNING_NEURALNET_H
