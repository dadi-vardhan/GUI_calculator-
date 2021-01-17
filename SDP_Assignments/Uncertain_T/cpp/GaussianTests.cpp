#include <iostream>
#include "uncertain.h"
#include "gaussian.h"
#include "ISampler.h"
// #include "random_primitive.h"

using namespace std;


// RandomPrimitive<T>::RandomPrimitive(){}

void gaussian_sample(){
    Gaussian x(5.0,2.0); 
    Sampler s;
    float* test = s.create(x.distribution,NUM_OF_SAMPLES); 
    for(int i=0; i<100; i++){
        cout << (test[i] >= -3 && test[i <= 13]) << endl; 
        if (!(test[i] >= -3 && test[i <= 13]) ){cout << "break" << endl; break;}
    }

}

void gaussian_mean(){

    float sum_value = 0.0; 
    Gaussian x(5,1); 
    Sampler s; 
    float* test = s.create(x.distribution,NUM_OF_SAMPLES); 
    for(int i=0; i<NUM_OF_SAMPLES; i++){
        sum_value += test[i]; 
    }

    sum_value = sum_value/NUM_OF_SAMPLES ; 
    cout << (sum_value >= 4.6 && sum_value <= 5.4) << endl; 
    if(!(sum_value >= 4.6 && sum_value <= 5.4)) {
        cout << "break" << endl; 
       
    }

}


void gaussian_bnn_sample(){


    // Gaussian z = x+y; 
    Uncertain<float> x = Gaussian(1,1);
    Uncertain<float> y = Gaussian(4,1);
    Uncertain<float> z = x+y;

  
    Sampler s; 
    float* test = s.create(z.distribution,NUM_OF_SAMPLES); 
    float* new_test = s.take(100); 

    for(int i=0; i<100; i++){
        cout << (new_test[i] >= -3.0 && new_test[i] <= 13) << endl; 

    }

}



void gaussian_bnn_mean(){


    // Gaussian z = x+y; 
    Uncertain<float> x = Gaussian(1,1);
    Uncertain<float> y = Gaussian(4,1);
    Uncertain<float> z = x+y;

    float sum = 0.0; 
    Sampler s; 
    float* test = s.create(z.distribution,NUM_OF_SAMPLES); 
    float* new_test = s.take(100); 

    for(int i=0; i<100; i++){
        sum += s.new_distribution[i]; 

    }
    sum = sum/100; 

    cout << (sum >= 4.11 && sum <= 5.89) << endl; 

}


void gaussian_bernoulli_mean(){

    Uncertain<float> x = Gaussian(1,1);
    Uncertain<float> y = Gaussian(4,2);
    Uncertain<float> z = x > y; 

    Sampler s; 
    float* test = s.create(z.distribution,NUM_OF_SAMPLES); 
    float* new_test = s.take(100); 

    int k = 0; 

    for(int i=0; i<100; i++){
        //workaround to get a bernoulli distribution 
        test[i] = abs(round(test[i])) ;
        if (test[i] > 1){ test[i] = 1;}

        if(test[i] >= 1){
            k += 1; 
        }
    }

    cout<< k << " " << (k>=13 && k < 52) << endl; 




}

void gaussian_bernoulli_conditional(){

    Uncertain<float> x = Gaussian(1,1);
    Uncertain<float> y = Gaussian(4,2);
    Uncertain<float> z = x < y;


    if((x>y).probability(1)){

        cout << "X > Y evaluates true, incorrectly" << endl;

    }
    if((x<y).probability(1)){

        cout << "X < Y evaluates true, incorrectly" << endl;

    }

    if(!(x>y).probability(0)){

        cout << "X > Y evaluates true, incorrectly" << endl;

    }

    if(!(x<y).probability(0)){

        cout << "X < Y evaluates true, incorrectly" << endl;

    }





}



int main(){

    Uncertain<float> x = Gaussian(11,0.03);
    Uncertain<float> y = Gaussian(10,0.04);


    gaussian_sample();
    gaussian_mean();
    gaussian_bnn_sample();
    gaussian_bnn_mean();
    gaussian_bernoulli_mean();
    gaussian_bernoulli_conditional();

    return 0;
}
