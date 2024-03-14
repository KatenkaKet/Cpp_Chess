#include "list.h"

Item *List::Head(){
	return this->head;
}

Item *List::Tail(){
	return this->tail;
}

Item *Item::Next(){
	return this->next;
}

Item *Item::Prev(){
	return this->prev;
}

void List::Add(Item *p){         // Метод добавления Item
	if (this->head == NULL){
		this->head = p;
		this->tail = p;
		p->next = NULL;
		p->prev = NULL;
	}
	else{
		p->next = NULL;
		p->prev = this->tail;
		this->tail->next = p;
		this->tail = p;
	}
}


Item *List::GetItem(int n){      // Поиск элемнета по его номеру
	int i = 0;
	Item *p;
	p = Head();
	while(p != 0){
		if (i == n){
			return p;
		}
		p = p->next;
		i++;
	}
	return NULL;
}

int List::Count(){              // Подсчёт количества элементов
	int i = 0;
	Item *p;
	p = Head();
	while(p != NULL){
		p = p->next;
		i++;
	}
	return i;
}

int List::GetIndex(Item *p){   // Определение индекса по указателю
	int i =0;
	Item *m;
	m = Head();
	while(m != NULL){
		if(m == p){
			return i;
		}
		m = m->next;
		i++;
	}
	return -1;
}

void List::Clear(){           // Очистка списка
	Item *p, *j = NULL;
	p = Head();
	while(p){
		j = p->next;
		delete p;
		p = j;
	}
	this->head = NULL;
	this->tail = NULL;
}


Item *List::Remove(int n){      // Исключение элемента
	Item *p;
	p = GetItem(n);
	if(p){
		if (Head() == p && p->next == NULL){
			this->head = NULL;
			this->tail = NULL;
		}
		else if(p->prev == NULL){
			this->head = p->next;
			this->head->prev = NULL;
		}
		else if(p->next == NULL){
			this->tail = p->prev;
			this->tail->next = NULL;
		}
		else{
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
	}
	return p;
}

void List::Delete(int n){        // Удаление элемнета
	Item *p;
	p = Remove(n);
	delete p;
}
/*
void List::Insert(Item *m, int n){   //Вставка элемента в заданную позицию
	Item *p;
	if (this->head == NULL){
		Add(m);
	}
	else if(n == 0){ 
		this->head->prev = m;
		m->next = this->head;
		m->prev = NULL;
		this->head = m;
		}
	else{
		p = GetItem(n-1);
		if (p == NULL || p->next == NULL){
			Add(m);
		}
		else{
				m->next = p->next;
				m->prev = p;
				p->next = m;
				m->next->prev = m;			
		}
	}
}
*/

void List::Insert(Item *m, int n){
	Item *p = GetItem(n);
	if (p==NULL){
		Add(m);
	}
	else{
		m->next = p;
		m->prev = p->prev;
		if(p->prev != NULL){
			p->prev->next = m;
		}
		else{
			this->head = m;
		}
		p->prev = m;
	}
}





