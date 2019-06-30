#pragma once
#include "Network.h"
#include <vector>
#include "Neuron.h"
class Network
{
public:
	Network(int inputs, std::vector<Neuron> hidden, std::vector<Neuron> outputs);
	Network(int inputs, int Qty, int Layers, int outputs);
	Network(std::vector<Neuron> neurons);
	Network(Neuron perceptron);
	~Network();
	void Train(double expectedOutput, int maxiterations);
	std::vector<double> inputs;
	std::vector<double> output();
	std::vector<std::vector<Neuron>> Layers;
	std::vector<std::vector<Neuron>> HiddenLayers;
	std::vector<Neuron> OutputLayer;
};

