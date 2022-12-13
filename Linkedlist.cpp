#include<iostream>

struct linked_list
{
	//value of current node
	int val;
	//pointer to next node
	linked_list* next = NULL;
};

//doesn't have to be called head, but for this example of linked list implementation
//I decided to name it head for clarity. If you wanted to make multiple linked lists
//you can name them different things.
//you would also need to slightly modify the addNode and printList functions below
//and add in a parameter so you can modify specific lists
linked_list* head;

//adds new nodes to linked list
void addNode(int num)
{
	//creates new node with given parameter
	linked_list* tmp = new linked_list;
	tmp->val = num;
	tmp->next = NULL;

	//if head value isn't set, created node is set to be the head node
	if (head == NULL)
	{
		head = tmp;
	}
	//otherwise, traverse the linked list until it reaches a node with no next value and then set
	//last nodes next value to newly created node
	else
	{
		//traverses linked list via a copy of the head node and goes until it hits an empty next node val
		linked_list* temp1 = head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		//adds newly created node to the end of the list
		temp1->next = tmp;
	}
}

//prints current linked list
void printList()
{
	linked_list* temp1 = head;
	while (temp1->next != NULL)
	{
		std::cout << temp1->val << " --> ";
		temp1 = temp1->next;
	}
	std::cout << temp1->val << std::endl;
}

int main()
{
	addNode(2);
	printList();

	addNode(3);
	printList();

	addNode(4);
	printList();
}