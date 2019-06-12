#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "Persona.h"
using namespace std;

class Empleado: public Persona{
	private:
		char direccion[40],telefono[40];
		int puesto,rentas;//por ejemplo 1=Gerente 2=Administrador 3=Servicio
		int salario;
		float comisiones;

	public:
		Empleado *siguiente;
		void mostrar();
		void setdireccion(char* dire);
		char* getdireccion();
		void settelefono(char *tel);
		char* gettelefono();
		void setpuesto(int pues);
		int getpuesto();
		void setrentas(int renta);
		int getrentas();
		void setcomision(float comision);
		float getcomision();
		int getsalario();
		friend class ListaEmpleado;
		friend class Rentas;
		~Empleado();
		Empleado(){
		}
		/*
		dire,tele,pues,codi,nom,edad
		*/
		Empleado(char *dire,char *tel,int pues,int codi,char *nom,int eda):Persona(nom,codi,eda){	
		strcpy(direccion,dire);
		strcpy(telefono,tel);
		puesto=pues;
		rentas=0;
		if(pues=1)
		salario=25000;
		if(pues==2)
		salario=20000;
		if(pues==3)
		salario=10000;
		comisiones=0;
	}
};
Empleado::~Empleado(){}
void Empleado::mostrar(){
	Persona::mostrar();
	cout<<"Direccion:"<<endl<<direccion<<endl;
	cout<<"Telefono:"<<endl<<telefono<<endl;
	if(puesto==1){
	cout<<"Puesto: Gerente"<<endl;
	cout<<"Rentas:"<<endl<<rentas<<endl;
	cout<<"Salario:"<<endl<<salario<<endl;
	}
	if(puesto==2){
	cout<<"Puesto: Administrador"<<endl;
	cout<<"Rentas:"<<endl<<rentas<<endl;
	cout<<"Salario:"<<endl<<salario<<endl;
	cout<<"Comisiones:"<<endl<<comisiones<<endl;
	}
	if(puesto==3){
	cout<<"Puesto: Servicio"<<endl;
	cout<<"Salario:"<<endl<<salario<<endl;
	}
}
void Empleado::setdireccion(char *dire){
	strcpy(direccion,dire);
}
char *Empleado::getdireccion(){
	return direccion;
}
void Empleado::settelefono(char *tel){
	strcpy(telefono,tel);
}
char *Empleado::gettelefono(){
	return telefono;
}
void Empleado::setpuesto(int pues){
	puesto=pues;
}
int Empleado::getpuesto(){
	return puesto;	
}
void Empleado::setrentas(int renta){
	rentas=renta;
}
int Empleado::getrentas(){
	return rentas;	
}
void Empleado::setcomision(float comision){
	comisiones=comision;
}
float Empleado::getcomision(){
	return comisiones;	
}
int Empleado::getsalario(){
	return salario;	
}