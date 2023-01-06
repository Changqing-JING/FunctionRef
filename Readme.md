Implementation of function reference. 
If a lambda expression is saved in std::function, it lead to dynamic memory allocation. It wastes both RAM and CPU.
FunctionRef can be used to store a lambda expression as sync callback function as reference.
