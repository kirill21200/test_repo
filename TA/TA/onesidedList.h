#pragma once
#include "Node.h"
template<typename T>
class onesidedList
{
public:
	int Size; // Кол-во элементов
	Node<T>* head; // Указатель на первый элемент

	onesidedList()
	{
		Size = 0;
		head = nullptr;
	}
	~onesidedList()
	{
		clear();
	}

	void push_back(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* current = this->head; // текущий узел, изначально head
			while (current->pNext != nullptr) // нахождение последнего узла
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}

		Size++;
	} // добавить в конец

	void push_front(T data)
	{
		head = new Node<T>(data, head);
		Size++;
	}

	void insert(T data, int index)
	{
		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node<T>* previous = this->head; // узел перед тем куда нужно добавить

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}

			Node<T>* newNode = new Node<T>(data, previous->pNext);
			previous->pNext = newNode;

			Size++;
		}
	}

	void removeAt(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node<T>* previous = head;
			Node<T>* toDelete;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			toDelete = previous->pNext;

			previous->pNext = toDelete->pNext;
			delete toDelete;

			Size--;
		}
	}

	void pop_back()
	{
		removeAt(Size - 1);
	}

	T getByIndex(int index)
	{
		int counter = 0; // индекс текущего узла (счётчик)
		Node<T>* current = this->head; // текущий узел

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

	void pop_front()
	{
		Node<T>* temp = head; // временный узел

		head = head->pNext;

		delete temp;

		Size--;
	}

	void clear()
	{
		while (Size != 0)
		{
			pop_front();
		}
	}
};

