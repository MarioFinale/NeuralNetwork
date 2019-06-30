#pragma once
#include <vector>

class Neuron
{
public:
	Neuron(int id, int inputs);
	~Neuron();
	bool Train(std::vector<std::vector<double>> inputs, std::vector<double> expectedVals, int maxIterations);
	bool Train(double expectedVal, int maxIterations);
	bool SetInputs(std::vector<double> inputs);
	int id;
	int itCount;
	double bias;
	double learningFactor;
	std::vector<std::vector<double>> input;
	double output();
};
