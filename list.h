#include <iostream>

using namespace std;

class List;
class Item;

class List{
	private: 
		Item *head;
		Item *tail;
	public:
		List(){
			this->head = NULL;
			this->tail = NULL;
		}
		Item *Head();
		Item *Tail();
		void Add(Item *p);
		Item *GetItem(int n);
		int Count();
		int GetIndex(Item *p);
		void Clear();
		Item *Remove(int n);
		void Delete(int n);
		void Insert(Item *m, int n);
		~List(){
			Clear();
		}
};

class Item{
	friend List;
	private:
		Item *next;
		Item *prev;
	public:
		Item(){
			prev = NULL;
			next = NULL;
		}
		Item *Next();
		Item *Prev();
		virtual ~Item(){
		}		
};


