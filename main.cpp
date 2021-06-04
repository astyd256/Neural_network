#include <iostream>
#include <ctime>
#include "Neuron.h"
/* Default values */
float desired_deviation = 0.01;
int MAX_ITER = 1000;             // number of max iterations required for learning
float speed = 0.000001;          // speed of learning

int main() {
    /* Creating neuron */
    srand(time(nullptr)); // generating new seed
    float A = rand()%10 + rand()%100/100.;                    // generating random a (in activation function y = kx + a)
    double WEIGHT1 = rand()%2 - rand()%100/100.;               // random weight
    double WEIGHT2 = rand()%2 - rand()%100/100.;               // random weight
    Neuron n1(A, WEIGHT1, WEIGHT2);             // creating new object of class neuron

    std::cout << "A: " << n1.get_a() << "; weight 1: " << n1.get_weight()[0] << "; weight 2: " << n1.get_weight()[1] << ".\n";

    double deviation = 10000, value1, value2;
    int counter;

    /* Learning */
    for (counter = 0; deviation > desired_deviation and counter < MAX_ITER; counter++) {
        value1 = (rand()%100 + rand()%100/100.); // creating new example value 1
        value2 = (rand()%100 + rand()%100/100.); // creating new example value 2
        deviation = n1.learn(value1, value2, value1 + value2, speed); //

        std::cout << value1 << " + " << value2 <<" Result: \n";
        std::cout << "Number of generation: " << counter << '\n';
        std::cout << "With neuron (desired deviation = " << desired_deviation << "): " << n1.calculate(value1, value2) << '\n';
        std::cout << "With computing: " << value1 + value2 << '\n';
        std::cout << n1.get_weight()[0] << '\t' << n1.get_weight()[1] << '\t' << n1.get_a() <<'\n';
    }

    /* Result output */
    std::cout << "Input 2 numbers, which you want to  summarize: \n";
    std::cin >> value1;
    std::cin >> value2;
    std::cout << "With neuron (desired deviation = " << desired_deviation << "): " << n1.calculate(value1, value2) << '\n';
    std::cout << "With computing: " << value1 + value2 << '\n';
}
