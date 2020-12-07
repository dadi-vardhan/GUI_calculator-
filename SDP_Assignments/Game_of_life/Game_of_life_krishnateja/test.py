from game_of_life import *
import pytest
import sys

size = 100
live= 255
dead = 0
vals = [live, dead]

def version_test():
    #test case for python version
    version = sys.version_info
    assert version >(3,0),"version should be greater than 3.0 "

def grid_size_test():
    #test case for veryfying the grid size
    grid = gen_grid(size,vals)
    assert grid.shape == (size,size)

def grid_similarity():
    #test case for 
    grid = gen_grid(size,vals)
    updated_grid = grid_update(grid,size,live,dead)
    assert (grid != updated_grid).any(), "grid wasn't updated"

if __name__ == "__main__":
    version_test()
    grid_size_test()
    grid_similarity()



