
#ifndef PERSONA
#define PERSONA
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string>
using namespace std;

class Persona{
	private:
		char nombre[40];
		int codigo;
		int edad;

	public:
	Persona(char *nom,int codi, int eda){
	strcpy(nombre,nom);
	codigo=codi;
	edad=eda;
	}
		bool consultar(char *nom);
		bool consultarcodi(int codi);
		void mostrar();
		void setnombre(char *nom);
		char* getnombre();
		void setcodigo(int codigo);
		int getcodigo();
		void setedad(int eda);
		int getedad();
		~Persona(){}
		Persona(){}
};

bool Persona::consultar(char *nom){
	
	if(strcmp(nom,nombre) == 0)
	return true;
	else
	return false;
}
void Persona::mostrar(){
	cout<<"Nombre:"<<endl<<nombre<<endl;
	cout<<"Codigo:"<<endl<<codigo<<endl;
	cout<<"Edad:"<<endl<<edad<<endl;
}
void Persona::setedad(int eda){
	edad=eda;
}
int Persona::getedad(){
	return edad;
}
char *Persona::getnombre(){
	return nombre;
}
void Persona::setnombre(char *nom){
	strcpy(nombre,nom);
}
int Persona::getcodigo(){
	return codigo;
}
void Persona::setcodigo(int codi){
	codigo=codi;
}
bool Persona::consultarcodi(int codi){
	if(codi==codigo)
	return true;
	else
	return false;
}
#endif