#include <cstddef>
#include <iostream>
using namespace std;

const int DEBUG = 0;

template <class T> class Node {
public:

  Node(){}
  Node ( T el ){
    element = el;
    next = NULL;
  }
  T element;
  Node * next;
};




template <class T> class Container {
public:
  Container (){
    first = NULL;
    last = NULL;
    size = 0;
  }

  virtual ~Container (){
    while (size != 0){
      deleteFirst();
    }
#ifdef DEBUG
    std::cout << "destructor of Container" << '\n';
#endif
  }
  void pushFirst(T element){
    if ((first == NULL)){
      Node<T> * node = new Node<T>(element);
      first = node;
      last = node;
    }
    else {
      Node<T> * node = new Node<T>(element);
      node->next = first;
      first = node;
    }
    size++;
  }
  void pushLast (T element){
    if ((first == NULL)){
      Node<T> * node = new Node<T>(element);
      first = node;
      last = node;
    }
    else{
        Node<T> * node = new Node<T>(element);
        last->next = node;
        last = node;
    }
    size++;
  }
  void deleteFirst(){
    if (first == last){
      delete first;
      first = NULL;
      last = NULL;
    }
    else{
      Node<T> * temp = first;
      first = first->next;
      delete temp;
    }
    size--;
  }
  void deleteLast(){
    if (first == last){
      delete first;
      first = NULL;
      last = NULL;
    }
    else{
      Node<T> * temp = first;
      while (temp->next != last){
        temp = temp->next;
      }
      delete last;
      last = temp;
      last->next = NULL;
    }
    size--;
  }
  T getFirst (){
    return first->element;
  }
  T getLast (){
    return last->element;
  }
  T getNth (int n){
    Node<T> * p = first;
    for (int i = 0; i < n ; i++) {
      p = p->next;
    }
    return p->element;
  }
  int getSize(){
    return size;
  }
  bool isEmpty(){
    if (size == 0) return true;
      else return false;
  }
  void empty(){
    while (size != 0){
      deleteFirst();
    }
  }
  void print(){
    if (first != NULL){
      Node<T> * temp;
      temp = first;
      while (temp != NULL) {
        cout << temp->element << endl;
        temp = temp->next;
      }

    }
  }

private:
  size_t size;
  Node<T> *first, *last;
};
