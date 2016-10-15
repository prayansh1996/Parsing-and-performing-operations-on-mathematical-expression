#ifndef POLYNOMIAL_TEMPLATE_H_INCLUDED
#define POLYNOMIAL_TEMPLATE_H_INCLUDED
#include <iostream>
#define zx cout<<"here";
using namespace std;
class linkedlists;
ostream& operator<<(ostream &obj, const linkedlists &L);

template <typename hole = int>
class node
{public:
    node *next;
    hole coeff;
    hole pow;
    friend class linkedlists;


    node(): coeff(0), pow(0), next(NULL){};
    node(const hole a,const hole b): coeff(a), pow(b), next(NULL){};
    ~node();
    friend ostream& operator<<(ostream &obj, const linkedlists &L);
};


class linkedlists
{public:
    node<> *head;

    linkedlists(): head(NULL){};
    ~linkedlists();
    void clearlist();
    linkedlists(const linkedlists&);
    template <typename hole> void insert_end(hole, hole);
    void delete_end();
    void delete_position(node<> *temp);
    void printlist();
    friend ostream& operator<<(ostream &obj, const linkedlists &L);
    template <typename hole> void insert_at_sorted(hole coeff, hole pow);
    template <typename hole> void get_expression(char* str);
    template <typename hole> int get_node(char *str, int i, hole &coeff, hole &pow);
    template <typename hole> int get_num(char *str, int i, hole &num);
    void operator+=(const linkedlists &L);
    void operator-=(const linkedlists &L);
    void operator*=(const linkedlists &L);
    void operator=(linkedlists L);
    friend linkedlists operator+(const linkedlists &L1, const linkedlists &L2);
    friend linkedlists operator-(const linkedlists &L1, const linkedlists &L2);
};


//NODE FUNCTIONS
template <typename hole>
node<hole>::~node()
{   /*cout<<"\nNode Destructed\n";*/}

//LINKEDLISTS FUNCTIONS

linkedlists::~linkedlists()         //DESTRUCTOR
{
    node<> *temp;
    while(head)
    {   temp = head->next;
        delete head;
        head = temp;
    }//cout<<"\nLinkedList Destroyed\n";
}

void linkedlists::clearlist()         //DESTRUCTOR
{
    node<> *temp;
    while(head)
    {   temp = head->next;
        delete head;
        head = temp;
    }//cout<<"\nLinkedList Destroyed\n";
}

linkedlists::linkedlists(const linkedlists &L2)         //COPY CONSTRUCTOR
{
    head = NULL;
    node<> *trav = L2.head;
    node<> *prev = NULL;

    while(trav)
    {   node<> *temp = new node<>(trav->coeff, trav->pow);
        temp->next = NULL;
        if(head==NULL)
        {   head = temp; }
        else{   prev->next = temp;}
        prev = temp;
        trav = trav->next;
    }
}

template <typename hole>
void linkedlists::insert_end(hole coeff, hole pow)          //INSERT AT END
{
    node<> *temp = new node<>(coeff, pow);

    if(head==NULL)
    {   head = temp;
        return;
    }

    node<> *trav = head;
    while(trav->next)
    {   trav = trav->next;}
    trav->next = temp;
}

void linkedlists::delete_end()          //DELETE FROM END
{
    if(head==NULL)
    {   return;}

    node<> *curr = head, *prev = NULL;
    while(curr->next)
    {   prev = curr;
        curr = curr->next;
    }
    if(prev==NULL)
    {   head = NULL;}
    else
    {   prev->next = 0;}

    delete curr;
}

void linkedlists::delete_position(node<> *temp)      //DELETE A GIVEN POINTER
{
    node<> *prev = NULL, *curr = head;
    while(curr!=temp)
    {   prev = curr;
        curr = curr->next;
    }

    if(prev == NULL)
    {   head = curr->next;
        delete curr;
    }
    prev->next = curr->next;
    delete curr;
}

void linkedlists::printlist()           //PRINT LIST
{
    node<> *trav = head;
    cout<<endl;
    while(trav)
    {   if(trav->coeff>=0 && trav!=head)
        {   cout<<'+';}
        if(trav->coeff!=1)
        {   cout<<trav->coeff;}
        cout<<"x^"<<trav->pow<<' ';
        trav = trav->next;
    }cout<<"= 0";
}

#endif // POLYNOMIAL_TEMPLATE_H_INCLUDED
