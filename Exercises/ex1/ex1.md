# Exercise 1
About: Basic C++: implement a class, allocate objects, write a function.  

## 1
A class Date describes a date with year, month, and day. Your task is to
implement the member functions, one of the constructors and a function to
compute the number of days between two dates. The constructor that creates a
Date object representing the current date is already implemented (read about
the C functions for date and time handling in the man pages for localtime, if
you're interested). You may ignore leap years in the next() function, if you
wish. 

Files: date.h, date.cc (to be completed by you), datetest.cc (test program). 

Compile, link and execute with the commands:
```
 make datetest  
 ./datetest   
```
The command make without an argument builds (compiles and links) all the
programs in this exercise.

## 2
The class Point describes a point in the plane. The program pointtest.cc
allocates a point object in different ways. Study the program and make sure
that you understand the different alternatives.

## 3
Study the program sizetest.cc. Try to predict the output from the program, then
run the program and check your prediction. 

## 4
A palindrome is a word that reads the same both forwards and backwards.
Examples: anna, amanaplanacanalpanama. Write a function that takes a string as
parameter and returns true if the word is a palindrome, false otherwise. Also
write a program that reads words from the terminal and checks whether they are
palindromes. Modify the makefile to build the program.

