//
//  Fecha.h
//  Proyecto 3
//
//  Created by Ernesto Garcia on 4/14/19.
//  Copyright © 2019 Ernesto Garcia. All rights reserved.
//

#ifndef Fecha_h
#define Fecha_h

class Fecha{
    friend istream& operator>> (istream &is, Fecha &f1);
    friend ostream& operator<< (ostream &os, Fecha f1);
public:
    //Constructores
    Fecha();
    Fecha(int,int,int);
    //Metodos de acceso
    int getDia(){return dd;}
    int getMes(){return mm;}
    int getAnio(){return aa;}
    //Metodo de modificacion
    void setFecha(int,int,int);
    //Sobrecarga
    bool operator>=(Fecha);
    bool operator<=(Fecha);
    bool operator>(Fecha);
    bool operator<(Fecha);
    bool operator==(Fecha);
    Fecha operator+(int);
private:
    int dd,mm,aa;
    string nombreMes();
    bool esBisiesto();
};

Fecha::Fecha(){
    dd=1;
    mm=1;
    aa=2000;
}

Fecha::Fecha(int dia, int mes, int anio){
    dd=dia;
    mm=mes;
    aa=anio;
}

void Fecha::setFecha(int dia,int mes, int anio){
    dd=dia;
    mm=mes;
    aa=anio;
}

bool Fecha::esBisiesto(){
    if(aa%4==0)
        return true;
    return false;
}

string Fecha::nombreMes(){
    switch(mm){
        case 1:
            return "Ene";
            break;
        case 2:
            return "Feb";
            break;
        case 3:
            return "Mar";
            break;
        case 4:
            return "Abr";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "Jun";
            break;
        case 7:
            return "Jul";
            break;
        case 8:
            return "Ago";
            break;
        case 9:
            return "Sep";
            break;
        case 10:
            return "Oct";
            break;
        case 11:
            return "Nov";
            break;
        case 12:
            return "Dic";
            break;
        default:
            return "No existe";
    }
}

bool Fecha::operator>=(Fecha f1){
    if( *this>f1 || *this==f1)
        return true;
    return false;
}

bool Fecha::operator<=(Fecha f1){
    if( *this<f1 || *this==f1)
        return true;
    return false;
}

bool Fecha::operator>(Fecha f1){
    if(aa<f1.aa)
        return false;
    if(aa>f1.aa)
        return true;
    if(mm<f1.mm)
        return false;
    if(mm>f1.mm)
        return true;
    if(dd>f1.dd)
        return true;
    return false;
}

bool Fecha::operator<(Fecha f1){
    if(aa<f1.aa)
        return true;
    if(aa>f1.aa)
        return false;
    if(mm<f1.mm)
        return true;
    if(mm>f1.mm)
        return false;
    if(dd<f1.dd)
        return true;
    return false;
}

bool Fecha::operator==(Fecha f1){
    if(*this<f1 || *this>f1)
        return false;
    return true;
}

istream& operator>> (istream &is, Fecha &f1){
    is>>f1.dd;
    is>>f1.mm;
    is>>f1.aa;
    return is;
}

ostream& operator<< (ostream &os, Fecha f1){
    os<<f1.dd << " de " << f1.nombreMes() << " de " << f1.aa;
    return os;
}

Fecha Fecha::operator+(int dias){
    Fecha f1;
    f1=*this;
    f1.dd+=dias;
    bool rept=false;
    do{
        if(f1.mm==2 && f1.esBisiesto() && f1.dd>29){
            f1.dd-=29;
            f1.mm++;
        }
        else {
            if(f1.mm==2 && f1.dd>28 && !f1.esBisiesto()){
                f1.dd-=28;
                f1.mm++;
            }
            else{
                if((f1.mm==1 || f1.mm==3 || f1.mm==5 || f1.mm==7 || f1.mm==8 || f1.mm==10 || f1.mm==12)&& f1.dd>31){
                    f1.dd-=31;
                    f1.mm++;
                }
                else{
                    if((f1.mm==4 || f1.mm==6 || f1.mm==9 || f1.mm==11) && f1.dd>30){
                        f1.dd-=30;
                        f1.mm++;
                    }else{
                        rept=true;
                    }
                }
            }
        }
        if(f1.mm>12){
            f1.mm-=12;
            f1.aa++;
        }
    }while(rept==false);
    return f1;
}
#endif /* Fecha_h */
