#include <iostream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
using namespace std;

//Integrantes : Samuel Pérez Catalán
//              Juan villalobos Elola

void mostrar( int x , int A[], int B[])  //para mostrar los polinomios
{

int tam= x;
int i ;
for(i=0; i <tam ; i++)
{
  if(A[i]!=0)
  {
cout<<"(";
cout<<A[i]<<")"<<"X**"<<B[i];
cout<<"\t";
if(tam != i+1)
{
cout<<" + ";
}
}
}
}
float  fx(int fxA[], int fxB[], int X, int tam)  // poder reemplazar X en el polinomio ingresado
{
int i ;
float suma=0;

for (i=0; i<tam; i++)
{
suma = suma + (fxA[i]*pow(fxB[i],X));

}
return suma;


}


float fdx(int fdxA[], int fdxB[], int X, int tam) //poder reemplazar X en el polinomio derivado
{

int i ;
float suma=0;

for (i=0; i<tam; i++)
{
suma = suma + (fdxA[i]*pow(fdxB[i],X));

}
return suma;


}


void NewthonRaphson_polinomio( int x , int A[], int B[], int dA[], int dB[]) // solucion del metodo newton raphson
{

float inicio;
int aux;
float valorfx, valorfdx;
int cont=1;
cout<<endl;
cout<<"Ingrese valor inicial (X0) ";
cin>>inicio;
valorfx=fx(A,B,inicio,x);
valorfdx= fdx(dA,dB,inicio,x);
cout<<endl;
cout<<" ¿Cuantas iteraciones desea realizar ?";
cout<<endl;
cin>>aux;

while(aux!=0) //iteraciones del metodo
{
inicio = inicio - (valorfx/valorfdx);
cout<<endl;
cout<<"X"<<cont<<":"<<inicio;
cout<<endl;
valorfx=fx(A,B,inicio,x);
valorfdx= fdx(dA,dB,inicio,x);
aux--;
cont++;
}
}



int main()
{
char polinomio[100];
int valores[100];
int exponente[100];
int CX[100];
char ayuda[100];
int largo,i=0,cont,j=0,h=0;
int d_CX[100], d_exponente[100];
float fdx, fx;
string xoxo;
cout<<"Ingrese el polinomio :";
cout<<endl;
cin.getline(polinomio,100);
largo=strlen(polinomio);
char *puntero;
char *p2;
puntero = strtok(polinomio,  " * ");
while(puntero!=NULL )     // proceso para poder dividir el polinomio
   {
      
       xoxo=puntero;
      
      valores[i] = atoi(xoxo.c_str());
      i++;
       
       
      puntero = strtok(NULL," * ");
      
    }
cont=i;

for(i=0; i<cont; i++) //llenar datos para vector de CX y el vector exponente, para tener una mejor forma de manejar los datos
{
if(valores[i]!=0)
{
    if(i%2==0)
     {
         cout<<endl;
         CX[j]=valores[i];
         //cout<<CX[j];
         j++;
     }
     if(i%2!=0)
      {
        cout<<endl;
        exponente[h]=valores[i];
        //cout<<exponente[h];
         h++;
 
       }
   
   } 

}
cont = cont/2;
for(i=0; i < cont ; i++) //derivada 
{

d_CX[i]= CX[i]*exponente[i];
d_exponente[i]=exponente[i]-1;

}
cout<<"F(X) :"; //mostrar Fx
cout<<"\t";
mostrar(cont, CX , exponente);
cout<<endl;
cout<<endl;
cout<<"F(dX) :";  //mostrar Fdx
cout<<"\t";
mostrar(cont , d_CX , d_exponente);
cout<<endl;
NewthonRaphson_polinomio(cont, CX ,exponente, d_CX ,d_exponente);

return 0;
}
