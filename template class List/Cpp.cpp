﻿#include <iostream>

using namespace std;

template <typename T>
class List 
{
private:

    template <typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T> *head;
public:
  
    List();
    ~List();
    void push_back(T data);
    void pop_front();
    void clear();
    void push_front(T data);
    void insert(T data, int index);
    void remove(int);
    void pop_back();

    int Get_size()
    {
        return Size;
    }
    T& operator[](const int index);
};

template <typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}

template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;

    delete temp;

    Size--;
}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;

        Size++;  }
}

template<typename T>
void List<T>::remove(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;

        delete toDelete;
        Size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    remove(Size - 1);
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}


int main()
{
    List<int> lst;
    lst.push_front(1);
    lst.push_back(2);
   
    for (int i = 0; i < lst.Get_size(); i++)
    {
        cout << lst[i] << " ";
    }
    lst.pop_front();
    lst.pop_back();

    return 0;
}
  