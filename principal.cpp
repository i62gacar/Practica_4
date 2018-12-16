#include <cstdlib>
#include <iostream>
#include <fstream>
#include "programa.h"

using namespace std;

int main(void){
  int opcion1=-1, opcion2;
  vector <Profesor> profesores;
  Profesor p;
  while(opcion1!=0){
  	opcion2=-1;
  	cout<<"Introduzca una opcion:"<<endl;
  	cout<<"1. Iniciar sesion"<<endl;
  	cout<<"2. Registrar usuario"<<endl;
  	cout<<"0. salir"<<endl;
  	cin>>opcion1;
  	switch(opcion1){
  		case 1:
  			while(opcion2!=0){
  				cout<<endl<<"Introduzca una opcion:"<<endl;
  				cout<<"1. Introducir usuario"<<endl;
  				cout<<"2. Modificar usuario"<<endl;
  				cout<<"3. Eliminar usuario"<<endl;
  				cout<<"4. Cargar fichero"<<endl;
  				cout<<"5. Guardar fichero"<<endl;
  				cout<<"6. Cargar copia de seguridad"<<endl;
  				cout<<"7. Hacer copia de seguridad"<<endl;
  				cout<<"8. Imprimir por pantalla todos los alumnos"<<endl;
  				cout<<"9. Visualizar grupo"<<endl;
  				cout<<"0. Cambiar de usuario"<<endl;
  				cin>>opcion2;
  				switch(opcion2){
  					case 1:
  						p.Get_Agenda().Insertar_Alumno();
  					break;
  					
  					case 2:
  					
  					break;
  					
  					case 3:
  					
  					break;
  					
  					case 4:
  					
  					break;
  					
  					case 5:
  					
  					break;
  					
  					case 6:
  					
  					break;
  					
  					case 7:
  					
  					break;
  					
  					case 8:
  						p.Get_Agenda().Imprimir_Pantalla();
  					break;
  					
  					case 9:
  					
  					break;
  					
  					case 0:
  						cout<<"Se ha cerrado la sesion"<<endl<<endl;
  					break;
  					
  					default:
  						cout<<"Opcion incorrecta"<<endl<<endl;
  					break;
  				};
  			}
  		break;
  		
  		case 2:
  			
  		break;
  		
  		case 0:
  			cout<<"El sistema se va a cerrar"<<endl;
  		break;
  		
  		default:
  			cout<<"Opcion desconocida"<<endl;
  		break;
  	};
  }
  return 0;
}
