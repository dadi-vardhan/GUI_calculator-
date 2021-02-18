import numpy as np
from Uncertain.MarkovChainMonteCarloSampler import MarkovChainMonteCarloSampler

class Sampler():
    def __init__(self):
        self.model = None

    def create(self,source):
        """[summary]

        Args:
            source ([type]): [description]
        """
        model = MarkovChainMonteCarloSampler(source)
        dist = model.mcmc_sampler()
        self.model = dist

    def take(self,samples):
        return np.random.choice(self.model,samples)
