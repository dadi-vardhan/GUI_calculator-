# Uncertain< T > in C++ 

This is an implementation of the datatype Uncertain< T > as discussed in [1]. This data structure is developed in C++ language. 

## General Idea 

The idea is to create a datatype which implements first order uncertainty. On an abstract level, it is desired to include uncertainty in calculations easily espicially for those who are not experts in uncertainty and statistics. 

## How does work? (to be updated frequently till the end of the project)

In principle, the goal is to deal with distributions in calculations instead of one value. Namely, taking an input one value (e.g measurement, any calculated result) and consider it as a sample from some distribution (assumed to be gaussian with mean 0 and pre-defined variance). This distribution is sampled using Box-Mueller.

Calculations with distributions allow to make use of the noise included in the distribution that enables to modify hypothesis tesgting for decision makings. 

# How to use it 

Simply place the headerfile `uncertain_t.h` in your project directory and in your main application add 

`#include "uncertaint_t.h"`