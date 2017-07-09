#include "librerias.h"
#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

 struct nodo
{
	struct nodo* siguiente;
	string titulo;
	string autor;
	string editora;
	string categoria;
};

typedef nodo *Libro;

void agregar(Libro &nodo, string titulo, string autor, string editora,string categoria)
{

		Libro aux = new (struct nodo);
		aux->titulo = titulo;
		aux->autor = autor;
		aux->editora = editora;
		aux->categoria = categoria;
		aux-> siguiente = nodo;

		nodo = aux;


}

void extraer(Libro p)
{
	Libro aux;
	aux = p;
	int num = 1;
	 while( aux !=NULL )
	 {
		 cout<<endl<<"\t Libros "<<num<<endl;
		 cout<<endl<<"\t"<<"Titulo: "+aux->titulo <<"\n\tAutor: "+aux->autor <<"\n\tEditora: "+aux->editora <<"\n\tCategoria: "+aux->categoria <<endl;
		 aux = aux->siguiente;
		 num++;
	 }

}

string ultimoLibro(Libro &p)
	{
		string titulo, autor, editora, categoria;
		Libro aux;

		aux = p;

		titulo = aux->titulo;
		autor = aux->autor;
		editora = aux->editora;
		categoria = aux->categoria;

		return " Titulo: "+titulo+"\n Autor: "+autor+"\n Editora: "+editora+"\n Categoria: "+categoria;


	}
							//metodo buscar
/*------------------------------------------------------------------------*/
void busqueda(Libro &p, string _categoria)
{
	string titulo, autor, editora, categoria;
	Libro aux;
	aux = p;
	int m = 1;


		while(aux != NULL)
		{
			if(aux->categoria == _categoria)
			{
				cout<<endl<<"\t Libros "<<m<<endl;
			    cout<<endl<<"\t"<<"Titulo: "+aux->titulo <<"\n\tAutor: "+aux->autor <<"\n\tEditora: "+aux->editora <<"\n\tCategoria: "+aux->categoria <<endl;
				 aux = aux->siguiente;
				 m++;
			}
		}


}
void menu(){
    system("cls");
    cout <<endl << "Sistema de gestión bibliotecaria" <<endl;
    cout <<endl << "1 - Listar libro" <<endl;
    cout << "2 - Insertar libro" <<endl;
    cout << "3 - Solicitar ultimo libro de la pila" <<endl;
    cout << "4 - Buscar libro por categoria" <<endl;
    cout << "5 - Salir" <<endl;

    cout <<endl << "Seleccione una opcion => ";
}

int main()
{

	string titulo, autor, editora, categoria, buscar;
		int opcion = 0, s = 0, a = 0, b = 0;
		Libro libro1 = NULL;
		string mensaje = "";

	do
	{
		menu(); cin >> opcion;
		switch(opcion)
		{

		case 2:
			do{
				system("cls");
				cout <<endl << "Sistema de gestión bibliotecaria\n";
				cout <<"\nInsertar Libro\n";
				cout  << "\n 1 - Titulo: ";
				cin >> titulo;
				cout << "\n2 - Autor: ";
				cin >> autor;
				cout << endl << "3 - Editora: ";
				cin >> editora;
				cout << endl << "4 - Categoria: ";
				cin >> categoria;

				agregar(libro1,titulo, autor, editora,categoria);

				cout <<endl<<endl<< "1 - Seguir agregando" <<endl;
				cout << "2 - Salir" <<endl;
				cout <<endl << "Seleccione una opcion => ";
				cin >>b;
			}while(b != 2);

			break;

		case 1:
			system("cls");
			cout <<endl << "Sistema de gestión bibliotecaria" <<endl;
			cout <<endl << "Lista de libro" <<endl;

			if(libro1 != NULL)
			{
				extraer(libro1);

			}else{cout <<endl << "No tenemos libros registrados :(" <<endl;}


				cout <<endl << "1 - Salir(si = 1) ->: ";
				cin >> s;

				if(s == 1)
				{
					menu();
				}

			break;
		case 3:
			system("cls");
			cout <<"Ultimo Libro Agregado"<<endl<<endl;

			if(libro1 != NULL)
			{
				string mostrar = ultimoLibro(libro1);
				cout <<mostrar<<endl;
			}

			cout <<endl << "1 - Salir(si = 1) ->: ";
			cin >> s;

				if(s == 1)
				{
					menu();
				}

			break;

		case 4:

				system("cls");
				cout <<"Busqueda "<<endl<<endl;
				if(libro1 == NULL){

					cout <<endl<<"No tenemos libros registrados :("<<endl;
				}

				if(libro1 != NULL)
				{
					cout << "Seleccione la categoría de que desea buscar: ";
				    cin >> buscar;
					busqueda(libro1,buscar);

				}

				cout <<endl << "1 - Salir(si = 1) ";
				if(libro1 != NULL)
				{
				  cout <<endl << "2 - Seguir buscando ";
				}
				cout <<endl << " Seleccione una opcion: ";
				cin >> s;
				if(s == 1){

					menu();
				}

			break;

		  }
	}while(opcion != 5);


	system("pause");
	return 0;
}
