# Exercise 3
About: Copying, dynamic arrays, random numbers.

## 1
The program countobj.cc contains a class that has a counter that is incremented when an object of the class is created and decremented when an object is destroyed. The function f demonstrates that the class seems to function correctly, but the functions g and h  show otherwise. Correct the class so also g and h give correct results.

## 2
We have started to write a class SVector that we hope will become a usable vector class. (This is a futile attempt, since we cannot hope to write a class that is as good as std::vector.) The test program in svectortest.cc is intended to demonstrate that the basic functionality of the class is correct, but it gives unexpected results.  
  
What has happened? What is the cause of the error? Correct the class (not the test program) so the program gives the expected output.  
  
A similar error to the one demonstrated by the test program may occur in another circumstance. When? Correct the class so this error cannot occur.  

## 3
The class BitBuffer receives bits which are packed in a byte (8 bits). As soon as the buffer is full a byte should be written (as a character) to an ostream with the function put(unsigned char ch). Implement the class, test with bitbuffertest.cc. As an example, the input 0 1 0 0 0 0 0 1 should give the output A.

## 4
Random numbers can be used to encrypt texts. You need a random number generator that can be initialized with a seed (the encryption key), so the same sequence of random numbers can be reproduced. The characters are encrypted by adding a random number to each character. We assume that all characters are in the interval [0, 256) and that the random numbers are in the same interval. The encrypted characters shall also be in this interval. Example:

```
Character:              A     t     t     a     c     k     !
Character code:        65   116   116    97    99   107    33 
Random number:          4   207     6     1    12   255     8 
Encrypted code:        69    67   122    98   111   106    41 
Encrypted character:    E     C     z     b     o     j     )
```
Implement the class Crypto, test with cryptotest.cc.
