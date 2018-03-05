# Excercise 2
About: Memory, strings

## 1
Run the program memerrortest.cc -- it illustrates what happens upon
memory-related execution errors. Some errors are detected, some are not. In a
larger program, the undetected errors would probably lead to catastrophic
errors much later during the execution. Run again, under control of Valgrind
(see lab 1). 

## 2
Morse code is a method of transmitting text information as a series of short
and long signals ('dots' and 'dashes'). For example, the letter 'a' is coded as
'.–', 'b' as '–...', and so on. We ignore spaces between words. Implement the
class MorseCode, test with morsetest.cc. The file morsecode.def contains the
morse code definitions of the letters a–z. Characters outside this range should
be ignored. Hint: in decode(), use an istringstream to read morse codes from
the code string.

## 3
Editors for program text usually help with matching of parentheses: when you
type a ), ] or } the editor highlights the corresponding left parenthesis.
Example (... is a sequence of characters except parentheses):
```
...(...(...[...]...)...)...{...}...
           |<--|           |<--|
       |<----------|
   |<------------------|
```
Implement the function find_left_par in the class Editor, test with
editortest.cc.
