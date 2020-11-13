#include <iostream>
#include <stdexcept>

class calculator{

public:
    calculator(){
        std::cout << "Initiating Calculator" << std::endl;
    }
    // ~calculator();
    double add(double x,double y){
        return x+y;
    }
    double subtract(double x,double y){
        return x-y;
    }
    double multiply(double x,double y){
        return x*y;
    }
    double divide(double x,double y){
        if (y==0){
            throw std::overflow_error("Divide by zero exception");
        }
        return x/y;
    }
private:

};

// int main(){
//     calculator a; 
//     std::cout<<a.divide(2,0)<<std::endl;
//     return 0; 
// }

