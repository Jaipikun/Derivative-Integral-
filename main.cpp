#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#define MIN 0.0
#define MAX 10.0 
#define N 17
#define NH0 3.5

 
//Function used for testing
double test_function(double x)
{
    return pow(3,x);
}

double pi_search(double x)
{
    return sqrt(1-(x*x));
}

//Derivatives

double derivative_1(double x,double h,double (*function)(double))
{
    double deriv = (function(x+h)-function(x-h))/(2*h);
    return deriv;
}

double derivative_2(double x,double h,double (*function)(double))
{
    double deriv = (function(x+h)-function(x-h)-(2*function(x)))/pow(h,2);
    return deriv;
}

//Integrals

double integral(double x_min, double x_max, double n, double (*function)(double))
{
    double h = (x_max-x_min)/(2.0*n);
    double x = x_min+h;
    double result = 0;

    for(int i=0; i<n; i++)
    {
        result += h*( function(x+h) + 4.0*function(x) + function(x-h) ) / 3.0;
        x += 2.0*h;
    }
    return result;
}


//main
double nh[N];

int main()
{
    ofstream data;
    ofstream data2;
    ofstream data3;
    data.open("data.txt");
    data2.open("data2.txt");
    data3.open("data3.txt");
    data.precision(7);
    data2.precision(7);
    data3.precision(7);

    //1st and 2nd derivative test
    for(double h = 0.1;h>pow(10,-17);h*=0.1)
    {
        data<<derivative_1(3,h,test_function)<<"\t"<<-log10(h)<<endl;
        data2<<derivative_2(3,h,test_function)<<"\t"<<-log10(h)<<endl;
    }

    //integral test
    for(int i = 0;i<N;i++)
    {
        nh[i]=pow(NH0,i);
    }
    for(int i = 0;i<=N;i++)
    {
        cout<<i<<endl; // for time measurement
        data3<<integral(MIN,MAX,nh[i],test_function)<<'\t'<<i<<endl;
    }
    data.close();
    data2.close();
    data3.close();
    
    ofstream pi;
    pi.open("pi.txt");
    pi.precision(30);
    
    pi<<2*integral(-1,1,100000000,pi_search)<<endl;
    pi.close();
    return 0;
}