#include <iostream>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <algorithm>
#include <functional>
#include "uncertain_t.h"
// #include "uncertain_t.cpp"

using namespace std; 

int main(){


    // double arr[5] = {1.757,1.454,1.234,1.123,1.023};
    double meas = 1.0;  
    Uncertain<double> a(meas);

   

    cout << "mean= " << a.mu << endl; 
    cout << "variance= " << a.var << endl; 
    // cout  << "distribution is "<< endl; 
    // for(int i=0; i<15; i++){
    // cout << a.distribution[i] << endl; 

    // }
    cout << "---------------" << endl;
    Uncertain<double> b(5); 

    cout << "mean of b is " << b.mu << endl; 
    cout << "variance of b is " << b.var << endl;
  
    Uncertain<double> c;


    // c = a + b; 

    // cout << "---------------" << endl; 
    // cout << "mean of c is " << c.mu << endl; 
    // cout << "variance of c is " << c.var << endl;


    // c = a * b; 

    // cout << "---------------" << endl; 
    // cout << "mean of c is " << c.mu << endl; 
    // cout << "variance of c is " << c.var << endl;


    // c = a / b; 

    // cout << "---------------" << endl; 
    // cout << "mean of c is " << c.mu << endl; 
    // cout << "variance of c is " << c.var << endl;

    // cout << "addition of distribtions" << endl; 
    // for(int i=0; i<15; i++){
    // cout << c.distribution[i] << endl; 
    // }
 
    // cout << "subtraction of distribtions" << endl;
    // c = a - b; 
    // for(int i=0; i<15; i++){
    // cout << c.distribution[i] << endl; 

    // }

    // cout << "multiplication of distribtions" << endl;
    // c = a * b; 
    // for(int i=0; i<15; i++){
    // cout << c.distribution[i] << endl; 

    // }

    // cout << "division of distribtions" << endl;
    // c = a / b; 
    // for(int i=0; i<15; i++){
    // cout << c.distribution[i] << endl; 

    // }

    bool test =  b > 100 ;

    cout <<"test result is : " << test << endl;

    cout <<"probability " << b.pr_g(100) <<endl; 
    

    
    return 0;
}