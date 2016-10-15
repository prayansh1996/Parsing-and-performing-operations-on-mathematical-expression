#include <iostream>
#include <stdio.h>
#include "polynomial_functions.h"
using namespace std;


int main()
{
    linkedlists L1, L2, L3;
    L1.get_expression<int>("2  x^2   + 2 + 3x = 0");
    L2.get_expression<int>("4x^    2 - 1 +2 + 3x^(3) = 0");
    cout<<L1;
    cout<<L2;

    cout<<endl<<endl<<"ADDITION";
    L3=L1+L2;
    cout<<L3;

    cout<<endl<<endl<<"SUBTRACTION";
    L3=L1-L2;
    cout<<L3;

    cout<<endl<<endl<<"MULTIPLICATION";
    L3=L1*L2;
    cout<<L3;
    return 0;
}


/*
char E[100];
    cout<<"Expressions are of the type ax^2 + bx^1 +cx^0 = 0\n";
    cout<<"Enter expression 1: ";
    gets(E);
    L1.get_expression<int>(E);
    cout<<"Enter expression 2: ";
    gets(E);
    L2.get_expression<int>(E);
    cout<<L1;
    cout<<L2;
*/
