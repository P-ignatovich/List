#include "list.h"

template<typename T>
List<T>::List()
{
  size = 0;
  head = nullptr;
}

template<typename T>
List<T>::~List()
{
  for(int i = 0; i < size; i++)
  {
    popBack();
  }
}

template<typename T>
void List<T>::pushBack(T data)
{
  if(!head)
  {
    head = new Node<T>(data);
  }
  else
  {
    Node<T>* current = head;

    while(current->pNext)
    {
      current = current->pNext;
    }
    current->pNext = new Node<T>(data);
  }
  size++;
}

template<typename T>
void List<T>::popBack()
{
  if(size == 0)
  {
    perror("fucked up: list is empty");
    exit(EXIT_FAILURE);
  }
  List::Node<T>* current = head;
  for(int i = 0; i < size - 2; i++)
  {
    current = current->pNext;
  }
  delete current->pNext;
  current->pNext = nullptr;
  size--;
}

template<typename T>
T& List<T>::operator[](const int index)
{
  List::Node<T>* current = head;
  int counter = 0;
  while(current)
  {
    if (counter == index)
    {
      return current->data;
    }
    current = current->pNext;
    counter++;
  }
  perror("fucked up: no element with such index");
  exit(EXIT_FAILURE);
}

template<typename T> template<typename U> List<T>::Node<U>::Node(U data, Node<U>* pNext)
{
  this->data = data;
  this->pNext = pNext;
}


