#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <iomanip>
using namespace std;

ifstream f("inputradix.txt");
int a[1000000],n,i;

int maxi(int A[], int n)
{
    int i,m;
    m=-1;
    for( i=0 ; i<n ; i++)
        if(A[i]>m)
            m=A[i];
    return m;
}

void Count(int A[], int n, int b)
{
    int v1[n],i,vcar[n]; // vectorul in care pun, i, vectorul cu pzoitii

    for(i=0;i<=9;i++)
        vcar[i]=0;

    for( i=0 ; i<n ; i++)
        vcar[ (A[i]/b) %10 ]++;




    for( i=1 ; i<=9 ; i++)
        vcar[i] += vcar[i-1];

    for( i=n-1 ; i>=0 ; i--)
    {
        v1[ vcar[ (A[i]/b) %10 ] -1 ] = A[i];
        vcar[ (A[i]/b) %10 ]--;
    }

    for( i=0 ; i<n ; i++)
        A[i] = v1[i];
}

void afisare(int A[], int n)
{
    int i;
    for(i=0 ; i<n ; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void Radix(int A[], int n)
{

    int b,nrb;
    nrb=maxi(A,n);
    for( b=1 ; nrb/b>0 ; b = b*10)
    Count(A,n,b);
}

int verificare(int A[], int n)
{
    int ok,i;
    ok=1;
    for(i=0;i<n-1;i++)
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
    for(i=0 ; i<n ; i++)
        f>>a[i];
        auto t_start = std::chrono::high_resolution_clock::now();
    Radix(a,n);
        auto t_end = std::chrono::high_resolution_clock::now();
    afisare(a,n);
        cout<<std::fixed << std::setprecision(2) << std::chrono::duration<double, std::milli>(t_end-t_start).count()<<endl;
    cout<<verificare(a,n);
    }
    else
    {
    cout<<"nu se poate face.";
    }
    return 0;
}
