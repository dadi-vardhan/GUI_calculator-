import numpy as np
import matplotlib.pyplot as plt 
import matplotlib.animation as animation

grid_size = 100
live= 255
dead = 0
vals = [live, dead]

# populate grid with random live/dead cells - more dead than live
grid = np.random.choice(vals, grid_size*grid_size, p=[0.2, 0.8]).reshape(grid_size, grid_size)

def update(data):
  global grid
  # copy grid 
  # and we go line by line 
  newGrid = grid.copy()
  for i in range(grid_size):
    for j in range(grid_size):
      # compute 8-neghbor sum 
      neighbours_sum = (grid[i, (j-1)%grid_size] + grid[i, (j+1)%grid_size] + 
               grid[(i-1)%grid_size, j] + grid[(i+1)%grid_size, j] + 
               grid[(i-1)%grid_size, (j-1)%grid_size] + grid[(i-1)%grid_size, (j+1)%grid_size] + 
               grid[(i+1)%grid_size, (j-1)%grid_size] + grid[(i+1)%grid_size, (j+1)%grid_size])/255
      # Conway's rules
      if grid[i, j]  == live:
        if (neighbours_sum < 2) or (neighbours_sum > 3):
          newGrid[i, j] = dead
      else:
        if neighbours_sum == 3:
          newGrid[i, j] = live
  # update data
  mat.set_data(newGrid)
  grid = newGrid
  return [mat]

# set up animation
fig, ax = plt.subplots()
mat = ax.matshow(grid)
ani = animation.FuncAnimation(fig, update, interval=50,
                              save_count=50)
plt.show()