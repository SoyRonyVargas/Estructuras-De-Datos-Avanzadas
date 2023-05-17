#include <iostream>

using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int valor) {
        this->valor = valor;
        izquierdo = NULL;
        derecho = NULL;
    }
};
//
Nodo* insertarNodo( Nodo* nodo , int numero )
{
    
    if( nodo == NULL )
    {
        Nodo* nodo = new Nodo(numero);
        return nodo;
    }

    if( numero < nodo->valor )
    {
        nodo->izquierdo = insertarNodo( nodo->izquierdo , numero );
    }

    if( numero > nodo->valor )
    {
        nodo->derecho = insertarNodo( nodo->derecho , numero );
    }

    return nodo;

}

int main()
{

    Nodo* raiz = NULL;
    
    while( true )
    {
        
		int numero;

        cout<<"Ingresa el numero: ";
        
        cin>>numero;

        if( numero == -1 ) break;

        raiz = insertarNodo(raiz , numero);

    }

}

