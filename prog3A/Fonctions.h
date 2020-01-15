#include "vector"

using namespace std;
struct Point
{
    double x;
    double y;
};

vector<Point> toBernstein(vector<double> polynome);
vector<Point> casteljeau(vector<Point> ctrl, int index);
Point milieu(Point A, Point B);
bool memeSigne(vector<Point> ctrl);
