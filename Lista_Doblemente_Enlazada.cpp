#include <iostream>
#include <conio.h>

using namespace std;
//using namespace System;

int RandomN(int min, int max) {
	//Random r;
	int n = 10;//r.Next(min, max);
			   //System::Threading::Thread::Sleep(5);
	return n;
}

struct Nodo
{
	int elem;
	Nodo* prev;
	Nodo* next;
	Nodo(int elem, Nodo* prev = nullptr, Nodo* next = nullptr) : elem(elem), prev(prev), next(next) {};
	void setElem(int elem) { this->elem = elem; }
};

class List
{
private:
	Nodo* head;
	int lon;

public:
	List() {
		lon = 0;
	}
	~List() {}
	int longitud() {
		return lon;
	}
	bool esVacia() {
		return lon == 0;
	}
	void AddToStart(int elem) {
		head = new Nodo(elem, head->prev, head);
		lon++;
	}
	void AddLast(int elem) {
		Add(elem, lon + 1);
	}
	void Add(int elem, int pos) {
		if (pos == 1) {		//se considera al elemento 1 como el primero de la lista
			AddToStart(elem);
			return;
		}
		auto aux = head;
		for (int i = 1; i < pos - 1; i++) {
			aux = aux->next;
		}
		aux->next = new Nodo(elem, aux, aux->next);
		lon++;
	}
	void PrintList() {
		auto aux = head;
		for (int i = 1; i < lon; i++) {
			cout << aux->elem << " | ";
			aux = aux->next;
		}
	}
	void InitializeRandom() {
		lon = RandomN(5, 16);
		head = new Nodo(RandomN(0, 101));
		auto aux = head->next;
		auto aux2 = head;
		for (int i = 1; i < lon; i++) {
			aux = new Nodo(RandomN(0, 101), aux2);
			aux2->next = aux;
			aux = aux->next;
			aux2 = aux2->next;
		}
	}
	void eliminaInicio() {
		if (lon > 0) {
			Nodo * aux = head;
			head = head->next;
			delete aux;
			lon--;
		}
	}
	void eliminaPos(int pos) {
		Nodo * aux = head;
		Nodo * aux2 = head->next;
		for (int i = 1; i < pos; i++) {
			if (i < pos - 1) {
				aux = aux->next;
				aux2 = aux2->next;
			}
		}
		if (pos != lon) {
			Nodo * aux3 = aux2->next;
			aux3->prev = aux;
		}
		aux->next = aux2->next;

		delete aux2;
		lon--;
	}
	void eliminaFinal() {
		eliminaPos(lon);
	}
	void Modificar(int elem, int pos) {
		auto aux = head;
		for (int i = 1; i < pos - 1; i++) {
			aux = aux->next;
			if (i == pos - 2)
			{
				aux->next = new Nodo(elem, aux, aux->next);
			}
		}
	}
	int Buscar(int pos) {
		auto aux = head;
		for (int i = 0; i < pos - 1; i++)
		{
			aux = aux->next;
			if (i == pos - 2)
			{
				return aux->elem;
			}
		}
	}
};

int main() {

	List* l = new List();
	l->InitializeRandom();
	l->PrintList();
	int elem = 858, pos = 8;
	int elem2 = 523, pos2 = 4;
	int pos3 = 4;
	l->Add(elem, pos);

	cout << "\n\nAgregar " << elem << " en la posicion " << pos << "\n\n";
	l->AddLast(20);

	cout << "\n\nAgregar " << elem2 << " en la posicion " << pos2 << "\n\n";
	l->Modificar(elem2, pos2);

	l->PrintList();

	cout << endl << "Buscar Pos: " << pos3 << " El elemento es: " << l->Buscar(pos3) << "\n\n";

	cout << endl << "Longitud: " << l->longitud();
	_getch();
	return 0;
}