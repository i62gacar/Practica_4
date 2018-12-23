#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <string>
#include <vector>

using namespace std;

struct Auxiliar_alumno{
	char dni[20], apellido[20], nombre[20], email[20], direccion[20], fecha[20];
	int telefono, curso, equipo, lider;
};

struct Auxiliar_profesor{
	char usuario[20], password[20], rol[20];
};

class Persona{
private:
  string DNI_, Nombre_, Apellido_, Email_, Direccion_, Fecha_Nacimiento_;
  int Telefono_;
public:
  string Get_DNI(){return DNI_;}
  void Set_DNI(string DNI){DNI_=DNI;}
  string Get_Nombre(){return Nombre_;}
  void Set_Nombre(string nombre){Nombre_=nombre;}
  string Get_Apellido(){return Apellido_;}
  void Set_Apellido(string apellido){Apellido_=apellido;}
  int Get_Telefono(){return Telefono_;}
  void Set_Telefono(int telefono){Telefono_=telefono;}
  string Get_Email(){return Email_;}
  void Set_Email(string email){Email_=email;}
  string Get_Direccion(){return Direccion_;}
  void Set_Direccion(string direccion){Direccion_=direccion;}
  string Get_Fecha_Nacimiento(){return Fecha_Nacimiento_;}
  void Set_Fecha_Nacimiento(string fecha_nacimiento){Fecha_Nacimiento_=fecha_nacimiento;}
};

class Alumno: public Persona{
private:
  int Curso_Mas_Alto_, Equipo_, Lider_;
public:
  int Get_Curso(){return Curso_Mas_Alto_;}
  void Set_Curso(int curso){Curso_Mas_Alto_=curso;}
  int Get_Equipo(){return Equipo_;}
  void Set_Equipo(int equipo){Equipo_=equipo;}
  int Get_Lider(){return Lider_;}
  void Set_Lider(int lider){Lider_=lider;}
  void Set_Alumno(Alumno alumno);
};


class Agenda{
private:
  vector<Alumno> alumnos;
public:
  Alumno Get_Alumno(int h){return alumnos[h];}
  void Set_Alumno_Lista(Alumno alumno){alumnos.push_back(alumno);}
  int Get_Tamano();
  bool Buscar_Alumno(string cadena);
  void Imprimir_Pantalla();
  void Visualizar_Grupo();
  void Insertar_Alumno();
  void Modificar_Alumno();
  void Eliminar_Alumno();
};

class Profesor: public Persona{
private:
  string Usuario_, Password_, Rol_;
public:
  string Get_Usuario(){return Usuario_;}
  void Set_Usuario(string Usuario){Usuario_=Usuario;}
  string Get_Password(){return Password_;}
  void Set_Password(string Password){Password_=Password;}
  string Get_Rol(){return Rol_;}
  void Set_Rol(string rol){Rol_=rol;}
  void Set_Profesor(Profesor p);
  void Hacer_Copia(Agenda &agenda);
  void Cargar_Copia(Agenda &agenda);
  void Registrar_Profesor(vector<Profesor>& profesores);
  bool Iniciar_Sesion(vector<Profesor>& profesores);
  void Guardar_Fichero(Agenda &agenda);
  void Cargar_Fichero(Agenda &agenda);
  void Cargar_Usuarios(vector<Profesor>& profesores);
};

#endif
