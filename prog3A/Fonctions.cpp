#include "Fonctions.h"
#include "iostream"

vector<Point> toBernstein(vector<double> polynome)
{
    vector<Point> res;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    Point p0,p1,p2,p3,p4,p5;

    switch (polynome.size()-1)
    {
    case 3:
        a = polynome[3];
        b = polynome[2];
        c = polynome[1];
        d = polynome[0];
        p0.x = 0;
        p0.y = d;
        res.push_back(p0);
        p1.x = 1./3.;
        p1.y = (c/3.)+d;
        res.push_back(p1);
        p2.x = 2./3.;
        p2.y = (b/3.)+(2.*c/3.)+d;
        res.push_back(p2);
        p3.x = 1.;
        p3.y = a+b+c+d;
        res.push_back(p3);
        break;

    case 4:
        a = polynome[4];
        b = polynome[3];
        c = polynome[2];
        d = polynome[1];
        e = polynome[0];

        p0.x = 0;
        p0.y = e;
        res.push_back(p0);

        p1.x = 1/4;
        p1.y = (d/4)+e;
        res.push_back(p1);

        p2.x = 1/2;
        p2.y = (c/6)+(d/2)+e;
        res.push_back(p2);

        p3.x = 3/4;
        p3.y = (b/4)+(c/2)+(3*d/4)+e;
        res.push_back(p3);

        p4.x = 1;
        p4.y = a+b+c+d+e;
        res.push_back(p4); 

        break;

    case 5:
        a = polynome[5];
        b = polynome[4];
        c = polynome[3];
        d = polynome[2];
        e = polynome[1];
        f = polynome[0];

        p0.x = 0;
        p0.y = f;
        res.push_back(p0);

        p1.x = 1/5;
        p1.y = (e/5)+f;
        res.push_back(p1);

        p2.x = 2/5;
        p2.y = (d/10)+(2*e/5)+f;
        res.push_back(p2);

        p3.x = 3/5;
        p3.y = (e/10)+(3*d/10)+(3*e/5)+f;
        res.push_back(p3);

        p4.x = 4/5;
        p4.y = (b/5)+(2*c/5)+(3*d/5)+(4*e/5)+f;
        res.push_back(p4);

        p5.x = 1;
        p5.y = a+b+c+d+e+f;
        res.push_back(p5); 

        break;
    }
    return res;
}

vector<Point> casteljeau(vector<Point> ctrl,int index)
{
    vector<vector<Point>> res;
    vector<Point> pts;
    if(ctrl.size()!=0)
    {
        if(memeSigne(ctrl)==true)
        {
            return pts;
        }
    }
    else
    {
        return pts;
    }
    // if (ctrl[0].y==0)
    // {
    //     pts.push_back(ctrl[0]);
    // }
    // if (ctrl[ctrl.size()-1].y==0)
    // {
    //     pts.push_back(ctrl[ctrl.size()-1]);
    // }
    
    res.push_back(ctrl);
    int i = 0;
    while (res[i].size()!=1)
    {
        vector<Point> p;
        res.push_back(p);
        i++;
        for(int j = 0; j<res[i-1].size()-1;j++)
        {
            res[i].push_back(milieu(res[i-1][j],res[i-1][j+1]));
        }
        
    }
    if(index == 0)
    {
        pts.push_back(res[i][0]);
    }
    else
    {
        vector<Point> ctrl1;
        vector<Point> ctrl2;
        for(int k = 0; k<res.size(); k++)
        {
            ctrl1.push_back(res[k][0]);
            ctrl2.push_back(res[res.size()-k-1][res[res.size()-k-1].size()-1]);
        }
        vector<Point> gauche = casteljeau(ctrl1,index -1);
        vector<Point> droite = casteljeau(ctrl2, index -1);
        
        for(int l = 0; l<gauche.size(); l++)
        {
            pts.push_back(gauche[l]);
        }
        for(int l = 0; l<droite.size(); l++)
        {
            pts.push_back(droite[l]);
        }
    }
    return pts;
}

    Point milieu(Point A, Point B)
    {
        Point res;
        res.x = (A.x+B.x)/2;
        res.y = (A.y+B.y)/2;
        return res;
    }
    
    bool memeSigne(vector<Point> ctrl)
    {
        bool meme = true;
        if(ctrl[0].y >=0)
        {
            for(int i = 1; i<ctrl.size();i++)
            {
                if (ctrl[i].y < 0)
                {
                    meme = false;
                }
                
            }
        }
        else
        {
            for(int i = 1; i<ctrl.size();i++)
            {
                if (ctrl[i].y > 0)
                {
                    meme = false;
                }
            }
               
        }
        
        return meme;
        
    }
