#include "linkedlist.h"

int main()
{
    //example linked list
    
    Employee employee1("dell", "jason", 10, "programmer");
    Employee employee2("dell", "jason", 80, "janitor");
    Node node1(employee1.GetCompany(), employee1.GetName(), employee1.GetID(), employee1.GetJob());
    Node node2(employee2.GetCompany(), employee2.GetName(), employee2.GetID(), employee2.GetJob());
    Node node3("dell", "jeff muffins", 1, "ceo");

    LinkedList ll;
    ll.insert(node1);
    ll.insert(node2);
    ll.insert(node3);
    cout << "linked list 1: " << endl;
    ll.print();
    LinkedList ll2;
    ll2 = ll;
    LinkedList ll3(ll2);
    ll2.insert(node1);
    cout << endl << "linked list 2: " << endl;
    ll2.print();
    cout << endl << "linked list 3: " << endl;
    ll3.print();

    return 0;
}