/*
 * binario.cxx
 * 
 * Copyright 2016 Gabriel Vargas <gabreta@VmGabriel96>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;

double timeval_diff(struct timeval * a, struct timeval * b)
{
    return
	(double)(a->tv_sec + (double)a->tv_usec/1000000) -
	(double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int aleatorio ()
{
    int a = rand() % 5000 + 5000;
    return a;
}

void llenar (int * a, int n)
{
    for (int i=0;i<n;i++)
    {
	a[i]=aleatorio();
    }
}

void imprimir (int * a, int n)
{
    cout <<"[ ";
    for (int i=0;i<n;i++)
    {
	cout<<a[i]<<" ";
    }
    cout <<"]"<<endl;
}

int * intercambio (int a[], int posa,int posb)
{
    //posa = posicion de origen
    //posb = posicion de destino
    int temp=a[posb];
    a[posb]=a[posa];
    a[posa]=temp;
    return a;
}

int * inserccion (int * a, int N)
{
    int i,j,v;
    for (i=1; i<=N; i++)
    {
	j=i;
	v=a[j];
	while(a[j-1]>v && j>0)
	{
	    a[j]=a[j-1];
	    j--;
	}
	a[j]= v;
    }
    return a;
}

int busqbinaria(int * a, int n, int dato)
{

    //Retorna la posicion o -1 sino se encuentra
    
    int Iarriba = n-1;
    int Iabajo = 0;
    int Icentro;
    while (Iabajo <= Iarriba)
    {
	Icentro = (Iarriba + Iabajo)/2;
	if (a[Icentro] == dato)
	    return Icentro;
	else
	    if (dato < a[Icentro])
		Iarriba=Icentro-1;
	    else
		Iabajo=Icentro+1;
    }
    return -1;
}

int main (int argc, char ** argv)
{
    int n;

    for (n=50;n<=1000;n+=50)
    {	
	struct timeval t_ini, t_fin;
	double secs;
    
	int * s = new int [n];

	llenar(s,n);

	inserccion(s,n);

	gettimeofday(&t_ini, NULL);
	int d=busqbinaria(s,n,s[n-14]);
	gettimeofday(&t_fin, NULL);

	secs = timeval_diff(&t_fin, &t_ini);

	/*if (d>=0 && d<=n)
	{
	    cout <<"Posicion: "<<d<<endl;
	}
	else
	{
	    cout<<"Dato no Encontrado"<<endl;
	}
	*/

	cout <<"N: "<<n<<" pos: "<<d<<" Time "<<secs<<endl;
	delete []s;
    }
    return 0;
}
