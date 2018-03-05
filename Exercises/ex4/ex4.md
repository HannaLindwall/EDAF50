# Exercise 4
About: Operator overloading, inheritance.

## 1
Write a class Rational that describes rational numbers, i.e., numbers like 22/3
or –5/6. All numbers should be in their simplest forms, e.g., 1/2 instead of
2/4 or 3/6. Implement constructs so the program in testrational.cc works
correctly, (To convert a number to its simplest form, you must compute the
greatest common divisor of the numerator and the denominator. The classical GCD
algorithm is Euclid's algorithm, but there are faster algorithms that don't use
division. See, for example, Binary GCD.)

## 2
In shapetest.cc three objects aShape, aSqua, and aCircle are created, and the
print() function is used to check the identity (type) of each object.
Everything seems to work correctly, but when object types are checked in
another way the results are wrong. Explain the results and correct the classes
so both checks produce the same results. 

## 3
In shapevectortest.cc we assume that we have fixed the error from assignment 2.
We now store a mix of Square and Circle objects in a vector. The results are
wrong -- the objects seem to lose their type again. Explain why this happens
and fix the error,
