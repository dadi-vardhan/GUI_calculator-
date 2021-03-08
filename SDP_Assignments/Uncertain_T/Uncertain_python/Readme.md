# Uncertain<T> library
	
[![Python application](https://github.com/dadi-vardhan/SDP/actions/workflows/python-app.yml/badge.svg)](https://github.com/dadi-vardhan/SDP/actions/workflows/python-app.yml)

## Table of contents
* [General info](#general-info)
* [Tools and Libraries](#technologies)
* [Setup](#setup)
* [UML diagram](#UML-digram)

## General info
A programming langauage abstraction for Uncertain data. This package is a python porting from a already existing c# implementation of [Uncertain<T>](https://github.com/klipto/Uncertainty) library.
  
	
## Tools and Libraries
Project is created with:
* Python version: 3.x
* numpy version: 1.18.x
* scipy version: 1.4.x
	
## Setup
To run this project, install it locally using pip:

```
$ pip install UncertainPythonSDP==1.1.3
```
To install numpy and scipy run:

```
$ pip install numpy
$ pip install scipy
```
To run the test cases run:
```
$ cd ~/Uncertain_python
$ python /UncertainTests/GaussianTests.py
# pytest -v 
```

Usage of the library:

```python
import UncertainPythonSDP
from UncertainPythonSDP.Uncertain.Gaussian import Gaussian
from UncertainPythonSDP.Uncertain.Uncertaint import Operator

distribution_1 = Gaussian(1.0,2.0)
distribution_2 = Gaussian(2.0,4.0)

sum_distribution = Operator(distribution_1)+Operator(distribution_2)

```
## UML diagram 

![Algorithm schema](UML_diagram.png)
