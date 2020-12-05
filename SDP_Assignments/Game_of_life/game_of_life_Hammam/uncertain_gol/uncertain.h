#ifndef UNCERTAIN_T_H
#define UNCERTAIN_T_H

using namespace std; 

const int NUM_OF_SAMPLES = 100;
const int SET_SIZE = 15;
const float BIN_SIZE = 1;

template<typename T>
class Uncertain{
    private:
        int size;
    public:
        Uncertain();
        Uncertain(T constant,T constant2=0.0);
        //copy constructor
        template<class Q> Uncertain(const Q &x){

                Q tmp = x; 
                distribution = new T[NUM_OF_SAMPLES];
                for (int i=0; i < NUM_OF_SAMPLES; i++ ){
                *(this->distribution+i) = tmp.GetSample() ;}
                this->histogram();
                
                
                
                }
        // }

        // cout<< tmp.mu<<endl; ;}


                // *() = *();
                // cout<<x.dist()[7];
                // copy(std::begin(x.dist()), end(x.dist()), begin(this->distribution));
                // *(this->distribution) = *(x.dist(this->distribution));
        // };
        T* distribution;
        T pr(T x);
        T* arr; 
        T* prob_distribution;
        T smallest(T* arr, int n) ;
        T largest(T* arr, int n) ;
        
        T e();  
        void histogram(); 
        Uncertain<T> operator+(Uncertain<T>);
        Uncertain<T> operator-(Uncertain<T>);
        Uncertain<T> operator*(Uncertain<T>);
        Uncertain<T> operator/(Uncertain<T>);
        template<typename Q> void operator=(Q x);
        template<typename Q> bool operator>(Q);
        template<typename Q> bool operator>=(Q);
        template<typename Q> bool operator<(Q);
        template<typename Q> bool operator<=(Q);
        template<typename Q> bool operator==(Q);

};

template<typename T>
Uncertain<T>::Uncertain(){
    distribution = new T[NUM_OF_SAMPLES];
    // this->histogram();
}
template<typename T>
Uncertain<T>::Uncertain(T constant, T constant2){
    distribution = new T[NUM_OF_SAMPLES];
    for(int i=0; i<NUM_OF_SAMPLES; i++){
        *(distribution + i) = constant; 
        // this->histogram();
    }
    // this->histogram();
}

template<typename T>
template<typename Q> bool Uncertain<T>::operator>(Q x){

    bool result = true; 

    
    
    float probability_sum= 0.0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){

        if (this->distribution[i]>x){
            probability_sum++ ;
        }}
    
    probability_sum = probability_sum/ NUM_OF_SAMPLES; 
    

    if (probability_sum >= 0.5){

        result = true; 
    } else {

        result= false;  
    }

    // if (this->e() > x && this->pr(this->e()) >= 0.45){

    //     result= true; 
    // } else {

    //     result = false; 
    // }

        

    
    return result;

}

// template<typename T>
// template<typename Q> void Uncertain<T>::operator=(Q x){

//     for (int i=0; i < NUM_OF_SAMPLES; i++ ){
//                 *(this->distribution+i) = x.GetSample();}
// }

template<typename T>
T Uncertain<T>::e(){

    T ev = 0.0; 

    for(int i=0; i < SET_SIZE; i++){

        // cout <<this->pr(this->distribution[i]) << "*" << this->distribution[i] <<( this->pr(this->distribution[i])*this->distribution[i]) << endl; 

        ev  = ev +( this->pr(this->arr[i]) *this->arr[i]); 


    }


return ev;

}

template<typename T>
template<typename Q> bool Uncertain<T>::operator>=(Q x){

    bool result = true; 

    float probability_sum= 0.0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){

        if (this->distribution[i]>=x){
            probability_sum++ ;
        }}
    
    probability_sum = probability_sum/ NUM_OF_SAMPLES; 
    

    if (probability_sum >= 0.5){

        result = true; 
    } else {

        result= false;  
}

return result;}



template<typename T>
template<typename Q> bool Uncertain<T>::operator==(Q x){

    bool result = true; 

    
    
    float probability_sum= 0.0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){

        if (this->distribution[i]==x){
            probability_sum++ ;
        }}
    
    probability_sum = probability_sum/ NUM_OF_SAMPLES; 
    

    if (probability_sum >= 0.5){

        result = true; 
    } else {

        result= false;  
    }


    return result;

}





template<typename T>
template<typename Q> bool Uncertain<T>::operator<=(Q x){

    bool result = true; 
    // if(1-this->pr(x)>0.5){
    //     result = true;

    // }else{
    //     result = false; 
    // }
    //THE GENERAL CONCEPT IS USE CDF 
    
    // this->histogram();
    float probability_sum= 0.0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){

        if (this->distribution[i]<=x){
            probability_sum++ ;
        }}
    
    probability_sum = probability_sum/ NUM_OF_SAMPLES; 
    

    if (probability_sum >= 0.5){

        result = true; 
    } else {

        result= false;  
    

}
return result;}


template<typename T>
template<typename Q> bool Uncertain<T>::operator<(Q x){

    bool result = true; 
    // if(1-this->pr(x)>0.5){
    //     result = true;

    // }else{
    //     result = false; 
    // }
    //THE GENERAL CONCEPT IS USE CDF 
    
    // this->histogram();
    float probability_sum= 0.0; 
    for (int i=0; i<NUM_OF_SAMPLES; i++){

        if (this->distribution[i]<x){
            probability_sum++ ;
        }}

    probability_sum = probability_sum/ NUM_OF_SAMPLES; 


    if (probability_sum >= 0.5){

        result = true; 
    } else {

        result= false; 

}
return result;}

template<typename T>
T Uncertain<T>::pr(T x){
    this->histogram();
    T count = 0.0; 
    for (int i=0; i<SET_SIZE; i++){
        if(x >  *(this->arr+i) && x<=  *(this->arr+i+1)){
            count = this->prob_distribution[i];
        }
    
    }
    delete[] arr; 
    delete[] prob_distribution;
    return count;
}

template<typename T>
Uncertain<T> Uncertain<T>::operator+(Uncertain<T> aso) {

    // distribution = this->gaussian();
    // aso.distribution = aso.gaussian();

    Uncertain<T> brandnew; 
    
    for (int i=0; i<NUM_OF_SAMPLES; i++){
        brandnew.distribution[i] = this->distribution[i] + aso.distribution[i];
    }
    // brandnew.histogram();

    return(brandnew);
}

template<typename T>
Uncertain<T> Uncertain<T>::operator-(Uncertain<T> aso) {

    // distribution = this->gaussian();
    // aso.distribution = aso.gaussian();

    Uncertain<T> brandnew; 

    
    for (int i=0; i<NUM_OF_SAMPLES; i++){

        brandnew.distribution[i] = this->distribution[i]  - aso.distribution[i];
    }
    // brandnew.histogram();

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
    // brandnew.histogram();

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
    // brandnew.histogram();

    return(brandnew);
}

template<typename T>
T Uncertain<T>::largest(T* arr, int n) 
{ 
    int i; 
      
    // Initialize maximum element 
    float max = arr[0]; 
  
    // Traverse array elements  
    // from second and compare 
    // every element with current max  
    for (i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
  
    return max; 
} 

template<typename T>
T Uncertain<T>::smallest(T* arr, int n) 
{ 
    int i; 
      
    // Initialize maximum element 
    float min = arr[0]; 
  
    // Traverse array elements  
    // from second and compare 
    // every element with current max  
    for (i = 1; i < n; i++) 
        if (arr[i] < min) 
            min = arr[i]; 
  
    return min; 
} 


template<typename T>
void Uncertain<T>::histogram(){

    int n = NUM_OF_SAMPLES;
    T max = this->largest(this->distribution,n); 
    T min = this->smallest(this->distribution,n);
    
    // int size = 0;
    size = abs(int(max - min)+2); 
    if (max <= 1){
        size = abs((int)max*100); 
        // cout << "size now is "<< size; 
        // cout << (int)max*100; 
    }
    else{
    // size = (int)max +2;
    size = SET_SIZE; 
    
     }


    arr = new T[size]; 
    // for(int i=0; i<size; i++){
    //     arr[i] = 0.0;
    // }
    for (int i =0; i<size; i++){
        // cout << i ; 
        if (max >=0 && max <= 1 ){
            arr[i] = min + i*0.2 - 3*BIN_SIZE ;
        }else
        {arr[i] = (int)min + i*BIN_SIZE- 3*BIN_SIZE;}
         
        // cout << arr[i] << endl; 
    }
    // cout << "samples last" <<arr[size-1] << endl; 


    prob_distribution = new T[size]; 
    for (int i =0; i < size; i++){
        prob_distribution[i] = 0.0;
    }

    // sort(samples, samples + size); 
    // cout << "size " << n ; 
      for (int i =0; i<n; i++){

       for (int j=0; j < size+1; j++){
        // cout <<"time to count" <<arr[j]<<" "<<distribution[i] << "and "<<arr[j+1]<<endl;
        if (this->distribution[i] >= arr[j] && this->distribution[i] < arr[j+1]) {
            // cout <<"who am I " << samples[i] <<endl;
            prob_distribution[j]++; 
            // cout << prob_distribution[j]++ <<endl;

        }}


    }

    float sum = 0.0;

    for (int j =0; j < size; j++){

        sum = sum + prob_distribution[j];
    }

    for (int i =0; i < size; i++){

        prob_distribution[i] = prob_distribution[i]/sum;
        // cout <<arr[i]<<","<< prob_distribution[i]<<endl;

    }
    // for (int i=0; i<size; i++) 
    // {   cout << "rv: " << arr[i] << " : ";
        
    //     cout << prob_distribution[i] << " "<<endl; 
    
    // // probs.push_back(probabilities[i]); 
    // }
    }






#endif