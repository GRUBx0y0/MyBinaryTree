// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;                         

template<typename T>                      //Шаблонный класс бинарного дерева
class BinaryTree
{
private:

	template<typename T>
	class Node
	{
	public:

		Node *pNext_left, *pNext_right;
		T data;
		int index;

		Node(T data = T(), int index = 0, Node *pNext = nullptr, Node *pPrev = nullptr)        //Класс одного узла дерева
		{
			this->data = data;
			this->pNext_left = pNext;
			this->pNext_right = pPrev;
			this->index = index;
		}
	};


	int Size;
	Node<T> *head;

public:

	BinaryTree();                             //Конструктор
	void add_element(int index, T data);      //Функция добавить элемент
	T read_index(int index);
	void show(Node<T> *element);
	void show();

};


template<typename T>
BinaryTree<T>::BinaryTree()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
T BinaryTree<T>::read_index(int index)
{
	Node<T> *current = head;

	bool spec = true;        //flag

	while (spec)
	{
		if (index == current->index)
		{
			return(current->data);
		}

		if (current->pNext_left == nullptr && current->pNext_right == nullptr)
		{
			spec = false;
		}

		else
		{
			spec = false;

			if (current->index < index)
			{

				if (current->pNext_right != nullptr)
				{
					spec = true;
					current = current->pNext_right;
				}

			}

			else
			{

				if (current->index > index)
				{

					if (current->pNext_left != nullptr)
					{
						current = current->pNext_left;
						spec = true;
					}

				}

			}

		}
	}

	return 0;

}

template<typename T>
void BinaryTree<T>::show(Node<T> *element)
{

	cout << element->index << ": " << element->data << "\n\n";

	if(element->pNext_left != nullptr)
	{
		show(element->pNext_left);
	}

	if (element->pNext_right != nullptr)
	{
		show(element->pNext_right);
	}

}

template<typename T>
void BinaryTree<T>::show()
{
	show(head);
}







template<typename T>
void BinaryTree<T>::add_element(int index, T data)
{
     if(Size == 0)
	 {
		 head = new Node<T>(data, index);
		 Size++;  //Увеличиваем размер дерева на 1
	 }

	 else
	 {
		 Node<T> *current = this->head;

		 bool spec = true;        //Флаг, который отвечает за продолжение поиска в while()
		 bool isnew = true;
		 
		 while (spec)
		 {
			 if (current->index == index)            //Если элемент уже существует, то просто заменяем данные по искомому индексу
			 {
				 spec = false;
				 current->data = data;
				 isnew = false;
			 }

			 else
			 {

				 if (current->pNext_left == nullptr && current->pNext_right == nullptr)             //Проверяем, есть ли вообще у узла ветки
				 {
					 spec = false;
				 }

				 else
				 {
					 spec = false;                          //Ставим переключатель на 0, чтобы выполнение while продолжилось, нужно, чтобы он еще заработал 1

					 if (current->index < index)    
					 {

						 if (current->pNext_right != nullptr)
						 {
							 spec = true;
							 current = current->pNext_right;
						 }

					 }

					 else
					 {

						 if (current->index > index)
						 {

							 if (current->pNext_left != nullptr)
							 {
								 current = current->pNext_left;
								 spec = true;
							 }

						 }

					 }

				 }
			 }
		 }

		 if (isnew)
		 {

			 if (current->index < index)                            //Выбираем, куда отправить данные и где создать новый узел
			 {
				 current->pNext_right = new Node<T>(data, index);
			 }

			 else
			 {
				 current->pNext_left = new Node<T>(data, index);
			 }

			 Size++;  //Увеличиваем размер дерева на 1
		 }
	 }

	
}



int main()
{
	BinaryTree<int> MyTree;

	MyTree.add_element(5, 0);   
	MyTree.add_element(7, 11);  //Направо
	MyTree.add_element(2, 0);  //Налево
	MyTree.add_element(3, 3);  //Налево Направо
	MyTree.add_element(6, 3);   //Направо Направо
	MyTree.add_element(11, 3);   //Направо Направо
	MyTree.add_element(11, 4);   //Направо Направо
	
	MyTree.add_element(1, *" ");
	
     
	MyTree.show();

	system("PAUSE");

    return 0;
}


