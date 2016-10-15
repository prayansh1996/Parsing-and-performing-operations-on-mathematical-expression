#ifndef POLYNOMIAL_FUNCTIONS_H_INCLUDED
#define POLYNOMIAL_FUNCTIONS_H_INCLUDED
#include <iostream>
#include <cmath>
#include "polynomial_template.h"
#define zx cout<<"here";
using namespace std;

//FUNCTION DECLARATION
bool isnum(char s);

//FUNCTION DEFINITIONS
template <typename hole>
void linkedlists::insert_at_sorted(hole coeff, hole pow)
{
    node<> *temp = new node<>(coeff, pow);
    if(head == NULL)
    {   head = temp;
        return;
    }

    node<> *prev = NULL, *curr = head;
    while(curr && curr->pow >= pow)
    {   if(curr->pow == pow)
        {   curr->coeff+=coeff;
            delete temp;
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    if(prev == NULL)
    {   temp->next = head;
        head = temp;
        return;
    }
    prev->next = temp;
    temp->next = curr;
}


bool isnum(char s)
{   return (s>='0' && s<='9')? 1:0;}


template <class T>
void linkedlists::get_expression(char* str)           //SETS EXPRESSION AS NODES INTO A LINKED LIST
{
    int i=0, multiplier;
    T coeff, pow;
    while(str[i]!= '=')
    {
        coeff=0, pow=0;
        if(i==0 && (isnum(str[i]) || str[i]=='x'))
        {   i = get_node(str, i, coeff, pow);
            insert_at_sorted(coeff, pow);
        }
        else if(str[i]=='-' || str[i]=='+')
        {   switch(str[i])
            {   case '+':multiplier = 1;  break;
                case '-':multiplier = -1; break;
            }
            i = get_node(str, i, coeff, pow);
            insert_at_sorted(coeff*multiplier, pow);
        }
        else
        {   i++;}
    }
}


template <class T>
int linkedlists::get_node(char *str, int i, T &coeff, T &pow)     //RETURNS COEFF AND POW AND CHANGES I TO THE NEXT OF THE
{                                                           //LAST NUMBER
    bool is1 = false;
    while(isnum(str[i])==0)
    {   if(str[i]=='x')
        {   is1 = true;
            coeff = 1;
            break;
        }
        i++;
    }
    if(is1==false)
    {   i = get_num(str, i, coeff);}

    if(str[i]!='x')
    {   pow=0;
        return i;
    }i++;
    if(str[i]!='^')
    {   pow=1;
        return i;
    }i++;

    while(isnum(str[i])==0)
    {   i++;}
    i = get_num(str, i, pow);

    return i;
}


template <class T>
int linkedlists::get_num(char *str, int i, T &num)          //CHANGES NUMBER AND NEXT OF I
{
    int j=i, nextchar, pow=1; num=0;
    while(isnum(str[j]))
    {   j++;}
    nextchar = j;
    j--;

    while(j>=i)
    {   num = num + (str[j] - '0')*pow;
        pow*=10;
        j--;
    }
    return nextchar;
}


ostream& operator<<(ostream &obj, const linkedlists &L)         //COUT OVERLOADED
{
    if(L.head==NULL)
    {   return obj;}
    node<> *trav = L.head;
    char sign = '-';
    if(trav->coeff>=0)
    {   sign = '+';}

    cout<<endl;
    while(trav)
    {   //COEFF SIGN
        if(trav->coeff>=0)
        {   if(sign == '+')        //FOR FIRST
            {   sign = 0;}
            else
            {   cout<<"+ ";}
        }
        else
        {   cout<<"-";
            if(sign == '-')
            {   sign = 0;}
            else
            {   cout<<' ';}
        }
        //COEFF
        if(trav->coeff!=1 || trav->pow!=1)
        {   cout<<abs(trav->coeff);}
        //POWER
        if(trav->pow==1)
        {   cout<<'x';}
        else if(trav->pow!=0)
        {   cout<<"x^"<<trav->pow;}
        cout<<' ';
        trav = trav->next;
    }cout<<"= 0";
    return obj;
}


void linkedlists::operator+=(const linkedlists &L)
{
    node<> *temp = L.head;
    while(temp)
    {   insert_at_sorted(temp->coeff, temp->pow);
        temp = temp->next;
    }
}

void linkedlists::operator-=(const linkedlists &L)
{
    node<> *temp = L.head;
    while(temp)
    {   insert_at_sorted(temp->coeff*(-1), temp->pow);
        temp = temp->next;
    }
}

linkedlists operator+(const linkedlists &L1, const linkedlists &L2)
{
    linkedlists L3;
    L3+=L1;
    L3+=L2;
    return L3;
}

linkedlists operator-(const linkedlists &L1, const linkedlists &L2)
{
    linkedlists L3;
    L3+=L1;
    L3-=L2;
    return L3;
}

void linkedlists::operator*=(const linkedlists &L)
{
    node<> *travL1 = head, *travL2 = NULL, *temp = NULL;
    int coeff, pow;

    while(travL1)
    {   travL2 = L.head;
        coeff = travL1->coeff;
        pow = travL1->pow;
        while(travL2)
        {   insert_at_sorted(coeff*travL2->coeff, pow+travL2->pow);
            travL2 = travL2->next;
        }
        travL1->coeff-=coeff;

        if(travL1->coeff==0)
        {   temp = travL1->next;
            delete_position(travL1);
            travL1 = temp;
        }
        else
        {   travL1 = travL1->next;}
    }
}


linkedlists operator*(const linkedlists &L1, const linkedlists &L2)
{
    linkedlists L3;
    L3.insert_at_sorted(1, 0);
    L3*=L1;
    L3*=L2;
    return L3;
}

void linkedlists::operator=(linkedlists L)
{
    head = L.head;
    L.head = NULL;
}

#endif // POLYNOMIAL_FUNCTIONS_H_INCLUDED
