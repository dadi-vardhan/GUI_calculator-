import numpy as np
import matplotlib.pyplot as plt
from GolLogic import Logic

class Console(object):

   def __init__(self, size, seed = 'Random'):
      if seed == 'Random':
         self.state = np.random.randint(2, size = size)
      self.logic = Logic(self)
      self.iteration = 0

    
   def animate(self):
       '''
       fucntion to create animations of the cell propogation

       and dieing using matplotlib library.

       Parameters: none

       Returns: none

       '''

       i = self.iteration
       im = None
       plt.title("Game of life implementation")
       while True:
            if i == 0:
                plt.ion()
                im = plt.imshow(self.state, vmin = 0, vmax = 2, cmap = plt.cm.gray)
            else:
                im.set_data(self.state)
            i += 1
            self.logic.cell_propogation_rules()
            print('Life Cycle: {} Birth: {} Survive: {}'.format(i, 
                            self.logic.total_cell_birth, self.logic.total_cell_survived))
            plt.pause(0.01)
            yield self