#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <random>

using namespace std;

const int NUM_OF_SAMPLES = 100;




float mean(float* x, float s){ 

    float sum = 0.0; 

    for(int i=0; i < s; i++){

        sum += *(x+i); 
    }

    float mean = sum/s ; 

    return mean; 

}


class MarkovChainMonteCarloSampler {
    public: 
        int size; 
        float* distribution; 
        float* new_distribution; 
        int iterations = 5000; 
        MarkovChainMonteCarloSampler();
        MarkovChainMonteCarloSampler(float* distrib, int s);
        float prior(float* x); 
        float random_normal(float mu, float sigma); 
        float random_uniform(float a, float b); 
        float* transition_model(float* x);
        float likelihood(float* x, float* distrib); 
        bool accept(float oldTrace, float trace); 
        float* sampling(); 

};

MarkovChainMonteCarloSampler::MarkovChainMonteCarloSampler(){

    // this->distribution = new float[8];

}


MarkovChainMonteCarloSampler::MarkovChainMonteCarloSampler(float* distrib, int s){

    // this->size = (sizeof(distrib)/sizeof(distrib[0]));
    this->size = s; 
    this->distribution = new float[size];
    for(int i=0; i<size; i++){
        *(distribution + i) = *(distrib + i); }

    this->sampling(); 
}

float MarkovChainMonteCarloSampler::prior(float* x){
    float p = 1;

    if (*(x+1) <= 0){
        p = 0; }

    return p;
}


float MarkovChainMonteCarloSampler::random_normal(float mu, float sigma){

    static const double epsilon = std::numeric_limits<double>::min();
    static const double two_pi  = 2.0*3.141592653;

    // thread_local double z1;
    double z0,z1,mag;
    // thread_local bool generate;
    // bool generate;
    // generate = !generate;
    // srand(time(0));
    // int max = 1;
    // if (!generate)
    //     return z1;

    double u1,u2;


    do
    {
        // u1 = rand() * (1.0 / RAND_MAX);
        // u1 = ((double) rand() / (RAND_MAX)) ;
        // u1 = dist(mt); 
        u1 = this->random_uniform(0,1); 
        u2 = this->random_uniform(0,1); 


        // cout << u1 << "u111" << endl; 
        // u2 = dist(mt); 
        // u2 = ((double) rand() / (RAND_MAX)) ;
        // cout << "u1" << u1 << endl; 
    }
    while (u1 <= epsilon);

    mag = sigma * sqrt(-2.0*log(u1));
    z0 = mag * cos(two_pi * u2) + mu;
    z1 = mag * sin(two_pi * u2) + mu;
    // nextGaussianSample = z1; 
    float sample = (float) z1; 
    // cout << "sample" << sample << endl; 
    // cout << "sample " << sample << endl; 
    return sample;

}

float MarkovChainMonteCarloSampler::random_uniform(float a, float b){
    random_device generator; 
	uniform_real_distribution<float> distribution(a,b);
    float r = distribution(generator); 
    return r; 
}

float* MarkovChainMonteCarloSampler::transition_model(float* x){
    float* xx = new float[2]; 
    xx[0] = x[0]; 
    xx[1] = this->random_normal(*(x+1),0.5);

    return xx; 
}

float MarkovChainMonteCarloSampler::likelihood(float* x, float* distrib){

    float sum = 0.0; 
    float a = 0.0;
    float b = 0.0;
    float c = 0.0; 
    //dont forget to change 3 into NUM_OF_SAMPLES
    for(int i=0; i < 3; i++){
    a =  -log(x[1] * sqrt(2* M_PI) );
    b = (distrib[i] - x[0])*(distrib[i] - x[0]);
    c = 2*x[1]*x[1]; 
    sum +=  a - (b/c);
    }

    return sum; 

}

bool MarkovChainMonteCarloSampler::accept(float oldTrace, float trace){

    bool decision = false; 
    if (trace > oldTrace){

        decision = true; 

    }
    else{ 

        float acceptance = this->random_uniform(0,1); 
        if (acceptance < exp(trace-oldTrace)){
            decision = true; 
        }

    }
    return decision; 
}



float* MarkovChainMonteCarloSampler::sampling(){

float obs_mean = mean(this->distribution,size); 
float x[2] = {obs_mean, 0.1}; 
float* accepted_mean;
accepted_mean = new float[3000]; 
float* accepted_sigma; 
accepted_sigma = new float[3000]; 
// float rejected[][1] = {}; 
float* x_new; 
x_new = new float[2]; 
float x_lik; 
float x_new_lik; 
float oldtrace; 
float newtrace; 
int count_accepted = 0; 
float means_sum = 0.0; 
float sigmas_sum = 0.0;

for(int i=0; i<iterations; i++){
    
    x_new = this->transition_model(x); 
    // for(int i=0; i<2; i++){
    //     cout << "x_new 0 " << x_new[0] << " x_new 1 " << x_new[1] << endl; 
    // }
    x_lik = this->likelihood(x,this->distribution); 
    x_new_lik = this->likelihood(x_new,this->distribution); 
    oldtrace = x_lik + log(this->prior(x)); 
    newtrace = x_new_lik + log(this->prior(x_new)); 
    if(this->accept(oldtrace,newtrace)){
        // cout << "accepted" << endl; 
        for(int i=0; i<2; i++){
            *(x+i) = *(x_new +i); }
            // cout << *(x) << "," << *(x+1) << endl;

        accepted_mean[count_accepted] = x_new[0];
        accepted_sigma[count_accepted] = x_new[1];
        means_sum += x_new[0]; 
        sigmas_sum += x_new[1];

        // cout << accepted_mean[count_accepted] << "," << accepted_sigma[count_accepted]<< endl;

        count_accepted += 1;


        }

    }

// cout << "size of accepted mean = " << (sizeof(accepted_mean)/sizeof(*accepted_mean)) << endl; 


int burnin = (int)(0.75*count_accepted);
// cout << "burnin" << burnin << endl; 
int start = count_accepted - burnin;
// for (int i=start; i<count_accepted; i++){
//     means_sum += accepted_mean[i];
//     sigmas_sum += accepted_sigma[i];
// }

float mu = means_sum/count_accepted;
float sigma = sigmas_sum/count_accepted;

new_distribution = new float[1000]; 
for(int i=0; i<1000; i++){
    new_distribution[i] = this->random_normal(mu,sigma);
}



float* model;
model = new float[2]; 
model[0] = mu; 
model[1] = sigma; 
return model; 








// return this-> distribution; 
}






// int main(){
//     cout << "test mcmc" << endl; 
    

//     float source[10] = {7,7.5,6.7,6.3,6.8,6.5,6,6.1,5.1,7}; 
//     int size = (sizeof(source)/sizeof(source)[0]); 


//     // call sampler 
//     MarkovChainMonteCarloSampler MCMC(source,size); 
//     cout << "source size is " << MCMC.size << endl; 
    

//     // cout << MCMC.distribution[1] << endl; 
//     // cout << MCMC.prior(params) << endl; 
//     // cout <<"rand normal" << MCMC.random_normal(params[0],params[1]) << endl; 
//     // cout << MCMC.transition_model(params)[1] << endl;
//     // cout << MCMC.likelihood(params,source) << endl; 
//     // cout << MCMC.random_uniform() << endl; 
//     // cout << MCMC.accept(0.5,0.3) << endl; 
//     cout << MCMC.sampling()[0] << endl;
//     cout << MCMC.sampling()[1] << endl;

//     return 0; 
// }

