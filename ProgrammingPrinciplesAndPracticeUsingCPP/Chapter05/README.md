# Answers to Review, Drills and Exercises
Note: All non-programming questions will be listed here.

## Drills

**See Chapter 5: Errors**  for the instructions

[Drill.cpp](Drill.cpp)

## Review
> 1. Name four major types of errors and briefly define each one.

**Answer:** The four major types of errors are compiler, linker, runtime,
and logical errors. Compiler errors are usually errors found by the compiler,
linker errors found by the linker, runtime errors, found while the program
is being executed, and lastly, logical errors are errors that is made by the 
programmer, usually a mistake in computation etc.

> 2. What kinds of errors can we ignore in student programs?

**Answer:** In my opinion, errors we can ignore are the additional headers
included in the program, and some logical errors like the program not being 
able to handle unexpected inputs from users.

> 3. What guarantees should every completed project offer?

**Answer:** Every completed project must guarantee to handle every possible error, 
tested and every function is tested for the expected results.

> 4. List three approaches we can take to eliminate errors in 
programs and produce acceptable software.

**Answer:** Three approaches in eliminating errors in programrs and produce
acceptable software is organize software to minimize errors, eliminate most of
errors made through debugging and testing, and make sure the remaining errors
are not serious.

> 5. Why do we hate debugging?

**Answer:** We hate debugging as it is tedious and wastes time especially for large
programs.

> 6. What is a syntax error? Give five examples.

**Answer:** A syntax error is an error found by the compiler in which seems to be
not formed according to c++ program

```c++
int s1 = area(7;           // error: ) missing
int s2 = area(7)           // error: ; missing
Int s3 = area(7);          // error: Int is not a type
int s4 = area('7);         // error: non-terminated character (' missing)
integer s5 = area(7);      // error: integer is not a type
```

> 7. What is a type error? Give five examples.

**Answer:** A type error is a mismatch between types for a variable, function, etc.

```c++
int x0 = arena(7);              // error: undeclared function
int x1 = area(7);               // error: wrong number of arguments
int x2 = area("seven",2);       // error: 1st argument has a wrong type
int x3 = area("seven","three"); // error: both arguments have a wrong type
string x4 = area(7);            // error: wrong return type if area is returning an int. There is no direct conversion from int to string
```

> 8. What is a linker error? Give three examples.

**Answer:** A linker error is an error found by the linker usually when a fucntion
is defined several times in different translation units, it will give an error.

```c++
int area(int length, int width); // calculate area of a rectangle
int main()
{
int x = area(2,3);
}
```

```c++
int area(int x, int y) { /* . . . */ } // "our" area()
```

```c++
double area(double x, double y) { /* . . . */ } // not "our" area()
int area(int x, int y, char unit) { /* . . . */ } // not "our" area()
```

> 9. What is a logic error? Give three examples.

**Answer:** Logic error are errors that can't be detected by the computer and usually
an error that produces a different output from the expected output. 

```c++
int a = 0;
if (a = 0)
    cout << "a is equal to zero\n";
```

```c++
// initialize a
int a = 0;
while (a > 10)
{
    // ... do something
    ++a;
}
```

```c++
int findMinimum(vector<int> v)
{
    int minimum = 0;
    for (int element : v)
    {
        if (element < minimum)
            minimum = element;
    }
    return minimum;
}
```

> 10. List four potential sources of program errors discussed in the text.

**Answer:** Four potential sources of program errors discussed in the text are 
Incomplete programs, Unexpected input, Logical errors, Unexpected argumaents.

> 11. How do you know if a result is plausible? What techniques do you 
have to answer such questions?

**Answer:** A result will be plausible with the help of estimation or "guesstimation"
which uses common sense, few arithmetics, and few facts.

> 12. Compare and contrast having the caller of a function handle a run-time 
error vs. the called function’s handling the run-time error.

**Answer:** In handling errors, when the caller of a function handle a run-time 
error, it will always check the parameters before calling, this might lead to some
long codes as you need to always need to write the code for checking the parameters as
for the function handling the error, once the function has been called, it will perform
checks thus, reducing the line of codes needed to check errors.

> 13. Why is using exceptions a better idea than returning an “error value”?

**Answer:** Using exceptions is better as such it combines various approaches to error
handling. 

> 14. How do you test if an input operation succeeded?

**Answer:** We can test if an input operation succeded by testing the input stream 
in which case is usally the character input stream (cin). e.g if (cin) ... else ...

> 15. Describe the process of how exceptions are thrown and caught.

**Answer:** First exceptions are only thrown inside the try block in which a function
will throw an exception if it finds an error that it cannot handle and indicating what
went wrong in which will indicate what to do in that certain throw.

> 16. Why, with a vector called v, is v[v.size()] a range error? What would be 
the result of calling this?

**Answer:** Calling a vector v in v[v.size()] will cause a range error because
indices counts with n-1 as such size() functions counts on n numbers. 

> 17. Define pre-condition and post-condition; give an example (that is not the 
area() function from this chapter), preferably a computation that requires a loop.

**Answer:** Pre-condition is a requirement of a function upon its argument while 
post-condition is a requirement of a function upon its return. 

```C++
//PRECONDITION
double positive_sqrt(double a)
// check that the argument is positive
{
    if (!(0<a)) // ! means "not"
        error("bad arguments for positive_sqrt");

    return sqrt(a);
}
```

```C++
//POSTCONDITION
double rectangle_circumference(double height, double width)
// check that the arguments are positive
{
    if (!(0<height && 0<width)) // ! means "not" and && means "and"
        error("bad arguments for rectangle_circumference");

    double circumference = 2*height + 2*width;
    if (circumference <= 0) error("rectangle_circumference() post-condition");
    return circumference;
}
```
> 18. When would you not test a pre-condition?

**Answer:** One would not check a pre condition if it meets the following 
requirements, Nobody would give bad arguments - which is unusual, It would slow down
my code, or It is too complicated to check. 

> 19. When would you not test a post-condition?

**Answer:** Almost same to pre-condition in which we will not test a post-condition if 
it would slow down your code, or it is too complicated to check.

> 20. What are the steps in debugging a program?

**Answer:** In debugging a program we usually get the program to compile, get the program
to link, and get the program to do what it is supposed to do. We do this sequence for several
times each time depending on the size of a program.

> 21. Why does commenting help when debugging?

**Answer:** Commenting helps due to it makes the program readable and increases the chance
of the programmer to catch those bugs.

> 22. How does testing differ from debugging?

**Answer:** Debugging is searching for errors and fixing them while testing is giving a 
program a set of inputs in which the results will be compared to what was expected. 