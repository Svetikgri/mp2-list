#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
  DataType data;
  Node* next;
  // здесь могут быть конструкторы, методы, деструктор Node
    Node(DataType _data = 0, Node* _next = NULL){
		data = _data;
		next = _next;
}
	~Node() {};
	Node(const Node &node2);
	Node& operator =(const Node& next);
bool operator==(const Node& node2) const;
};

class List
{
  // любые поля
	Node* head;
public:
  List() { head = NULL; };
  
  List(const List& list2);
  List& operator=(const List& list2);
  ~List();
  List(const Node &temp);
  

  void InsertToHead(const DataType& d); // вставить элемент d первым
  void InsertToTail(const DataType& d); // вставить элемент d последним
  void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node
  void Delete(const DataType& d); // удалить звено со значением data = d
  Node* Search(const DataType& d); // найти указатель на звено со значением data = d
  void Clean(); // удалить все звенья
  int GetSize(); // узнать число звеньев в списке
  Node* GetHead() { return head; } // получить указатель на первое звено списка

  void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
  List Merge(Node* node, const List& list2); // создать список3, добавив список2 в текущий список после указателя node  
  List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

  friend ostream& operator<<(ostream& os, const List& l);
  bool operator==(const List& list2) const;// списки равны, если элементы в них идут в одинаковом порядке

};
#endif


struct TMonom
{
	double coef;
	unsigned abc;
};

typedef TMonom TKey

	class TLink
	{
	public:
		TKey Key;
		TLink pNext;
	};

	class TRingList
	{
	private:
		TLink* head;
		TLink* cur;
	public:
		TRingList();//конструктор создает голову
		TRingList(const TRingList &);// конструктор копирования
		~TRingList;//
		int Reset();//указатель на текущий
		int GetNext();// получить след эл-т
		int IsEnded();//дошли ли до конца
	};
	 
	class TPolinom
	{
	private:
		TRingList* list;
	public:
		TPolinom(const std string);//конструктор с параметром
		TPolinom(const TPolinom);//констуктор копирования
		TPolinom();
	};
