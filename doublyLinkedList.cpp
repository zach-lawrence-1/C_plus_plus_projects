#include<iostream>

class doublyLinkedList
{
private:
	//private as we don't want the user to be able to modify these outside the class
	doublyLinkedList* m_head = NULL;
	doublyLinkedList* m_tail = NULL;
public:
	const int BACKWARD = 0;
	const int FORWARD = 1;
	int data;
	doublyLinkedList* next = NULL;
	doublyLinkedList* prev = NULL;

	//adds node to end of doubly linked list
	void addNode(int val)
	{
		doublyLinkedList* tmp = new doublyLinkedList;
		tmp->data = val;
		if (m_head == NULL)
		{
			m_head = tmp;
			return;
		}
		doublyLinkedList* temp1 = m_head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = tmp;
		tmp->prev = temp1;
		m_tail = tmp;
	}
	
	//prints doubly linked list either backward or forward based on what user wants
	void printList(int direction)
	{
		if (direction == BACKWARD)
		{
			std::cout << "backward\n";
			doublyLinkedList* temp1 = m_tail;
			while (temp1->prev != NULL)
			{
				std::cout << temp1->data << " --> ";
				temp1 = temp1->prev;
			}
			std::cout << temp1->data << std::endl;
			return;
		}
		std::cout << "forward\n";
		doublyLinkedList* temp1 = m_head;
		while (temp1->next != NULL)
		{
			std::cout << temp1->data << " --> ";
			temp1 = temp1->next;
		}
		std::cout << temp1->data << std::endl;
	}
};

int main()
{
	doublyLinkedList list1;
	list1.addNode(1);
	list1.addNode(2);
	list1.addNode(3);
	list1.printList(list1.FORWARD);
	list1.printList(list1.BACKWARD);
}