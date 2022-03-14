#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <iomanip>
using namespace std;

ifstream f("input_count.txt");
int a[10000000],n,i;

int maxi(int A[], int n)
{
    int max1,i;
    max1=A[0];
    for( i=1; i<n; i++)
        if(A[i]>max1)
            max1=A[i];
    return max1;
}

int mini(int A[], int n)
{
    int min1,i;
    min1=A[0];
    for( i=1; i<n; i++)
        if(A[i]<min1)
            min1=A[i];
    return min1;
}

void Afisare(int A[], int n)
{
    int i;
    for( i=0; i<n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void counting(int A[], int n)
{
    int i,minim,maxim;
    maxim=maxi(A,n);
    minim=mini(A,n);
    int v1[n],vpoz[maxim-minim+1];

    int mvpoz;
    mvpoz=maxim-minim+1;

    for( i=0; i<mvpoz; i++)
        vpoz[i]=0;

    for( i=0; i<n; i++)
        vpoz[A[i]-minim]++;

    for( i=1; i<mvpoz; i++)
        vpoz[i]+=vpoz[i-1];

    for( i=n-1; i>=0; i--)
        {
        v1[vpoz[A[i]-minim]-1] = A[i];
        vpoz[A[i]-minim]--;
        }

    for( i=0; i<n; i++)
        A[i] = v1[i];

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
    for( i=0; i<n; i++)
        f>>a[i];
        auto t_start = std::chrono::high_resolution_clock::now();
    counting(a,n);
        auto t_end = std::chrono::high_resolution_clock::now();
    Afisare(a,n);
    cout<<std::fixed << std::setprecision(2) << std::chrono::duration<double, std::milli>(t_end-t_start).count()<<endl;
    cout<<verificare(a,n);
    return 0;
}
