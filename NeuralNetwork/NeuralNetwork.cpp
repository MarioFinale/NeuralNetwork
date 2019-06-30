// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include "Neuron.h"
#include "Network.h"

bool checkinput() {

	if (!std::cin) {
		std::cout << "\n Valor invalido.";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}


void OUTPUT_NETWORK_INFO(Network nnetwork) {

	std::cout << "\n\n============INFORMACION SOBRE LA RED============";
	std::cout << "\nEntradas: "; std::cout << nnetwork.inputs.size();
	size_t hiddenLayers = nnetwork.HiddenLayers.size();
	for (size_t layerindex = 0; layerindex < hiddenLayers; layerindex++)
	{
		std::cout << "\nCapa oculta "; std::cout << layerindex; std::cout << ":";
		size_t ncount = nnetwork.HiddenLayers[layerindex].size();
		for (size_t nindex = 0; nindex < ncount; nindex++)
		{
			std::cout << "\n  Neurona "; std::cout << nindex; std::cout << ":";
			std::cout << "\n    Pesos: ";
			size_t nweights = nnetwork.HiddenLayers[layerindex][nindex].input.size();
			std::cout << "{";
			for (size_t w = 0; w < nweights; w++)
			{
				std::cout << nnetwork.HiddenLayers[layerindex][nindex].input[w][1];
				if (w < nweights - 1) {
					std::cout << ",";
				}
			}
			std::cout << "}";
		}
	}
	std::cout << "\nCapa de salida:";
	size_t ncount = nnetwork.OutputLayer.size();
	for (size_t nindex = 0; nindex < ncount; nindex++)
	{
		std::cout << "\n  Neurona "; std::cout << nindex; std::cout << ":";
		std::cout << "\n    Pesos: ";
		size_t nweights = nnetwork.OutputLayer[nindex].input.size();
		std::cout << "{";
		for (size_t w = 0; w < nweights; w++)
		{
			std::cout << nnetwork.OutputLayer[nindex].input[w][1];
			if (w < nweights - 1) {
				std::cout << ",";
			}
		}
		std::cout << "}";
	}
	std::cout << "\n================================================";
}

void XOR_GATE_EXCERCISE() {
	std::cout << "Entrenando...";
	std::clock_t begin = clock();
	Neuron OR_perceptron = Neuron::Neuron(0, 2);

	std::vector<std::vector<double>> OR_inputs = {	{0,0},
													{0,1},
													{1,0},
													{1,1} };
	std::vector<double> OR_results = { 0, 1, 1, 1 };
	OR_perceptron.Train(OR_inputs, OR_results, -1);

	Neuron AND_perceptron = Neuron::Neuron(0, 2);
	std::vector<std::vector<double>> AND_inputs = { {0,0},
													{0,1},
													{1,0},
													{1,1} };
	std::vector<double> AND_results = { 0, 0, 0, 1 };
	AND_perceptron.Train(AND_inputs, AND_results, -1);

	Neuron XOR_perceptron = Neuron::Neuron(0, 2);
	std::vector<std::vector<double>> XOR_inputs = { {0,0},
													{0,1},
													{1,0},
													{1,1} };
	std::vector<double> XOR_results = { 0, 0, 1, 0 };
	XOR_perceptron.Train(XOR_inputs, XOR_results, -1);


	clock_t end = clock();
	double elapsed_secs = double((double)end - (double)begin) / CLOCKS_PER_SEC;
	std::cout << "\nEntrenamiento completo.";

	std::cout << "\n"; std::cout << AND_perceptron.itCount + OR_perceptron.itCount + XOR_perceptron.itCount; std::cout << " iteraciones";
	std::cout << " en "; std::cout << elapsed_secs; std::cout << " segundos.";

	std::vector<Neuron> hiddenlayer = { OR_perceptron , AND_perceptron };
	std::vector<Neuron> outputlayer = { XOR_perceptron };
	Network XOR_Network = Network(2, hiddenlayer, outputlayer);

	OUTPUT_NETWORK_INFO(XOR_Network);

	double a;
	double b;

	while (true)
	{
		std::cout << "\n\n\nEntrada A:"; std::cin >> a;
		checkinput();
		std::cout << "\nEntrada B:"; std::cin >> b;
		checkinput();

		if (((a == 0) || (a == 1)) && ((b == 0) || (b == 1))) {
			XOR_Network.inputs[0] = a;
			XOR_Network.inputs[1] = b;
			std::cout << "\nResultado: "; std::cout << XOR_Network.output()[0];
		}
		else {
			std::cout << "\n Las entradas deben ser 0 o 1.";
		}
	}
}

void PerceptronExercise() {

	Neuron tperceptron = Neuron::Neuron(0, 9);

	std::vector<double> inputs = { 0,1,0,0,0,0,1,0,1 };
	double results[1] = { 1 };
	tperceptron.SetInputs(inputs);
	std::cout << "Entrenando...";
	std::clock_t begin = clock();
	tperceptron.Train(results[0], -1);
	clock_t end = clock();
	double elapsed_secs = double((double)end - (double)begin) / CLOCKS_PER_SEC;
	std::cout << "\nEntrenamiento completo.";
	std::cout << "\n"; std::cout << tperceptron.itCount; std::cout << " iteraciones";
	std::cout << " en "; std::cout << elapsed_secs; std::cout << " segundos.";
	Network tnet = Network(tperceptron);
	OUTPUT_NETWORK_INFO(tnet);
}





int main()
{
	//PerceptronExercise();

	XOR_GATE_EXCERCISE();

}
