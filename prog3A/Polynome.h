#include "vector"
#define Pi 3.141592654
class Polynome{
        
    public:
        vector<double> coefs;
        Polynome(vector<double> coefs);

        int getDeg();

        vector<double> resolvUsueal();
        vector<double> usual2();
        vector<double> usual3();
        vector<double> usual4();

        double* resolvCastel();
        double* castel3();
        double* castel4();
        double* castel5();
};