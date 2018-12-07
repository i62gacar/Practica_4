#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <string>

using namespace std;

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
  string Get_Fecha_Nacimiento(){return Fecha_Nacimiento_;}
  void Set_Fecha_Nacimiento(string fecha_nacimiento){Fecha_Nacimiento_=fecha_nacimiento;}
};

class Alumno: public Persona{
private:
  int Curso_Mas_Alto_, Equipo_;
  bool Lider_;
public:
  int Get_Curso(){return Curso_Mas_Alto_;}
  void Set_Curso(int curso){Curso_Mas_Alto_=curso;}
  int Get_Equipo(){return Equipo_;}
  void Set_Equipo(int equipo){Equipo_=equipo;}
  bool Get_Lider(){return Lider_;}
  void Set_Lider(bool lider){Lider_=lider;}
};


class Agenda{
private:
  Alumno alumnos[];
public:
  bool Buscar_Alumno(string cadena);
  //void Imprimir_Pantalla(){}
  //void Visualizar_Alumno(){}
  void Insertar_Alumno();
  //void Modificar_Alumno();
  void Eliminar_Alumno();
};

class Profesor: public Persona{
private:
  bool Rol_;
  Agenda agenda_;
public:
  bool Get_Rol(){return Rol_;}
  void Set_Rol(bool rol){Rol_=rol;}
  Agenda Get_Agenda(){return agenda_;}
  void Set_Agenda(Agenda agenda){agenda_=agenda;}
  //void Hacer_Copia(){}
  ///void Registrar_Profesor(){}
  //void Iniciar_Sesion(){}
  //void Guardar_Fichero(){}
  //void Cargar_Fichero(){}
};

#endif
