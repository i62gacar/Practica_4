#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include "programa.h"

using namespace std;


int Agenda::Get_Tamano(){
	int tam;
	if(alumnos.empty()==true){
		tam=0;
	}
	else{
		tam=alumnos.size();
	}
	return tam;
}

void Profesor::Set_Profesor(Profesor p){

	Set_Usuario(p.Get_Usuario());
	Set_Password(p.Get_Password());
	Set_Rol(p.Get_Rol());
}

void Alumno::Set_Alumno(Alumno alumno){
	Set_DNI(alumno.Get_DNI());
	Set_Nombre(alumno.Get_Nombre());
	Set_Apellido(alumno.Get_Apellido());
	Set_Direccion(alumno.Get_Direccion());
	Set_Email(alumno.Get_Email());
	Set_Telefono(alumno.Get_Telefono());
	Set_Fecha_Nacimiento(alumno.Get_Fecha_Nacimiento());
	Set_Curso(alumno.Get_Curso());
	Set_Equipo(alumno.Get_Equipo());
	Set_Lider(alumno.Get_Lider());
}

bool Agenda::Buscar_Alumno(string cadena){

	bool enc=false;
	int aux[20], n=0, i, tamano=Get_Tamano();
	string DNI;
	if(alumnos.empty()==true){
		return enc;
	}
	else{
		for(i=0; i<tamano && enc==false; i++){

			if(cadena==Get_Alumno(i).Get_DNI()){

				enc=true;
			}
			if(cadena==Get_Alumno(i).Get_Apellido()){

				aux[n]=i;
				n++;
			}
		}
		while(enc==false && n!=0){

			if(n==1){
				enc=true;
			}
			if(n>1){
				cout<<"Hay más de un alumno, introduce el DNI."<<endl;
				cin>>DNI;
				for(i=0; i<n; i++){
					if(DNI==Get_Alumno(aux[i]).Get_DNI()){
						enc=true;
					}
				}
			}
		}
		return enc;
	}
}

void Agenda::Insertar_Alumno(){
	string DNI, Nombre, Apellidos, Email, Direccion, Fecha;
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

	if(DNI=="NULL"){
		cout<<"ERROR, el DNI está vacío"<<endl;
		return;
	}
	if(Nombre.compare("NULL")==0){
		cout<<"ERROR, el Nombre está vacío"<<endl;
		return;
	}
	if(Apellidos.compare("NULL")==0){
		cout<<"ERROR, el Apellido está vacío"<<endl;
		return;
	}
	if(Telefono==0){
		cout<<"ERROR, el Teléfono está vacío"<<endl;
		return;
	}
	if(Email.compare("NULL")==0){
		cout<<"ERROR, el Email está vacío"<<endl;
		return;
	}
	if(Fecha.compare("NULL")==0){
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
		Set_Alumno_Lista(aux);
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
			cin>>opc;
			if(opc>0 && opc<11){
				datos[n]=opc;
				n++;
			}
			else if(opc==0){

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
				alumnos[h].Set_Nombre(cadena);
			break;

			case 2:
				cout<<"Introduzca unos nuevos apellidos"<<endl;
				cin>>cadena;
				alumnos[h].Set_Apellido(cadena);
			break;

			case 3:
				cout<<"Introduzca un nuevo DNI"<<endl;
				cin>>cadena;
				alumnos[h].Set_DNI(cadena);
			break;

			case 4:
				cout<<"Introduzca un nuevo email"<<endl;
				cin>>cadena;
				alumnos[h].Set_Email(cadena);
			break;

			case 5:
				cout<<"Introduzca una nueva direccion"<<endl;
				cin>>cadena;
				alumnos[h].Set_Direccion(cadena);
			break;

			case 6:
				cout<<"Introduzca un nuevo telefono"<<endl;
				cin>>aux;
				alumnos[h].Set_Telefono(aux);
			break;

			case 7:
				cout<<"Introduzca una nueva fecha de nacimiento"<<endl;
				cin>>cadena;
				alumnos[h].Set_Fecha_Nacimiento(cadena);
			break;

			case 8:
				cout<<"Introduzca un nuevo curso mas alto"<<endl;
				cin>>aux;
				alumnos[h].Set_Curso(aux);
			break;

			case 9:
				cout<<"Introduzca un nuevo equipo"<<endl;
				cin>>aux;
				alumnos[h].Set_Equipo(aux);
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
					alumnos[h].Set_Lider(lider);
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

void Profesor::Guardar_Fichero(Agenda &agenda){
	string nomfich;
	Auxiliar_alumno aux;
	Alumno alumno;
	cout<<"Introduzca el nombre del fichero: "<<endl;
	cin>>nomfich;
	ifstream fichero(nomfich.c_str(), ios::binary);
	if(fichero.is_open()){
		fichero.read((char *) &aux, sizeof(Auxiliar_alumno));
		while(!fichero.eof()){
			alumno.Set_DNI(aux.dni);
			alumno.Set_Nombre(aux.nombre);
			alumno.Set_Apellido(aux.apellido);
			alumno.Set_Telefono(aux.telefono);
			alumno.Set_Email(aux.email);
			alumno.Set_Direccion(aux.direccion);
			alumno.Set_Fecha_Nacimiento(aux.fecha);
			alumno.Set_Curso(aux.curso);
			alumno.Set_Equipo(aux.equipo);
			alumno.Set_Lider(aux.lider);
			agenda.Set_Alumno_Lista(alumno);
			fichero.read((char *) &aux, sizeof(Auxiliar_alumno));
		}
		fichero.close();
		cout<<"Los datos se han introducido con exito"<<endl;
	}
	else{
		cout<<"Error el fichero no se ha abierto"<<endl;
	}
}

void Profesor::Cargar_Fichero(Agenda &agenda){
	string nomfich;
	int i;
	Auxiliar_alumno aux;
	cout<<"Introduzca el nombre del fichero: "<<endl;
	cin>>nomfich;
	ofstream fichero(nomfich.c_str(), ios::binary);
	if(fichero.is_open()){
		for(i=0; i<agenda.Get_Tamano(); i++){
			strcpy(aux.dni, agenda.Get_Alumno(i).Get_DNI().c_str());
			strcpy(aux.nombre, agenda.Get_Alumno(i).Get_Nombre().c_str());
			strcpy(aux.apellido, agenda.Get_Alumno(i).Get_Apellido().c_str());
			strcpy(aux.email, agenda.Get_Alumno(i).Get_Email().c_str());
			strcpy(aux.direccion, agenda.Get_Alumno(i).Get_Direccion().c_str());
			strcpy(aux.fecha, agenda.Get_Alumno(i).Get_Fecha_Nacimiento().c_str());
			aux.telefono=agenda.Get_Alumno(i).Get_Telefono();
			aux.curso=agenda.Get_Alumno(i).Get_Curso();
			aux.equipo=agenda.Get_Alumno(i).Get_Equipo();
			aux.lider=agenda.Get_Alumno(i).Get_Lider();
			fichero.write((const char *)&aux, sizeof(aux));
		}
		cout<<"Se han introducido los datos con exito"<<endl;
	}
	else{
		cout<<"El fichero no se ha podido abrir"<<endl;
	}
}

void Profesor::Hacer_Copia(Agenda &agenda){
	time_t rawtime;
	struct tm * tlocal;

	time(&rawtime);
	tlocal=localtime(&rawtime);
	char output[11];
	strftime(output, 11,"%d-%m-%y", tlocal);

	int i;
	Auxiliar_alumno aux;
	ofstream fichero(output, ios::binary);
	if(fichero.is_open()){
		for(i=0; i<agenda.Get_Tamano(); i++){
			strcpy(aux.dni, agenda.Get_Alumno(i).Get_DNI().c_str());
			strcpy(aux.nombre, agenda.Get_Alumno(i).Get_Nombre().c_str());
			strcpy(aux.apellido, agenda.Get_Alumno(i).Get_Apellido().c_str());
			strcpy(aux.email, agenda.Get_Alumno(i).Get_Email().c_str());
			strcpy(aux.direccion, agenda.Get_Alumno(i).Get_Direccion().c_str());
			strcpy(aux.fecha, agenda.Get_Alumno(i).Get_Fecha_Nacimiento().c_str());
			aux.telefono=agenda.Get_Alumno(i).Get_Telefono();
			aux.curso=agenda.Get_Alumno(i).Get_Curso();
			aux.equipo=agenda.Get_Alumno(i).Get_Equipo();
			aux.lider=agenda.Get_Alumno(i).Get_Lider();
			fichero.write((const char *)&aux, sizeof(aux));
		}
		cout<<"La copia se ha generado correctamente como "<<output<<endl;
	}
	else{
		cout<<"El fichero no se ha podido abrir"<<endl;
	}
}

void Profesor::Cargar_Copia(Agenda &agenda){
	string nomfich;
	Auxiliar_alumno aux;
	Alumno alumno;
	cout<<"Introduzca el nombre del fichero: "<<endl;
	cin>>nomfich;
	ifstream fichero(nomfich.c_str(), ios::binary);
	if(fichero.is_open()){
		fichero.read((char *) &aux, sizeof(Auxiliar_alumno));
		while(!fichero.eof()){
			alumno.Set_DNI(aux.dni);
			alumno.Set_Nombre(aux.nombre);
			alumno.Set_Apellido(aux.apellido);
			alumno.Set_Telefono(aux.telefono);
			alumno.Set_Email(aux.email);
			alumno.Set_Direccion(aux.direccion);
			alumno.Set_Fecha_Nacimiento(aux.fecha);
			alumno.Set_Curso(aux.curso);
			alumno.Set_Equipo(aux.equipo);
			alumno.Set_Lider(aux.lider);
			agenda.Set_Alumno_Lista(alumno);
			fichero.read((char *) &aux, sizeof(Auxiliar_alumno));
		}
		fichero.close();
		cout<<"La copia se han introducido con exito"<<endl;
	}
	else{
		cout<<"Error el fichero no se ha abierto"<<endl;
	}
}

void Agenda::Imprimir_Pantalla(){
	int tamano=Get_Tamano(), opcion;
	char dni[20], nombre[20], apellido[20], email[20], direccion[20], fecha[20];
	
	Auxiliar_alumno aux;
	ofstream fich("Alumnos.md", ios::binary);
	if(fich.is_open()){
/*		cout<<"Porque variable desea ordenar: "<<endl;
		cout<<"1. DNI"<<endl;
		cout<<"2. Nombre"<<endl;
		cout<<"3. Apellido"<<endl;
		cout<<"4. Curso mas alto"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				for(int i=0; i<tamano; i++){
					for(int j=i; j<tamano; j++){
						if(Get_Alumno(i).Get_DNI()<Get_Alumno(i).Get_DNI()){
							aux.Set_Alumno(Get_Alumno(i));
							Get_Alumno(i).Set_Alumno(Get_Alumno(j));
							Get_Alumno(j).Set_Alumno(aux);
						}
					}
				}
			break;

			case 2:
				for(int i=0; i<tamano; i++){
					for(int j=i; j<tamano; j++){
						if(Get_Alumno(i).Get_Nombre()<Get_Alumno(i).Get_Nombre()){
							aux.Set_Alumno(Get_Alumno(i));
							Get_Alumno(i).Set_Alumno(Get_Alumno(j));
							Get_Alumno(j).Set_Alumno(aux);
						}
					}
				}
			break;

			case 3:
				for(int i=0; i<tamano; i++){
					for(int j=i; j<tamano; j++){
						if(Get_Alumno(i).Get_Apellido()<Get_Alumno(i).Get_Apellido()){
							aux.Set_Alumno(Get_Alumno(i));
							Get_Alumno(i).Set_Alumno(Get_Alumno(j));
							Get_Alumno(j).Set_Alumno(aux);
						}
					}
				}
			break;

			case 4:
				for(int i=0; i<tamano; i++){
					for(int j=i; j<tamano; j++){
						if(Get_Alumno(i).Get_Curso()<Get_Alumno(i).Get_Curso()){
							aux.Set_Alumno(Get_Alumno(i));
							Get_Alumno(i).Set_Alumno(Get_Alumno(j));
							Get_Alumno(j).Set_Alumno(aux);
						}
					}
				}
			break;

			default:
				cout<<"Opcion incorrecta"<<endl;
			break;
		};*/
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
			strcpy(aux.dni, Get_Alumno(i).Get_DNI().c_str());
			strcpy(aux.nombre, Get_Alumno(i).Get_Nombre().c_str());
			strcpy(aux.apellido, Get_Alumno(i).Get_Apellido().c_str());
			strcpy(aux.email, Get_Alumno(i).Get_Email().c_str());
			strcpy(aux.direccion, Get_Alumno(i).Get_Direccion().c_str());
			strcpy(aux.fecha, Get_Alumno(i).Get_Fecha_Nacimiento().c_str());
			aux.telefono=Get_Alumno(i).Get_Telefono();
			aux.curso=Get_Alumno(i).Get_Curso();
			aux.equipo=Get_Alumno(i).Get_Equipo();
			aux.lider=Get_Alumno(i).Get_Lider();
			fich.write((const char *)&aux, sizeof(aux));
		}
		fich.close();
	}
}

void Profesor::Registrar_Profesor(vector<Profesor>& profesores){

 	string Usuario, Password, Rol;
 	int rol=0;
 	Auxiliar_profesor aux;
 	bool encontrado=false;
 	Profesor p;
 	ofstream fich("usuarios.bin", ios::binary);

 	cout<<"Introduzca el Usuario:"<<endl;
	cin>>Usuario;

	cout<<"Introduzca la contraseña:"<<endl;
	cin>>Password;

	cout<<"Introduzca el rol de profesor que cumple:"<<endl<<"1. si es coordinador"<<endl<<"2. si es ayudante"<<endl;
	cin>>rol;
	if(rol==1){
		Rol="coordinador";
	}
	else{
		Rol="ayudante";
	}

	if(Usuario.compare("NULL")==0){
		cout<<"ERROR, el Usuario está vacío"<<endl;
		return;
	}

	if(Password.compare("NULL")==0){
		cout<<"ERROR, la contraseña está vacía"<<endl;
		return;
	}

	for(int i=0; i<profesores.size() && encontrado==false; i++){
		if(profesores[i].Get_Usuario()==Usuario){
			encontrado=true;
		}
	}
	if(encontrado==false){
		if(fich.is_open()){
			p.Set_Usuario(Usuario);
			p.Set_Password(Password);
			p.Set_Rol(Rol);
			profesores.push_back(p);
			strcpy(aux.usuario, Usuario.c_str());
			strcpy(aux.password, Password.c_str());
			strcpy(aux.rol, Rol.c_str());
			fich.write((const char *)&aux, sizeof(aux));
			cout<<"Usuario introducido con exito"<<endl<<endl;
		}
	}
	else{
		cout<<"El usuario ya existe"<<endl<<endl;
	}
	fich.close();
}

bool Profesor::Iniciar_Sesion(vector<Profesor>& profesores){

 	string Usuario, Password;
 	bool exito=false, encontrado=false;
 	Profesor p;
 	int i;

 	cout<<"Introduzca el Usuario:"<<endl;
	cin>>Usuario;

	cout<<"Introduzca la contraseña:"<<endl;
	cin>>Password;

	if(Usuario.compare("NULL")==0){
		cout<<"ERROR, el Usuario está vacío"<<endl;
		return exito;
	}

	if(Password.compare("NULL")==0){
		cout<<"ERROR, la contraseña está vacía"<<endl;
		return exito;
	}
	for(i=0; i<profesores.size() && exito==false && encontrado==false; i++){
		if(profesores[i].Get_Usuario()==Usuario){
			encontrado=true;
			if(profesores[i].Get_Password()==Password){
				exito=true;
				Set_Usuario(profesores[i].Get_Usuario());
				Set_Password(profesores[i].Get_Password());
				Set_Rol(profesores[i].Get_Rol());
			}
		}
	}
	return exito;
}

void Profesor::Cargar_Usuarios(vector<Profesor>& profesores){
	Auxiliar_profesor aux;
	Profesor profesor;
	ifstream fichero("usuarios.bin", ios::binary);
	if(fichero.is_open()){
		fichero.read((char *) &aux, sizeof(Auxiliar_profesor));
		while(!fichero.eof()){
			profesor.Set_Usuario(aux.usuario);
			profesor.Set_Password(aux.password);
			profesor.Set_Rol(aux.rol);
			profesores.push_back(profesor);
			//cout<<profesor.Get_Usuario()<<endl;
			fichero.read((char *) &aux, sizeof(Auxiliar_profesor));
		}
		fichero.close();
		cout<<"Los profesores se han introducido con exito"<<endl<<endl;
	}
	else{
		cout<<"Error el fichero no se ha abierto"<<endl<<endl;
	}
}

void Agenda::Visualizar_Grupo(){

	int grupo=0, tam=Get_Tamano(), aux[50], n=0, i;

	cout<<"Indique el grupo que desea visualizar"<<endl;
	cin>>grupo;
	for(i=0; i<tam; i++){
		if(Get_Alumno(i).Get_Equipo()==grupo){
			aux[n]=i;
			n++;
		}
	}
	if(n==0){
		cout<<"Dicho grupo no existe"<<endl;
		return;
	}
	else{
		cout<<"El equipo "<<grupo<<" está compuesto por:"<<endl;
		for(i=0; i<n; i++){
			cout<<"Nombre: "<<Get_Alumno(aux[i]).Get_Nombre()<<endl;
			cout<<"Apellido: "<<Get_Alumno(aux[i]).Get_Apellido()<<endl;
			cout<<"DNI: "<<Get_Alumno(aux[i]).Get_DNI()<<endl;
			cout<<"Email: "<<Get_Alumno(aux[i]).Get_Email()<<endl;
			cout<<"Direccion: "<<Get_Alumno(aux[i]).Get_Direccion()<<endl;
			cout<<"Fecha de nacimiento: "<<Get_Alumno(aux[i]).Get_Fecha_Nacimiento()<<endl;
			cout<<"Telefono: "<<Get_Alumno(aux[i]).Get_Telefono()<<endl;
			cout<<"Curso mas alto: "<<Get_Alumno(aux[i]).Get_Curso()<<endl;
			cout<<"Equipo: "<<Get_Alumno(aux[i]).Get_Equipo()<<endl;
			cout<<"Lider: "<<Get_Alumno(aux[i]).Get_Lider()<<endl<<endl;
		}
	}


}
