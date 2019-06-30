#include "Neuron.h"
#include <vector>
#include <cmath>
#include <iostream>

Neuron::Neuron(int id, int inputs)
{
	Neuron::bias = 0.5;
	Neuron::id = id;
	Neuron::learningFactor = 0.1;
	Neuron::itCount = 0;
	std::vector<double> tvals = { 0, 0.1 };
	std::vector<std::vector<double>> timput(inputs, tvals);
	Neuron::input = timput;
}

double StepActivationFunction(double sum, double bias) {
	return sum >= bias;
}

double SigmoidActivationFunction(double sum, double bias) {
	double temp = sum + bias;
	return  1 / (1 + std::exp(-temp));
}

double Neuron::output()
{
	double sum = 0;
	size_t inputsize = Neuron::input.size();
	for (int i = 0; i < inputsize; i++)
	{
		sum += Neuron::input[i][0] * Neuron::input[i][1];
	}
	return StepActivationFunction(sum, Neuron::bias);
}

bool GradientDescent(std::vector<std::vector<double>> & input, double output, double expectedVal, double learningFactor) {
	double error = expectedVal - output;
	size_t inputsize = input.size();
	for (int i = 0; i < inputsize; i++)
	{
		double newWeight = input[i][1] + learningFactor * error * input[i][0];
		input[i][1] = newWeight;
	}
	return true;
}

bool Neuron::Train(double expectedVal, int maxIterations) {
	bool result = false;
	for (size_t i = 0; i < maxIterations; i++)
	{
		Neuron::itCount++;
		result = GradientDescent(Neuron::input, Neuron::output(), expectedVal, Neuron::learningFactor);
		double actualOutput = output();
		if (actualOutput == expectedVal) {			
			break;
		}
	}
	return result;
}

bool Neuron::Train(std::vector<std::vector<double>> inputs, std::vector<double> expectedVals, int maxIterations) {
	size_t evalscount = expectedVals.size();
	size_t inputscount = inputs.size();

	bool ok = true;
	for (size_t i = 0; i < maxIterations; i++)
	{
		ok = true;
		for (size_t inputComb = 0; inputComb < inputscount; inputComb++)
		{
			SetInputs(inputs[inputComb]);
			Train(expectedVals[inputComb], maxIterations);
		}
		
		for (size_t i = 0; i < inputscount; i++)
		{
			SetInputs(inputs[i]);
			double tval = output();
			ok = (ok && (tval == expectedVals[i]));
		}
		if (ok == true) { break; }
	}
	return ok;
}

bool Neuron::SetInputs(std::vector<double> inputs)
{
	size_t icount = input.size();
	for (size_t i = 0; i < icount; i++)
	{
		input[i][0] = inputs[i];
	}
	return true;
}

Neuron::~Neuron()
{


}
