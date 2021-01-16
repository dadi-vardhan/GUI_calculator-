#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <random>
#include "MarkovChainMonteCarloSampler.h"

#ifndef ISAMPLER
#define ISAMPLER 


using namespace std;

class Sampler : public MarkovChainMonteCarloSampler {
    private:

    public:
        float* model; 
        Sampler(); 
        float* create(float* distrib,int size);
        float* take(int size); 

};

Sampler::Sampler(): MarkovChainMonteCarloSampler(){}

float* Sampler::create(float* distrib,int size){

    this->new_distribution = new float[1000];

    MarkovChainMonteCarloSampler MCMC(distrib,size); 
    for(int i=0; i<1000; i++) {

        this->new_distribution[i] = MCMC.new_distribution[i]; 
    }
    return this->new_distribution; 
}


float* Sampler::take(int size){

    float* samples_set = new float[size]; 
    int random_index = 0; 
    for(int i=0; i<size; i++){
        random_index = (int)this->random_uniform(0,size); 
        samples_set[i] = this->new_distribution[random_index]; 
    }

    return samples_set;

}

// int main(){
//     Sampler s;
//     float test_samples[3] = {8.4,8.0,8.2}; 
//     float* d = new float[3];
//     int size = (sizeof(test_samples)/sizeof(test_samples)[0]);
//     d = s.create(test_samples,size);
//     cout << d[0] << " " << d[1] << " " << d[2] <<  endl; 
//     float* samples = new float[3]; 
//     samples = s.take(3); 
//     cout << samples [0] << " " << samples[1] << endl; 

//     return 0; 
// }
#endif