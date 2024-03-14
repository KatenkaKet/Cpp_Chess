#include "subj.h"


const char * const TypeName[] = {"(unknown)", "King", "Queen", "Rook", "Elephant", "Horse", "Pawn"};
const char * const FigureColor[] = {"(unknown)", "black", "white"};

class King;

class King : public Base{
	public:
		int Attack(int x, int y) override;
};

class Queen : public Base{
	public:
		virtual int Attack(int x, int y);
};

class Rook : public Base{
	public:
		virtual int Attack(int x, int y);
};

class Elephath : public Base{
	public:
		virtual int Attack(int x, int y);
};

class Horse : public Base{
	public:
		virtual int Attack(int x, int y);
};

class Pawn : public Base{
	public:
		virtual int Attack(int x, int y);
};

int Base::X(){
	return this->x;
}

int Base::Y(){
	return this->y;
}

Base& SubjList::operator[](int i){
	return *static_cast<Base*>(GetItem(i));
}

int SubjList::DoMenu(char * s[], int max){
	int i = 1;
	for (i = 1; i <= max; i++)
		printf("%d. %s\n", i , s[i]);
	printf(">");
	fflush(stdin);
	scanf("%d", &i);
	return i<1||i>max?0:i;
}

void SubjList::Print(void){
	int i = 0;
	SubjList &s = *this;
    for (i = 0; i < Count(); i++){
    	cout << i + 1 << "." << endl;
    	s[i].Print();
	}
      
}

void Base::Print(void){
    printf("%s:\n", (this->type > 0 && this->type <= 6) ? TypeName[this->type] : "unknown object!");
	printf("\tColor: %s\n", (this->c >= 0 && this->c <= 2 ) ? FigureColor[this->c] : "unknown color");
	printf("\tCoordinates:\n");
	printf("\t\tx: %d\n\t\ty: %d\n", this->x, this->y);
}

void SubjList::AddBase(Base *p){
	this->Add((Item *)p);
	p->Input();
}

void Base::Input(){
	int x, y;
	SubjList s;
	color cc;
	
	cc = (color)s.DoMenu((char **)FigureColor, 2);
	this->c = cc;
	
	do{
		printf("Enter x coordinate: \n>");
		scanf("%d", &x);
	}while(x<1 || x >8);
	this->x = x;
	do{
		printf("Enter y coordinate: \n>");
		scanf("%d", &y);
	}while(y<1 || y >8);
	this->y = y;
}

const bool Base::operator ==(color i){
	return this->Color() == i;
}


void SubjList::SearchByColor(){
	color cc;
	SubjList &s = *this;
	int i = 0;

	if(this){
		if(this->Head()){
			cc = (color)DoMenu((char **)FigureColor, 2);
			for(i = 0; i < Count(); i++){
				if(s[i] == cc){
					s[i].Print();
				}
			}
		}
		else{
			cout << "List is empty." << endl;
		}
	}
	else{
		cout << "ERROR: wrong list!" << endl;
	}	
}

void SubjList::Attack(int i){
	Item *p;
	Base *b;
	int x, y;
	int j;
	SubjList &s = *this;
	do{
		printf("Enter x coordinate: \n>");
		scanf("%d", &x);
	}while(x<1 || x >8);
	do{
		printf("Enter y coordinate: \n>");
		scanf("%d", &y);
	}while(y<1 || y >8);
	
	int count = 0;
	if(this){
		if(this->Head()){
			for(j = 0; j < Count(); j++){
				if(i == s[j].Attack(x, y)){
					s[j].Print();
					count++;
				}
			}
		}
		else{
			printf("List is empty.\n");
		}
	}
	else{
		printf("ERROR: wrong list!\n");
	}
	if (!count)
		cout << "Таких фигур нет" << endl;
	
}

//int Base::Attack(int x, int y){
//	switch(this->Type()){
//		case ItKing:
//			return ((King *) this)->Attack(x, y);
//		case ItQueen:
//			return ((Queen *)this)->Attack(x, y);
//		case ItRook:
//			return ((Rook *)this)->Attack(x, y);
//		case ItElephath:
//			return ((Elephath *)this)->Attack(x, y);
//		case ItHorse:
//			return ((Horse *)this)->Attack(x, y);
//		case ItPawn:
//			return ((Pawn *)this)->Attack(x, y);
//		}
//}

int King::Attack(int x, int y){
	if(this->X() == x && (this->Y()+1 == y || this->Y()-1 == y))
		return 1;
	else if(this->X()+1 == x && (this->Y()+1 == y || this->Y() == y || this->Y()-1 == y))
		return 1;
	else if(this->X()-1 == x && (this->Y()+1 == y || this->Y() == y || this->Y()-1 == y))
		return 1;
	else
		return 0;
}

int Queen::Attack(int x, int y){
	if(this->X() == x && this->Y() != y)
		return 1;
	else if(this->X() != x && this->Y() == y)
		return 1;
	else if(abs(this->X() - x)== abs(this->Y()-y))
		return 1;
	else
		return 0;
}

int Rook::Attack(int x, int y){
	if(this->X() == x && this->Y() != y)
		return 1;
	else if(this->X() != x && this->Y() == y)
		return 1;
	else
		return 0;
}

int Elephath::Attack(int x, int y){
	if(abs(this->X() - x)== abs(this->Y()-y))
		return 1;
	else
		return 0;
}

int Horse::Attack(int x, int y){
	if(this->X()+1 == x && this->Y()+2 == y)
		return 1;
	else if(this->X()+2 == x && this->Y()+1 == y)
		return 1;
	else if(this->X()+2 == x && this->Y()-1 == y)
		return 1;
	else if(this->X()+1 == x && this->Y()-2 == y)
		return 1;
	else if(this->X()-1 == x && this->Y()-2 == y)
		return 1;
	else if(this->X()-2 == x && this->Y()-1 == y)
		return 1;
	else if(this->X()-2 == x && this->Y()+1 == y)
		return 1;
	else if(this->X()-1 == x && this->Y()+2 == y)
		return 1;
	else
		return 0;
}

int Pawn::Attack(int x, int y){
	if(this->X()+1 == x && this->Y()+1 == y)
		return 1;
	else if (this->X()-1 == x && this->Y()-1 == y)
		return 1;
	else
		return 0;
}


int SubjList::sort(){
	int size = this->Count();
	if (size == 0 || size == 1)
		return 0;
	int i = 0;
	SubjList K;
	Item * temp;
	for(i = 0; i <size; i++){
		K.Add(this->sorting());
	}
	size = K.Count();
	
	for(i = 0; i < size; i++){
		temp = K.Remove(0);
		this->Add(temp);
	}
}

const bool Base::operator <(Base& s){
	return (int)this->Type() < s.Type();
}

Item * SubjList::sorting(){
	int i, count = 0;
	Item * res = NULL;
	//int min = (int)((Base *)this->Head())->type;
	SubjList &s = *this;
	
	for(i = 0; i < Count(); i++){
		if(s[i] < s[count]){
			count = i;
//			min = (int)s[i].Type();
		}
	}
	res = this->Remove(count);
	return res;
}


Base * create(ItemType t){
	Base *temp = NULL;
	switch(t){
		case ItKing:
			temp = new King;
			break;
		case ItQueen:
			temp = new Queen;
			break;
		case ItRook:
			temp = new Rook;
			break;
		case ItElephath:
			temp = new Elephath;
			break;
		case ItHorse:
			temp = new Horse;
			break;
		case ItPawn:
			temp = new Pawn;
			break;
		}
	if(temp){
		temp->type = t;
	}
	return temp;
}




