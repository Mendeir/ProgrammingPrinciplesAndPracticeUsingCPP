# Answers to Review, Drills and Exercises
Note: All non-programming questions will be listed here.

## Drills

**See Chapter 4: Computation**  for the instructions

[Drill1-5.cpp](Drill1-5.cpp) [Drill6-11.cpp](Drill6-11.cpp)

## Review

> 1. What is a computation?

**Answer:** The act of producing an output based from the inputs. 

> 2. What do we mean by inputs and outputs to a computation? 
Give examples.

**Answer:** By inputs and output we mean that it is the information
coming into and out from the computer.

> 3. What are the three requirements a programmer should keep 
in mind when expressing computations?

**Answer:** The three requirements are the computations must be
correct, simple, and efficient.

> 4. What does an expression do?

**Answer:** An expression computes a value from a number of operands.

> 5. What is the difference between a statement and an expression, 
as described in this chapter?

**Answer:** An expression computes a value from a number of operands 
while a statement produces several values or have a decision on what
operands to use for example on those expressions.

> 6. What is an lvalue? List the operators that require an lvalue. 
Why do these operators, and not the others, require an lvalue?

**Answer:** lvalue represents an object that has a memory in it. The
operators that requires lvalue are unary, and binary operators. These
operators require lvalues as they need to be stored in the memory without
it, the computation will be useless.

> 7. What is a constant expression?

**Answer:** Constants expressions are used to give meaningful names
to literals that we don't need to change the value from the entire
program.

> 8. What is a literal?

**Answer:** A notation that directly speciefies a value.

> 9. What is a symbolic constant and why do we use them?

**Answer:** It is a named object that you can't give a new value after
it has been initialized.

> 10. What is a magic constant? Give examples.

**Answer:** Magic constants are non-obvious literals in the code.

> 11. What are some operators that we can use for integers and 
floating-point values?

**Answer:** Some operators that we can use are +, -, *, /.

> 12. What operators can be used on integers but not on floating-point 
numbers?

**Answer:** One operator that can't be used on floating-point numbers
is the modulo operator (%).

> 13. What are some operators that can be used for strings?

**Answer:** one operator that can't be used for string is the minus
ooperator (-).

> 14. When would a programmer prefer a switch-statement to an 
if-statement?

**Answer:** A programmer should use the switch statement if the programmer
will compare several constants.

> 15. What are some common problems with switch-statements?

**Answer:** Some problems with switch statements is that its value must
be constant expressions only and it only accepts integer, char, or enums
which limits its functionalities when it comes to string or any other data
type.

> 16. What is the function of each part of the header line in a 
for-loop, and in what sequence are they executed?

**Answer:** A for loop starts with initializing a variable that
will be used for loop e.g (int counter = 0;) after that it will
check the condition set to the loop e.g (counter <= 10;) if it's
true, it will change the value that is set e.g (++counter). it will
continue to check the condition and change the value until the condition
is false.

> 17. When should the for-loop be used and when should the while-loop
be used?

**Answer:** for-loop is always encouraged as it is readable due to 
all its function is in the for-loop header. However, for-loop lacks
functionalities when the number of iterations is unkown in which
while loop is best if the number of iterations is unknown.

> 18. How do you print the numeric value of a char?

**Answer:** To print the numberic value of a char you cast it explicitly
with char('n'); where n is the numeric value

> 19. Describe what the line char foo(int x) means in a function 
definition.

**Answer:** the functino char foo(int x) returns a char data type
with a function name foo that only accepts integers as a parameter.

> 20. When should you define a separate function for part of a program? 
List reasons.

**Answer:** We want to define a separate function if we were to 
make different computations.

> 21. What can you do to an int that you cannot do to a string?

**Answer:** A thing you can do in an int but not in a string
is shift its bits using a bitwise operator.

> 22. What can you do to a string that you cannot do to an int?

**Answer:** A thing that you can do in a string but not in an int
is concatenate. 

> 23. What is the index of the third element of a vector?

**Answer:** The index of an element is n-1 which is n will be
the element that you are looking for the third element in a vector
will be 2.

> 24. How do you write a for-loop that prints every element of a vector?

**Answer:** In order to print every element using a for loop you can
use the for ranged loop which follows the syntax for 
(data-type variable_name : vector_name ). With that we cout the variable 
name in order to print the elements

> 25. What does vector<char> alphabet(26); do?

**Answer:** It will create a vector of 26 char initialized to ''.

> 26. Describe what push_back() does to a vector.

**Answer:** push_back purpose is to add a new element to a vector.

> 27. What does vector’s member size() do?

**Answer:** size() will return the size or the number of elements in 
a vector.

> 28. What makes vector so popular/useful?

**Answer:** Vector is popular and useful as many programs need a way 
to collection multiple data. With that vector can store multiple amounts 
of data and grows as you put more data in it and can be accessed easily
using the index of the element. 

> 29. How do you sort the elements of a vector?

**Answer:** In order to sort a vector we need to use the sort(vector_name) 
algorithm which will sort the vector in ascending order.
