from typing import TypeVar, Generic

T = TypeVar('T')

class Weighted(Generic[T]):
    def __init__(self, value: T, prob: float) -> None:
        self.Probability = prob        
        self.Value = value

    def set(self, new: T, NewProbability: float) -> None:        
        self.Value = new
        self.Probability = NewProbability

    def get(self) -> T, float:        
        return self.Value, self.Probability

    def ToString():
        return "V: {} P: {}".format(self.Value, self.Probability)