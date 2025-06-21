#include<iostream>
using namespace std;
#include<string>

class Shape{//this is an abstract class it can not be instantionated and act as a blueprint for derived class 
    public:
    //pure virtual function
        virtual double getArea() const = 0;

        virtual void draw() const = 0;

        virtual void display() const {
            cout << "Shape with Area" << getArea() << endl;
        }

        virtual ~Shape() = default;
};

class Rectangle:public Shape{
    private:
        double width, height;
        public:
        Rectangle(double w,double h){
            this->width = w;
            this->height = h;
        }

        double getArea() const override{
            return this->height * this->width;
        }

        void draw() const override{
            cout << "Draw rectange of width: " << this->width << "height " << this->height<<endl;
        }
        
};

int main(int argc, char const *argv[])
{
    // Shape s; we will get error because teh abstract class can not be instantiated

    Rectangle rect(5, 3);
    cout<<rect.getArea()<<endl;
    rect.draw();

    return 0;
}
