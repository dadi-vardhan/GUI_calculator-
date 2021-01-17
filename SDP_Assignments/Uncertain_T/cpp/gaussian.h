#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <random>
#include "uncertain.h"
#include "ISampler.h"
#include "MarkovChainMonteCarloSampler.h"
#ifndef GAUSSIAN
#define GAUSSIAN

using namespace std;
// const int NUM_OF_SAMPLES = 1000; 
// const int SET_SIZE = 15; 
// const float BIN_SIZE = 0.5; 

class Gaussian: public MarkovChainMonteCarloSampler{

    private:
        

    public:
        float mu;
        float std_dev;
        // float*  distribution; 
        float nextGaussianSample; 
        int size;
        // map<float,float> prob_distribution; 
        Gaussian();
        ~Gaussian(); 
        Gaussian(float mean, float var);
        template<class Q> Gaussian(const Q &x){

                Q tmp = x;
                distribution = new float[NUM_OF_SAMPLES];
                for (int i=0; i < NUM_OF_SAMPLES; i++ ){
                *(this->distribution+i) = tmp.GetSample() ;}
                // this->histogram();
                MarkovChainMonteCarloSampler MCMC(this->distribution,NUM_OF_SAMPLES); 
                for(int i=0; i<NUM_OF_SAMPLES; i++){
                    this->distribution[i] = this->new_distribution[i]; 
                }
                }
        // float Pr(double t);
        float NextGaussian(); 
        float GetSample(); 

        float* arr; 
        float* prob_distribution;
       
        // Gaussian operator=(Gaussian x); 
        
};

Gaussian::Gaussian(){}
Gaussian::~Gaussian(){
    // delete[] this->distribution;
}

Gaussian::Gaussian(float mean, float stddev){
            this->mu = mean; 
            this->std_dev = stddev; 
            for(int i=0; i<NUM_OF_SAMPLES; i++){
                this->distribution[i] = GetSample(); 
            }
            
        }


float Gaussian::NextGaussian(){

    static const double epsilon = std::numeric_limits<double>::min();
    static const double two_pi  = 2.0*3.141592653;

    // thread_local double z1;
    double z0,z1,mag;

    double u1,u2;


    do
    {

        u1 = this->random_uniform(0,1); 
        u2 = this->random_uniform(0,1); 

    }
    while (u1 <= epsilon);

    mag = this->std_dev * sqrt(-2.0*log(u1));
    z0 = mag * cos(two_pi * u2) + this->mu;
    z1 = mag * sin(two_pi * u2) + this->mu;

    float sample = (float) z1; 

    return sample;

}

float Gaussian::GetSample(){
    
    return this->NextGaussian() * this->std_dev + this->mu; 

}




#endif