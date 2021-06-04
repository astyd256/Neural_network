#include "Neuron.h"

#pragma once
class NeuronLayer
{
	Neuron* LayerNeurons;
	int NeuronAmount;
	int* NeuronIndexes;

public:

	void SetLayer(int NAmount, int aaa, int sss, int* IndexCounter, int** Connected, int CAmount, float* ConWeights);

	int GetNeuronsAmount();

	Neuron& operator[](int i);
	
};

