import numpy as np
import matplotlib.pyplot as plt 
import matplotlib.animation as animation
from gaussian import Gaussian
import sys

def gen_grid(grid_size,vals):
  """Function to generate the grid

  Args:
      grid_size (int): size of grid required
      vals (list): live and dead values for grid

  Returns:
      [array]: array generated using size and values
  """

  grid_random = np.random.choice(vals,grid_size*grid_size,p=[0.5,0.5]).reshape(grid_size,grid_size)
  print(grid_random)
  return grid_random


def grid_update(grid,grid_size,live,dead):
  """function to update the grid after evolution 

  Args:
      grid (arry): input array
      grid_size (int): size of grid
      live (int): value assigned for live cells
      dead (int): value assigned for live cells

  Returns:
      [array]: updated grid after calcultaing neighbor sum
  """
  # copy grid 
  # and we go line by line 
  mean = 0
  std = 0.1
  newGrid = grid.copy()
  for i in range(grid_size):
    for j in range(grid_size):
      # compute 8-neghbor sum 
      neighbours_sum = (Gaussian(mean,std).get_sample()+grid[i, (j-1)%grid_size]) + (Gaussian(mean,std).get_sample() + grid[i, (j+1)%grid_size])+\
        (Gaussian(mean,std).get_sample() +grid[(i-1)%grid_size, j] )+ (Gaussian(mean,std).get_sample()+grid[(i+1)%grid_size, j]) + \
        (Gaussian(mean,std).get_sample() + grid[(i-1)%grid_size, (j-1)%grid_size])+ (Gaussian(mean,std).get_sample()+grid[(i-1)%grid_size, (j+1)%grid_size]) + \
        (Gaussian(mean,std).get_sample()+grid[(i+1)%grid_size, (j-1)%grid_size]) + (Gaussian(mean,std).get_sample()+grid[(i+1)%grid_size, (j+1)%grid_size])
      
      # neighbours_sum = (grid[i, (j-1)%grid_size] + grid[i, (j+1)%grid_size] + 
      #          grid[(i-1)%grid_size, j] + grid[(i+1)%grid_size, j] + 
      #          grid[(i-1)%grid_size, (j-1)%grid_size] + grid[(i-1)%grid_size, (j+1)%grid_size] + 
      #          grid[(i+1)%grid_size, (j-1)%grid_size] + grid[(i+1)%grid_size, (j+1)%grid_size])

      #print(neighbours_sum)
      # # Conway's rules
      if grid[i, j]  == live:
        if (neighbours_sum < 2) or (neighbours_sum > 3):
            newGrid[i, j] = dead
        elif ((neighbours_sum >=2) and (neighbours_sum <=3)):
            newGrid[i,j] = live
      else:
        if (neighbours_sum) == 3:
            newGrid[i, j] = live
  #print(newGrid)  
  
  return newGrid

def ani_update(data):
  """ function to update the animation

  Args:
      data (image): image for animation

  Returns:
      [image]: updated image for animation
  """
  # update data
  new_grid = grid_update(grid,grid_size,live,dead)
  img.set_data(new_grid)
  grid[:] = new_grid[:]
  return img


if __name__ == "__main__":
  try:    
    grid_size = 20
    live= 1
    dead = 0
    vals = [live, dead]
    # populate grid with random live/dead cells - more dead than live
    grid= gen_grid(grid_size,vals)
    # set up animation
    fig, ax = plt.subplots()
    img = ax.imshow(grid)
    ani = animation.FuncAnimation(fig, ani_update)
    plt.show()
  except KeyboardInterrupt:
    sys.exit()
  