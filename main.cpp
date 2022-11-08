#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double test_function(double x)
{
    return pow(5,x);
}

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

int main()
{
    ofstream data;
    ofstream data2;
    data.open("data.txt");
    data2.open("data2.txt");
    
    for(double h = 0.1;h>pow(10,-17);h*=0.1)
    {
        data<<derivative_1(3,h,test_function)<<"\t"<<-log10(h)<<endl;
        data2<<derivative_2(3,h,test_function)<<"\t"<<-log10(h)<<endl;
    }

    data.close();
    data2.close();
    return 0;
}