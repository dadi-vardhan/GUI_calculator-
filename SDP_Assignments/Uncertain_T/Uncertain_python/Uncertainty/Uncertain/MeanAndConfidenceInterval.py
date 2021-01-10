import sys

class MeanAndConfidenceInterval():
    def __init__(self, Mean: float, CI: float) -> None:
        self.Mean = Mean        
        self.CI = CI

    def set(self, Mean: float, CI: float) -> None:
        self.Mean = Mean
        self.CI = CI

    def get(self) -> float, float:
        return self.Mean, self.CI

    def ToString():
        return "{} +- {}".format(self.Mean, self.CI)