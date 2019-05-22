#include <iostream>

template<typename T>
class List
{
public:
  List();
  ~List();

  void pushBack(T data);
  void popBack ();
  int getSize() {return size;}

  T& operator[](const int index);
private:
  template<typename U>
  class Node
  {
  public:
    Node(U data = U(), Node* pNext = nullptr);
 
    U data;
    Node* pNext;
  };
  int size;
  Node<T>* head;
};