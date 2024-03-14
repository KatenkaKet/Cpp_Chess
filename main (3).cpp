#include <iostream>
//#include<conio.h>
#include "subj.h"
#include<locale.h>
using namespace std;

const char * const Menu[] = {"none", "Добавить фигуру", "Удалить фигуру", "Вывести список фигур",
							"Сортировка фигур по рангу", "Поиск фигур по цвету", 
							"Поиск фигур, которые бьют клетку с заданными координатами",
							"Поиск фигур, которые не бьют клетку с заданными координатами",
							"Очистить список",	"Вывод одной фигуры по её номеру",
							"Выход"};
# define N 10 //количество пунктво меню

const char * const TypeName[] = {"(unknown)", "King", "Queen", "Rook", "Elephant", "Horse", "Pawn"};

int main()
   {
   	
   	setlocale(LC_ALL, "Russian");
    //char c;       // для ввода пункта меню
    Base *p;     // рабочий указатель
    //DebugList L;  // объект списка
    SubjList L;
    int n;
    int c;
    ItemType t;
    /*
    	L - стековый объект, поэтому он уничтожится автоматически,
    	а его деструктор (если он реализован) обеспечит очистку cписка,
    	т.е. уничтожение всех элементов
    */
    
    do
    {
       c = L.DoMenu((char **)Menu, N);
       switch (c)
       {
        case 1:   // Добавить фигуру
        	t = (ItemType)L.DoMenu((char **)TypeName, 6);
        	p = create(t);
            L.AddBase(p);
            break;
        case 2:  // Удалить фигуру
        	if (L.Count()){
	        	L.Print();
	        	cout << "Введите номер фигуры, которую хотите удалить\n>";
	        	cin >> n;
	        	L.Delete(n-1);
			}
        	else
        		cout << "Список пуст." << endl;
        	break;
        case 3:  // Вывести список фигур
        	if (L.Count())
        		L.Print();
        	else
        		cout << "Список пуст." << endl;
        	break;
        case 4:  // Сортировка фигур по рангу
        	L.sort(); 
        	L.Print();
        	break;
        case 5:  // Поиск фигур по цвету
        	L.SearchByColor();
        	break;
        case 6:  // Поиск фигур, которые бьют клетку с заданными координатами          
        	L.Attack(1);
        	break;  
        case 7:  // Поиск фигур, которые не бьют клетку с заданными координатами
        	L.Attack(0);
        	break;
        case 8:  // Очистить список
        	L.Clear();
            break;
        case 9: // Вывод одной фигуры по её номеру
            L.Print();
			cout << "Выберите номер: " << endl;
			cin >> n;
			p = (Base *)L.GetItem(n-1);
			if(p)
				p->Print();
            break;
       }
    }while (c != 10); 
   return 0;
   }
   
   
   
   
