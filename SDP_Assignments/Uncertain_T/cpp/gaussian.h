#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <random>
#include "uncertain.h"

using namespace std;
// const int NUM_OF_SAMPLES = 1000; 
// const int SET_SIZE = 15; 
// const float BIN_SIZE = 0.5; 

class Gaussian{

    private:
        

    public:
        float mu;
        float std_dev;
        // float*  distribution; 
        float nextGaussianSample; 
        int size;
        // map<float,float> prob_distribution; 
        Gaussian();
        Gaussian(float mean, float var);
        // float Pr(double t);
        float NextGaussian(); 
        float GetSample(); 
        float pdf(float x); 
        // void histogram(float bin_size);
        // float smallest(float* arr, int n); 
        // float largest(float* arr, int n);
        float pr(float);
        float* arr; 
        float* prob_distribution;
        vector<float> rvs;
        vector<float> probs;
       
        // Gaussian operator=(Gaussian x); 
        
};

Gaussian::Gaussian(){}

Gaussian::Gaussian(float mean, float stddev){
            this->mu = mean; 
            this->std_dev = stddev; 
            
        }







// float Gaussian::Pr(double t){
//     float a = 1.0/(this->std_dev * sqrt(2*22/7)); 
//     float b = exp(-pow(t-this->mu,2)/(2*this->std_dev*this->std_dev));
//     return a*b;
// }

float Gaussian::NextGaussian(){

    static const double epsilon = std::numeric_limits<double>::min();
    static const double two_pi  = 2.0*3.141592653;

    // thread_local double z1;
    double z1;
    // thread_local bool generate;
    bool generate;
    generate = !generate;
    srand(time(0));
    int max = 1; 
    if (!generate)
        return z1;

    double u1,u2;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-1,1);
    do
    {
        // u1 = rand() * (1.0 / RAND_MAX);
        // u1 = ((double) rand() / (RAND_MAX)) ;
        u1 = dist(mt); 
        // cout << u1 << "u111" << endl; 
        u2 = dist(mt); 
        // u2 = ((double) rand() / (RAND_MAX)) ;
        // cout << "u1" << u1 << endl; 
    }
    while (u1 <= epsilon);

    double z0;
    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
    nextGaussianSample = z1; 
    double sample = z0; 
    // cout << "sample " << sample << endl; 
    return sample;

}

float Gaussian::GetSample(){
    
    return this->NextGaussian() * this->std_dev + this->mu; 

}

float Gaussian::pdf(float x){
    float h = (x-this->mu)/(this->std_dev);
    float a = -h*h*0.5;
    return exp(a)/((sqrt(2) * sqrt(3.14))*this->std_dev);
}



