//A program to show operator overloading in C++


#include<iostream>
using namespace std;

class complex
{
    float re, im;
    public:
        complex()
        {}
        complex(float a, float b)
        {
            re = a; im = b;
        }
        void Accept()
        {
            cout<<"Real: ";cin>>re;
            cout<<"Imaginary: ";cin>>im;
        }
        void Display()
        {
            cout<<re<<" + "<<im<<"i"<<endl;
        }
        complex operator *(complex z1)
        {
            complex z3;
            z3.re = z1.re * re -  z1.im * im;
            z3.im = z1.im * re + z1.re * im;
            return z3;
        }
        complex operator /(complex z1)
        {
            complex z3;
            z3.re = (z1.re * re +  z1.im * im)/(z1.re*z1.re+z1.im*z1.im);
            z3.im = (z1.re*im - re*z1.im)/(z1.re*z1.re+z1.im*z1.im);
            return z3;
        }
        complex friend operator +(complex z1, complex z2);
        complex friend operator -(complex z1, complex z2);
};

complex operator +(complex z1, complex z2)
{
    complex z3;
    z3.re = z1.re + z2.re;
    z3.im = z1.im + z2.im;
    return z3;
}

complex operator -(complex z1, complex z2)
{
    complex z3;
    z3.re = z1.re - z2.re;
    z3.im = z1.im - z2.im;
    return z3;
}

int main()
{
    complex z1(3,5);
    complex z2(4,3);
    complex z3;
    cout<<"Enter complex no. z1 \n";
    z1.Accept();
    cout<<"Enter complex no. z2 \n";
    z2.Accept();
    int ch;
    char con;
    do
    {
        cout<<"z1 = ";
        z1.Display();
        cout<<"z2 = ";
        z2.Display();
        cout<<"\nMenu: "<<"\n1. Addition\n2. Subtraction\n3. multiplication\n4. Division\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                z3=z1+z2;
                cout<<"z1 + z2 = ";
                z3.Display();
                break;
            case 2:
                z3=z1-z2;
                cout<<"z1 - z2 = ";
                z3.Display();
                break;   
            case 3:
                z3=z1*z2;
                cout<<"z1 * z2 = ";
                z3.Display();
                break;
            case 4:
                z3=z1/z2;
                cout<<"z1 / z2 = ";
                z3.Display();
                break;
            default:
                cout<<"Enter correct choice!";   
        }
        cout<<"\nWant to continue? y/n ... ";
        cin>>con;
    }while(con == 'y' || con == 'Y');
    return 0;
}

