#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double test_function(double x){
    return pow(x,2);
}

double derivative_1(double x,double h,double (*function)(double)){
    double deriv = (function(x+h)-function(x-h))/(2*h);
    return deriv;
}



int main(){
    cout<<derivative_1(3,1,test_function);
    return 0;
}