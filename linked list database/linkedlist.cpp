#include "linkedlist.h"

//node

Node::Node() : next(nullptr), data() {}

Node::Node(string company, string name, int id, string job) : data(company, name, id, job), next(nullptr) {}

//operator overload for < to compare nodes for sorting purposes
bool Node::operator<(const Node& node)
{
	return this->data < node.data;
}

//linkedlist

LinkedList::LinkedList() : head(nullptr) {}

//copy constructor
LinkedList::LinkedList(const LinkedList& source) : head(nullptr)
{
	Node* tempSourceNode = source.head;
	Node* tempCurrNode = nullptr;
	if (tempSourceNode == nullptr)
	{
		return;
	}
	
	else
	{
		head = new Node(tempSourceNode->data.GetCompany(), tempSourceNode->data.GetName(), 
        tempSourceNode->data.GetID(), tempSourceNode->data.GetJob());

		tempCurrNode = head;
		tempSourceNode = tempSourceNode->next;
	}

	/* go through source linked list and make new nodes for every node that exists in source and then copy data values
	for all new nodes */
	while (tempSourceNode != nullptr)
	{
		//make new node of current temp source node and then change temp source node to next followed by making
		//the new node the next node in the new linked list
		Node* newNode = new Node(tempSourceNode->data.GetCompany(), tempSourceNode->data.GetName(), 
        tempSourceNode->data.GetID(), tempSourceNode->data.GetJob());

		tempSourceNode = tempSourceNode->next;
		tempCurrNode->next = newNode;
		tempCurrNode = tempCurrNode->next;
	}
}

//returns linked list object reference and sets current object to object passed in and is a copy assignment operator
LinkedList& LinkedList::operator=(const LinkedList& source)
{
    //prevent self assignment
    if (this != &source)
    {
        //deallocate current memory to prevent leaks
        this->clear();

        Node* tempSourceNode = source.head;
        Node* tempCurrNode = nullptr;
        
        if (source.head == nullptr)
        {
            return *this;
        }
        
        else
        {
            head = new Node(tempSourceNode->data.GetCompany(), tempSourceNode->data.GetName(), 
            tempSourceNode->data.GetID(), tempSourceNode->data.GetJob());

		    tempCurrNode = head;
		    tempSourceNode = tempSourceNode->next;
        }

        //allocate memory and copy values
        //go through each node until it reaches the end
        while (tempSourceNode != nullptr)
        {
            Node* newNode = new Node(tempSourceNode->data.GetCompany(), tempSourceNode->data.GetName(), 
            tempSourceNode->data.GetID(), tempSourceNode->data.GetJob());
    
		    tempSourceNode = tempSourceNode->next;
		    tempCurrNode->next = newNode;
		    tempCurrNode = tempCurrNode->next;
        }
    }
    
    return *this;
}

//destructor
LinkedList::~LinkedList() 
{
    if (this->head == nullptr)
    {
        return;
    }
    clear();
    this->head = nullptr;
}

//go through linked list and delete all nodes
void LinkedList::clear()
{
    Node* tempNode = this->head;
    Node* nextNode = nullptr;

    if (this->head == nullptr)
    {
        return;
    }

    while (tempNode != nullptr)
    {
        nextNode = tempNode->next;
        delete tempNode;
        tempNode = nextNode;
    }
}

//inserts new node into correct position in sorted list
void LinkedList::insert(Node& node)
{
    Node* newNode = new Node(node.data.GetCompany(), node.data.GetName(), node.data.GetID(), node.data.GetJob());

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	//only one node in linked list so you must determine which one is greater which will be the next node
	else if (head->next == nullptr)
	{
		if (newNode->operator<(*head))
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		
		head->next = newNode;
		newNode->next = nullptr;
		return;
	}

	//more than one node exists
	Node* tempNode = head;
	Node* nextNode = tempNode->next;

	//new node is less than head so it will become new head
	if (newNode->operator<(*head))
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	while (nextNode != nullptr)
	{
		if (nextNode->operator<(*newNode))
		{
			tempNode = tempNode->next;
			nextNode = nextNode->next;
			continue;
		}
		//temp node is greater so it is time to insert new node before it
		tempNode->next = newNode;
		newNode->next = nextNode;
		return;
	}
	tempNode->next = newNode;
	newNode->next = nullptr;
	return;
}

//prints linked list
void LinkedList::print()
{
    Node* tempNode = this->head;

    if (this->head == nullptr)
    {
        return;
    }

    int i = 0;
    while (tempNode != nullptr)
    {
        i++;
        cout << "Node " << i << ": " << tempNode->data.GetCompany() << " " << tempNode->data.GetName() << " " << 
        tempNode->data.GetID() << " " << tempNode->data.GetJob() << endl;
        tempNode = tempNode->next;
    }
}