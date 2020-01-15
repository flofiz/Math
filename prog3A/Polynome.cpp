#include "Polynome.h"
using namespace std;

Polynome::Polynome(vector<double> coefs)
{
    this->coefs = coefs;
}

vector<double> Polynome::usual3()
{
    vector<double> res;
    double a = this->coefs[3];
    double b = this->coefs[2];
    double c = this->coefs[1];
    double d = this->coefs[0];
    double p = -(pow(b,2)/(3*pow(a,2)))+(c/a);
    double q = (b/(27.*a))*(((2*pow(b,2))/(pow(a,2)))-((9.*c)/a))+(d/a);
    double delta = -(4.*pow(p,3)+27.*pow(q,2));
    cout<<"p=" << p << endl << " q= " << q << endl << "delta = " << delta << endl;
    if(delta < 0 && delta < -0.0000000001)
    {
        double u3 = (-q+sqrt(-delta/27.))/2.;
        double u = cbrt(u3);
        double v3 = (-q-sqrt(-delta/27.))/2.;
        double v = cbrt(v3);
        res.push_back(u+v-b/(3*a));
    }
    if(delta > -0.0000000001 && delta < 0.0000000001)
    {
        res.push_back(((3.*q)/p)-(b/(3*a)));
        res.push_back(-(3.*q)/(2.*p)-(b/(3*a)));
    }
    if(delta > 0 && delta > 1*pow(10,-10))
    {
        for(int k = 0; k<3; k++)
        {
            res.push_back(2.*sqrt(-p/3)*cos((1.0/3.0)*acos(((3.*q)/(2.*p))*sqrt(3./(-p)))+((2.*k*Pi)/3.))-b/(3*a));
        }
    }
    return res;
}

vector<double> Polynome::usual4()
{
    double a = this->coefs[4];
    double b = this->coefs[3];
    double c = this->coefs[2];
    double d = this->coefs[1];
    double e = this->coefs[0];
    // double p = (-3*b*b)/(8*a*a)+c/a;
    // double q = pow(b/2,3)/pow(a,3)-(1/2)*((b*c)/(a*a))+(d/a);
    // double r = -3*pow(b/(4*a),4)+(c*pow(b/4,2))/pow(a,3)-(1/4)*((b*d)/pow(a,2))+e/a;
    double p =(-3*pow(b,2))/(8*pow(a,2))+c/a;
    double q = ((pow(b,3))/(8*pow(a,3)))-((b*c)/(2*pow(a,2)))+(d/a);
    double r = ((-3*pow(b,4))/(256*pow(a,4)))+((pow(b,2)*c)/(16*pow(a,3)))-((b*d)/(4*pow(a,2)))+(e/a);
    cout << "p4 = " << p << " q4 = " << q << " r4= " << r << endl;
    vector<double> poly;
    poly.push_back(4*r*p-pow(q,2));
    poly.push_back(-8*r);
    poly.push_back(-4*p);
    poly.push_back(8);
    Polynome tmp(poly);
    vector<double> lambda = tmp.usual3();
    double l0 = lambda[0];

    // double a0 = sqrt(2*l0-p);
    // double b0 = -q/(2*a0);
    // vector<double> p1;
    // p1.push_back(l0+b0);
    // p1.push_back(a0);
    // p1.push_back(1);
    // vector<double> p2;
    // p2.push_back(l0-b0);
    // p2.push_back(-a0);
    // p2.push_back(1);
    vector<double> v;
    double u = 2*l0-c+pow(b,2)/4;
    if(u<0)
    {
        return v;
    }
    else
    {
        u=sqrt(u);
        double d1 = -2*l0-c+2*(d-b*l0)/(u)+b*u+pow(b,2)/2;
        if(d1 >= 0)
        {
            v.push_back((-u+sqrt(d1))/2-b/4);
            v.push_back((-u-sqrt(d1))/2-b/4);
        }
        double d2 = -2*l0-c-2*(d-b*l0)/(u)-b*u+pow(b,2)/2;
        if(d1 >= 0)
        {
            v.push_back((u+sqrt(d1))/2-b/4);
            v.push_back((u-sqrt(d1))/2-b/4);
        }
    }
    // Polynome p1 = Polynome({l0+(b*l0-d)/(2*u),u+b/2,1});
    // Polynome p2 = Polynome({l0-(b*l0-d)/(2*u),-u+b/2,1});

    // vector<double> v1;
    // if(2*l0 - p >= 0)
    // {
    //     vector<double> p1 = {l0-(q/(2*sqrt(2*l0-p))),sqrt(2*l0 - p),1};
    //     vector<double> p2 = {l0+(q/(2*sqrt(2*l0-p))),-sqrt(2*l0 - p),1};
    //     v1 = Polynome(p1).usual2();
    //     vector<double> v2 = Polynome(p2).usual2();
    //     for(int i=0; i<v2.size();i++)
    //     {
    //         v1.push_back(v2[i]);
    //     }
    // }
    
    // vector<double> v1 = Polynome(p1).usual2();
    // vector<double> v2 = Polynome(p2).usual2();

    // for(int i=0; i<v1.size();i++)
    // {
    //     v.push_back(v1[i]);
    // }

    // for(int i=0; i<v2.size();i++)
    // {
    //     v.push_back(v2[i]);
    // }
    return v;
}


// vector<double> Polynome::usual4()
// {
//     double a = this->coefs[4];
//     double b = this->coefs[3];
//     double c = this->coefs[2];
//     double d = this->coefs[1];
//     double e = this->coefs[0];
//     vector<double> lambda = Polynome({4*c*e-d*d,b*b,2*b*d-8*e,4*c,8}).usual3();
//     double l0 = lambda[0];
//     double u0 = sqrt(2*l0-c+pow(b,2)/4);
//     vector<double> v1 = Polynome({l0+((b*l0-d)/2*u0),u0+b/2,1}).usual2();
//     vector<double> v2 = Polynome({l0-((b*l0-d)/2*u0),-u0+b/2,1}).usual2();

//     for(int i=0; i<v2.size();i++)
//     {
//         v1.push_back(v2[i]);
//     }
//     return v1;


// }

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
    if(delta > 0)
    {
        res.push_back((-b-sqrt(delta))/(2*a));
        res.push_back((-b+sqrt(delta))/(2*a));
    }
    return res;
}

vector<double> Polynome::getPolynome()
{
    return this->coefs;
}

vector<double> Polynome::resolvUsual()
{
    vector<double> solutions;
    switch (this->coefs.size()-1)
    {
    case 2:
        solutions = usual2();
        break;
    case 3:
        solutions = usual3();
        break;
    case 4:
        solutions = usual4();
        break;
    default:
        cout << "degré non pris en charge" << endl;
        break;
    }
    return solutions;
}

vector <double> Polynome::resolvCastel(int precision)
{
    vector<double> res;
    vector<Point> resPts = casteljeau(toBernstein(this->coefs),precision);
    vector<double> pPInf,pM01,pMInf;

    for(int i = 0; i<coefs.size();i++)
    {
        pPInf.push_back(coefs[coefs.size()-i-1]);
    }
    vector<Point> resPtsInf = casteljeau(toBernstein(pPInf),precision);

    for(int i = 0; i<coefs.size();i++)
    {
        pM01.push_back(pow(-1,i)*coefs[i]);
    }
    vector<Point> resPtsM01 = casteljeau(toBernstein(pM01),precision);
    
    for(int i = 0; i<coefs.size();i++)
    {
        pMInf.push_back(pM01[pM01.size()-i-1]);
    }
    vector<Point> resPtsMInf = casteljeau(toBernstein(pMInf),precision);

    for(int i = 0; i<resPts.size();i++)
    {
        res.push_back(resPts[i].x);
    }
    for(int i = 0; i<resPtsInf.size();i++)
    {
        res.push_back(1/resPtsInf[i].x);
    }
    for(int i = 0; i<resPtsM01.size();i++)
    {
        res.push_back(-resPtsM01[i].x);
    }
    for(int i = 0; i<resPtsMInf.size();i++)
    {
        res.push_back(-1/resPtsMInf[i].x);
    }
    return res;
}