When is a destructor called? 
 

### A destructor function is called automatically when: 

1. the object goes out of scope
2. the program ends
3. a scope (the { } parenthesis) containing local variable ends.
4. a delete operator is called
 

### Destructor rules

1. The name should begin with a tilde sign(~) and match the class name.
2. There cannot be more than one destructor in a class.
3. Unlike constructors that can have parameters, destructors do not allow any parameter.
4. They do not have any return type, not even void. I
5. A destructor should be declared in the public section of the class.
6. The programmer cannot access the address of the destructor.
7. It has no return type, not even void.
8. When you do not specify any destructor in a class, the compiler generates a default destructor and inserts  it into your code.