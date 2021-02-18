from os import error
from Uncertain.Sampler import Sampler
import numpy as np
import scipy as sp

class Extensions():
    def __init__(self):
        self.EXPECTED_VALUE_SAMPLE_SIZE = 1000
        self.MAX_SAMPLE_SIZE = 10000
        self.INITIAL_SAMPLE_SIZE = 10
        self.SAMPLE_SIZE_STEP = 10

    def pr(self,source,numm_samples=10,prob=0.5,
            alpha=0.5,epsilon=0.03,max_samples=1,
            init_sample_size=1,sample_size_step=1):

        H_0=prob-epsilon
        H_1=prob+epsilon
        beta = alpha
        a = np.log(beta/(1-alpha))
        b= np.log((1-beta)/alpha)
        k=0
        
        w_sum=0.0
        w_sum_true=0.0
        s= Sampler()
        s.create(source)
        li = s.take(10)
        count = 0.0
        for i in li:
            #print("first_for loop done")
            if i>=0.5:
                count=count+1
        count = count/len(li)
        num_samples=0
        while (num_samples<init_sample_size):
            #print("second_while loop done")
            if li[num_samples]>0.5:
                k=k+1
                w_sum_true=w_sum_true+count
            w_sum=w_sum+count
            num_samples+=1
        test = None
        while (numm_samples<= max_samples):
            #print(" loop done")
            log_likelihood = w_sum_true * np.log(H_1/H_0)+(w_sum-w_sum_true)*np.log((1-H_1)/(1-H_0))
            
            if (log_likelihood>=b):
                test=True
            elif (log_likelihood<=a):
                test = False
            else:
                i=0
                while (i<sample_size_step):
                    count=0.0
                    li=s.Take(10)
                    for it in li:
                        if it>=0.5:
                            count=count+1
                    count = count/len(li)
                    
                    if li[i]>0.5:
                        k=k+1
                        w_sum_true=w_sum_true+count
                    w_sum=w_sum+count
                    i=i+1
                    numm_samples+=sample_size_step
            test = False
        
        return test
        
        

