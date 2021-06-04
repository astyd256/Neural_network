#include "Neuron.h"

Neuron::Neuron(float aa, double weight1, double weight2) {
    /**
     * ����������� ������ � ������� �������� ��������� ���� �������
     * � ������� ���������� ������.*/
    if (std::abs(weight1) <= 1 and std::abs(weight2) <= 1) {
        weight = new double[2];
        weight[0] = weight1;
        weight[1] = weight2;
        a = aa;
    }
    else throw std::range_error("Weight is higher than expected.\n");
}

double Neuron::calculate(double value1, double value2) {
    /**
     * ����� ������, ������������� �������� �������� ������� �� ������ �����.*/
    return a * (value1 * weight[0] + value2 * weight[1]);
}

double Neuron::learn(double value1, double value2, double result, float speed) {
    /**
     * ����� ������, ���������� �� ��������.
     * @return:: �������� ���������� ����� ������� ��������� � ����������*/
    double delta = a * (calculate(value1, value2) - result);
    double delta_w1 = -speed * delta * value1;
    double delta_w2 = -speed * delta * value2;
    weight[0] = weight[0] + delta_w1;  // ���������� ������ �����
    weight[1] = weight[1] + delta_w2;  // ���������� ������ �����
    a = a - delta * speed;
    return 0.5 * pow(result - calculate(value1, value2),2);
}

double Neuron::get_a() const {
    return a;
}

double* Neuron::get_weight() {
    return weight;
}
