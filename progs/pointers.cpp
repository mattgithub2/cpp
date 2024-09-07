#include <iostream>

void foo () { std::cout << "Hello from foo"; }

void print(void (*funcptr)()) { funcptr(); }

int main(int argc, char **argv){

    int* a = nullptr; // pointer to an int
    const int* a2 = nullptr; // pointer to a const int
    int* const a3 = nullptr; // const pointer to an int
    const int* const a4 = nullptr; // const pointer to a const int
                                   //
                                   //
    void (*funcptr)() = foo;

    funcptr();
    print(funcptr);


    int x = 2;
    int y =3;
                                   
    // Pointer to an int 
    int* ptr = new int(4);
    delete ptr;
    ptr = &x; // OK
    *ptr = 3; // OK
              
    // Pointer to const int (address pointed to can be changed (value stored at that address cannot) )
    const int* ptr2 = &x;
    ptr2 = &y; // OK
    // *ptr2 = 3; // Error!

    // const pointer to int (address cannot be changed but the value stored at address can)
    int* const ptr3 = &x;
    *ptr3 = 3; // OK
    // ptr3 = &y; Error!
    // const pointer to a const int (address cannot be changed nor can the value stored at that address) // Error!
    const int* const ptr4 = &x;
    // *ptr3 = 3; // Error!
    // ptr3 = &y // Error;

    return 0;
}
