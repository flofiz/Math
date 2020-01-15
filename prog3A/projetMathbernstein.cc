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


    cout<<"Bonjour et bon travail"<<endl;
    return 0;
}
