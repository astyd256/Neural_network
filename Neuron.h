#include <cmath>
#include <stdexcept>
#pragma once
class Neuron
{
public:
    double get_a() const;
    double* get_weight();
	Neuron(float aa, double weight1, double weight2);
	double calculate(double value1, double value2);
	double learn(double value1, double value2, double result, float speed);

private:
    double* weight;
    double a;
};

