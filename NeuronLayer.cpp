#include "NeuronLayer.h"

void NeuronLayer::SetLayer(int NAmount, int aaa, int sss, int *IndexCounter, int **Connected, int CAmount, float* ConWeights)
{
	NeuronAmount = NAmount;
	LayerNeurons = new Neuron[NeuronAmount];

	int* ConnectedToVertex;
	ConnectedToVertex = new int[CAmount];

	float* ConnectedW;
	ConnectedW = new float[CAmount];

	int k = 0;
	for (int i = 0; i < NeuronAmount; i++)
	{
		k = 0;
		for(int j = 0;j<CAmount;j++)
			if (*IndexCounter == Connected[j][0])
			{
				ConnectedW[k] = ConWeights[j];
				ConnectedToVertex[k] = Connected[j][1];
				k++;
			}

		LayerNeurons[i].SetData(aaa, sss, *IndexCounter, ConnectedToVertex, k, ConnectedW);
		*IndexCounter = *IndexCounter + 1;
	}
	delete[] ConnectedToVertex;
}

int NeuronLayer::GetNeuronsAmount()
{
	return NeuronAmount;
}

Neuron& NeuronLayer::operator[](int i)
{
	if (i < NeuronAmount) return LayerNeurons[i];
	else throw "Out of size bounds!";
}
