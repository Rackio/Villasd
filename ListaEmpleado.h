#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "Empleado.h"
class ListaEmpleado{
 public:
 int longi;
 int codi;
 Empleado *Lista;//Puntero Lista de la clase empleado
 void agregarinicio(char *dire,char *tele,int pues,char *nom,int edad);
 void agregarinicio(Empleado *p);
 void cargararchivo();
 void ordenar();
 void consultartodos();
 void consultaruno(char *nom);
 Empleado* regresar(int codi);
 bool esMayor(char *x,char *y);
 ListaEmpleado(){Lista=NULL;};
 void eliminar(int codi);
 void Insercion();
 void editar(int codi);
 void recargarchivo();
};
void ListaEmpleado::agregarinicio(char *dire,char *tele,int pues,char *nom, int edad){
if(Lista==NULL)
codi=1;
ofstream entrada;
entrada.open("Empleado.dat",ios::out|ios::app|ios::binary);
  if(entrada.fail())
  {
            cout<<"error al crear archivo";
            _getch();      
  }   
  else{
Empleado *p= new Empleado(dire,tele,pues,codi,nom,edad);
entrada.write((char *)p,sizeof(Empleado));
entrada.close();
if(Lista==NULL){
	Lista=p;
	p->siguiente=p;
	longi=1;
}
else{
Empleado *x;
p->siguiente=Lista;
x=Lista;

while(x->siguiente!=Lista){
	x=x->siguiente;
}
x->siguiente=p;
}
Lista=p;
longi++;
codi++;
  }
  entrada.close();
}
void ListaEmpleado::agregarinicio(Empleado *p){
if(Lista==NULL){
	Lista=p;
	p->siguiente=p;
	longi=1;
	codi=1;
}
else{
Empleado *x;
p->siguiente=Lista;
x=Lista;

while(x->siguiente!=Lista){
	x=x->siguiente;
}
x->siguiente=p;
}
Lista=p;
longi++; 
codi++;
return;
}
      
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
     _getch();
	 system("cls");
     }
	 salida.close();
}


void ListaEmpleado::ordenar(){
	/*
 Empleado *actual;
   actual = Lista; 
   int cont=1,cursor,k;
   char auxdireccion[40],auxtelefono[40];
   int auxpuesto,auxrentas,auxedad;
   char auxnom[40],auxcodi[40];
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
   */
}

/*void ListaEmpleado::Insercion() {
  int i, a;
	 Empleado *index;
	 Empleado *x;
	 x=Lista;
  for (i=1; i < longi; i++) {
	  index = x->siguiente;
	 a = i-1;
	 while (a >= 0 && esMayor(x->getnombre(), index->getnombre())==true) {
      numbers[a + 1] = numbers[a];
      a--;
    }
    numbers[a+1] = index;
  }
}
*/
void ListaEmpleado::eliminar(int codi){
	ofstream entrada;
	entrada.open("tempEmpleado.dat",ios::out|ios::binary);
	ifstream salida;
	salida.open("Empleado.dat",ios::in|ios::binary);
	if (salida.fail()||entrada.fail())
	{
	cout<<"error al abrir el archivo"<<endl;
	_getch();                  
	}
   else{
   Empleado *nodo;
   nodo=Lista;
   do {
      if((Lista)->siguiente->consultarcodi(codi)==false){
	  Lista = (Lista)->siguiente;
	  entrada.write((char *)Lista,sizeof(Empleado));    
	  }
   } while((Lista)->siguiente->consultarcodi(codi)==false&& Lista != nodo);
   if((Lista)->siguiente->consultarcodi(codi)==true) {//valo igual
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
     remove("Empleado.dat");
     rename("tempEmpleado.dat","Empleado.dat");

}
bool ListaEmpleado::esMayor(char *x,char *y){
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
void ListaEmpleado::consultartodos(){
	Empleado *x;
	if(Lista!=NULL){
	x=Lista;
	while(x->siguiente!=Lista){
	x->mostrar();
	x=x->siguiente;
}
	x->mostrar();
	//	Lista =1 , 2 , 3
	}
	else
		cout<<"Sin Datos\n";
}
void ListaEmpleado::consultaruno(char *nom){
	bool igual;
	Empleado *x;
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
void ListaEmpleado::editar(int codi){
	char nom[40],tel[40],dire[50];
	int edad,puesto,rentas;
	bool igual;
	Empleado *x;
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
		cout<<"Ingresa telefono"<<endl;
		cin>>tel;
		fflush(stdin);
		cout<<"Ingresa direccion"<<endl;
		cin>>dire;
		cout<<"Ingresa Puesto \n1. para gerente \n2. Administrador \n3. Servicio\n Ingresa numero correspondiente:\t";
		fflush(stdin);
		cin>>puesto;
		x->setnombre(nom);
		x->setedad(edad);
		x->setdireccion(dire);
		x->settelefono(tel);
		if((x->getpuesto())!=3){
		cout<<"Ingresa las rentas"<<endl;
		cin>>rentas;
		x->setrentas(rentas);
		}
		x->setpuesto(puesto);
		recargarchivo();
		return;
		}
		else{
		x=x->siguiente;
		igual=false;
		}
	}
}
void ListaEmpleado::recargarchivo(){
	ofstream entrada;
	entrada.open("tempEmpleado.dat",ios::out|ios::binary);
	Empleado *x;
	if(Lista!=NULL){
	x=Lista;
	while(x->siguiente!=Lista){
	entrada.write((char *)x,sizeof(Empleado));
	x=x->siguiente;
	}
	entrada.write((char *)x,sizeof(Empleado));
	//	Lista =1 , 2 , 3
	}
	remove("Empleado.dat");
	rename("tempEmpleado.dat","Empleado.dat");
	entrada.close();
}
/*Empleado* ListaEmpleado::regresar(int codi){
		bool igual;
	Empleado *x;
	x=Lista;
	for(int i=0; i<longi;i++){
		igual=x->consultarcodi(codi);
		if(igual==true){
		return x;
		}
		else{
		x=x->siguiente;
		igual=false;
		}
	}
}*/