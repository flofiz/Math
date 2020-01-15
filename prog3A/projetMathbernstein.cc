/********************************************************/
/*                    projetMathbernstein.cc                          */
/********************************************************/
/*                                                       */
/********************************************************/ 


#include <stdlib.h>
#define Pi 3.141592654
#include <iostream>
#include <string>
#include <fstream>
#include "Polynome.h"
// #include "Fonctions.h"
using namespace std;


int main(int argc,char **argv)
{
    // vector<double> poly = {-2,7,-6,4,1.};
    // Polynome pol(poly);
    // vector<double> res = pol.usual4();
    // vector<double> res = Polynome({135,144,48,8}).usual3();

    // vector<double> poly = {1.5,-2,-2.5,1};
    //vector<double> poly = {6,-12.5,0.5,1};
    vector<double> poly = {-2,-1,2,1};
    Polynome pol(poly);
    vector<double> res = pol.resolvCastel(10);
    for(int i = 0; i < res.size(); i++)
    {
        cout << "r" << i << "= " << res[i] << endl;
    }
    cout << "1) equation degré 3" << endl;
    cout << "2) equation degré 4" << endl;
    cout << "3) equation degré 5 (aucune fonction usuelle prise en charge)" << endl;
    vector <double> coefs;
    int choix = 0;
    cin >> choix;
    double a,b,c,d,e,f;
    switch (choix)
    {
    case 1:
        cout << "veuillez saisir une equation de la forme ax3+bx2+cx+d" << endl;
        cout << "a= ";
        cin >> a;
        cout << endl << "b= ";
        cin >> b;
        cout << endl << "c= ";
        cin >> c;
        cout << endl << "d= ";
        cin >> d;
        cout << endl;
        coefs = {d,c,b,a};
        break;
    case 2:
        cout << "veuillez saisir une equation de la forme ax4+bx3+cx2+dx+e" << endl;
        cout << "a= ";
        cin >> a;
        cout << endl << "b= ";
        cin >> b;
        cout << endl << "c= ";
        cin >> c;
        cout << endl << "d= ";
        cin >> d;
        cout << endl << "e= ";
        cin >> e;
        cout << endl;
        coefs = {e,d,c,b,a};
        break;
    case 3:
        cout << "veuillez saisir une equation de la forme ax5+bx4+cx3+dx2+ex+f" << endl;
        cout << "a= ";
        cin >> a;
        cout << endl << "b= ";
        cin >> b;
        cout << endl << "c= ";
        cin >> c;
        cout << endl << "d= ";
        cin >> d;
        cout << endl << "e= ";
        cin >> e;
        cout << endl << "f= ";
        cin >> f;
        cout << endl;
        coefs = {f,e,d,c,b,a};
        break;
    
    default:
        break;
    }
    Polynome polynome(coefs);
    int choix2 = 0;
    int iterations=0;
    vector<double> resUsuelle;
    vector<double> resCastel;
    cout << "1) Résolution par le solveur de bernstein" << endl;
    if(choix == 1 || choix == 2)
    {
        cout << "2) Résolution par méthode usuelle" << endl;
        cout << "3) Comparaison entre méthode usuelle et solveur de bernstein" << endl;
    }

    cin>>choix2;
    
    switch (choix2)
    {
    case 1:
        cout << "nombre d'iterations?" << endl;
        cin >> iterations;
        resCastel = polynome.resolvCastel(iterations);
        for (int i = 0; i < resCastel.size(); i++)
        {
            cout << "r"<<i<<"= " << resCastel[i] << endl;
        }
        break;
    
    case 2:
        resUsuelle = polynome.resolvUsual();
        for (int i = 0; i < resUsuelle.size(); i++)
        {
            cout << "r"<<i<<"= " << resUsuelle[i] << endl;
        }
        break;

    case 3:
        cout << "nombre d'iterations?" << endl;
        cin >> iterations;
        resCastel = polynome.resolvCastel(iterations);
        resUsuelle = polynome.resolvUsual();
        cout << "les solutions avec deCasteljeau sont:" << endl;
        for (int i = 0; i < resCastel.size(); i++)
        {
            cout << "r"<<i<<"= " << resCastel[i] << endl;
        }
        cout << "les solutions avec la méthode usuelle sont:" << endl;
        for (int i = 0; i < resUsuelle.size(); i++)
        {
            cout << "r"<<i<<"= " << resUsuelle[i] << endl;
        }
        break;
    
    default:
        break;
    }


    cout<<"Bonjour et bon travail"<<endl;
    return 0;
}
