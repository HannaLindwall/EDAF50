# Exercise 5
About: Iterators, lambdas, standard containers.
## 1
The class Text represents texts that have several lines. The class has no
constructor, no destructor, no copy constructor and no assignment operator. Are
these functions not necessary? Supply the class with an iterator so the program
in testtext.cc functions correctly. You must make additions to the class, but
you may not change the representation of the text.

## 2
The program in personsorttest.cc gives a lot of compilation errors. What is the
cause of the errors? Fix the program.

## 3
Modify the program in sortwords.cc so it functions as described in the
comments.

## 4
When you wish to store values that are identified by keys you usually would use
a map. A map has logarithmic time complexity for insertions, deletions and
searches and  is normally implemented with a binary search tree. This has some
drawbacks -- for example, a map iterator is complex (it must traverse a tree),
and the nodes in the tree need space for pointers to children and parent. 

Many applications that use a map are of the type "insert values at the start,
then search many times." Then, it would be better to use a sorted vector to
store the values (the insertions will be slower but searching will be faster,
and the values will occupy less space).

Write a class AV (for Associative Vector) that functions as a std::map but
stores the values in a sorted vector. Binary search should be used for all
searches (there are binary search algorithms in the standard library). You only
need to implement the constructs that are used in avtest.cc.
