// #include <iostream>
// #include <math.h>
// #include <vector>
// #include <cstdlib>
// #include <cmath>
// #include <limits>
// #include <algorithm>
// #include <functional>
// #include "uncertain_t.cpp"

#ifndef UNCERTAIN_T_H
#define UNCERTAIN_T_H

using namespace std; 

const int NUM_OF_SAMPLES = 50; 
const double GAUSSIAN_MEAN = 0; 
const double GAUSSIAN_NOISE = 0.1; 
const double THRESHOLD = 0.4; 


template<typename T> 
class Uncertain{
    private: 
        int size; 

    public: 

        Uncertain(T measurement);
        Uncertain(); 
        T mean(); 
        T variance();  
        T pr_g(T check);
        T pr_l(T check);
        T pr_l_eq(T check);
        T pr_g_eq(T check);
        T pr_eq(T check);
        T* ptr;
        T mu; 
        T var; 
        T* distribution; 
        Uncertain<T> operator+(Uncertain<T>); 
        Uncertain<T> operator-(Uncertain<T>); 
        Uncertain<T> operator*(Uncertain<T>); 
        Uncertain<T> operator/(Uncertain<T>); 
        bool operator>(T check); 
        bool operator<(T check);
        bool operator<=(T check);
        bool operator>=(T check);
        bool operator==(T check);  


        void print();  
        // Y mean(); 
        // Y variance();
        T sd(); 
        T* gaussian();
        T generateGaussianNoise(T mu, T sigma); 

        // Y* distribution;  

};

template<typename T>
T Uncertain<T>::pr_g(T check){

    T count = 0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        // cout << "dist[i] " << this->distribution[i] <<" check " << check << endl; 
        if (this->distribution[i] > check){

            count++; 
        }
    }
    // cout << "count is " << count << endl; 
    return (T)count/NUM_OF_SAMPLES; 

}


template<typename T>
T Uncertain<T>::pr_l(T check){

    T count = 0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        // cout << "dist[i] " << this->distribution[i] <<" check " << check << endl; 
        if (this->distribution[i] < check){

            count++; 
        }
    }
    // cout << "count is " << count << endl; 
    return (T)count/NUM_OF_SAMPLES; 

}


template<typename T>
T Uncertain<T>::pr_l_eq(T check){

    T count = 0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        // cout << "dist[i] " << this->distribution[i] <<" check " << check << endl; 
        if (this->distribution[i] <= check){

            count++; 
        }
    }
    // cout << "count is " << count << endl; 
    return (T)count/NUM_OF_SAMPLES; 

}

template<typename T>
T Uncertain<T>::pr_g_eq(T check){

    T count = 0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        // cout << "dist[i] " << this->distribution[i] <<" check " << check << endl; 
        if (this->distribution[i] >= check){

            count++; 
        }
    }
    // cout << "count is " << count << endl; 
    return (T)count/NUM_OF_SAMPLES; 

}

template<typename T>
T Uncertain<T>::pr_eq(T check){

    T count = 0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        // cout << "dist[i] " << this->distribution[i] <<" check " << check << endl; 
        if (this->distribution[i] == check){

            count++; 
        }
    }
    // cout << "count is " << count << endl; 
    return (T)count/NUM_OF_SAMPLES; 

}




template<typename T>
Uncertain<T>::Uncertain(){

    ptr = new T[1];
    size = 1; 
    for (int i =0; i<size; i++){
        ptr[i] = 0; 
    }
    // cout << "ptr=" << ptr[0];


    distribution = new T[NUM_OF_SAMPLES];
    distribution = this->gaussian(); 
    mu = this->mean(); 
    // cout << "mean is calculated " << endl; 
    var = variance(); 
}

template<typename T> 
Uncertain<T>::Uncertain(T measurement){

    // Y q = *(&arr + 1) - arr; 
    // cout << "size is" << q << endl; 
    // s = (int) q; 

    ptr = new T[1];
    size = 1; 
    for (int i =0; i<size; i++){
        ptr[i] = measurement; 
    }
    // cout << "ptr=" << ptr[0];


    distribution = new T[NUM_OF_SAMPLES];
    distribution = this->gaussian(); 
    mu = this->mean(); 
    // cout << "mean is calculated " << endl; 
    var = this->variance(); 
    // cout << "variance is calculated" << endl;  
    // cout << "succeeded" << distribution[2] << endl; 
}


template<typename T>
void Uncertain<T>::print(){

    for (int i=0; i<size; i++){
        cout<<" "<< *(ptr + i) << endl;
    }
}


template<typename T>
T Uncertain<T>::sd(){
    T var = 0;  
    for (int i=0; i < size; i++){
        var += (this->distribution-this->mu)*(this->distribution-this->mu);
    }
    var /= NUM_OF_SAMPLES; 
    T s_d = sqrt(var); 
    return s_d; 
}

//input is one value, sample from a gausian distribution the noises and add it the measured value to get a new distribution
template<typename T>
T * Uncertain<T>::gaussian(){

    T* dist = new T[NUM_OF_SAMPLES]; 
    for(int i=0; i<NUM_OF_SAMPLES; i++){
        dist[i] = this->ptr[0] + this->generateGaussianNoise((T)GAUSSIAN_MEAN,(T)GAUSSIAN_NOISE); 
    }
    return dist;
}

template<typename T>
bool Uncertain<T>::operator>(T check){

    bool decision = false; 
    T threshold = (T)THRESHOLD; 

    if (this->pr_g(check) > threshold){

        decision = true;
    } else {

        decision = false; 
    }
     
     return decision; 


}


template<typename T>
bool Uncertain<T>::operator<(T check){

    bool decision = false; 
    T threshold = (T)THRESHOLD; 

    if (this->pr_l(check) > threshold){

        decision = true;
    } else {

        decision = false; 
    }
     
     return decision; 


}


template<typename T>
bool Uncertain<T>::operator<=(T check){

    bool decision = false; 
    T threshold = (T)THRESHOLD; 

    if (this->pr_l_eq(check) > threshold){

        decision = true;
    } else {

        decision = false; 
    }
     
     return decision; 


}



template<typename T>
bool Uncertain<T>::operator>=(T check){

    bool decision = false; 
    T threshold = (T)THRESHOLD; 

    if (this->pr_g_eq(check) > threshold){

        decision = true;
    } else {

        decision = false; 
    }
     
     return decision; 


}



template<typename T>
bool Uncertain<T>::operator==(T check){

    bool decision = false; 
    T threshold = (T)THRESHOLD; 

    if (this->pr_eq(check) > threshold){

        decision = true;
    } else {

        decision = false; 
    }
     
     return decision; 


}


template<typename T>
Uncertain<T> Uncertain<T>::operator+(Uncertain<T> aso) {

    // distribution = this->gaussian();
    // aso.distribution = aso.gaussian();

    Uncertain<T> brandnew; 
    
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        brandnew.distribution[i] = this->distribution[i] + aso.distribution[i];
    }

    //update other members as well 
    brandnew.mu = brandnew.mean();  
    brandnew.var = brandnew.variance(); 
    return(brandnew);
}

template<typename T>
Uncertain<T> Uncertain<T>::operator-(Uncertain<T> aso) {

    // distribution = this->gaussian();
    // aso.distribution = aso.gaussian();

    Uncertain<T> brandnew; 
    
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        brandnew.distribution[i] = this->distribution[i] - aso.distribution[i];
    }
    //update other members as well 
    brandnew.mu = brandnew.mean();  
    brandnew.var = brandnew.variance(); 
    return(brandnew);
}

template<typename T>
Uncertain<T> Uncertain<T>::operator*(Uncertain<T> aso) {

    // distribution = this->gaussian();
    // aso.distribution = aso.gaussian();

    Uncertain<T> brandnew; 
    
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        brandnew.distribution[i] = this->distribution[i] * aso.distribution[i];
    }
    brandnew.mu = brandnew.mean();  
    brandnew.var = brandnew.variance(); 

    return(brandnew);
}

template<typename T>
Uncertain<T> Uncertain<T>::operator/(Uncertain<T> aso) {

    // distribution = this->gaussian();
    // aso.distribution = aso.gaussian();

    Uncertain<T> brandnew; 
    
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        brandnew.distribution[i] = this->distribution[i] / (aso.distribution[i]+0.0001);
    }
    brandnew.mu = brandnew.mean(); 
    brandnew.var = brandnew.variance(); 
    return(brandnew);
}


// template<typename Y>
// Y mean(Y* ptr,int size){
//     Y summation = 0; 
//     for(int i=0; i<size; i++){
//         summation = summation + *(ptr +i);
//     }
//     return summation/(Y)size; 
// }
template<typename T> 
T Uncertain<T>::mean(){
    T summation = 0; 
    for(int i=0; i<NUM_OF_SAMPLES; i++){
        summation = summation + *(this->distribution +i);
    }
    return summation/(T)NUM_OF_SAMPLES; 

}

// template<typename Y>
// Y variance(Y* ptr,Y mean,int size){
//     Y var = 0;  
//     for (int i=0; i < size; i++){
//         var += (ptr[i]-mean)*(ptr[i]-mean);
//     }
//     var /= size; 
//     return var; 
// }
template<typename T> 
T Uncertain<T>::variance(){
    T var = 0;  
    for (int i=0; i < NUM_OF_SAMPLES; i++){
        var += (this->distribution[i]-this->mu)*(this->distribution[i]-this->mu);
    }
    var /= NUM_OF_SAMPLES; 
    return var; 

}




template<typename T>
T Uncertain<T>::generateGaussianNoise(T mu, T sigma){

    static const double epsilon = std::numeric_limits<double>::min();
    static const double two_pi  = 2.0*3.141592653;
    
    // thread_local double z1;
    double z1;
    // thread_local bool generate;
    bool generate;
    generate = !generate;
    
    if (!generate)
        return z1 * sigma + mu;
    
    double u1,u2;
    do
    {
        u1 = rand() * (1.0 / RAND_MAX);
        u2 = rand() * (1.0 / RAND_MAX);
    }
    while (u1 <= epsilon);
    
    double z0;
    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
    return (T)(z0 * sigma + mu);

}





#endif