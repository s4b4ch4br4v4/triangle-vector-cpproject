#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>
#include <cstring>

using namespace std;

class RightTriangle{
    private:
        double a;
        double b;

    public:
        // CONSTRUCTOR
        RightTriangle(double a = 0, double b = 0){
            Seta(a);
            Setb(b);
        }

        // GETTERS:
        double Geta(){return a;}
        double Getb(){return b;}
        double Getc(){return sqrt(Geta() * Geta() + Getb() * Getb());}

        double GetC(){return M_PI / 2;}

        //SETTERS:
        void Seta(double a = 0){this->a = fabs(a);}
        void Setb(double b = 0){this->b = fabs(b);}

        // PERIMETER AND AREA:
        double P(){
            if(Geta() == 0 || Getb() == 0){
                return 0;
            } else {
                return Geta() + Getb() + Getc();
            }
        }

        double S(){
            if(Geta() == 0 || Getb() == 0){
                return 0;
            } else {
                return Geta() * Getb() / 2;
            }
        }

        //ANGLES:
        double A(){
            if(Geta() == 0){
                return -1;
            } else {
                return atan(Getb() / Geta());
            }
        }

        double B(){
            if(Getb() == 0){
                return -1;
            } else {
                return atan(Geta() / Getb());
            }
        }

        // INNER CIRCLE RADIUS:
        double r(){
            if(Geta() == 0 || Getb() == 0){
                return 0;
            } else {
                return (Geta() + Getb() - Getc()) / 2;
            }
        }

        // OUTER CIRCLE RADIUS:
        double R(){
            return Getc() / 2;
        }
};

class Vector{
    private:
        unsigned int Dimension;
        RightTriangle* myvector;

    public:
        // CONSTRUCTOR:

        Vector(unsigned int Dimension = 1){
            SetD(Dimension);
            myvector = new RightTriangle[Dimension];
        }

        // SETTERS:

        void SetD(unsigned int Dimension = 1){
            assert(Dimension != 0);
            this->Dimension = Dimension;
        }

        void SetElement(unsigned int i, RightTriangle triangle){
            myvector[i] = triangle;
        }

        // GETTERS:

        unsigned int GetD(){return Dimension;}
        RightTriangle* GetV(){return myvector;}
};

// TRIANGLE FUNCTIONS:

RightTriangle CinFromConsole(){
    cout<<endl;
    double a = 0; cout<<"Input a: "; cin>>a;
    double b = 0; cout<<"Input b: "; cin>>b;
    return RightTriangle(a, b);
}
void CoutToConsole(RightTriangle tmp){
    cout<<"\nHypotenuse: "<<tmp.Getc()<<endl;
    cout<<"Perimeter: "<<tmp.P()<<endl;
    cout<<"Area: "<<tmp.S()<<endl<<endl;
    cout<<"Angle A: "<<tmp.A()<<endl;
    cout<<"Angle B: "<<tmp.B()<<endl;
    cout<<"Angle C: "<<tmp.GetC()<<endl<<endl;
    cout<<"Circles: r = "<<tmp.r()<<" R = "<<tmp.R()<<endl;
}

// VECTOR FUNCTIONS:

Vector CinDimension(){
    unsigned int i = 0;
    cout<<"Input dimension of your vector: "; cin>>i;
    return Vector(i);
}

Vector CinElements(Vector myvector){
    cout<<"Input elements: "<<endl;
    for(int i = 0; i < myvector.GetD(); ++i){
        cout<<"V["<<i+1<<"]:";
        RightTriangle triangle = CinFromConsole();
        myvector.SetElement(i, triangle);
    }
    return myvector;
}

void CoutElements(Vector myvector){
    system("cls");
    cout<<"V["<<myvector.GetD()<<"] = { "<<endl<<endl;
    for(int i = 0; i < myvector.GetD(); ++i){
        cout<<"["<<i+1<<"]:"<<endl;
        CoutToConsole(myvector.GetV()[i]);
        cout<<endl;
    }
    cout<<"}"<<endl;
}

int main(int argc, char* argv){

    Vector TriangleVector = CinDimension();
    CinElements(TriangleVector);
    CoutElements(TriangleVector);

    return 0;
}
