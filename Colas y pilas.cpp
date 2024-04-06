#include<iostream>
#include<stdlib.h>

using namespace std;

struct nodo{
	int data;
	nodo *next;
	int priority;	
};

void insert_pila(nodo *&list,int data,int priority);
void insert_cola(nodo *&list,int data,int priority);
void showList(nodo *&list);
void detele(nodo *&list);
int main(){
	
	int option;
	bool  continues=true;
	int priority;
	int data;
	nodo *list=NULL;
	bool warning=false;
	bool isPilas=true;
	string opti;
	
	cout<<"\tCONFIGURACION"<<endl;
	cout<<"1. Usar colas"<<endl;
	cout<<"2. Usar pilas"<<endl;
	cout<<"*. default(pila)"<<endl;
	cout<<"-->";cin>>opti;
	
	if(opti=="1"){
		isPilas=false;
	}
	system("cls");
	do{
		if(isPilas){
			cout<<"\t MENU PRINCIPAL PILAS\n"<<endl;
		}
		else{
			cout<<"\t MENU PRINCIPAL COLAS\n"<<endl;
		}
		
		cout<<"1. Agregar Proceso"<<endl;
		cout<<"2. Despachar proceso"<<endl;
		cout<<"3. Mostrar procesos"<<endl;
		cout<<"4. salir"<<endl;
		cout<<"--> ";cin>>option;
		
		switch(option){
			case 1:{
				cout<<"\tAGREGAR PROCESO"<<endl<<endl;
				cout<<"Valor del proceso: ";cin>>data;
				do{
					if(warning){
						cout<<"*la prioridad no puede ser menor que 0*"<<endl;
					}
					cout<<"Prioridad del proceso: ";cin>>priority;
					warning=true;
				}while(priority<0);
				warning=false;
				if(isPilas){
					insert_pila(list,data,priority);	
				}
				else{
					insert_cola(list,data,priority);
				}
				
				break;
			}
			case 2:{
				
				detele(list);
					
				system("pause");
				break;
			}
			case 3:{
				showList(list);
				
				system("pause");
				break;
			}
			case 4:{
				continues=false;
				break;
			}
			
		}
		system("cls");
	}while(continues);
	
	system("pause");
	return 0;
}

void insert_pila(nodo *&list,int data,int priority){
	
	nodo *newNodo= new nodo();
	newNodo->data=data;
	newNodo->priority=priority;
	nodo *aux1=list;
	nodo *aux2;
	
	while(aux1!=NULL && aux1->priority<priority){
		aux2=aux1;
		aux1=aux1->next;
	}
	
	if(aux1==list){
		list=newNodo;
		
	}
	else{
		aux2->next=newNodo;
	}
	newNodo->next=aux1;
}

void insert_cola(nodo *&list,int data,int priority){
	nodo *newNodo= new nodo();
	newNodo->data=data;
	newNodo->priority=priority;
	nodo *aux1=list;
	nodo *aux2;
	
	while(aux1!=NULL && aux1->priority<=priority){
		aux2=aux1;
		aux1=aux1->next;
	}
	
	if(aux1==list){
		list=newNodo;
		
	}
	else{
		aux2->next=newNodo;
	}
	newNodo->next=aux1;
	
	
}

//true=pila
//false=cola
void showList(nodo *&list){
	
	nodo *aux=list;
	
	while(aux!=NULL){
		cout<<"[ DATA="<<aux->data<<", Priority="<<aux->priority<<"] -> ";
		aux=aux->next;
	}
	cout<<"NULL"<<endl;		
	


}

void detele(nodo *&list){
	nodo *aux=list;
	if(list!=NULL){
		list=list->next;
		cout<<"PROCESO DESPACHADO:"<<endl;
		cout<<"[ DATA="<<aux->data<<", Priority="<<aux->priority<<"]"<<endl;
		delete aux;		
	}
	else{
		cout<<"NO HAY PROCESOS"<<endl;
	}

}
