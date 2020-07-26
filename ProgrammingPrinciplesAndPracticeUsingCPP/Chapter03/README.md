# Answers to Review, Drills and Exercises
Note: All non-programming questions will be listed here.

## Drills

**See Chapter 3:objects, types and values drills**  for the instructions

[DrillLetter.cpp](DrillLetter.cpp)

## Review

> 1. What is meant by the term prompt?

**Answer:** Waits for the user to enter any character from the keyboard.

> 2. Which operator do you use to read into a variable?

**Answer:** operator>>

> 3. If you want the user to input an integer value into your program
for a variable named number, what are two lines of code you could write 
to ask the user to do it and to input the value into your program?

**Answer:** 
```c++
	int number { 0 };
	cin >> number;
```

> 4. What is \n called and what purpose does it serve?

**Answer:** \n is a special character in c++ which creates a newline.

> 5. What terminates input into a string?

**Answer:** A whitespace.

> 6. What terminates input into an integer?

**Answer:** Incompatible characters or using EOF - end-of-file 
ctrl+z (windows) ctrl+d (linux).

> 7. How would you write
```c++
cout << "Hello, ";
cout << first_name;
cout << "!\n";
```
> as a single line of code?

**Answer:** 
```c++
cout << "Hello, " << first_name << "!\n";
```

> 8. What is an object?

**Answer:** An object is a region in a memory that holds a value and a type.

> 9. What is a literal?

**Answer:** An object that represents a fixed value. 

> 10. What kinds of literals are there?

**Answer:** There are 6 kinds of literals in which they are 
**Integer Literals,** **Floating-point literals,** 
**Boolean Literals,** **Character Literals,** 
**String Literals,** and  **Pointer Literals.**

> 11. What is a variable?

**Answer:** A named object.

> 12. What are typical sizes for a char, an int, and a double?

**Answer:** A char usually have a byte, an int 4 bytes and a double 8 bytes.

> 13. What measures do we use for the size of small entities in memory, 
such as ints and strings?

**Answer:** We usually use bits or bytes in which case a byte is 8 bits.

> 14. What is the difference between = and ==?

**Answer:** = is an assignment operator while == is an equality operator.

> 15. What is a definition?

**Answer:** Declaration that sets aside memory for an object.

> 16. What is an initialization and how does it differ from an assignment?

**Answer:** Initialization is setting a value for a new variable while assignment
is setting a new value for an existing variable.

> 17. What is string concatenation and how do you make it work in C++?

**Answer:** String concatenation is by combining two string varaibles. It can
be done with the help of the '+' operator for strings.

> 18. Which of the following are legal names in C++? If a name is not legal,
why not?
```c++
This_little_pig         This_1_is fine              2_For_1_special
latest thing            the_$12_method              _this_is_ok
MiniMineMine            number                      correct?
```

```
Legal                   Illegal                     Illegal
Illegal                 Illegal                     Legal
Legal                   Legal                       Illegal
```

> 19. Give five examples of legal names that you shouldn’t use because 
they are likely to cause confusion.

**Answer:** Names from the standard library must be avoided like string, 
cout, cin, null, nullptr.

> 20. What are some good rules for choosing names?

**Answer:** A good rule of thumb in choosing a name is atleast it must
be relevant to the code you are writing. Another thing is that avoid starting
with _ eventhough it is accepted as it may cause confusion to some of the names
int the library. Lastly, be consistent with the naming convetions that you
have used throughout the program.

> 21. What is type safety and why is it important?

**Answer:** Type-safety is when the compiler checks that the programmer doesn't
mix data types. It is important because it will avoid data loss and human
errors. 

> 22. Why can conversion from double to int be a bad thing?

**Answer:** A conversion from double to an int is a bad thing because an 
integer data type can't hold any floating-point numbers in which if given one,
the data may be trunctuated resulting to data loss.

> 23. Define a rule to help decide if a conversion from one type to 
another is safe or unsafe.

**Answer:** Usually bool or char values into an integer is safe. While
double to any integer is unsafe, integer to any data type smaller to it is
also unsafe. 