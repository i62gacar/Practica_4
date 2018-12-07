#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "programa.h"

using namespace std;


bool Agenda::Buscar_Alumno(string cadena){

	bool enc=false;
	int auxy[20], n=0;
	string DNI;
	for(int i=0; enc==true; i++){		

		if(cadena.compare(alumnos[i].Get_DNI())==0){

			enc=true;
		}
		if(cadena.compare(alumnos[i].Get_Apellido())==0){

			auxy[n]=i;
			n++;
		}

		while(enc==false || n!=0){

			if(n==1){

				enc=true;
			}
			if(n>1){

				cout<<"Hay más de un alumno, introduce el DNI."<<endl;
				cin>>DNI;
				for(i=0; i==n; i++){
					if(DNI.compare(alumnos[auxy[i]].Get_DNI())==0){

						enc=true;
					}
				}
			}
		}
	}
	return enc;
}

void Agenda::Insertar_Alumno(){

	alumnos[0].Set_DNI(NULL);
	alumnos[0].Set_Nombre(NULL);
	alumnos[0].Set_Apellido(NULL);
	alumnos[0].Set_Telefono(0);
	alumnos[0].Set_Email(NULL);
	alumnos[0].Set_Fecha_Nacimiento(NULL);
	alumnos[0].Set_Curso(0);
	alumnos[0].Set_Equipo(0);
	alumnos[0].Set_Lider(false);

	if((alumnos[0].Get_DNI()).compare(NULL)==0){

		cout<<"ERROR, el DNI está vacío"<<endl;
		return;
	}
	if((alumnos[0].Get_Nombre()).compare(NULL)==0){

		cout<<"ERROR, el Nombre está vacío"<<endl;
		return;
	}
	if((alumnos[0].Get_Apellido()).compare(NULL)==0){

		cout<<"ERROR, el Apellido está vacío"<<endl;
		return;
	}
	if((alumnos[0].Get_Telefono())==0){

		cout<<"ERROR, el Teléfono está vacío"<<endl;
		return;
	}
	if((alumnos[0].Get_Email()).compare(NULL)==0){

		cout<<"ERROR, el Email está vacío"<<endl;
		return;
	}
	if((alumnos[0].Get_Fecha_Nacimiento()).compare(NULL)==0){

		cout<<"ERROR, la Fecha de Nacimiento está vacía"<<endl;
		return;
	}
	if((alumnos[0].Get_Curso())==0){

		cout<<"ERROR, el Curso está vacío"<<endl;
		return;
	}
	if((alumnos[0].Get_Equipo())==0){

		cout<<"ERROR, el Equipo está vacío"<<endl;
		return;
	}

	cout<<Buscar_Alumno(alumnos[0].Get_DNI());
	cout<<Buscar_Alumno(alumnos[0].Get_Nombre());
	cout<<Buscar_Alumno(alumnos[0].Get_Apellido());
	cout<<Buscar_Alumno(alumnos[0].Get_Email());
	cout<<Buscar_Alumno(alumnos[0].Get_Fecha_Nacimiento());

}

void Agenda::Eliminar_Alumno(){

	int l=0, cont=9;
	string cadena2;

	if(cadena2.compare(alumnos[l].Get_DNI())==0){

		cout<<Buscar_Alumno(alumnos[0].Get_DNI());
	}
	if(cadena2.compare(alumnos[l].Get_Apellido())==0){

		cout<<Buscar_Alumno(alumnos[0].Get_Apellido());
	}

	for(l=0; l<cont; l++){

		alumnos[l]=alumnos[0];
		cont--;
	}

	
}