
//Bubble sort

#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;

ifstream f("input_bubble.txt");

int v[10000000],v1[10000000],n,i;


/*
void afisarecomputing(int &nr)
{
    cout<<"----------------------";
    if(nr=99999999)
    {
    system("CLS");
    nr=0;
    }
    nr++;
}
*/


void bubble(int v[1000000], int n)
{
    int i,ok,aux,nr;
    ok=0;
    nr=0;
    while(ok==0)
    {
        ok=1;
        for(i=1;i<=n-1;i++)
            if(v[i]>v[i+1])
        {
            aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
            ok=0;
        }
        //afisarecomputing(nr);
    }
}

void afisare(int A[], int n)
{
    int i;
    for(i=1;i<=n;i++)
        cout<<A[i]<<" ";
}
int verificare(int A[], int n)
{
    int ok,i;
    ok=1;
    for(i=1;i<n;i++)
        if(A[i]>A[i+1])
        {
            ok=0;
            break;
        }
    return ok;
}

int main()
{
    f>>n;
    if(n<=100000)
    {
    for(i=1;i<=n;i++)
        f>>v[i];


        auto t_start = std::chrono::high_resolution_clock::now();

    bubble(v,n);

        auto t_end = std::chrono::high_resolution_clock::now();

        for(i=1;i<=n;i++)
        cout<<v[i]<<" ";

        cout<<endl;
        cout<< std::fixed << std::setprecision(2) << std::chrono::duration<double , std::milli>(t_end - t_start).count()<<endl;
        cout<<verificare(v,n);
    }
    else
    {
    cout<<"Nu se poate face.";
    }
    return 0;
}
