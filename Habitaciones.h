#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class Habitacion{
private:
bool disponible;
int tipodehabitacion;//1 doble 2 cuadruple 3 lujo
int precio;//doble 1000 cuadruple 2000 lujo 3000
char nombre[20];
int rentado;
	public:
		void mostrar();
		void setnombre(char* nom);
		char* getnombre();
		void setdisponibilidad(bool value);
		bool getdisponibiladad();
		int getprecio();
		int gettipodehabitacion();
		void setrentado(int x);
		int getrentado();
		~Habitacion();
		Habitacion(){
		}
		/*
		*/
		Habitacion(char *nom,int tipode){	
		strcpy(nombre,nom);
		tipodehabitacion=tipode;
		if(tipode==1){
			precio=1000;
		}
		if(tipode==2){
			precio=2000;
		}
		if(tipode==3){
			precio=3000;
		}
		disponible=true;
		rentado=NULL;
	}
};
char* Habitacion::getnombre(){
	return nombre;
}
void Habitacion::setnombre(char*nom){
		strcpy(nombre,nom);
}
void Habitacion::setdisponibilidad(bool value){
	disponible=value;
}
bool Habitacion::getdisponibiladad(){
	return disponible;
}
void Habitacion::setrentado(int x){
	rentado = x;
}
int Habitacion::getrentado(){
	return rentado;
}
