#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <iomanip>
using namespace std;

ifstream f("inputshell.txt");
int a[1000000],n,i;

void shellsort(int A[], int n)
{
    int sp,i,j,cp;
    for( sp = n/2 ; sp>0 ; sp--)
    {
        for( i = 0 ; i<n-sp && i<sp ; i++)
            if(A[i]>A[i+sp])
            swap(A[i],A[i+sp]);

    }

    for( i=1 ; i<n ; i++)
    {
        cp=A[i];
        j=i-1;
        while(cp < A[j] && j>=0)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = cp;
    }
}

void afisare(int A[], int n)
{
    int i;
    for(i=0 ; i<n ; i++)
        cout<<A[i]<<" ";
    cout<<endl;
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
    for( i=0 ; i<n ; i++)
        f>>a[i];
        auto t_start = std::chrono::high_resolution_clock::now();
    shellsort(a,n);
        auto t_end = std::chrono::high_resolution_clock::now();
    afisare(a,n);
        cout<<std::fixed << std::setprecision(2) << std::chrono::duration<double, std::milli>(t_end-t_start).count()<<endl;
        cout<<verificare(a,n);
    return 0;
}
