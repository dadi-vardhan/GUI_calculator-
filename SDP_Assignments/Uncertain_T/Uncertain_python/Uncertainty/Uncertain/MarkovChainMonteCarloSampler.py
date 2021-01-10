import numpy as np 
import random
import sys

class MarkovChainMonteCarloSampler():
    
    def __init__(self,source):
        self.source = source
        self.iterations = 5000
        
    def prior(self,x):
        if(x[1] <=0):
            return 0
        return 1
    
    def transition_model(self,x):
        return [x[0],np.random.normal(x[1],0.5,(1,))[0]]

    def likelihood(self,x,data):
        return np.sum(-np.log(x[1] * np.sqrt(2* np.pi) )-((data-x[0])**2) / (2*x[1]**2))
    
    def accept(self,oldTrace,trace):
        if trace>oldTrace:
            return True
        else:
            accept=np.random.uniform(0,1)
            return (accept < (np.exp(trace-oldTrace)))
        
    def MarkovChainMonteCarloSampler(self):
        obs_mean = np.mean(self.source)
        x = [obs_mean,0.1]
        accepted = []
        rejected = [] 
        for i in range(self.iterations):
            x_new =  self.transition_model(x)    
            x_lik = self.likelihood(x,self.source)
            x_new_lik = self.likelihood(x_new,self.source) 
            oldtrace = x_lik + np.log(self.prior(x))
            newtrace = x_new_lik+np.log(self.prior(x_new))
            if (self.accept(oldtrace,newtrace)):            
                x = x_new
                accepted.append(x_new)
            else:
                rejected.append(x_new)  
        accepted = np.array(accepted)      
        burnin=int(-0.75*accepted.shape[0])
        mu=accepted[burnin:,0].mean()
        sigma=accepted[burnin:,1].mean()
        model = np.random.normal(mu,sigma,self.source.shape)
        return model
