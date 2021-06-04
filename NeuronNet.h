#include<iostream>
#include "NeuronLayer.h"

#pragma once

class NeuronNet
{
	int AmountOfLayers = 0;
	NeuronLayer* NetNeuronLayers;

	int* NetNeuronLayersNeuronAmount;

public:

	NeuronNet(int NeuronLayerAmount, int **NeuronLayerConnections, float*CWeight, int ConnectionsAmount, int a, int speed, int NeuronAmount, int*LayerNeuronAmount, bool initialzie);

	void OutputGraph();

	void InputStartData(int a, int b);
	void CalcGeneration();
};

