#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	
	
};
void menu();
Nodo *crearNodo (int);
void insertarNodo(Nodo *&,int); 
Nodo *arbol=NULL;
void mostrarArbol(Nodo *,int);

int main(){
	menu();
	
	
	
	getch();
	return 0;
	
}

void menu(){
	
	int dato,opcion,contador=0;
	
	do{
		cout<<"\t.:Menu:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar arbol"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1: cout<<"\nDigite un numero: ";
			cin>>dato;
			insertarNodo(arbol,dato);
			cout<<"\n";
			system("pause");
			break;
			
			case 2: cout<<"\nMostrando el arbol\n\n";
			mostrarArbol(arbol,contador);
			cout<<"\n";
			system("pause");
			break;
		}
		system("cls");
	}while(opcion !=3);
	
	
}
Nodo *crearNodo(int n){
	
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der= NULL;
	nuevo_nodo->izq= NULL;
	
	return nuevo_nodo;
	
}

void insertarNodo(Nodo *&arbol,int n){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
		
		
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->izq,n);	
		}
		else{
			insertarNodo(arbol->der,n);
		}
	}
	
	
}

void mostrarArbol(Nodo *arbol,int cont){
	
	
	if(arbol == NULL){
		return;
}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
		
	}	
							
}
