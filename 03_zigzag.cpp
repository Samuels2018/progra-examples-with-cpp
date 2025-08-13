#include<iostream>
#include "Lista.h"
#include<string>
#include <sstream>

using namespace std;


int longestZigZagSublist(Lista<int> target);
void inicioDeSublista(Lista<int> target, int &num, bool &creciente, int &cont);

using namespace std;

int main(){

    Lista<int> l;
    int result;

    l.insertarFinal(1);
    l.insertarFinal(3);
    l.insertarFinal(2);
    l.insertarFinal(4);
    l.insertarFinal(4);
    l.insertarFinal(3);
    l.insertarFinal(4);
    l.insertarFinal(2);
    l.insertarFinal(6);
    l.insertarFinal(3);
    l.insertarFinal(4);
    l.insertarFinal(5);
    l.insertarFinal(2);
    l.insertarFinal(3);

    result=longestZigZagSublist(l);
    cout<<"La longitud de la sublista zigzag es: "<<result<<endl;

    

}

int longestZigZagSublist(Lista<int> target){

    int longSub, num, n, cont; //contador de la longitud de la sublista
    bool creciente; // bandera para comparar el zigzag

        

        
    if(target.esVacia() && target.getLongitud()<3){
        return 0;

    }

    n=target.getLongitud();
    num=target.consultarPos(1);
    target.eliminarPos(1);
    longSub=0;
    creciente=false;
    cont=1;
    
    inicioDeSublista(target, num, creciente, cont);

        while(!target.esVacia()){

           if(creciente=true && num<target.consultarPos(1)){
            creciente=false;
            cont++;
            num = target.consultarPos(1);
            target.eliminarPos(1);
           }else{
            if(creciente==false && num>target.consultarPos(1)){
                creciente=true;
                cont++;
                num = target.consultarPos(1);
                target.eliminarPos(1);
                }else{
                    if(cont>longSub){
                        longSub=cont;
                    }

                    cont=1;
                    if(creciente==true && num>target.consultarPos(1)){
                        
                        num = target.consultarPos(1);
                        target.eliminarPos(1);  
                        cont++;
                    
                }else{
                    if(creciente==false && num<target.consultarPos(1)){
                        
                         num = target.consultarPos(1);
                        target.eliminarPos(1);  
                        cont++;
                    }else{
                        inicioDeSublista(target, num, creciente, cont);
                    }
                }



    
                }

            }
        }
    
        return longSub;

}
void inicioDeSublista(Lista<int> target, int &num, bool &creciente, int &cont){

    

    while(num==target.consultarPos(1) && !target.esVacia()){

       if(num>target.consultarPos(1)){
            creciente=true;
            cont++;
             num = target.consultarPos(1);
            target.eliminarPos(1);
           
        }else if(num<target.consultarPos(1)){
           creciente=false;
            cont++;
            num = target.consultarPos(1);
            target.eliminarPos(1);
          
           
        }else{
            num= target.consultarPos(1);
            target.eliminarPos(1);
           
        }
    }

}