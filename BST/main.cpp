#include <iostream>

using namespace std;

struct Node
{
    int key;
    char name;
    Node *parent = NULL;
    Node *left = NULL;
    Node *right = NULL;
    Node(int key, char name)
    {
        this->key = key;
        this->name = name;
    }
} *bst;
void insert(int key, char name)
{
    if(!bst)
    {
        bst = new Node(key, name);
        return;
    }
    Node *control = bst;
    while(true)
    {
        if(key <= control->key)
        {
            if(!control->left)
            {
                control->left = new Node(key, name);
                control->left->parent = control;
                control = control->left;
                return;
            }
            else
            {
                control = control->left;
            }
        }
        else
        {
            if(!control->right)
            {
                control->right = new Node(key, name);
                control->right->parent = control;
                return;
            }
            else
            {
                control = control->right;
            }
        }
    }
}
void pick(int index)
{
    if(bst == NULL)
        return;
    Node *control = bst;
    cout << control->name;
    while(index != control->key)
    {
        if(index < control->key)
        {
            if(control->left)
            {
                control = control->left;
                cout << control->name;
            }
            else return;
        }
        else
        {
            if(control->right)
            {
                control = control->right;
                cout << control->name;
            }
            else return;
        }
    }
}
int main()
{
    int action;
    do
    {
        cin >> action;
        int key;
        switch(action)
        {
        case 0:
            char name;
            cin >> key >> name;
            insert(key, name);
            break;
        case 1:
            cin >> key;
            pick(key);
            break;
        }
    }while(action != 2);
    return 0;
}
