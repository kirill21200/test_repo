#pragma once
template<typename T>
class Node // описание элемента списка
{
public:
	Node *pNext; // ссылка на следующий элемент
	T data; // значение элемента
	Node(T data = T(), Node *pNext = nullptr) // значения по умолчанию
	{
		this->data = data;
		this->pNext = pNext;
	}
};

