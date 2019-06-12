#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "Cliente.h"
class ListaCliente{
 public:
 int longi;
 int cod;
 Cliente *Lista;//Puntero Lista
 void agregarinicio(char *nac,char *dis,char *nom, int edad,char *cor);
 void agregarinicio(Cliente *p);
 void cargararchivo();
 void ordenar();
 void consultartodos();
 void consultaruno(char *nom);
 bool esMayor(char *x,char *y);
 ListaCliente(){Lista=NULL;};
 void eliminar(int codi);
 void editar(int codi);
 void recargarchivo();
};
void ListaCliente::agregarinicio(char *nac,char *dis, char *nom, int edad,char *cor){
	if(Lista==NULL)
		cod=1;
ofstream entrada;
entrada.open("Cliente.dat",ios::out|ios::app|ios::binary);
  if(entrada.fail())
  {
            cout<<"error al crear archivo";
            getch();      
  }   
  else{
Cliente *p= new Cliente(nac,dis,cod,nom,edad,cor);
entrada.write((char *)p,sizeof(Cliente));
entrada.close();
if(Lista==NULL){
	Lista=p;
	p->siguiente=p;
	longi=1;
	p->setcodigo(cod);
}
else{
Cliente *x;
p->siguiente=Lista;
x=Lista;

while(x->siguiente!=Lista){
	x=x->siguiente;
}
x->siguiente=p;
}
Lista=p;
longi++;
cod++;
p->setcodigo(cod);
  }
  entrada.close();
}
void ListaCliente::agregarinicio(Cliente *p){
if(Lista==NULL){
	Lista=p;
	p->siguiente=p;
	longi=1;
	cod = 1;
}
else{
Cliente *x;
p->siguiente=Lista;
x=Lista;

while(x->siguiente!=Lista){
	x=x->siguiente;
}
x->siguiente=p;
}
Lista=p;
longi++;
cod++;
return;
}
      
void ListaCliente::cargararchivo(){
	Cliente *w[100];
	ifstream salida;
     salida.open("Cliente.dat",ios::in|ios::binary);
     int x;
     if (salida.fail())
     {
     cout<<"No existen datos guardados"<<endl;
     _getch();                  
     }
     else       
     {
     int nreg;
     salida.seekg(0,ios::end);
	 nreg=salida.tellg()/sizeof(Cliente);
     salida.seekg(0);  
     for( x=0;x<nreg;x++)
              {
				  w[x]=new Cliente();
				  salida.read((char *)w[x],sizeof(Cliente));	
				  agregarinicio(w[x]);
              }
	 if(x>0){
	 cout<<"Datos cargados :3 :"<<x<<endl;
	 }
   
	 _getch();
	 system("cls");
     }
	 salida.close();
}
/*
void ListaEmpleado::cargararchivo(){
	Empleado *p[100];
	ifstream salida;
     salida.open("Empleado.dat",ios::in|ios::binary);
     int x;
     if (salida.fail())
     {
     cout<<"No existen datos guardados"<<endl;
     getch();                  
     }
     else       
     {
     int nreg;
     salida.seekg(0,ios::end);
	 nreg=salida.tellg()/sizeof(Empleado);
     salida.seekg(0);  
     for( x=0;x<nreg;x++)
              {
				  p[x]=new Empleado();
				  salida.read((char *)p[x],sizeof(Empleado));	
				  agregarinicio(p[x]);
              }
	 if(x>0){
	 cout<<"Datos cargados :3 :"<<x<<endl;
	 }
     salida.close();
     _getch();
	 system("cls");
     }
}
*/

/*void ListaCliente::ordenar(){

 Cliente *actual;
   actual = Lista; 
   int cont=1,cursor,k;
   char auxnac[40],auxdis[40];
   int auxcodi,auxedad;
   char auxnom[40],auxcor[40];
   int i=0;
   while(i!=longi){
      cursor=cont;       cout<<"\ncursor:"<<cursor<<" ";
	  strcpy(auxnom,actual->getnombre());
	  cout<<"\nNombre"<< auxnom<<" ";
	  strcpy(auxdireccion,actual->getdireccion());
	  cout<<"\nDireccion"<< auxdireccion<<" ";
	  strcpy(auxtelefono,actual->gettelefono());
	  cout<<"\nTelegono"<< auxtelefono<<" ";
	  strcpy(auxcodi,actual->getcodigo());
	  cout<<"\nCodigo"<< auxcodi<<" ";
	  auxedad=actual->getedad();
	  cout<<"\nEdad"<< auxedad<<" ";
	  auxpuesto=actual->getpuesto();
	  cout<<"\nPuesto"<< auxpuesto<<" ";
	  auxrentas=actual->getrentas();
	  cout<<"\nRentas"<< auxrentas<<" ";
      k = cursor-1;       cout<<"\nk: "<< k<<" ";
      Empleado *anterior=Lista;
      for(int f=0;f<k-1;f++){
         anterior=anterior->siguiente;
      }
                     cout<<"\nAnterior: "<<anterior->getnombre()<<" ";
      while(k>=0 && (esMayor(auxnom,anterior->getnombre())==false)){
      	anterior->siguiente->setnombre(anterior->getnombre());
		anterior->siguiente->setdireccion(anterior->getdireccion());
		anterior->siguiente->settelefono(anterior->gettelefono());
		anterior->siguiente->setcodigo(anterior->getcodigo());
		anterior->siguiente->setedad(anterior->getedad());
		anterior->siguiente->setpuesto(anterior->getpuesto());
        Empleado *temp=Lista;
         for(int j=0;j<k-2;j++){
            temp=temp->siguiente;
         }   
                     cout<<"\nTemp:"<<temp->getnombre();         
         anterior=temp   ;   
         k--;   
      }
    	cout<<"\n--"<<auxnom<<endl;
      Empleado *temp2 = Lista;
      for(int h=0;h<k;h++){
      temp2=temp2->siguiente;   
      }
     strcpy(auxnom,temp2->getnombre());
	 cout<<"\nNombre"<< auxnom<<" ";
	 strcpy(auxdireccion,temp2->getdireccion());
	 cout<<"\nDireccion"<< auxdireccion<<" ";
	 strcpy(auxtelefono,temp2->gettelefono());
	 cout<<"\nTelegono"<< auxtelefono<<" ";
	 strcpy(auxcodi,temp2->getcodigo());
	 cout<<"\nCodigo"<< auxcodi<<" ";
	 auxedad=temp2->getedad();
	 cout<<"\nEdad"<< auxedad<<" ";
	 auxpuesto=temp2->getpuesto();
	  cout<<"\nPuesto"<< auxpuesto<<" ";
	  auxrentas=temp2->getrentas();
	  cout<<"\nRentas"<< auxrentas<<" ";
	  actual=temp2->siguiente;
      cont++;   
	  i++;
   }
   cout<<"\n\n\tLista ordenada..."<<endl;

}
*/
void ListaCliente::eliminar(int codi){
	ofstream entrada;
	entrada.open("tempCliente.dat",ios::out|ios::binary);
	ifstream salida;
	salida.open("Cliente.dat",ios::in|ios::binary);
	if (salida.fail()||entrada.fail())
	{
	cout<<"error al abrir el archivo"<<endl;
	getch();                  
	}
   else{
	  
   Cliente *nodo;
   nodo=Lista;
   do {
      if((Lista)->siguiente->consultarcodi(codi)==false){
	  Lista = (Lista)->siguiente;
	  entrada.write((char *)Lista,sizeof(Cliente));    
	  }
   } while((Lista)->siguiente->consultarcodi(codi)==false&& Lista != nodo);
   if((Lista)->siguiente->consultarcodi(codi)==true) {//valor igual
      if(Lista == (Lista)->siguiente) {
         delete(Lista);
         Lista = NULL;
		 longi=0;
      }
      else {
         nodo = (Lista)->siguiente;
         (Lista)->siguiente = nodo->siguiente;
         delete(nodo);
		 longi=longi-1;
      }
   }
	  }
    salida.close();
     entrada.close();
     remove("Cliente.dat");
     rename("tempCliente.dat","Cliente.dat");

}

bool ListaCliente::esMayor(char *x,char *y){
    for (int i=0;i<40;i++){
        char a=x[i];
        char b=y[i];
        if(a>=97&&a<=122){
            a-=32;
        }
        if(b>=97&&b<=122){
            b-=32;
        }
        if(a > b)
            return true;
        else if( a < b)
            return false;
    }
    return false;
}
void ListaCliente::consultartodos(){
	Cliente *x;
	if(Lista!=NULL){
	x=Lista;
	while(x->siguiente!=Lista){
	x->mostrar();
	x=x->siguiente;
}
	x->mostrar();
	}
	else
		cout<<"Sin Datos\n";
}
void ListaCliente::consultaruno(char *nom){
	bool igual;
	Cliente *x;
	x=Lista;
	for(int i=0; i<longi;i++){
		igual=x->consultar(nom);
		if(igual==true){
		x->mostrar();
		return;
		}
		else{
		x=x->siguiente;
		igual=false;
		}
	}

}
void ListaCliente::editar(int codi){
	char nom[40],dis[40],nac[40],cor[40];
	int edad;
	bool igual;
	Cliente *x;
	x=Lista;
	for(int i=0; i<longi;i++){
		igual=x->consultarcodi(codi);
		if(igual==true){
		x->mostrar();
        cout<<"-------------------Ingresa datos a cambiar------------------------"<<endl;
		fflush(stdin);
		cout<<"Ingresa nombre"<<endl;
		cin>>nom;
		cout<<"Edad"<<endl;
		cin>>edad;
		fflush(stdin);
		cout<<"Ingresa nacionalidad"<<endl;
		cin>>nac;
		fflush(stdin);
		cout<<"Ingresa disciplina"<<endl;
		cin>>dis;
		cout << "Ingresa correo electronico" << endl;
		fflush(stdin); cin >> cor;
		x->setnombre(nom);
		x->setedad(edad);
		x->setdisciplina(dis);
		x->setnacion(nac);
		x->setcorreo(cor);
		recargarchivo();
		return;
		}
		else{
		x=x->siguiente;
		igual=false;
		}
	}
}
void ListaCliente::recargarchivo(){
	ofstream entrada;
	entrada.open("tempCliente.dat",ios::out|ios::binary);
	Cliente *x;
	if(Lista!=NULL){
	x=Lista;
	while(x->siguiente!=Lista){
	entrada.write((char *)x,sizeof(Cliente));
	x=x->siguiente;
	}
	entrada.write((char *)x,sizeof(Cliente));
	//	Lista =1 , 2 , 3
	}
	remove("Cliente.dat");
	rename("tempCliente.dat","Cliente.dat");
	entrada.close();
}
