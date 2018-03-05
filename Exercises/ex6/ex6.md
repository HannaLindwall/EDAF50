# Exercise 6
About: Template functions, containers, algorithms.

## 1
"Counting sort" is an efficient sorting method if the elements that are to be
sorted are integral values in a limited range. You count the number of
occurrences of each value and then output each value the correct number of
times.  

Example: sort {6, 3, 6, 2, –1, 3}. The number of occurrences becomes {1, 0, 0,
1, 2, 0, 0, 2} (one –1, no 0, no 1, one 2, two 3, no 4, no 5, two 6).  

Implement the function csort in csorttest.cc. Sort some million values in the
range [1, 1000] and compare the execution time for csort with that of
std::sort. csort should be better. Sort some thousand values in the range [–10
000 000, +10 000 000] and compare again.  

## 2
Write a class SequenceGenerator to be used in generate.cc. Deduce from the
program text what the class should look like.  

## 3
Write a program that reads a number of text files, whose names are given on the
command line, and prints the 20 most common words in the files along with the
total number of occurrences in all files. You may assume that there are only
letters and whitespace in the files. Give an error message if a file cannot be
opened.
