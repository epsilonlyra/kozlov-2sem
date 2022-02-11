#include<iostream>
#include <iomanip>
#include <math.h>
using namespace std;
float fbasel(long int  n){
    float sum = 0;
    for (long int i = 1; i<= n; i++ ){
    float an = i;
        sum += 1/(an*an);
    }
    return(sum);
}
double dbasel(long int  n){
    double sum = 0;
    for (long int i = 1; i<= n; i++ ){
    double  an = i;
        sum += 1/(an*an);
    }
    return(sum);
}
int main(){
long int n;
cin>>n;
cout<<setprecision(15)<<fbasel(n)<<" float"<<endl;
cout<<setprecision(15)<<dbasel(n)<<" double"<<endl;
return(0);
}

