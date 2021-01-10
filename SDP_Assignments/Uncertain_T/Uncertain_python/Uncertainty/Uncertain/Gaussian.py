
import numpy as np 
import random
import sys

class Gaussian:
    def __init__(self,mu,std):
        self.mean = mu
        self.std = std
        self.samples = 1000
        
    def gaussian(self):
        population = np.random.normal(self.mean,self.std,self.samples)
        return population
    