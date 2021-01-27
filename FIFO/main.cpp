#include <iostream>

using namespace std;

struct fifo
{
    int key;
    fifo *next = NULL;
    fifo(int key)
    {
        this->key = key;
    }
};
fifo *querry = NULL;
void insert(int key)
{
    if(!querry)
    {
        querry = new fifo(key);
        return;
    }
    fifo *control = querry;
    while(control->next)
    {
        control = control->next;
    }
    control->next = new fifo(key);
}
void print()
{
    if(!querry)
        return;
    fifo *control = querry;
    while(control->next)
    {
        cout << control->key;
        control = control->next;
    }
    cout << control->key;
}
void pull()
{
    if(!querry)
        return;
    cout << querry->key;
    fifo *control = querry;
    querry = querry->next;
    delete control;
}
int main()
{
    int action;
    do
    {
        cin >> action;
        if(action == 0)
        {
            int number;
            cin >> number;
            insert(number);
        }
        else if(action == 1)
        {
            pull();
        }
        else if(action == 2)
        {
            print();
        }
    }while(action != 3);
    return 0;
}
