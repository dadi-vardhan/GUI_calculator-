import time
import numpy as np
import matplotlib.pyplot as plt


class Logic(object):

   def __init__(self, console):
      self.state = console.state

   
   def neighbour_cell_count(self):
      '''
      Counts the number of cells present at time 't' 
      
      on the console and returns it.

      Parameters: none

      Returns: cell [int]
      '''
      state = self.state
      cell = (state[0:-2,0:-2] + state[0:-2,1:-1] + state[0:-2,2:] +
          state[1:-1,0:-2] + state[1:-1,2:] + state[2:,0:-2] +
          state[2:,1:-1] + state[2:,2:])
      return cell

   
   def cell_propogation_rules(self):
      '''
      function that defines the rules for the cell-propogation.

      Parameters: none

      Returns : state 
      '''
      cell = self.neighbour_cell_count()
      state = self.state
      cell_birth = (cell == 3) & (state[1:-1,1:-1] == 0)
      survive = ((cell == 2) | (cell == 3)) & (state[1:-1,1:-1] == 1)
      state[...] = 0
      state[1:-1,1:-1][cell_birth | survive] = 1
      total_cell_birth = np.sum(cell_birth)
      self.total_cell_birth = total_cell_birth
      total_cell_survived = np.sum(survive)
      self.total_cell_survived = total_cell_survived
      return state



