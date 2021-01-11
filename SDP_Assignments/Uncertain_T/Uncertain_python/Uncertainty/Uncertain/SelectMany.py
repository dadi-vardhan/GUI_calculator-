import sys
from typing import TypeVar, Generic

T = TypeVar('T')

class SelectMany:                # To be inherited from Uncertain!!!!!!!!!!!!!!!!!!!!!!!    
    class Weighted(Generic[T]):
        def __init__(self, source, collectionSelector, ResultSelector) -> None:
            self.source = source  
            self.collectionSelector = collectionSelector
            self.ResultSelector = ResultSelector

        def set(self, collectionSelector, ResultSelector) -> None:        
            self.collectionSelector = collectionSelector
            self.ResultSelector = ResultSelector

        def get(self):        
            return self.collectionSelector, self.ResultSelector

        def GetSupport(self):
            for a in self.source.Support():              # Support() needs to be implemented!!!!!!!!!!!
                for b in self.collectionSelector(a.Value).Support():
                    result = self.ResultSelector(a.Value, b.Value)
                    result.Probability*=(a.Probability*b.Probability)
                    return result

        def Accept(self, visitor):
            visitor.Visit(self)