#include "NeuronNet.h"

NeuronNet::NeuronNet(int NeuronLayerAmount, int** NeuronLayerConnections, float* CWeight, int ConnectionsAmount, int a, int speed, int NeuronAmount, int* LayerNeuronAmount, bool initialzie)
{//                     кол-во слоев                       кол-во свзяей и между чем             кон а    скорость об       кол-во нейронов          кол-во нейронов в слою                
	AmountOfLayers = NeuronLayerAmount;
	NetNeuronLayers = new NeuronLayer[AmountOfLayers];

	int* PointConnections;
	PointConnections = new int[ConnectionsAmount];

	NetNeuronLayersNeuronAmount = new int[AmountOfLayers];
	int IndCounter = 0;
	for (int i = 0; i < AmountOfLayers; i++)
	{
		NetNeuronLayersNeuronAmount[i] = LayerNeuronAmount[i];
		NetNeuronLayers[i].SetLayer(NetNeuronLayersNeuronAmount[i], a, speed, &IndCounter, NeuronLayerConnections, ConnectionsAmount, CWeight);
	}
}

void NeuronNet::OutputGraph()
{
	for (int i = AmountOfLayers - 1; i >= 0; i--)
	{
		for (int j = 0; j < NetNeuronLayers[i].GetNeuronsAmount(); j++)
			std::cout << NetNeuronLayers[i][j].GetConnected(0) << "(" << NetNeuronLayers[i][j].GetConnectedWeight(0) << ")=(b ="<< NetNeuronLayers[i][j].GetB()<<")" << NetNeuronLayers[i][j].GetIndex() <<"(data = "<< NetNeuronLayers[i][j].GetData()<< ")=(" << NetNeuronLayers[i][j].GetConnectedWeight(1) << ")" << NetNeuronLayers[i][j].GetConnected(1) << "\t";
		
		std::cout << std::endl;
	}
}

void NeuronNet::InputStartData(int a, int b)
{
	NetNeuronLayers[0][0].SetDataS(a);
	NetNeuronLayers[0][1].SetDataS(b);
}

void NeuronNet::CalcGeneration()
{
	/*int AmountOfLayers = 0;
	NeuronLayer* NetNeuronLayers;
	int NetConnectionsAmount = 0;
	int** NetConnections;
	float* NetConnectionsWeight;
	int aa = 0;
	int LearnSpeed = 0;
	int NerounsAmount = 0;
	int* NetNeuronLayersNeuronAmount = 0;*/

	for (int i = 0; i < AmountOfLayers - 1; i++)
	{
		float IndexWeight = 0, **S;
		int j = 0, n = 0, m = 0, ic = 0, iw = 0, icn = 0;
		bool next = false;

		n = NetNeuronLayers[i].GetNeuronsAmount();
		m = NetNeuronLayers[i+1].GetNeuronsAmount();

		S = new float*[m];
		for (int mm = 0; mm < m; mm++)
		{
			S[mm] = new float[2]; //S array of connections/weights for next layer consists of (index of vertex to pass weight, weight to pass)
			S[mm][0] = NetNeuronLayers[i + 1][mm].GetIndex();
			S[mm][1] = 0;
		}

		for (int in = 0; in < n; in++) //For every neuron in layer (i)
		{
			ic = 0, iw = 0;
			icn = NetNeuronLayers[i][in].GetConnectionsAmount();
			for (; ic < icn; ic++) //For every connection at neuron (in) in layer (i)
			{
				//Calc S for the next layer with connection data (ic) at neuron (in)
				int ConI = NetNeuronLayers[i][in].GetConnected(ic); //Connected index

				for (int im = 0; im < m; im++) 
					//Check connected index with indexes of vertex in (i+1) layer (already in S)
					//and add correct data with index in S
					if (ConI == (int)S[im][0])
					{
						float d = NetNeuronLayers[i][in].GetData() * NetNeuronLayers[i][in].GetConnectedWeight(ic);
						S[ic][1] += d;
						d = 0;
					}
				
			}
		}
		//
		for (int mm = 0; mm < m; mm++)
			NetNeuronLayers[i + 1][mm].CalcData(S[mm][1]);
		
			
		for (int mm = m-1; mm >=0; mm--)
			delete[] S[mm];
		
		delete[] S;
	}
}
