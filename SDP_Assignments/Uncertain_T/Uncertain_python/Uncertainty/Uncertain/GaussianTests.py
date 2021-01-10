import numpy as np 
import random
import sys
from Gaussian import Gaussian
from ISampler import Sampler

class GaussianTests:
    def Gaussian_sample(self):
        x = Gaussian(5.0,2.0).gaussian()
        sampler = Sampler().create(x)
        sampler = np.random.choice(sampler,100)
        for i in sampler:
            assert i >= -3 and i <= 13
        print("sample test passed")
    def Gaussian_mean(self):
        sum_value = 0.0
        x = Gaussian(5.0,1.0).gaussian()
        sampler = Sampler().create(x)
        sampler = np.random.choice(sampler,100)
        for i in sampler:
            sum_value += i
        sum_value /=100
        assert sum_value>=4.6 and sum_value <=5.4
        print("mean test passed")

GaussianTests().Gaussian_mean()
GaussianTests().Gaussian_sample()