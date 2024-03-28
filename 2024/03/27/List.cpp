#include "List.h"

template <typename T>
List<T>::List(T data)
{
    ptr_first = new node;
    ptr_first->data = data;
    length = 1;
}

template <typename T>
List<T>::~List()
{
    current = ptr_first;
    while (current != NULL)
    {
        node *temp = current;
        current = current->next;
        delete temp;
    }
}

template <typename T>
void List<T>::push_back(T data)
{
    ptr_last->next = new node;
    ptr_last = ptr_last->next;
    ptr_last->data = data;
    length++;
}

template <typename T>
void List<T>::move(int location)
{
    if (location >= current_num)
    {
        int count = current_num;
    }
    else
    {
        current = ptr_first;
        int count = 0;
    }
    int count = 0;
    while (count < location)
    {
        current = current->next;
        count++;
    }
}

template <typename T>
void List<T>::insert(T data, int location)
{
    node *temp = current;
    move(location);
    insert(data);
    current = temp;
}

template <typename T>
void List<T>::insert(T data)
{
    node *temp = current->next;
    current->next = new node;
    current->next->next = temp;
    current->next->data = data;
}

template <typename T>
void List<T>::del(int location)
{
    node *temp = current;
    move(location);
    del_next();
    current = temp;
}

template <typename T>
void List<T>::del_next()
{
    node *temp = current->next->next;
    delete current->next;
    current->next = temp;
}