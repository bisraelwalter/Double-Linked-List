#pragma once
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include "Exception.h"
#include <iostream>

using std::cout;
using std::endl;

template <class T>
class DoubleLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int nodeCount = 0;

public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& copy);
	~DoubleLinkedList();
	DoubleLinkedList& operator=(const DoubleLinkedList& rhs);
	bool isEmpty();
	void Prepend(T data);
	void Append(T data);
	T & First() const;
	T & Last() const;
	Node<T> * getHead() const;
	Node<T> * getTail() const;
	void Purge();
	void Extract(int index);
	void InsertAfter(int index, T data);
	void InsertBefore(int index, T data);
	void PrintForwards();
	void PrintBackwards();
};

template<class T>
inline DoubleLinkedList<T>::DoubleLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template<class T>
inline DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList & copy)
{
	head = tail = nullptr;
		Node<T> * temp = copy.head;

		while (temp)
		{
			this->Append(temp->getData());
			temp = temp->getNext();
		}
		nodeCount = copy.nodeCount;
}

template<class T>
inline DoubleLinkedList<T>::~DoubleLinkedList()
   {
		while (head)
		{
			Node<T> * temp = head->getNext();

			delete head;
			head = nullptr;
			head = temp;
		}
		tail = nullptr;
		head = nullptr;
}

template<class T>
inline DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList & rhs)
{
	head = tail = nullptr;
		Node<T> * temp = rhs.head;
		this->nodeCount = rhs.nodeCount;
		while (temp)
		{
			this->Append(temp->getData());
			temp = temp->getNext();
		}
	return *this;
}



template<class T>
inline bool DoubleLinkedList<T>::isEmpty()
{
	return head == nullptr;
}

template<class T>
inline void DoubleLinkedList<T>::Prepend(T data)
{
	if (head == nullptr)
	{
		Node<T> * theNewNode = new Node<T>;
		theNewNode->setData(data);
		tail = theNewNode;
		head = theNewNode;
		nodeCount++;
	}
	else
	{
		Node<T> * theNewNode = new Node<T>;
		theNewNode->setData(data);
		theNewNode->setNext(head);
		head->setPrevious(theNewNode);
		head = theNewNode;
		nodeCount++;
	}
}

template<class T>
inline void DoubleLinkedList<T>::Append(T data)
{
	if (head == nullptr)
	{
		Node<T> * theNewNode = new Node<T>;
		theNewNode->setData(data);
		tail = theNewNode;
		head = theNewNode;
		nodeCount++;
	}
	else
	{
		Node<T> * theNewNode = new Node<T>;
		theNewNode->setData(data);
		theNewNode->setPrevious(tail);
		tail->setNext(theNewNode);
		tail = theNewNode;
		nodeCount++;
	}
}

template<class T>
inline T & DoubleLinkedList<T>::First() const
{
	if (head == nullptr)
		throw Exception("List is empty");

	return head->getData();
}

template<class T>
inline T & DoubleLinkedList<T>::Last() const
{
	if (tail == nullptr)
		throw Exception("List is emtpy");

	return tail->getData();
}

template<class T>
inline Node<T>* DoubleLinkedList<T>::getHead() const
{
	return head;
}

template<class T>
inline Node<T>* DoubleLinkedList<T>::getTail() const
{
	return tail;
}



template<class T>
inline void DoubleLinkedList<T>::Purge()
{
	if (head != nullptr)
	{
		while (head)
		{
			Node<T> * temp = head->getNext();

			delete head;
			head = nullptr;
			head = temp;
		}
		tail = nullptr;
		head = nullptr;
		nodeCount = 0;
	}
}

template<class T>
inline void DoubleLinkedList<T>::Extract(int index)
{
	if (index < 1)
		throw Exception("Index out of bound, must be greater than zero");
	if (index > nodeCount)
		throw Exception("Index out of bound, indext does not exist");
		Node<T> * temp = head;

		if (nodeCount == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			for (int i = 1; i < index; i++)
			{
				temp = temp->getNext();
			}
			if (temp->getNext() == nullptr)
			{
				tail = temp->getPrevious();
				temp->setPreviousToNull(temp);
				temp->eraseNodePrevious();
				delete temp;
				temp = nullptr;
				nodeCount--;
			}
			else
			{ 
				if (temp->getPrevious() == nullptr)
				{
					head = temp->getNext();
					temp->setNextToNull(temp);
					temp->eraseNodeNext();
					delete temp;
					temp = nullptr;
					nodeCount--;
				}
			}
		}
}

template<class T>
inline void DoubleLinkedList<T>::InsertAfter(int index, T data)
{
	if (index < 1)
		throw Exception("Index out of bound, must be greater than zero");
	if (index > nodeCount)
		throw Exception("Index out of bound, index does not exist");

	Node<T> * temp = head;

	for (int i = 1; i < index; i++)
	{
		temp = temp->getNext();
	}
	if (index == nodeCount)
		Append(data);
	else
	{
		Node<T> * NewNode = new Node<T>;
		NewNode->setData(data);
		NewNode->setNext(temp->getNext());
		temp->setNext(NewNode);
		NewNode->setPrevious(temp);
		temp->setPreviousForNewNode(NewNode);
		nodeCount++;
	}
}

template<class T>
inline void DoubleLinkedList<T>::InsertBefore(int index, T data)
{
	if (index < 1)
		throw Exception("Index out of bound, must be greater than zero");
	if (index > nodeCount)
		throw Exception("Index out of bound, index does not exist");

	Node<T> * temp = head;

	for (int i = 1; i < index - 1; i++)
	{
		temp = temp->getNext();
	}
	if (index == 1)
		Prepend(data);
	else
	{
		Node<T> * NewNode = new Node<T>;
		NewNode->setData(data);
		NewNode->setNext(temp->getNext());
		temp->setNext(NewNode);
		NewNode->setPrevious(temp);
		temp->setPreviousForNewNode(NewNode);
		nodeCount++;
	}
}

template<class T>
inline void DoubleLinkedList<T>::PrintBackwards()
{
	if (tail)
	{
		Node<T> * temp = tail;

		while (temp)
		{
			cout << temp->getData() << endl;
			temp = temp->getPrevious();
		}
	}
	else
		cout << "List is empty" << endl;
}

template<class T>
inline void DoubleLinkedList<T>::PrintForwards()
{
	if (head)
	{
		Node<T> * temp = head;

		while(temp)
		{
			cout << temp->getData() << endl;
			temp = temp->getNext();
		}
	}
	else
		cout << "List is empty" << endl;

}

#endif











