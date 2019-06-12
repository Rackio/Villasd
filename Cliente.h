#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "Persona.h"
using namespace std;

class Cliente: public Persona{
	private:
		char nacionalidad[40],disciplina[40],correo[40];
		bool disponible;

	public:
		Cliente *siguiente;
		void mostrar();
		void setnacion(char* nac);
		char* getnacion();
		void setdisciplina(char *dis);
		char* getdisciplina();
		void setcorreo(char *corr);
		char* getcorreo();
		friend class ListaCliente;
		~Cliente();
		Cliente(){}
		Cliente(char *nac,char *dis,int codi,char *nom,int eda,char *cor):Persona(nom,codi,eda){	
		strcpy(nacionalidad,nac);
		strcpy(disciplina,dis);
		strcpy(correo,cor);
		disponible=true;
		}
};
Cliente::~Cliente(){}
void Cliente::mostrar(){
	Persona::mostrar();
	cout<<"Nacionalidad:"<<endl<<nacionalidad<<endl;
	cout<<"Disciplina:"<<endl<<disciplina<<endl;
	cout<<"Correo electronico: "<<endl<<correo<<endl; 
}
void Cliente::setnacion(char *nac){
	strcpy(nacionalidad,nac);
}
char *Cliente::getnacion(){
	return nacionalidad;
}
void Cliente::setcorreo(char *cor){
	strcpy(correo,cor);
}
char *Cliente::getcorreo(){
	return correo;
}
void Cliente::setdisciplina(char *dis){
	strcpy(disciplina,dis);
}
char *Cliente::getdisciplina(){
	return disciplina;	
}