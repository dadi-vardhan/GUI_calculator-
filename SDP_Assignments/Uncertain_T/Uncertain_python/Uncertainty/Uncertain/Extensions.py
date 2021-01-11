from os import error
from Uncertain.ISampler import Sampler
import numpy as np
import scipy as sp

class Extensions():
    def __init__(self):
        self.EXPECTED_VALUE_SAMPLE_SIZE = 1000
        self.MAX_SAMPLE_SIZE = 10000
        self.INITIAL_SAMPLE_SIZE = 10
        self.SAMPLE_SIZE_STEP = 10

    def pr(slef,source, prob=0.5, alpha=0.05, epsilon=0.03,
            max_sample_size=self.MAX_SAMPLE_SIZE,
            init_sample_size=self.INITIAL_SAMPLE_SIZE,
            sample_size_step=self.SAMPLE_SIZE_STEP):
        
        num_samples=0.0
        h_0 = prob - epsilon
        h_1 = prob + epsilon
        beta = alpha
        a = np.log(beta/(1-alpha))
        b = np,log((1-beta)/alpha)
        k=0
        w_sum =0.0
        w_sum_true =0.0 
        enumerator = Sampler.create(source).get_enumerator()

        # func_sampler()

        tmp = enumerator.current
        if enumerator.move_next() == False:
            print("ran out of data")
        return tmp

        while num_samples < init_sample_size:
            sample = func_sampler()
            if i<0:
                k=k+1
                w_sum_true += sample.probability
            w_sum += sample.probability

            num_samples += num_samples

