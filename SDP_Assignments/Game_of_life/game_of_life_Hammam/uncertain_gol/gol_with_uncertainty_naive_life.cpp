#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <functional>
#include "uncertain.h"
#include "gaussian.h"



//this code is a simplified version of the game of life code developed here
// https://github.com/MarioTalevski/game-of-life/blob/master/GameOfLife.cpp

using namespace std;
const int gridSize = 6; 

// Gaussian one(1.0,0.01); 
// Gaussian zero(0.0,0.01);

void printGrid(float gridOne[gridSize+1][gridSize+1]){
    for(int a = 1; a < gridSize; a++)
        {
        for(int b = 1; b < gridSize; b++)
        {
            if(gridOne[a][b] == 1.0)
            {
                cout << " 0 ";
            }
            else
            {
                cout << " . ";
            }
            if(b == gridSize-1)
            {
                cout << endl;
            }
        }
    }
}


void clearScreen(void) {
  // Tested and working on Ubuntu and Cygwin
  

//   #if defined(OS_LINUX) || defined(OS_MAC)
    cout << "\033[2J;" << "\033[1;1H"; // Clears screen and moves cursor to home pos on POSIX systems
//   #endif

}

void compareGrid (float gridOne[gridSize+1][gridSize+1], float gridTwo[gridSize+1][gridSize+1]){
    for(int a =0; a < gridSize; a++)
    {
        for(int b = 0; b < gridSize; b++)
        {
                gridTwo[a][b] = gridOne[a][b];
        }
    }
}


void determineState(float gridOne[gridSize+1][gridSize+1]){

    // Uncertain<double> test = Gaussian(0.0,0.4); 
    // Uncertain<double> test1 = Gaussian(1.0,0.4); 
    

    float gridTwo[gridSize+1][gridSize+1] = {};
    compareGrid(gridOne, gridTwo);
    // Array<double> one(1.0); 
    // Gaussian test(1.0,0.4);
    for(int a = 1; a < gridSize; a++)
    {
        for(int b = 1; b < gridSize; b++)
        {
            Uncertain<float> alive(0,0); 
            Uncertain<float> one(1.0,0);
            // double meas = 0.0;  
            // Array<double> alive(2.0);
            for(int c = -1; c < 2; c++)
            {
                for(int d = -1; d < 2; d++)
                {   
                    if(!(c == 0 && d == 0))
                    {   
                        Gaussian measure((float)gridTwo[a+c][b+d],0.5);
                        float sample = measure.GetSample(); 
                        
                        if(sample>=0.5)
				{   
                    alive= alive + one;
                    
				}
                    }
                }
             }
            
            // cout << "alive equals" <<  alive.mu << endl; 
            // cout << "alive < 2 " << alive.pr_l(2) << endl;  
            // cout << "alive > 3 " << alive.pr_g(3) << endl;
            // cout << "alive == 3 " << alive.pr_eq(3) << endl;
            
            if(alive < 2)
            {
                gridOne[a][b] = 0.0;
            }
            else if(alive == 3)
            {
                gridOne[a][b] = 1.0;
            }
            // else if(alive >= 2 && alive <= 3)
            // {
            //     gridOne[a][b] = 1.0;
            // }
            else if(alive > 3)
            {
                gridOne[a][b] = 0.0;
            }
        }
    }
}


int main(){

    float gridOne[gridSize +1 ][gridSize +1] = {};

    // for (int i =0; i< 5; i++)
    gridOne[3][3] = 1.0; 
    gridOne[3][2] = 1.0;
    gridOne[3][4] = 1.0;
    // gridOne[3][6] = true;
    // gridOne[2][5] = true;
    // gridOne[2][5] = true;
    // gridOne[7][4] = true;   
    // gridOne[5][4] = true;
    // gridOne[5][5] = true;
    // gridOne[6][5] = true;
    // gridOne[5][6] = true;            
    int count = 0; 

    while (count < 25)
	  {count++;
    printGrid(gridOne);
    determineState(gridOne);
    usleep(200000);
    clearScreen();
	  }



   

    return 0; 
}