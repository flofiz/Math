#include "vector"

using namespace std;
typedef struct Point
{
    double x;
    double y;
};

vector<Point> toBernstein(vector<double> poynome);
vector<Point> casteljeau(vector<Point> ctrl);
Point milieu(Point A, Point B);
