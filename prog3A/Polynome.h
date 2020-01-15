#include "vector"
#include <iostream>
#include "Fonctions.h"
#include "math.h"
#define Pi 3.141592654
// struct Point
// {
//     double x;
//     double y;
// };
class Polynome{
    public:
        
        std::vector<double> coefs;
        Polynome(std::vector<double> coefs);

        std::vector <double> getPolynome();
        int getDeg();

        std::vector<double> resolvUsual();
        std::vector<double> usual2();
        std::vector<double> usual3();
        std::vector<double> usual4();

        std::vector<double> resolvCastel(int precision);
        // std::vector<Point> toBernstein();
        // std::vector<Point> casteljeau(std::vector<Point> ctrl,int index);
};