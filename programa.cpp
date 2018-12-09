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

void Agenda::Modificar_Alumno(){
	string alumno, cadena;
	int opc=-1, n=0, i, h=0, aux;
	bool lider;
	int datos[12];
	cout<<"Introduzca el DNI del alumno que desea modificar"<<endl;
	cin>>alumno;
	if(Buscar_Alumno(alumno)==false){
		cout<<"El alumno no se encuentra en la agenda"<<endl;
		return;
	}
	else{
		while(Get_Alumno(h).Get_DNI()!=alumno){
			h++;
		}
		cout<<"Introduzca los datos que desea modificar:"<<endl;
		while(opc!=0){
			cout<<"1. Nombre"<<endl;
			cout<<"2. Apellidos"<<endl;
			cout<<"3. DNI"<<endl;
			cout<<"4. Email"<<endl;
			cout<<"5. Direccion"<<endl;
			cout<<"6. Telefono"<<endl;
			cout<<"7. Fecha de nacimiento"<<endl;
			cout<<"8. Curso mas alto"<<endl;
			cout<<"9. Equipo"<<endl;
			cout<<"10. Lider"<<endl;
			cout<<"0. SALIR"<<endl;
			cin>>aux;
			if(aux>0 && aux<11){
				datos[n]=aux;
				n++;
			}
			else if(aux==0){

			}
			else{
				cout<<"Opcion incorrecta"<<endl;
			}
		}
		for(i=0; i<n; i++){
			switch(datos[i]){
			case 1:
				cout<<"Introduzca un nuevo nombre:"<<endl;
				cin>>cadena;
				Get_Alumno(h).Set_Nombre(cadena);
			break;
			
			case 2:
				cout<<"Introduzca unos nuevos apellidos"<<endl;
				cin>>cadena;
				Get_Alumno(h).Set_Apellido(cadena);
			break;
			
			case 3:
				cout<<"Introduzca un nuevo DNI"<<endl;
				cin>>cadena;		
				Get_Alumno(h).Set_DNI(cadena);	
			break;
			
			case 4:
				cout<<"Introduzca un nuevo email"<<endl;
				cin>>cadena;		
				Get_Alumno(h).Set_Email(cadena);	
			break;
			
			case 5:
				cout<<"Introduzca una nueva direccion"<<endl;
				cin>>cadena;	
				Get_Alumno(h).Set_Direccion(cadena);		
			break;
			
			case 6:
				cout<<"Introduzca un nuevo telefono"<<endl;
				cin>>aux;	
				Get_Alumno(h).Set_Telefono(aux);		
			break;
			
			case 7:
				cout<<"Introduzca una nueva fecha de nacimiento"<<endl;
				cin>>cadena;	
				Get_Alumno(h).Set_Fecha_Nacimiento(cadena);		
			break;
			
			case 8:
				cout<<"Introduzca un nuevo curso mas alto"<<endl;
				cin>>aux;	
				Get_Alumno(h).Set_Curso(aux);		
			break;
			
			case 9:
				cout<<"Introduzca un nuevo equipo"<<endl;
				cin>>aux;	
				Get_Alumno(h).Set_Equipo(aux);		
			break;
			
			case 10:
				cout<<"Introduzca un nuevo Lider"<<endl;
				cin>>lider;		
				Get_Alumno(h).Set_Lider(lider);	
			break;
			
			};	
		}
		cout<<"Cambios realizados con exito"<<endl;
	}
}

void Profesor::Guardar_Fichero(){
	string fichero;
	cout<<"Introduzca el nombre del fichero: "<<endl;
	cin>>fichero;
}

void Profesor::Cargar_Fichero(){
	string fichero;
	cout<<"Introduzca el nombre del fichero: "<<endl;
	cin>>fichero;
}

