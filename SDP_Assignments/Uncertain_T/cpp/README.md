# Uncertain< T > in C++ 

This is an implementation of the datatype Uncertain< T > as discussed in [1]. This data structure is developed in C++ language. 

## General Idea 

The idea is to create a datatype which implements first order uncertainty. On an abstract level, it is desired to include uncertainty in calculations easily specifically for those who are not experts in uncertainty and statistics. 

## Source Code Structure 

This is a simplified version of the actual code in c# described [here](https://github.com/klipto/Uncertainty/tree/dev/Uncertain). However, this simplified structure is capable of performing successfully in a probabilistic fashion. As progress continues, more distributions will be added to the package. 

# Example 

Objective: to sample from a gaussian distribution and implement logical and mathematical operations. 

```cpp
#include <iostream>
#include "uncertain.h"
#include "gaussian.h"
#include "ISampler.h"

using namespace std; 


int main(){
    
Uncertain<float> x = Gaussian(2,0.03);
Uncertain<float> y = Gaussian(3,0.04);

Uncertain<float> z = x + y; 

//check if z's new mean in range of 5.3 and 4.7 

cout << (z >= 4.7 ) << endl; 
cout << (z <= 5.3) << endl; 

}

```

# Test Case 

You can find a useful test case that is "Game of Life" Algorithim [here](https://github.com/dadi-vardhan/SDP/tree/master/SDP_Assignments/Game_of_life/game_of_life_Hammam). In Game of Life, a sensor is used to measure whether the surrounding points are alive or dead. In our case the sensor is noise. These values are simulated using our uncertain<T> package. Using our package, we were able to successfully tolerate the noise coming from the sensor measurements. 
    
### Performance with a noisy sensor before using Uncertain<T> package. 
    
![alt text](https://github.com/dadi-vardhan/SDP/blob/raw/SDP_Assignments/Game_of_life/game_of_life_Hammam/uncertain_gol/demos/gol_naive_life.gif)
    
### Performance after using Uncertain<T> package. 
    
![alt text](https://github.com/dadi-vardhan/SDP/blob/raw/SDP_Assignments/Game_of_life/game_of_life_Hammam/uncertain_gol/demos/gol_bayes_life.gif)

## How does work? 
The following UML diagram describes the structure of the current Uncertain<T> library. 
    
![alt text](https://raw.githubusercontent.com/dadi-vardhan/SDP/master/SDP_Assignments/Uncertain_T/cpp/UML.png)
