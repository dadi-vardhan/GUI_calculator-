import numpy as np
from Uncertain import MarkovChainMonteCarloSampler

class Sampler():
    def __init__(self):
        self.model = None

    def create(self,source):
        model = MarkovChainMonteCarloSampler(source).MarkovChainMonteCarloSampler()
        self.model = model
        return model

    def Take(self,samples):
        return np.random.choice(self.model,samples)
