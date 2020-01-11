#include "Polynome.h"
#include "math.h"
using namespace std;
Polynome::Polynome(vector<double> coefs)
{
    this->coefs = coefs;
}

vector<double> Polynome::usual2()
{
    vector<double> res;
    double a = this->coefs[2];
    double b = this->coefs[1];
    double c = this->coefs[0];
    double delta = b*b-4*a*c;
    if(delta == 0)
    {
        res.push_back(-b*(2*a));
    }
    else if(delta > 0)
    {
        res.push_back((-b-sqrt(delta))/(2*a));
        res.push_back((-b+sqrt(delta))/(2*a));
    }
    return res;
}

vector<double> Polynome::usual3()
{
    vector<double> res;
    double a = this->coefs[3];
    double b = this->coefs[2];
    double c = this->coefs[1];
    double d = this->coefs[0];
    double p = -b/(3*a)+c/a;
    double q = (b/(27*a))*(((2*b*b)/(a*a))-(9*c)/a)+d/a;
    double delta = -(4*p*p*p+27*q*q);
    if(delta < 0)
    {
        double u3 = (-q+sqrt(-delta/27))/2;
        double u = pow(u3,1/3);
        double v3 = (-q-sqrt(-delta/27))/2;
        double v = pow(v3,1/3);
        res.push_back(u+v);
    }
    if(delta == 0)
    {
        res.push_back((3*p)/q);
        res.push_back(-(3*q)/(2*p));
    }
    if(delta > 0)
    {
        for(int k = 0; k<3; k++)
        {
            res.push_back(2*sqrt(-p/3)*cos((1/3)*acos((3*p)/(2*q)*sqrt(3/(-p)))+(2*k*Pi)/3));
        }
    }
}

vector<double> Polynome::usual4()
{
    double a = this->coefs[4];
    double b = this->coefs[3];
    double c = this->coefs[2];
    double d = this->coefs[1];
    double e = this->coefs[0];
    double p = (-3*b*b)/(8*a*a)+c/a;
    double q = pow(b/2,3)/pow(a,3)-(1/2)*((b*c)/(a*a))+(d/a);
    double r = -3*pow(b/(4*a),4)+(c*pow(b/4,2))/pow(a,3)-(1/4)*((b*d)/pow(a,2))+e/a;
    vector<double> poly;
    poly.push_back(4*r*p-q*q);
    poly.push_back(-8*r);
    poly.push_back(-4*p);
    poly.push_back(8);
    Polynome tmp(poly);
    vector<double> lambda = tmp.usual3();
    double l0 = lambda[0];
    double a0 = sqrt(2*l0-p);
    double b0 = -q/(2*a0);
    vector<double> p1;
    p1.push_back(l0+b0);
    p1.push_back(a0);
    p1.push_back(1);
    vector<double> p2;
    p2.push_back(l0-b0);
    p2.push_back(-a0);
    p2.push_back(1);
    vector<double> v1 = Polynome(p1).usual2();
    vector<double> v2 = Polynome(p2).usual2();

    for(int i=0; i<v2.size();i++)
    {
        v1.push_back(v2[i]);
    }
    return v1;
}

vector<double> Polynome::getPolynome()
{
    return this->coefs;
}