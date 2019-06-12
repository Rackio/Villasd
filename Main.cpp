#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "ListaEmpleado.h"
#include "ListaCliente.h"

int main() {
	system("color f1");
	ListaEmpleado lise;
	ListaCliente lisc;
	char nom[40],tel[40],dire[50],correo[50];
	int opc,edad,puesto,opc1,consulta,codi;
	lise.cargararchivo();
	lisc.cargararchivo();
	do{
		cout<<"1. Empleados \n2. Clientes \n3. Habitación \n4. Renta de habitación \n5. Reportes\n 6. Salir"<<endl;
		cin>>opc;
		system("cls");
		switch(opc){
			case 1://Empieza Empleados
				do{
					cout<<"1. Ingresar un nuevo registro. \n2. Consultar uno o varios registros. \n3. Eliminar un registro. \n4. Actualizar un registro. \n5.-Salir"<<endl;
					cin>>opc1;
					system("cls");
					switch(opc1){//Empieza Menu Empleados
						case 1:
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
							fflush(stdin);
							cout<<"Ingresa Puesto \n1. para gerente \n2. Administrador \n3. Servicio\n Ingresa numero correspondiente:\t";
							cin>>puesto;
							lise.agregarinicio(dire,tel,puesto,nom,edad);
							system("cls");
							break;
						case 2:
							
							do{
							system("cls");
							cout<<"1. Consultar uno. \n2. Consultar varios registros. \n3.-Ordenar \n4. Salir.";
							cin>>consulta;
							if(consulta==2){
								lise.consultartodos();
							}
							if(consulta==1){
							cout<<"Ingresa el nombre de la persona que deseas buscar";
							cin>>nom;
							lise.consultaruno(nom);
							}
							if(consulta==3){
							cout<<"...............Lista Ordenada...............\n";
							lise.ordenar();
							lise.consultartodos();
							}
							getch();
						}while(consulta!=4);
						break;	
						case 3:
							cout<<"Ingresa el codigo que deseas eliminar\n";
							cin>>codi;
							lise.eliminar(codi);
							break;
						case 4:
							cout<<"Ingresa el codigo que deseas actualizar\n";
							cin>>codi;
							lise.editar(codi);
							break;
					}//Termina Menu Empleados
				}while(opc1!=5);
			break;
			case 2:
				do {
					cout << "1. Ingresar un nuevo registro. \n2. Consultar uno o varios registros. \n3. Eliminar un registro. \n4. Actualizar un registro. \n5.-Salir" << endl;
					cin >> opc1;
					system("cls");
					switch (opc1) {//Empieza Menu Clientes
					case 1:
						fflush(stdin);
						cout << "Ingresa nombre" << endl;
						cin >> nom;
						cout << "Edad" << endl;
						cin >> edad;
						fflush(stdin);
						cout << "Ingresa nacionalidad" << endl;
						cin >> tel;
						fflush(stdin);
						cout << "Ingresa disciplina" << endl;
						cin >> dire;
						fflush(stdin);
						cout << "Ingresa correo electronico" << endl;
						cin >> correo;
						lisc.agregarinicio(tel, dire, nom, edad,correo);
						system("cls");
						break;
					case 2:
						do {
							system("cls");
							cout << "1. Consultar uno. \n2. Consultar varios registros. \n3.-Salir."<<endl;
							cin >> consulta;
							if (consulta == 2) {
								lisc.consultartodos();
							}
							if (consulta == 1) {
								cout << "Ingresa el nombre de la persona que deseas buscar";
								cin >> nom;
								lisc.consultaruno(nom);
							}
							getch();
						} while (consulta != 4);
						break;
					case 3:
						cout << "Ingresa el codigo que deseas eliminar\n";
						cin >> edad;
						lisc.eliminar(edad);
						break;
					case 4:
						cout << "Ingresa el codigo que deseas actualizar\n";
						cin >> edad;
						lisc.editar(edad);
						break;
					}//Termina Menu Clientes*/
				} while (opc1 != 5);
				break;
		}
	}while(opc!=6);
	
	
	
	return 0;
}