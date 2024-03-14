//#include <сmath>
#include <cstdlib>
#include "list.h"


class Base;
class SubjList;


enum ItemType{ItNone, ItKing, ItQueen, ItRook, ItElephath, ItHorse, ItPawn};
enum color{ItNope, black, white};

Base * create(ItemType t);

class Base : public Item{
	friend SubjList;
	private:
		int x;              // координата по оси х
		int y;              // координата по оси у
	public:
		Base(){
			type = ItNone;
			c = ItNope;
			x = 0;
			y = 0;
		}
		enum color c;   // цвет фигуры
		enum ItemType type; // ранг фигуры
		void Print();
		void Input();
		int X();
		int Y();
		virtual int Attack(int x, int y) = 0;
		ItemType Type(){
			return this->type;
		}
		color Color(){
			return this->c;
		}
		const bool operator <(Base& s); //сравнение структур по рангу
		const bool operator ==(color i); // сравнение по цвету
		
};

class SubjList : public List{
	friend Base;
	//friend void Base::Input();
	public:
		void Print();
		void AddBase(Base *p);
		int DoMenu(char * s[], int max);
		void SearchByColor();
		void Attack(int i);
		int sort();
		Item * sorting();
		Base& operator[](int i);
		
};

struct coordinates{
	public:
		int x;
		int y;
};












