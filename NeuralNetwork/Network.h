#pragma once
#include "Network.h"
#include <vector>
#include <string>
#include "Neuron.h"
class Network
{
public:
	Network(std::string name, int inputs, std::vector<Neuron> hidden, std::vector<Neuron> outputs);
	Network(std::string name, int inputs, int Qty, int Layers, int outputs);
	Network(std::string name, std::vector<Neuron> neurons);
	Network(std::string name, Neuron perceptron);
	std::string OUTPUT_NETWORK_INFO();
	~Network();
	void Train(double expectedOutput, int maxiterations);
	std::vector<double> inputs;
	std::vector<double> output();
	std::vector<std::vector<Neuron>> Layers;
	std::vector<std::vector<Neuron>> HiddenLayers;
	std::vector<Neuron> OutputLayer;
	std::string Name;
};

