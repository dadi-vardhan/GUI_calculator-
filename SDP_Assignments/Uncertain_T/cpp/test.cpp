#include <iostream>
#include "uncertain.h"
#include "gaussian.h"

using namespace std;

int main(){
    Uncertain<float> x = Gaussian(10,0.001);
    Uncertain<float> y = Gaussian(20,0.001);
    Uncertain<float> z;
    z = x+y;

    cout << z.pr(30) << endl;

    cout << z.e()<< endl; 

    Uncertain<float> w(3.0,0.0);

    cout << w.distribution[28] << endl; 
    
    return 0;
}