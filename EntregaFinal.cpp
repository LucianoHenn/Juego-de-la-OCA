#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>

using namespace std;
void Turno(int numJugador, char jugador[25], char J1[25], char J2[25]);
void VerificarPosicion(int P[2],int numJugador, int N);
bool Gano(int P[2],int numJugador, int N);
void Tablero(int P[2], int N,int NumJugada);

int main()
{
    int V[100],N,A,X,P[2];
    char J1[25],J2[25],jugador[25],ch,Boca;

    cout<<"Ingrese el nombre del jugador 1"<<endl;
    cin.getline(J1,25,'\n');
    cout<<"Ingrese el nombre del jugador 2"<<endl;
    cin.getline(J2,25,'\n');

    do{
    cout<<"Ingrese el tamanio N del tablero"<<endl;
    cin>>N;
    }while (N<0 || N>100);
    A=N/5;
  srand(time(NULL));




  for(int i=1;i<N-1;i++){
    X=rand()%A;
    if(rand()%3==0)
    X=-X;
    V[i]=X;
}
V[0]=0;
V[N-1]=0;


  int jugada=1, dado,numJugador=0,NumJugada;
  NumJugada=1;
   P[0]=0;
   P[1]=0;

  do{
    Turno(numJugador,jugador,J1,J2);
    Tablero(P,N,NumJugada);

    cout<<jugador<<", te encontras en la posicion: ["<<P[numJugador]<<"] .Presiona enter para tirar el dado"<<endl;
    ch=getch();
    dado=1+rand()%6;
    cout<<"En el dado salio el numero: "<<dado<<endl;

    P[numJugador]= P[numJugador]+dado;
    VerificarPosicion(P,numJugador,N);

    if(Gano(P,numJugador,N)){

    jugada=0;
    break;

    }
    if(V[P[numJugador]]>=0)
    cout<<"Te toca avanzar "<<V[P[numJugador]]<<endl;
    else
    cout<<"Te toca retroceder "<<-V[P[numJugador]]<<endl;
    P[numJugador]=P[numJugador]+V[P[numJugador]];

    VerificarPosicion(P,numJugador,N);

    if(Gano(P,numJugador,N)){

    jugada=0;
    break;

    }


    cout<<"La posicion del Jugador "<<jugador<<" es: ["<<P[numJugador]<<"]"<<endl;
       NumJugada++;
    if  (numJugador==0) numJugador=1;
      else numJugador=0;


    }  while(jugada=1);
    cout<<"Felicidades "<<jugador<<", has ganado!"<<endl;
    cout<<"La cantidad de jugadas hechas fueron: "<<NumJugada<<endl;


    ofstream file;
    file.open("Registro Juego.txt", ofstream::app);
    file<<"El ganador fue: "<<jugador<<" en: "<<NumJugada<<" jugadas"<<endl;
    file.close();

  }

void Turno(int numJugador, char jugador[25], char J1[25], char J2[25]){
if(numJugador==0)
        strcpy(jugador,J1);
    else
        strcpy(jugador,J2);

}

void VerificarPosicion(int P[2],int numJugador, int N){
int C;
if(P[numJugador]<0){

    cout<<"Ups, te has salido del tablero, debes volver al inicio"<<endl;
    P[numJugador]=0;
    }
    if(P[numJugador]>N-1){
    C=P[numJugador]-(N-1);
    cout<<"Ups, te has pasado, debes retroceder "<<C<<endl;
    P[numJugador]=N-1-P[numJugador]+N-1;

    }

}

bool Gano(int P[2],int numJugador, int N){
 if(P[numJugador]==N-1){

    return true;

}
else return false;

}

void Tablero(int P[2], int N,int NumJugada){
char Jugador1[101],Jugador2[101];
for(int i=0;i<N;i++){
Jugador1[i]=' ';
Jugador2[i]=' ';
}
Jugador1[P[0]]='1';
Jugador2[P[1]]='2';

cout<<"En el tablero se ubican asi: "<<endl;
for(int i=0;i<N;i++){
cout<<Jugador1[i];
}
Jugador1[N]='F';
cout<<Jugador1[N]<<endl;
for(int i=0;i<N;i++){
cout<<Jugador2[i];
}
Jugador2[N]='F';
cout<<Jugador2[N]<<endl;
}
