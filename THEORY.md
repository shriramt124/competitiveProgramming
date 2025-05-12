## Preprocessor

Preprocessors are programs that process the source code before the actual compilation begins. It is not the part of compilation, but a separate process that allows programmers to modify the code before compilation. It is the first process that the C source code goes through while being converted to executable file


## Preprocessor Directives

The preprocessor directives are the instructions to the preprocessor for doing some tasks such as text substitutions, macro expansions, including header files, and many more before compiling the code. All of these preprocessor directives begin with a ‘#’ hash symbol.

One of the most commonly used preprocessors is #include which is used to include the header files for different libraries in C programs. C provides more directives for different functionalities.

### Macros 
Macros are used to define constants or create functions that are substituted by the preprocessor before the code is compiled. The two preprocessors #define and #undef are used to create and remove macros in C.

### Inline Function
When a function is declared as inline, the compiler inserts the function's code directly at the point of invocation instead of performing a traditional function call. This can improve execution speed by eliminating the overhead of pushing and popping function arguments on the stack.



* https://learningc.org/chapters/chapter08-dynamic-memory-allocation/why-how-dynamic-alloc


* https://www.geeksforgeeks.org/cc-preprocessors/

* https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/

* https://markaicode.com/understanding-pure-virtual-functions-and-abstract-classes-in-cpp/

* https://www.geeksforgeeks.org/how-to-declare-a-2d-array-dynamically-in-c-using-new-operator/