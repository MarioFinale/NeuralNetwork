#include "Network.h"
#include <vector>
#include "Neuron.h"


Network::Network(int inputs, int hiddenQty, int hiddenLayers, int outputs) {

	std::vector<double> tvec(inputs);
	Network::inputs = tvec;

	std::vector<std::vector<Neuron>> tneur;

	for (size_t i = 0; i < hiddenLayers; i++)
	{





	}

}

Network::Network(Neuron perceptron) {
	OutputLayer = { perceptron };
	size_t pinputs = perceptron.input.size();
	std::vector<double> tinputs;
	for (size_t i = 0; i < pinputs; i++)
	{
		tinputs.emplace_back(perceptron.input[i][0]);
	}
	inputs = tinputs;
}

Network::Network(std::vector<Neuron> neurons) {
	OutputLayer = neurons;
	size_t pinputs = neurons[0].input.size();
	std::vector<double> tinputs;
	for (size_t i = 0; i < pinputs; i++)
	{
		tinputs.emplace_back(neurons[0].input[i][0]);
	}
	inputs = tinputs;
}



Network::Network(int inputs, std::vector<Neuron> hidden, std::vector<Neuron> outputs)
{
	std::vector<double> linputs(inputs);
	Network::inputs = linputs;
	std::vector<std::vector<Neuron>> hiddenlayer;
	hiddenlayer.emplace_back(hidden);
	HiddenLayers = hiddenlayer;

	for (size_t neuron = 0; neuron < hiddenlayer.size(); neuron++)
	{

		for (size_t i = 0; i < hiddenlayer[0][neuron].input.size(); i++)
		{
			std::vector<std::vector<double>> tinputs(inputs);
			for (size_t inp = 0; inp < hiddenlayer[0][neuron].input.size(); inp++)
			{
				tinputs[inp] = hiddenlayer[0][neuron].input[inp];
			}
		}
	}
	OutputLayer = outputs;

	for (size_t neuron = 0; neuron < OutputLayer.size(); neuron++)
	{
		for (size_t i = 0; i < OutputLayer[neuron].input.size(); i++)
		{
			std::vector<std::vector<double>> tinputs(inputs);
			for (size_t inp = 0; inp < OutputLayer[neuron].input.size(); inp++)
			{
				tinputs[inp] = OutputLayer[neuron].input[inp];
			}
		}
	}
}

std::vector<double> CalculateOutput(std::vector<double> inputs, std::vector<std::vector<Neuron>> HiddenLayers, std::vector<Neuron> OutputLayer) {

	std::vector<double> linputs = inputs;

	for (size_t layer = 0; layer < HiddenLayers.size(); layer++)
	{
		std::vector<Neuron> tlayer = HiddenLayers[layer];
		std::vector<double> lresults;

		for (size_t neuron = 0; neuron < tlayer.size(); neuron++)
		{
			for (size_t i = 0; i < tlayer[neuron].input.size(); i++)
			{
				tlayer[neuron].input[i][0] = linputs[i];
			}
			lresults.emplace_back(tlayer[neuron].output());
		}
		linputs = lresults;
	}

	std::vector<double> results;

	for (size_t neuron = 0; neuron < OutputLayer.size(); neuron++)
	{
		for (size_t i = 0; i < OutputLayer[neuron].input.size(); i++)
		{
			OutputLayer[neuron].input[i][0] = linputs[i];
		}
		results.emplace_back(OutputLayer[neuron].output());
	}
	return results;
}


Network::~Network()
{
}

void Network::Train(double expectedOutput, int maxiterations)
{





}

std::vector<double> Network::output()
{
	return CalculateOutput(Network::inputs, Network::HiddenLayers, Network::OutputLayer);
}
