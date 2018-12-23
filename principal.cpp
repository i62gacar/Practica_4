#include <cstdlib>
#include <iostream>
#include <fstream>
#include "programa.h"

using namespace std;

int main(void){
	int opcion1=-1, opcion2;
	vector <Profesor> profesores;
	profesores.clear();
  	Profesor p;
	Agenda agenda_act;
	p.Cargar_Usuarios(profesores);
  	
  	while(opcion1!=0){
  		opcion2=-1;
  		cout<<"Introduzca una opcion:"<<endl;
  		cout<<"1. Iniciar sesion"<<endl;
  		cout<<"2. Registrar usuario"<<endl;
  		cout<<"0. salir"<<endl;
  		cin>>opcion1;

  		switch(opcion1){
  			case 1:
  				if(p.Iniciar_Sesion(profesores)==true){
  					cout<<"Inicio de sesion con exito"<<endl<<endl;
  						if(p.Get_Rol()=="coordinador"){
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
  									agenda_act.Insertar_Alumno();
  								break;
			
  								case 2:
  								     agenda_act.Modificar_Alumno();
  								break;
			
  								case 3:
  		  	      				    agenda_act.Eliminar_Alumno();
  								break;
			
  								case 4:
									p.Cargar_Fichero(agenda_act);
  								break;
	
		  						case 5:
									p.Guardar_Fichero(agenda_act);
		  						break;
	
		  						case 6:
									p.Cargar_Copia(agenda_act);
		  						break;
		
		  						case 7:
									p.Hacer_Copia(agenda_act);
		  						break;
		
		  						case 8:
		  							agenda_act.Imprimir_Pantalla();
		  						break;
		
		  						case 9:
									agenda_act.Visualizar_Grupo();
		  						break;
		
		  						case 0:
		  							cout<<"Se ha cerrado la sesion"<<endl<<endl;
		  						break;
		
		  						default:
		  							cout<<"Opcion incorrecta"<<endl<<endl;
		  						break;
		  					};
		  				}
		  			}
		  			else{
		  				while(opcion2!=0){
  							cout<<endl<<"Introduzca una opcion:"<<endl;
  							cout<<"1. Introducir usuario"<<endl;
  							cout<<"2. Modificar usuario"<<endl;
  							cout<<"3. Eliminar usuario"<<endl;
  							cout<<"4. Cargar fichero"<<endl;
  							cout<<"5. Guardar fichero"<<endl;
  							cout<<"6. Imprimir por pantalla todos los alumnos"<<endl;
  							cout<<"7. Visualizar grupo"<<endl;
  							cout<<"0. Cambiar de usuario"<<endl;
  							cin>>opcion2;
  							switch(opcion2){
  								case 1:
  									agenda_act.Insertar_Alumno();
  								break;
			
  								case 2:
  								     agenda_act.Modificar_Alumno();
  								break;
			
  								case 3:
  		  	      				    agenda_act.Eliminar_Alumno();
  								break;
			
  								case 4:
									p.Cargar_Fichero(agenda_act);
  								break;
	
		  						case 5:
									p.Guardar_Fichero(agenda_act);
		  						break;
	
		  						case 6:
									agenda_act.Imprimir_Pantalla();
		  						break;
		
		  						case 7:
									agenda_act.Visualizar_Grupo();
		  						break;
		
		  						case 0:
		  							cout<<"Se ha cerrado la sesion"<<endl<<endl;
		  						break;
		
		  						default:
		  							cout<<"Opcion incorrecta"<<endl<<endl;
		  						break;
		  					};
		  				}
		  			}
	  			}
	  			else{
	  				cout<<"Error al iniciar sesion"<<endl<<endl;
	  			}
	  		break;

	  		case 2:
				p.Registrar_Profesor(profesores);
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
