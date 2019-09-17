//
//  main.cpp
//  Proyecto 3
//
//  Created by Ernesto Garcia on 4/14/19.
//  Copyright © 2019 Ernesto Garcia. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

#include "Reserva.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

//Función que recibe el arreglo de apuntadores y carga los datos del archivo Material
void cargaMaterial(Material *mat[],int &cont){
    ifstream input;
    input.open("Material.txt");
    int id,pag,duracion;
    string titulo,autor,sistema;
    char tipo;
    while (input >> id >> titulo >> tipo){
        switch(tipo){
            case 'L':
                input >> pag >> autor;
                mat[cont]=new Libro(id,titulo,pag,autor);
                break;
            case 'D':
                input >> duracion;
                mat[cont]=new Disco(id,titulo,duracion);
                break;
            default:
                input >> sistema;
                mat[cont]=new Software(id,titulo,sistema);
                break;
        }
        cont++;
    }
    input.close();
}

//Función que recibe el arrglo de reservas y carga los datos del archivo Reserva
void cargaReserva(Reserva reserv[],int &cont){
    ifstream input;
    input.open("Reserva.txt");
    int dd,aa,mm,mat,client;
    while (input >> dd >> mm >> aa >> mat >> client){
        Fecha f1(dd,mm,aa);
        reserv[cont].setFechaReservacion(f1);
        reserv[cont].setIdMaterial(mat);
        reserv[cont].setIdCliente(client);
        cont++;
    }
    input.close();
}

//Funcion que muestra el menu
void mostrarMenu(){
    cout << "Menú: " << endl << "a. Consultar la lista de materiales" << endl << "b. Consultar la lista de reservaciones" << endl << "c. Consultar las reservaciones de un material" << endl << "d. Consultar las reservaciones de una fecha dada" << endl << "e. Hacer una reservación" << endl << "f. Terminar" << endl;
}

//Funcion que recibe un idMaterial y regresa la posicion en donde se encuentra dentro del arreglo de materiales
int tipoMaterial(Material *mat[],int cont,int idMaterial){
    for(int i=0;i<cont;i++){
        if(mat[i]->getIdMaterial()==idMaterial){
            return i;
        }
    }
    return cont;
}

//Funcion que verfica si un material existe 
bool verifMaterial(Material *mat[],int cont,int idMaterial){
    for(int i=0;i<cont;i++){
        if(mat[i]->getIdMaterial()==idMaterial)
            return true;
    }
    return false;
}

//Función que carga al archivo de reservas los cambios hechos durante el programa
void cargaCambios(Reserva reserv[],int cont){
    ofstream output;
    output.open("Reserva.txt");
    for(int i=0;i<cont;i++){
        output << reserv[i].getFechaReservacion().getDia() << " " <<  reserv[i].getFechaReservacion().getMes() << " " << reserv[i].getFechaReservacion().getAnio() << " " << reserv[i].getIdMaterial() << " " << reserv[i].getIdCliente() << endl;
    }
    output.close();
}

Material *mat[20];
Reserva reserv[50];
int contMat,contResv,id,cliente;
char opcion;

int main() {
    cargaMaterial(mat,contMat);
    cargaReserva(reserv,contResv);
    do{
        bool hay=false;
        int dd,mm,aa;
        Fecha f1;
        mostrarMenu();
        cin >> opcion;
        switch(opcion){
            case 'a':
                cout << endl;
                for(int i=0;i<contMat;i++)
                    mat[i]->muestra();
                cout << endl;
                break;
            case 'b':
                cout << endl;
                for(int i=0;i<contResv;i++)
                    cout << "Inicia: " << reserv[i].getFechaReservacion() << " -- Termina: " << reserv[i].calculaFechaFinReserva(mat[tipoMaterial(mat,contMat,reserv[i].getIdMaterial())]->cantidadDeDiasDePrestamo()) <<" -- "<< mat[tipoMaterial(mat,contMat,reserv[i].getIdMaterial())]->getTitulo() << " -- Cliente: " << reserv[i].getIdCliente() << endl;
                cout << endl;
                break;
            case 'c':
                do{
                    if(hay==false)
                    cout << endl << "Dame el ID del material " << endl;
                    hay=true;
                    cin>>id;
                    if(!verifMaterial(mat,contMat,id))
                        cout << "Este material no existe, intenta de nuevo" << endl;
                }while(!verifMaterial(mat,contMat,id));
                hay=false;
                for(int i=0;i<contResv;i++){
                    if(reserv[i].getIdMaterial()==id){
                        if(hay==false)
                            cout << endl;
                        hay=true;
                        cout << mat[tipoMaterial(mat,contMat,reserv[i].getIdMaterial())]->getTitulo() << " -- Inicia: " << reserv[i].getFechaReservacion() << " -- Termina: " << reserv[i].calculaFechaFinReserva(mat[tipoMaterial(mat,contMat,reserv[i].getIdMaterial())]->cantidadDeDiasDePrestamo()) << endl;
                    }
                }
                if(!hay)
                    cout <<endl << "No hay reservas de este material" << endl;
                cout << endl;
                break;
            case 'd':
                cout << endl << "Dame el día" << endl;
                cin >> dd;
                cout << "Dame el mes" << endl;
                cin >> mm;
                cout << "Dame el año" << endl;
                cin >> aa;
                cout << endl;
                f1.setFecha(dd,mm,aa);
                for(int i=0;i<contResv;i++){
                    if(f1 >= reserv[i].getFechaReservacion() && f1<=reserv[i].calculaFechaFinReserva(mat[tipoMaterial(mat,contMat,reserv[i].getIdMaterial())]->cantidadDeDiasDePrestamo())){
                        hay=true;
                        cout << mat[tipoMaterial(mat,contMat,reserv[i].getIdMaterial())]->getTitulo() << " -- Cliente: " << reserv[i].getIdCliente() << endl;
                    }
                }
                if(!hay)
                    cout << "No hay materiales reservados en esta fecha" << endl;
                cout << endl;
                break;
            case 'e':
                cout << endl <<  "ID del cliente: " << endl;
                cin >> cliente;
                do{
                    if(!hay)
                    cout << "ID del material: " << endl;
                    hay=1;
                    cin >> id;
                    if(!verifMaterial(mat,contMat,id))
                        cout << "Este material no existe, intenta de nuevo" << endl;
                }while(!verifMaterial(mat,contMat,id));
                cout << "Fecha de reservación" << endl << "Día: ";
                cin >> dd;
                cout << "Mes: ";
                cin >>mm;
                cout << "Año: ";
                cin >>aa;
                f1.setFecha(dd,mm,aa);
                for(int i=0;i<contResv;i++){
                    if(reserv[i].getIdMaterial()==id){
                        if(f1 >= reserv[i].getFechaReservacion() && f1 <= reserv[i].calculaFechaFinReserva(mat[tipoMaterial(mat,contMat,reserv[i].getIdMaterial())]->cantidadDeDiasDePrestamo())){
                           cout << endl << "Este material ya se encuentra reservado en la fecha dada, la reservación no se llevará a cabo" << endl;
                            hay=0;
                        }
                        else if(f1+ mat[tipoMaterial(mat,contMat,id)]->cantidadDeDiasDePrestamo() >= reserv[i].getFechaReservacion() && f1+ mat[tipoMaterial(mat,contMat,id)]->cantidadDeDiasDePrestamo() <= reserv[i].calculaFechaFinReserva(mat[tipoMaterial(mat,contMat,reserv[i].getIdMaterial())]->cantidadDeDiasDePrestamo())){
                            cout << endl << "No se puede reservar el material en la fecha dada debido a que otra reservación esta demasiado próxima" << endl;
                            hay=0;
                        }
                    }
                }
                if(hay){
                    reserv[contResv].setFechaReservacion(f1);
                    reserv[contResv].setIdCliente(cliente);
                    reserv[contResv++].setIdMaterial(id);
                    cout << endl << "Se reservó el material exitosamente" << endl;
                }
                cout << endl;
                break;
            default:
                cout << endl;
                if(opcion!='f')
                cout << "No es una opción válida, vuelva a intentar" <<  endl << endl;
        }
    }while(opcion!='f');
    cargaCambios(reserv,contResv);
    cout << "Se guardaron los cambios realizados en las reservas" << endl << endl;
    return 0;
}

