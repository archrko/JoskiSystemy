#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
double f(double x,double y,double t){
        return 2*x-y+t*t-2*(sin(t)+1)+cos(t);
}
double g(double x,double y,double t){
        return x+2*y-sin(t)-2*t*t+2*t-1;
}
int main(int argc, char* argv[])
{
double Ho = 0.1, h = 0.1,eps = 0.01,tempXi,tempYi,tempXc,tempYc,k=2;
double x[1000],y[1000],t[1000]; int n,i;
x[0] = 1;y[0] = 0;t[0]=0;
        do{
                x[1] = x[0] + h*f(x[0],y[0],t[0]);     //r - k
                y[1] = x[0] + h*g(x[0],y[0],t[0]);

                tempXc = x[0] + h/2*f(x[0],y[0],t[0]);
                tempYc = x[0] + h/2*g(x[0],y[0],t[0]);

                tempXi = tempXc + h/2*f(tempXc,tempYc,t[0]); //xi
                tempYi = tempYc + h/2*g(tempXc,tempYc,t[0]);
                h/=2;
        }while (fabs(tempXi-x[1])+fabs(tempYi-y[1])>eps);
        Ho = h*2;                                              //Ho ZNAIDENO
        x[1] = tempXi;
        y[1] = tempYi;
        cout<<"Krok = "<<Ho<<endl;
        t[1] = Ho;
        x[1] = x[0] + Ho*f( x[0]+Ho/2*f(x[0],y[0],t[0]) , y[0]+Ho/2*f(x[0],y[0],t[0]) , t[0]+Ho/2);      //ZNAISHLI X1,Y1
        y[1] = y[0] + Ho*g( x[0]+Ho/2*g(x[0],y[0],t[0]) , y[0]+Ho/2*g(x[0],y[0],t[0]) , t[0]+Ho/2);
        cout<<"\tx[0] = "<<x[0]<<"\t\t\t\tX tochne = "<<sin(t[0])+1<<"\t\t\t\t";
        cout<<"y[0] = "<<y[0]<<"\t\t\t\tY tochne = "<<t[0]*t[0]<<endl;
        cout<<"\tx[1] = "<<x[1]<<"\t\t\t\tX tochne = "<<sin(t[1])+1<<"\t\t\t\t";
        cout<<"y[1] = "<<y[1]<<"\t\t\t\tY tochne = "<<t[1]*t[1]<<endl;
        n = (int)1/Ho;
        for(i = 0 ;i < n-1;i++)
        {
                x[i+2] = x[i+1];
                y[i+2] = y[i+1];
                do{
                		t[i+2] = (i+2)*Ho;
                        tempXi = x[i+2];
                        tempYi = y[i+2];
                        x[i+2] = x[i+1] + Ho/12*(5*f(tempXi,tempYi,t[i+2]) + 8*f(x[i+1],y[i+1],t[i+1]) - f(x[i+0],y[i+0],t[i+0]));
                        y[i+2] = y[i+1] + Ho/12*(5*g(tempXi,tempYi,t[i+2]) + 8*g(x[i+1],y[i+1],t[i+1]) - g(x[i+0],y[i+0],t[i+0]));
                }while  (fabs(tempXi-x[i+2])+fabs(tempYi-y[i+2])>eps);
                cout<<"\tx["<<i+2<<"] = "<<x[i+2]<<"\t\t\t\tX tochne = "<<sin(t[i+2])+1<<"\t\t\t\t";
                cout<<"y["<<i+2<<"] = "<<y[i+2]<<"\t\t\t\tY tochne = "<<t[i+2]*t[i+2]<<"\t\t\t\t"<<endl;
         }
//system("pause");
        return 0;
}
