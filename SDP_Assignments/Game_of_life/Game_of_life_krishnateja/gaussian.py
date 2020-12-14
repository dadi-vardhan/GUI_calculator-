
import numpy as np 
import matplotlib.pyplot as plt
import random
import sys

class Gaussian:
    def __init__(self,mu,std):
        self.mean = mu
        self.std = std
        self.samples = 10
        self.x_values = np.linspace(-1,1,20)

    def gaussian_pdf(self,x):
        gaussian = (1/(self.std*np.sqrt(2*np.pi)))*np.exp(-0.5*((x-self.mean)**2/(self.std)**2))
        return gaussian
    
    def distribution(self):
        dist = []
        for i in self.x_values:
            val = self.gaussian_pdf(i)
            dist.append(val)
        return dist

    def get_sample(self):
        sample = np.random.choice(self.distribution())
        #print(value_sam)
        return sample

# if __name__ == "__main__":
#     try:
#         s = Gaussian(0,0.1)
#         print (s.distribution())
#         si = s.distribution()
#         print(s.get_sample())
#         plt.plot(s.x_values,si)
#         plt.show()
#     except KeyboardInterrupt:
#         sys.exit()