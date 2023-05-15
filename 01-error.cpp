/* este programa contiene un arbol terciario equilibrado cada vez que se
 inserta un numero se coloca de tal forma que mientras no me acabe un nivel 
 no se crea un nivel nuevo*/
 #include <iostream>
 #include <malloc.h>
 using namespace std;
 struct arbol3
 {
  int numero;
  int numelemntosabajo;
  arbol3 *izq,*cen,*der;
 };
 int main()
 {
  arbol3 *raiz=NULL,*actual;
  int numero,cantidad,lugarnodo;
  do{
       cout<<"dame numero a meter al arbol -1 salir\n";
       cin>>numero;
       if(numero!=-1)
       {
        if(raiz==NULL)
        {
         raiz=(arbol3 *)malloc(sizeof(arbol3));
         raiz->numero=numero;//(*raiz).numero
         raiz->numelemntosabajo=0;
         raiz->cen=raiz->der=raiz->izq=NULL;
   } 
   else
   {
    actual=raiz;
    do{
     cantidad=actual->numelemntosabajo;
     if(actual->izq==NULL)
     {
           actual->izq=(arbol3 *)malloc(sizeof(arbol3));
           actual->numelemntosabajo++;
           actual=actual->izq;
           actual->numero=numero;//(*raiz).numero
           actual->numelemntosabajo=0;
           raiz->cen=raiz->der=raiz->izq=NULL;
           break;
     }
     else if(actual->cen==NULL)
     {
           actual->cen=(arbol3 *)malloc(sizeof(arbol3));
           actual->numelemntosabajo++;
           actual=actual->cen;
           actual->numero=numero;//(*raiz).numero
           actual->numelemntosabajo=0;
           raiz->cen=raiz->der=raiz->izq=NULL;
           break;
     }
     else if(actual->der==NULL)
     {
           actual->der=(arbol3 *)malloc(sizeof(arbol3));
           actual->numelemntosabajo++;
           actual=actual->der;
           actual->numero=numero;//(*raiz).numero
           actual->numelemntosabajo=0;
           raiz->cen=raiz->der=raiz->izq=NULL;
           break;
     }
        lugarnodo=cantidad%3;
     actual->numelemntosabajo++;
     switch(lugarnodo){
      case 0:
       actual=actual->izq;
       break;
      case 1:
       actual=actual->cen;
       break;
      case 2:
       actual=actual->der;
       break;
     } 
    }while(true);  
   }
  }
 }while(numero!=-1);
  return 0;
 }
