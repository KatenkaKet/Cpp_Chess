#include <iostream>
//#include<conio.h>
#include "subj.h"
#include<locale.h>
using namespace std;

const char * const Menu[] = {"none", "�������� ������", "������� ������", "������� ������ �����",
							"���������� ����� �� �����", "����� ����� �� �����", 
							"����� �����, ������� ���� ������ � ��������� ������������",
							"����� �����, ������� �� ���� ������ � ��������� ������������",
							"�������� ������",	"����� ����� ������ �� � ������",
							"�����"};
# define N 10 //���������� ������� ����

const char * const TypeName[] = {"(unknown)", "King", "Queen", "Rook", "Elephant", "Horse", "Pawn"};

int main()
   {
   	
   	setlocale(LC_ALL, "Russian");
    //char c;       // ��� ����� ������ ����
    Base *p;     // ������� ���������
    //DebugList L;  // ������ ������
    SubjList L;
    int n;
    int c;
    ItemType t;
    /*
    	L - �������� ������, ������� �� ����������� �������������,
    	� ��� ���������� (���� �� ����������) ��������� ������� c�����,
    	�.�. ����������� ���� ���������
    */
    
    do
    {
       c = L.DoMenu((char **)Menu, N);
       switch (c)
       {
        case 1:   // �������� ������
        	t = (ItemType)L.DoMenu((char **)TypeName, 6);
        	p = create(t);
            L.AddBase(p);
            break;
        case 2:  // ������� ������
        	if (L.Count()){
	        	L.Print();
	        	cout << "������� ����� ������, ������� ������ �������\n>";
	        	cin >> n;
	        	L.Delete(n-1);
			}
        	else
        		cout << "������ ����." << endl;
        	break;
        case 3:  // ������� ������ �����
        	if (L.Count())
        		L.Print();
        	else
        		cout << "������ ����." << endl;
        	break;
        case 4:  // ���������� ����� �� �����
        	L.sort(); 
        	L.Print();
        	break;
        case 5:  // ����� ����� �� �����
        	L.SearchByColor();
        	break;
        case 6:  // ����� �����, ������� ���� ������ � ��������� ������������          
        	L.Attack(1);
        	break;  
        case 7:  // ����� �����, ������� �� ���� ������ � ��������� ������������
        	L.Attack(0);
        	break;
        case 8:  // �������� ������
        	L.Clear();
            break;
        case 9: // ����� ����� ������ �� � ������
            L.Print();
			cout << "�������� �����: " << endl;
			cin >> n;
			p = (Base *)L.GetItem(n-1);
			if(p)
				p->Print();
            break;
       }
    }while (c != 10); 
   return 0;
   }
   
   
   
   
