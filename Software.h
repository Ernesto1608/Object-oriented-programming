//
//  Software.h
//  Proyecto 3
//
//  Created by Ernesto Garcia on 4/16/19.
//  Copyright © 2019 Ernesto Garcia. All rights reserved.
//

#ifndef Software_h
#define Software_h
#include "Material.h"

class Software:public Material{
public:
    Software();
    Software(int,string,string);
    //Acceso
    string getSistemaOper(){return sistemaOper;}
    //Modificación
    void setSistemaOper(string sis){sistemaOper=sis;}
    //Redefinidos
    void muestra();
    int cantidadDeDiasDePrestamo();
private:
    string sistemaOper;
};

Software::Software():Material(){
    sistemaOper="-";
}

Software::Software(int mat,string tit,string sis):Material(mat,tit){
    sistemaOper=sis;
}

void Software::muestra(){
    cout << "Software - " << idMaterial << " " << titulo << " -- Sistema operativo: " << sistemaOper << endl;
}

int Software::cantidadDeDiasDePrestamo(){
    return 1;
}


#endif /* Software_h */
