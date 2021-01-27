#include <iostream>

using namespace std;

struct querry
{
    float key;
    querry *next = NULL;
    querry(float key)
    {
        this->key = key;
    }
} *lifo;

void insert(float key)
{
    if(!lifo)
    {
        lifo = new querry(key);
        return;
    }
    querry *control = new querry(key);
    control->next = lifo;
    lifo = control;
}
void print()
{
    if(!lifo)
    {
         return;
    }
    querry *control = lifo;
    while(control->next)
    {
        cout << control->key;
        control = control->next;
    }
    cout << control->key;
}
void pull()
{
    if(!lifo)
    {
        cout << "x";
        return;
    }
    if(!lifo->next)
    {
        cout << lifo->key;
        delete lifo;
        lifo = NULL;
    }
    else
    {
        querry *control = lifo;
        cout << lifo->key;
        lifo = lifo->next;
        delete control;
    }
}
int main()
{
    int choose;
    do
    {
        cin >> choose;
        if(choose == 0)
        {
            float key;
            cin >> key;
            insert(key);
        }
        else if(choose == 1)
        {
            pull();
        }
        else if(choose == 2)
        {
            print();
        }
    }while(choose != 3);
    return 0;
}
