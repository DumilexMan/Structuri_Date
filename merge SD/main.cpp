#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <iomanip>
using namespace std;

ifstream f("input.txt");
int n,i;

void afisare(int A[], int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void Merge(int A[], int s, int m, int d) // vector stanga mijloc dreapta
{
    int  lv1=m-s+1;
    int  lv2=d-m;

    //lungime vectori

    int *vector1=new int [lv1];
    int *vector2=new int [lv2];

    for(int i = 0; i < lv1; i++)
        vector1[i]=A[s+i];
    for(int i = 0; i < lv2; i++)
        vector2[i]=A[m+i+1];

    int pozv1=0,pozv2=0,pozv=s;

    while(pozv1<lv1 && pozv2<lv2)
    {
        if( vector1[pozv1] <= vector2[pozv2] )
        {
            A[pozv]=vector1[pozv1];
            pozv1++;
        }
        else
        {
            A[pozv]=vector2[pozv2];
            pozv2++;
        }
        pozv++;
    }

    while(pozv1<lv1)
    {
        A[pozv]=vector1[pozv1];
        pozv1++;
        pozv++;
    }

    while(pozv2<lv2)
    {
        A[pozv]=vector2[pozv2];
        pozv2++;
        pozv++;
    }

}

void MergeSort(int A[], int s, int d) // vector stanga dreapta
{
    if (s>=d)  // conditia de iesire
        return;

    auto m=s+(d-s)/2; //mijlocul  am incercat sa evit un overflow
    MergeSort(A,s,m); // partea din stanga
    MergeSort(A,m+1,d); // partea din dreapta
    Merge(A,s,m,d);
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
    int  a[n];
    for(i=0;i<n;i++)
        f>>a[i];
        auto t_start = std::chrono::high_resolution_clock::now();
    MergeSort(a,0,n);
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
