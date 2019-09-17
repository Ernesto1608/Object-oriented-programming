//
//  Reserva.h
//  Proyecto 3
//
//  Created by Ernesto Garcia on 4/14/19.
//  Copyright © 2019 Ernesto Garcia. All rights reserved.
//

#ifndef Reserva_h
#define Reserva_h

#include "Fecha.h"

class Reserva{
public:
    //Constructores
    Reserva();
    Reserva(int,int,Fecha);
    //Métodos de acceso
    int getIdMaterial(){return idMaterial;}
    int getIdCliente(){return idCliente;}
    Fecha getFechaReservacion(){return fechaReservacion;}
    //Métodos de modificacion
    void setIdMaterial(int mat){idMaterial=mat;}
    void setIdCliente(int clien){idCliente=clien;}
    void setFechaReservacion(Fecha f1){fechaReservacion=f1;}
    //Métodos
    Fecha calculaFechaFinReserva(int);
private:
    int idMaterial,idCliente;
    Fecha fechaReservacion;
};

Reserva::Reserva(){
    idMaterial=0;
    idCliente=0;
}
Reserva::Reserva(int mat,int clien,Fecha f1){
    idMaterial=mat;
    idCliente=clien;
    fechaReservacion=f1;
}
Fecha Reserva::calculaFechaFinReserva(int dias){
    return fechaReservacion+dias;
}


#endif /* Reserva_h */
