/*
  Copyright (c) 2019
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2019
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

using std::runtime_error;

// This file defines the methods for two classes: LinkedListNode and LinkedList.
// The LinkedListNode methods have been defined for you.  You are responsible
// for defining the LinkedList methods.

// //////// LinkedListNode /////////////////////////////////////////////////////

template <typename T> LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

// //////// LinkedList /////////////////////////////////////////////////////////

template <typename T> LinkedList<T>::LinkedList() {
  this->size = 0;
  this->head = nullptr;
  this->tail = nullptr;
}

template <typename T> LinkedList<T>::~LinkedList() {
  while (this->size > 0) {
      removeFirst();
  }
}

template <typename T> void LinkedList<T>::checkInvariants() {
  int count = 0;
  LinkedListNode<T>* nextNode = this->head;
  while (nextNode != nullptr){
    count += 1;
    nextNode = nextNode->next;
  }
  if (count != this->size) {
    throw runtime_error("Invariants not applied.");
  }
}

template <typename T> int LinkedList<T>::getSize() {
  return this->size;
}

template <typename T> bool LinkedList<T>::isEmpty() {
  if (this->size == 0) {
    return true;
  } else {
    return false;
  }
}

template <typename T> T LinkedList<T>::getFirst() {
  if (this->size <= 0) {
    throw runtime_error("Linked list is empty.");
  } else {
    return this->head->value;
  }
}

template <typename T> T LinkedList<T>::getLast() {
  if (this->size <= 0) {
    throw runtime_error("Linked list is empty.");
  } else {
      return this->tail->value;
  }
}

template <typename T> T LinkedList<T>::get(int index) {
  LinkedListNode<T>* nextNode = this->head;
  if (index < 0 || index >= this->size) {
    throw runtime_error("Index out of bounds");
  } else {
    for (int i = 0; i < index; i++) {
      nextNode = nextNode->next;
    }
    return nextNode->value;
  }
}

template <typename T> void LinkedList<T>::insertFirst(T value) {
  if (this->size == 0) {
    LinkedListNode<T>* newNode = new LinkedListNode<T>(value, nullptr);
    this->head = newNode;
    this->tail = newNode;
    this->size += 1;
  } else {
    LinkedListNode<T>* newNode = new LinkedListNode<T>(value, this->head);
    this->head = newNode;
    this->size += 1;
  }
}

template <typename T> void LinkedList<T>::insertLast(T value) {
  LinkedListNode<T>* newNode = new LinkedListNode<T>(value, nullptr);
  if (this->size == 0) {
    this->head = newNode;
    this->tail = newNode;
  } else {
    this->tail->next = newNode;
    this->tail = newNode;
  }
  this->size += 1;
}

template <typename T> T LinkedList<T>::removeFirst() {
  if (this->size == 0) {
    throw runtime_error("Linked List is empty.");
  } if (this->size == 1) {
      LinkedListNode<T>* tempNode = this->head;
      T value = tempNode->value;
      delete tempNode;
      this->size -= 1;
      return value;
  } else {
      LinkedListNode<T>* tempNode = this->head;
      T value = tempNode->value;
      this->head = tempNode->next;
      delete tempNode;
      this->size -= 1;
      return value;
  }
}

template <typename T> T LinkedList<T>::removeLast() {
  //account for size = 0, size = 1, and else
  if (this->size == 0) {
    throw runtime_error("Linked List is empty.");
  } if (this->size == 1) {
    LinkedListNode<T>* tempNode = this->tail; //assign tail to the temp node
    T value = tempNode->value;
    delete tempNode;
    this->size -= 1;
    return value;
  } else {
      LinkedListNode<T>* tempNode = this->tail;
      T value = tempNode->value; //create a new node ptr, initially points to head
      LinkedListNode<T>* currentNode = this->head;

      for (int i = 0; i < (this->size - 2); i++) {
        currentNode = currentNode->next; // make it point to the next thing
      }
      currentNode->next = nullptr; //new node next should be nullptr
      this->tail = currentNode; //new tail should be new node
      delete tempNode;
      this->size -= 1;
      return value;
    }
}
