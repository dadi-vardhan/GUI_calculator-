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
#include "uncertain_t.h"




//this code is a simplified version of the game of life code developed here
// https://github.com/MarioTalevski/game-of-life/blob/master/GameOfLife.cpp

using namespace std;
const int gridSize = 8; 
void printGrid(bool gridOne[gridSize+1][gridSize+1]){
    for(int a = 1; a < gridSize; a++)
        {
        for(int b = 1; b < gridSize; b++)
        {
            if(gridOne[a][b] == true)
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

void compareGrid (bool gridOne[gridSize+1][gridSize+1], bool gridTwo[gridSize+1][gridSize+1]){
    for(int a =0; a < gridSize; a++)
    {
        for(int b = 0; b < gridSize; b++)
        {
                gridTwo[a][b] = gridOne[a][b];
        }
    }
}

void determineState(bool gridOne[gridSize+1][gridSize+1]){
    bool gridTwo[gridSize+1][gridSize+1] = {};
    compareGrid(gridOne, gridTwo);
    Array<double> one(1.0); 
    for(int a = 1; a < gridSize; a++)
    {
        for(int b = 1; b < gridSize; b++)
        {
            int alive = 0; 
            // double meas = 0.0;  
            // Array<double> alive(2.0);
            for(int c = -1; c < 2; c++)
            {
                for(int d = -1; d < 2; d++)
                {
                    if(!(c == 0 && d == 0))
                    {   
                        Array<double> sense((double)gridTwo[a+c][b+d]); 

                        // if(gridTwo[a+c][b+d])
                        if(sense.mu > 0.5)
				{   
                    // Array<double> to_add(1.0); 
                    // cout << "to add " << to_add.mu << endl;  
					// alive = alive + one;
                    
                    // cout << alive.ptr[3] << endl; 
                    ++alive;
                    
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
                gridOne[a][b] = false;
            }
            else if(alive == 3)
            {
                gridOne[a][b] = true;
            }
            else if(alive >= 2 && alive <= 3)
            {
                gridOne[a][b] = true;
            }
            else if(alive > 3)
            {
                gridOne[a][b] = false;
            }
        }
    }
}


int main(){

    bool gridOne[gridSize +1 ][gridSize +1] = {};

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
    while (true)
	  {
    printGrid(gridOne);
    determineState(gridOne);
    usleep(200000);
    clearScreen();
	  }



   

    return 0; 
}
