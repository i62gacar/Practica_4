#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "programa.h"

using namespace std;


int Agenda::Get_Tamano(){
	int tam=alumnos.size();
	return tam;
}

void Profesor::Set_Profesor(Profesor p){

	Set_Usuario(p.Get_Usuario());
	Set_Password(p.Get_Password());
	Set_Rol(p.Get_Rol());
}

bool Agenda::Buscar_Alumno(string cadena){

	bool enc=false;
	int auxy[20], n=0, i;
	string DNI;
	for(i=0; i<Get_Tamano(); i++){		

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
				for(i=0; i<n; i++){
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
	
	string DNI=NULL, Nombre=NULL, Apellidos=NULL, Email=NULL, Direccion=NULL, Fecha=NULL;
	int Telefono=0, Curso=0, Equipo=0, lider;
	int pos=Get_Tamano();
	Alumno aux;
	
	cout<<"Introduzca el DNI:"<<endl;
	cin>>DNI;
	cout<<"Introduzca el Nombre:"<<endl;
	cin>>Nombre;
	cout<<"Introduzca el Apellidos:"<<endl;
	cin>>Apellidos;
	cout<<"Introduzca el Email:"<<endl;
	cin>>Email;
	cout<<"Introduzca el Direccion:"<<endl;
	cin>>Direccion;
	cout<<"Introduzca el Telefono:"<<endl;
	cin>>Telefono;
	cout<<"Introduzca el Fecha de nacimiento:"<<endl;
	cin>>Fecha;
	cout<<"Introduzca el curso mas alto:"<<endl;
	cin>>Curso;
	cout<<"Introduzca el equipo:"<<endl;
	cin>>Equipo;
	cout<<"Introduzca si es lider del grupo o no:"<<endl;
	cout<<"1. si lo es"<<endl;
	cout<<"2. si no lo es"<<endl;
	cin>>lider;
	if(lider!=1){
		lider=2;
	}

	if(DNI.compare(NULL)==0){
		cout<<"ERROR, el DNI está vacío"<<endl;
		return;
	}
	if(Nombre.compare(NULL)==0){
		cout<<"ERROR, el Nombre está vacío"<<endl;
		return;
	}
	if(Apellidos.compare(NULL)==0){
		cout<<"ERROR, el Apellido está vacío"<<endl;
		return;
	}
	if(Telefono==0){
		cout<<"ERROR, el Teléfono está vacío"<<endl;
		return;
	}
	if(Email.compare(NULL)==0){
		cout<<"ERROR, el Email está vacío"<<endl;
		return;
	}
	if(Fecha.compare(NULL)==0){
		cout<<"ERROR, la Fecha de Nacimiento está vacía"<<endl;
		return;
	}
	if(Curso==0){
		cout<<"ERROR, el Curso está vacío"<<endl;
		return;
	}
	if(Buscar_Alumno(DNI)==false){
		aux.Set_DNI(DNI);
		aux.Set_Nombre(Nombre);
		aux.Set_Apellido(Apellidos);
		aux.Set_Telefono(Telefono);
		aux.Set_Email(Email);
		aux.Set_Direccion(Direccion);
		aux.Set_Fecha_Nacimiento(Fecha);
		aux.Set_Curso(Curso);
		aux.Set_Equipo(Equipo);
		aux.Set_Lider(lider);
		
		Set_Alumno(aux);
		cout<<"Alumno introducido con exito"<<endl;
	}
	else{
		cout<<"El alumno ya esta en el sistema"<<endl;
	}
}

void Agenda::Eliminar_Alumno(){

	int pos=Get_Tamano();
	string cadena;
	
	cout<<"Introduzca el DNI del alumno a eliminar:"<<endl;
	cin>>cadena;
	if(Buscar_Alumno(cadena)==true){
		for(int i=0; i<pos; i++){
			if(Get_Alumno(i).Get_DNI()==cadena){
				alumnos.erase(alumnos.begin()+i);
			}
		}
		cout<<"Se ha eliminado el alumno"<<endl;
	}
	else{
		cout<<"ERROR el usuario no esta"<<endl;
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
				cout<<"Introduzca 1 si es lider o 2 si no lo es"<<endl;
				cin>>lider;
				bool encontrado=false;
				int tam=Get_Tamano();
				if(lider==1){
					for(int j=0; j<tam || encontrado==false; j++){
						if(Get_Alumno(j).Get_Equipo()==Get_Alumno(h).Get_Equipo()){
							if(Get_Alumno(j).Get_Lider()==1){
								encontrado==true;
							}
						}
					}
				}
				if(encontrado==false){
					Get_Alumno(h).Set_Lider(lider);	
				}
				else{
					cout<<"Error, ya hay un lider en el grupo"<<endl;
				}
			break;
			
			};	
		}
		cout<<"Cambios realizados con exito"<<endl;
	}
}

void Profesor::Guardar_Fichero(){
	string nomfich;
	char nombre[20], apellido[20], dni[20], fecha[20], telefono[20], email[20], direccion[20], curso[2], equipo[2], lider[2];
	Alumno aux;
	cout<<"Introduzca el nombre del fichero: "<<endl;
	cin>>nomfich;
	ifstream fichero(nomfich.c_str(), ios::binary);
	if(fichero.is_open()){
		fichero.read((char *) &aux, sizeof(Alumno));
		while(!fichero.eof()){
			fichero.read((char *) &aux, sizeof(Alumno));//Puede dar fallos por los strings, si ocurre eso, cambiar los strings por char.
		}
		/*while(ficheroEntrada.getline(dni, 256, ',')){
			ficheroEntrada.getline(apellido, 256, ',');
			ficheroEntrada.getline(nombre, 256, ',');
			ficheroEntrada.getline(fecha, 256, ',');
			ficheroEntrada.getline(telefono, 256, ',');
			ficheroEntrada.getline(email, 256, ',');
			ficheroEntrada.getline(direccion, 256, ',');
			ficheroEntrada.getline(curso, 256, ',');
			ficheroEntrada.getline(equipo, 256, ',');
			ficheroEntrada.getline(lider, 256, '\n');
			aux.Set_DNI(dni);
			aux.Set_Nombre(nombre);
			aux.Set_Apellido(apellido);
			aux.Set_Direccion(direccion);
			aux.Set_Fecha_Nacimiento(fecha);
			aux.Set_Email(email);
			aux.Set_Telefono(atoi(telefono));
			aux.Set_Curso(atoi(curso));
			aux.Set_Equipo(atoi(equipo));
			if(atoi(lider)==1){
				aux.Set_Lider(true);
			}
			else{
				aux.Set_Lider(false);
			}
			agenda_.Set_Alumno(aux);
		}Estas lineas sirven para recibir ficheros de texto y no binarios*/
		fichero.close();
	}
	else{
		cout<<"ERROR el fichero no se ha abierto"<<endl;
	}
}

void Profesor::Cargar_Fichero(){
	string nomfich;
	int i;
	char dni[20], nombre[20], apellido[20], email[20], direccion[20], fecha[20];
	cout<<"Introduzca el nombre del fichero: "<<endl;
	cin>>nomfich;
	ofstream fichero(nomfich.c_str(), ios::binary);
	if(fichero.is_open()){
		for(i=0; i<Get_Agenda().Get_Tamano(); i++){
			strcpy(dni, Get_Agenda().Get_Alumno(i).Get_DNI().c_str());
			strcpy(nombre, Get_Agenda().Get_Alumno(i).Get_Nombre().c_str());
			strcpy(apellido, Get_Agenda().Get_Alumno(i).Get_Apellido().c_str());
			strcpy(email, Get_Agenda().Get_Alumno(i).Get_Email().c_str());
			strcpy(direccion, Get_Agenda().Get_Alumno(i).Get_Direccion().c_str());
			strcpy(fecha, Get_Agenda().Get_Alumno(i).Get_Fecha_Nacimiento().c_str());
			fichero.write((char *)dni, sizeof(dni));
			fichero.write((char *)nombre, sizeof(nombre));
			fichero.write((char *)apellido, sizeof(apellido));
			fichero.write((char *)email, sizeof(email));
			fichero.write((char *)direccion, sizeof(direccion));
			fichero.write((char *)fecha, sizeof(fecha));
			fichero.write((char *)Get_Agenda().Get_Alumno(i).Get_Telefono(), sizeof(int));
			fichero.write((char *)Get_Agenda().Get_Alumno(i).Get_Curso(), sizeof(int));
			fichero.write((char *)Get_Agenda().Get_Alumno(i).Get_Equipo(), sizeof(int));
			fichero.write((char *)Get_Agenda().Get_Alumno(i).Get_Lider(), sizeof(int));
		}
		cout<<"Se han introducido los datos con exito"<<endl;
	}
	else{
		cout<<"El fichero no se ha podido abrir"<<endl;
	}
/*coge los datos del sistema y los mete en un fichero
Abrimos el fichero y ponemos la correccion de errores y todo eso
recorremos el vector de la agenda y vamos mentiendo dentro de cada linea del fichero 
todos los valores de un alumno y pasamos a la siguiente linea*/
}

void Profesor::Hacer_Copia(){
	//Aqui es donde calculamos la fecha actual;
	time_t rawtime;
	struct tm * tlocal;
	
	time(&rawtime);
	tlocal=localtime(&rawtime);
	char output[11];
	strftime(output, 11,"%d/%m/%y", tlocal);
	
	int i;
	char dni[20], nombre[20], apellido[20], email[20], direccion[20], fecha[20];
	ofstream fichero(output, ios::binary);
	if(fichero.is_open()){
		for(i=0; i<Get_Agenda().Get_Tamano(); i++){
			strcpy(dni, Get_Agenda().Get_Alumno(i).Get_DNI().c_str());
			strcpy(nombre, Get_Agenda().Get_Alumno(i).Get_Nombre().c_str());
			strcpy(apellido, Get_Agenda().Get_Alumno(i).Get_Apellido().c_str());
			strcpy(email, Get_Agenda().Get_Alumno(i).Get_Email().c_str());
			strcpy(direccion, Get_Agenda().Get_Alumno(i).Get_Direccion().c_str());
			strcpy(fecha, Get_Agenda().Get_Alumno(i).Get_Fecha_Nacimiento().c_str());
			fichero.write((char *)dni, sizeof(dni));
			fichero.write((char *)nombre, sizeof(nombre));
			fichero.write((char *)apellido, sizeof(apellido));
			fichero.write((char *)email, sizeof(email));
			fichero.write((char *)direccion, sizeof(direccion));
			fichero.write((char *)fecha, sizeof(fecha));
			fichero.write((char *)Get_Agenda().Get_Alumno(i).Get_Telefono(), sizeof(int));
			fichero.write((char *)Get_Agenda().Get_Alumno(i).Get_Curso(), sizeof(int));
			fichero.write((char *)Get_Agenda().Get_Alumno(i).Get_Equipo(), sizeof(int));
			fichero.write((char *)Get_Agenda().Get_Alumno(i).Get_Lider(), sizeof(int));
		}
		cout<<"Se han introducido los datos con exito"<<endl;
	}
	else{
		cout<<"El fichero no se ha podido abrir"<<endl;
	}
}

void Profesor::Cargar_Copia(){
	string nomfich;
	char nombre[20], apellido[20], dni[20], fecha[20], telefono[20], email[20], direccion[20], curso[2], equipo[2], lider[2];
	Alumno aux;
	cout<<"Introduzca el nombre del fichero: "<<endl;
	cin>>nomfich;
	ifstream fichero(nomfich.c_str(), ios::binary);
	if(fichero.is_open()){
		fichero.read((char *) &aux, sizeof(Alumno));
		while(!fichero.eof()){
			fichero.read((char *) &aux, sizeof(Alumno));//Puede dar fallos por los strings, si ocurre eso, cambiar los strings por char.
		}
		fichero.close();
	}
	else{
		cout<<"ERROR el fichero no se ha abierto"<<endl;
	}
}

void Agenda::Imprimir_Pantalla(){
	int tamano=Get_Tamano();
	ofstream fich("Alumnos.md");
	for(int i=0; i<tamano; i++){
		cout<<"Alumno: "<<i<<endl;
		cout<<"DNI: "<<Get_Alumno(i).Get_DNI()<<endl;
		cout<<"Nombre: "<<Get_Alumno(i).Get_Nombre()<<endl;
		cout<<"Apellido: "<<Get_Alumno(i).Get_Apellido()<<endl;
		cout<<"Email: "<<Get_Alumno(i).Get_Email()<<endl;
		cout<<"Direccion: "<<Get_Alumno(i).Get_Direccion()<<endl;
		cout<<"Fecha de nacimiento: "<<Get_Alumno(i).Get_Fecha_Nacimiento()<<endl;
		cout<<"Telefono: "<<Get_Alumno(i).Get_Telefono()<<endl;
		cout<<"Curso mas alto: "<<Get_Alumno(i).Get_Curso()<<endl;
		cout<<"Equipo: "<<Get_Alumno(i).Get_Equipo()<<endl;
		if(Get_Alumno(i).Get_Lider()==1){
			cout<<"El alumno es lider de grupo"<<endl<<endl;
		}
		else{
			cout<<"El alumno no es lider del grupo"<<endl;
		}
		fich<<"## Alumno: "<<i<<endl;
		fich<<"### DNI: "<<Get_Alumno(i).Get_DNI()<<endl;
		fich<<"### Nombre: "<<Get_Alumno(i).Get_Nombre()<<endl;
		fich<<"### Apellido: "<<Get_Alumno(i).Get_Apellido()<<endl;
		fich<<"### Email: "<<Get_Alumno(i).Get_Email()<<endl;
		fich<<"### Direccion: "<<Get_Alumno(i).Get_Direccion()<<endl;
		fich<<"### Fecha de nacimiento: "<<Get_Alumno(i).Get_Fecha_Nacimiento()<<endl;
		fich<<"### Telefono: "<<Get_Alumno(i).Get_Telefono()<<endl;
		fich<<"### Curso mas alto: "<<Get_Alumno(i).Get_Curso()<<endl;
		fich<<"### Equipo: "<<Get_Alumno(i).Get_Equipo()<<endl;
		if(Get_Alumno(i).Get_Lider()==1){
			fich<<"### El alumno es lider de grupo"<<endl;
		}
		else{
			fich<<"### El alumno no es lider del grupo"<<endl<<endl;
		}
	}
	fich.close();
}

void Profesor::Registrar_Profesor(){

 	string Usuario=NULL, Password=NULL, Rol=NULL;
 	char usuario, password, rol;
 	Profesor p;
 	ifstream ficheroEntrada("usuarios.txt");

 	cout<<"Introduzca el Usuario:"<<endl;
	cin>>Usuario;

	cout<<"Introduzca la contraseña:"<<endl;
	cin>>Password;

	cout<<"Introduzca el rol de profesor que cumple:"<<endl;
	cin>>Rol;

	if(Usuario.compare(NULL)==0){
		cout<<"ERROR, el Usuario está vacío"<<endl;
		return;
	}

	if(Password.compare(NULL)==0){
		cout<<"ERROR, la contraseña está vacía"<<endl;
		return;
	}

	if(Rol.compare(NULL)==0){
		cout<<"ERROR, el rol está vacío"<<endl;
		return;
	}

	while(!ficheroEntrada.eof()){

		ficheroEntrada.read((char *);
		Get_Agenda().Set_Profesor(p);
	}

 }

 void Profesor::Iniciar_Sesion(){

 	string Usuario=NULL, Password=NULL, Rol=NULL;
 	Profesor p;

 	cout<<"Introduzca el Usuario:"<<endl;
	cin>>Usuario;

	cout<<"Introduzca la contraseña:"<<endl;
	cin>>Password;

	cout<<"Introduzca el rol de profesor que cumple:"<<endl;
	cin>>Rol;


 	if(Usuario.compare(p.Get_Usuario())!=0){

		cout<<"ERROR, el usuario no coincide"<<endl;
		return;
	}

	if(Password.compare(p.Get_Password())!=0){

		cout<<"ERROR, ela contraseña no coincide"<<endl;
		return;
	}

	
 }

