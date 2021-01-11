import numpy as np 
import random
import sys,os
currentdir = os.path.dirname(os.path.realpath(__file__))
parentdir = os.path.dirname(currentdir)
sys.path.append(parentdir)
from Uncertain.Gaussian import Gaussian
from Uncertain.ISampler import Sampler

class GaussianTests():
    def Gaussian_sample(self):
        x = Gaussian(5.0,2.0).gaussian()
        sampler = Sampler().create(x)
        for i in sampler.Take(100):
            assert(i >= -3 and i <= 13)

    def Gaussian_mean(self):
        sum_value = 0.0
        x = Gaussian(5.0,1.0).gaussian()
        sampler = Sampler().create(x)
        for i in sampler.Take(100):
            sum_value += i
        sum_value /=100
        assert(sum_value>=4.6 and sum_value <=5.4)

    def Gaussian_BNN_sample(self):
        x = Gaussian(1.0,1.0)
        y = Gaussian(4.0,1.0)
        z = x+y
        sampler = Sampler().create(z)
        for i in sampler.Take(100):
            assert(i >=-3.0 and i<=13.0) 

    def Gaussian_BNN_Mean(self):
        x = Gaussian(1.0,1.0)
        y = Gaussian(4.0,1.0)
        z = x+y
        sum =0.0
        sampler = Sampler().create(z)
        for i in sampler.Take(100):
            sum=sum+i
        sum = sum/100.0
        assert(sum>=4.11 and sum <=5.89)

    def Gaussian_Bernoulli_Conditional(self):
        x = Gaussian(1.0,1.0)
        y = Gaussian(3.0,2.0)
        z = x>y
        sampler = Sampler().create(z)
        k=0
        for i in sampler.Take(100):
            if i<0:
                k=k+1
        assert (k>=13 and k<52)
if __name__ == '__main__':
    test = GaussianTests()
    test.Gaussian_sample
    test.Gaussian_mean
    test.Gaussian_BNN_sample
    test.Gaussian_BNN_Mean