#pragma once
#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
	T data;
	Node* next;
	Node* previous;

public:
	Node();
	Node(const Node& copy);
	~Node();
	Node& operator=(const Node& rhs);
	Node* getNext();
	Node* getPrevious();
	void setNext(Node * next);
	void setPrevious(Node * previous);
	void setNextPrevious(Node * nextPrevious);
	void setPreviousNext(Node * previousNext);
	void setPreviousToNull(Node * next);
	void setNextToNull(Node * previous);
	void setPreviousForNewNode(Node * node);
	void setData(T data);
	void eraseNodeNext();
	void eraseNodePrevious();
	T & getData();
};

template<class T>
inline Node<T>::Node()
{
	next = nullptr;
	previous = nullptr;
}

template<class T>
inline Node<T>::Node(const Node & copy)
{
	this->data = copy.data;
	this->next = copy.next;
	this->previous = copy.previous;
}

template<class T>
inline Node<T>::~Node()
{
}

template<class T>
inline Node<T> & Node<T>::operator=(const Node & rhs)
{
	this->data = rhs.data;
	this->next = rhs.next;
	this->previous = rhs.previous;
}

template<class T>
inline Node<T> * Node<T>::getNext()
{
	return this->next;
}

template<class T>
inline Node<T> * Node<T>::getPrevious()
{
	return this->previous;
}

template<class T>
inline void Node<T>::setNext(Node * next)
{
 	this->next = next;
}

template<class T>
inline void Node<T>::setPrevious(Node * previous)
{
	this->previous = previous;
}

template<class T>
inline void Node<T>::setNextPrevious(Node * nextPrevious)
{
	nextPrevious->previous->setNext(nextPrevious->next);
}

template<class T>
inline void Node<T>::setPreviousNext(Node * previousNext)
{
	previousNext->next->setPrevious(previousNext->previous);
}

template<class T>
inline void Node<T>::setPreviousToNull(Node * previous)
{
	previous->previous->next = nullptr;
}

template<class T>
inline void Node<T>::setNextToNull(Node * next)
{
	next->next->previous = nullptr;
}

template<class T>
inline void Node<T>::setPreviousForNewNode(Node * node)
{
	next->next->setPrevious(node);
}

template<class T>
inline void Node<T>::setData(T data)
{
	this->data = data;
}

template<class T>
inline void Node<T>::eraseNodeNext()
{
	next = nullptr;
}

template<class T>
inline void Node<T>::eraseNodePrevious()
{
	previous = nullptr;
}

template<class T>
inline T & Node<T>::getData()
{
	return this->data;
}
#endif