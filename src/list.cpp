#include "list.h"


ostream & operator<<(ostream & os, const List & l)
{
	Node *temp = l.head;
	while (temp != NULL)
	{
		os << temp->data << " ";
		temp = temp->next;
	}
	os << endl;
	return os;
}

Node::Node(const Node & node2)
{
	data = node2.data;
	next = node2.next;
}

Node & Node::operator=(const Node & next2)
{
	data = next2.data;
	next = next2.next;
	return *this;
}

bool Node::operator==(const Node & node2) const
{
	if ((data == node2.data) && (next == node2.next))
		return true;
	else return false;
}

List::List(const List& list2)
{
	if (list2.head != NULL)
	{
		head = new Node(list2.head->data);
		Node *res = head;
		Node *res2 = list2.head->next;
		while (res2 != NULL)
		{
			res->next = new Node(res2->data);
			res = res->next;
			res2 = res2->next;
		}
	}
	else
		head = NULL;
}
List::List(const Node& list2)
{
	head = new Node(list2);
}


List & List::operator=(const List & list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head != NULL)
		{
			head = new Node(list2.head->data);
			Node *res = head;
			Node*res2 = list2.head->next;
			while (res2 != NULL)
			{
				res->next = new Node(res2->data);
				res = res->next;
				res2 = res2->next;
			}
		}
	}
	return *this;
}

List::~List()
{
	Node *res = head;
	Node *res2 = head;
	if (res != NULL)
	{
		while (res->next != NULL)
		{
			res2 = res->next;
			delete res;
			res = res2;
		}
		delete res;
	}
}

void List::InsertToHead(const DataType& d)
{
	Node *res = new Node(d);
	res->next = head;
	head = res;
}

void List::InsertToTail(const DataType& d)
{
	Node* res = head;
	if (res != NULL)
	{
		while (res->next != NULL)
			res = res->next;
		res->next = new Node(d);
	}
	else
		head = new Node(d);
}

void List::InsertAfter(Node* node, const DataType& d)
{

	if (head == NULL)
		throw "Head null";
	if (node != NULL)
	{
		Node* res = new Node(d, node->next);
		node->next = res;
	}
}

Node* List::Search(const DataType& d)
{
	Node* res = head;
	if (res != NULL)
	{
		while ((res->next != NULL) && (res->data != d))
		{
			res = res->next;
		}
		if (res->data == d)
			return res;
		else
			return NULL;
	}
	else
		return NULL;
}

void List::Clean()
{
	Node *res = head;
	Node *res2 = head;
	if (res != NULL)
	{
		while (res->next != NULL)
		{
			res2 = res->next;
			delete res;
			res = res2;
		}
		delete res;
		head = NULL;
	}
}

int List::GetSize()
{
	int size = 0;
	Node *res = head;
	while (res != NULL)
	{
		size++;
		res = res->next;
	}
	return size;
}

void List::Delete(const DataType& d)
{
	Node* res = head, *res2 = head;
	if (res != NULL) {
		while ((res->next != NULL) && (res->data != d))
		{
			res2 = res;
			res = res->next;
		}
		if (res->data == d)
		{
			res2->next = res->next;
			if (res == head)
				head = head->next;
			delete res;
		}
	}
}

void List::Inverse()
{
	if (head != NULL)
	{
		Node *res = head;
		Node *res2 = NULL;
		Node *res3 = head->next;
		if ((res != NULL) && (res->next != NULL))
		{
			do
			{
				res3 = res->next;
				res->next = res2;
				res2 = res;
				res = res3;
			} while (res != NULL);
			head = res2;
		}
	}
}

List List::Merge(Node * node, const List & list2)
{
	if (head != NULL)
	{
		List l(head->data);
		Node* res = l.head;
		Node* res2 = head;
		while ((res2->next != NULL) && (res2 != node))
		{
			res->next = new Node(res2->next->data);
			res = res->next;
			res2 = res2->next;
		}
		if (node != NULL)
		{
			Node* res3 = list2.head;
			while (res3 != NULL)
			{
				res->next = new Node(res3->data);
				res = res->next;
				res3 = res3->next;
			}
			while (res2->next != NULL)
			{
				res->next = new Node(res2->next->data);
				res = res->next;
				res2 =res2->next;
			}
		}
		return l;
	}
	else
	{
		return List();
	}
}

List List::Merge(const List & list2)
{
	if (head != NULL)
	{
		List l(head->data);
		Node *res = head->next;
		Node *res2 = l.head;
		while (res != NULL)
		{
			res2->next = new Node(res->data);
			res = res->next;
			res2 = res2->next;
		}
		res = list2.head;
		while (res != NULL)
		{
			res2->next = new Node(res->data);
			res = res->next;
			res2 = res2->next;
		}
		return l;
	}
	else
	{
		List l(list2);
		return l;
	}
}

bool List::operator==(const List & list2) const
{
	Node *temp = head;
	Node *temp2 = list2.head;
	bool f = true;
	while ((temp != NULL) && (temp2 != NULL) && (f))
	{
		if (temp->data != temp2->data)
			f = false;
		temp = temp->next;
		temp2 = temp2->next;
	}
	if ((temp != NULL) || (temp2 != NULL))
		f = false;
	return f;
}

