#include<iostream>
using namespace std;

class Lista_Int 
{
	struct Nodo 
	{
		int elem;
		Nodo *sig;
		Nodo *ant;
		Nodo(int elem, Nodo*ant, Nodo*sig):elem(elem),ant(ant), sig(sig){}
		~Nodo(){ }
	};

	// Atributos

	int cant; // Longitud
	Nodo*ini;
	Nodo* ult;

	// Constructor y Destructor

public: 
	Lista_Int():cant(0),ini(nullptr),ult(nullptr) {}
	~Lista_Int()
	{
		Nodo *aux;
		while(ini != nullptr)
		{
			aux = ini;
			ini = ini->sig;
			delete aux;
		}
	}


	int longitud() { return cant; }
	bool esVacia() { return cant == 0; }

	void insertarInicial(int elem) 
	{
		Nodo*ayuda;

		if (cant == 0)
		{
			 ayuda = new Nodo(elem, nullptr, nullptr);
			 ult = ayuda;
			 ini = ayuda;
		}
		else
		{
			ayuda = new Nodo(elem, nullptr, ini);
			ini->ant = ayuda;
			ini = ayuda;
		}
		cant++;
	}
	void insertarPos(int elem, int pos) {
		
		if (pos < 0 || pos > cant)
			return;

		else if (pos == 0)
			insertarInicial(elem);

		else if (pos == cant)
			insertarFinal(elem);
		else
		{
			Nodo* aux;
			Nodo*ayuda;

			if(pos<(cant/2))
			{
				aux = ini;

				for (int i = 1; i < pos; i++)
					aux = aux->sig;				
						
				ayuda = new Nodo(elem, aux, aux->sig);
		
				aux->sig->ant = ayuda;
				aux->sig = ayuda;
			}
			else 
			{
				aux = ult;

				for (int i = cant-1 ; i > pos; --i)
					aux = aux->ant;

				ayuda = new Nodo(elem, aux->ant, aux);

				aux->ant->sig = ayuda;
				aux->ant = ayuda;
			}		

			cant++;
		}
	}
	void insertarFinal(int elem) 
	{
		if (cant < 0)
			return;

		else if(cant == 0)
			insertarInicial(elem);

		else
		{
			Nodo*ayuda;

			ayuda = new Nodo(elem, ult, nullptr);

			ult->sig = ayuda;
			ult = ayuda;
			cant++;
		}
	}

	void modificarInicial(int elem)
	{
		if (cant > 0) ini->elem = elem;
	}
	void modificarPos(int elem,int pos)
	{
		if (pos<0 || pos>cant)
			return;
		
		else if (pos == 0)
			modificarInicial(elem);
		
		else if (pos == cant)
			modificarFinal(elem);
		
		else
		{
			Nodo* aux = ini;
			
			if (pos < (cant / 2))
			{
				aux = ini;

				for (int i = 0; i < pos; i++)
					aux = aux->sig;
			}
			else
			{
				aux = ult;

				for (int i = cant; i > pos; --i)
					aux = aux->ant;
			}
			aux->elem = elem;
		}
	}
	void modificarFinal(int elem) 
	{
		if (cant > 0)
			ult->elem = elem;
	}

	void eliminarInicial()
	{
		if (cant > 0)
		{
			Nodo* ayuda;
	
			if(cant == 1)
			{
				ayuda = ini;
				ini = nullptr;
				ult = nullptr;
			}

			else
			{
				ayuda = ini;
				ini = ini->sig;
				ini->ant = nullptr;
			}

			delete ayuda;
			cant--;
		
		}
	}
	void eliminarPos(int pos)
	{
		if (pos < 0 || pos >= cant)
			return;
		else if (pos == 0)
			eliminarInicial();
		else if (pos == cant - 1)
			eliminarFinal();
		else 
		{
			Nodo*aux;
			Nodo*ayuda;
			Nodo*ayuda2;

			if(pos<(cant/2))
			{
				aux = ini;
				for (int i = 0; i < pos; i++)
					aux = aux->sig;
			}
			else
			{
				aux = ult;
				for (int i = cant - 1; i > pos; i--)
					aux = aux->ant;
			}

			ayuda = aux->ant;
			ayuda2 = aux->sig;

			ayuda->sig = ayuda2;
			ayuda2->ant = ayuda;

			cant--;
			delete aux;

		}

	}
	void eliminarFinal()
	{
		if (cant == 0)
			return;
		else if (cant == 1)
			eliminarInicial();
		else 
		{
			Nodo*ayuda = ult;
			ult = ult->ant;
			ult->sig = nullptr;

			delete ayuda;
			cant--;
		}
	}

	int getInicio() {
		if(cant>0)
			return ini->elem;
		return 0;
	}
	int getPos(int pos) 
	{
		if (pos < 0 || pos >= cant)
			return 0;
		
		else if (pos == 0)
			return getInicio();
		
		else if (pos == cant - 1)
			return getFinal();

		else
		{
			Nodo*aux;

			if (pos < (cant / 2))
			{
				aux = ini;
				for (int i = 0; i < pos; i++)
				{
					aux = aux->sig;
				}
			}

			else
			{
				aux = ult;
				for (int i = cant-1; i > pos; i--)
					aux = aux->ant;
			}

			return aux->elem;
		
		}
	
	}
	int getFinal() 
	{
		if(cant>0)
			return ult->elem;
		return 0;
	}
	
	int buscar(int elem)
	{
		if (cant > 0)
		{
			Nodo*aux =ini;

			for (int i = 0; i < cant; i++)
			{
				if (aux->elem == elem)
					return i;
				aux = aux->sig;
			}

			return 0;
			
		}
	}

	void mostrar() 
	{
		for (int i = 0; i < cant; i++)
			cout << "Elemento: " << i << " : " << getPos(i)<<endl;

	}
};

int main() 
{
	Lista_Int lista1 = Lista_Int();

	cout << lista1.esVacia() << endl;
	
	lista1.insertarFinal(2);
	lista1.insertarInicial(1);
	lista1.insertarPos(0, 0);
	lista1.insertarPos(4, 3);
	lista1.insertarPos(3, 3);
	lista1.insertarFinal(6);
	lista1.insertarPos(5, 5);
	lista1.insertarFinal(7);

	lista1.eliminarFinal();

	lista1.mostrar();


	system("pause>=0");
	return 0;
}