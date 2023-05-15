#include <iostream>

using namespace std;

struct arbol3 {
    int numero;
    int numelementosabajo;
    arbol3* izq;
    arbol3* cen;
    arbol3* der;
};

void imprimirArbol(arbol3* nodo, int nivel = 0) {
    if (nodo == NULL)
        return;

    cout << string(nivel, '\t') << "(" << nivel << ") " << nodo->numero << endl;

    imprimirArbol(nodo->izq, nivel + 1);
    imprimirArbol(nodo->cen, nivel + 1);
    imprimirArbol(nodo->der, nivel + 1);
}

void insertarNumero(arbol3*& nodo, int numero) {
    
	if (nodo == NULL) {
        nodo = new arbol3;
        nodo->numero = numero;
        nodo->numelementosabajo = 0;
        nodo->izq = nodo->cen = nodo->der = NULL;
        return;
    }

    if (nodo->izq == NULL) 
	{
        insertarNumero(nodo->izq, numero);
        nodo->numelementosabajo++;
    } 
	else if (nodo->cen == NULL) 
	{
        insertarNumero(nodo->cen, numero);
        nodo->numelementosabajo++;
    } 
	else if (nodo->der == NULL) 
	{
        insertarNumero(nodo->der, numero);
        nodo->numelementosabajo++;
    } 
	else 
	{
        
		int lugarnodo = nodo->numelementosabajo % 3;
        
		nodo->numelementosabajo++;

        switch (lugarnodo) {
            case 0:
                insertarNumero(nodo->izq, numero);
                break;
            case 1:
                insertarNumero(nodo->cen, numero);
                break;
            case 2:
                insertarNumero(nodo->der, numero);
                break;
        }
        
    }
    
}

int main() {
    
	arbol3* raiz = NULL;
    
	int numero;

    do 
	{
        
		cout << "Ingrese un numero para insertar en el arbol (-1 para salir): ";
        
		cin >> numero;

        if (numero != -1)
            insertarNumero(raiz, numero);

    } while (numero != -1);

    imprimirArbol(raiz);

    return 0;
}

