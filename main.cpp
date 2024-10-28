#include <iostream>

using namespace std;

class ComplexNumber
{
public:
    ComplexNumber() : m_a(1), m_b(1) {};
    ComplexNumber(int a, int b) : m_a(a), m_b(b) {};
    ComplexNumber(ComplexNumber &obj)
    {
        m_a = obj.m_a;
        m_b = obj.m_b;
        cout << "Copied" << endl;
    }

    ~ComplexNumber()
    {
        cout << "Deleting" << endl;
    }

    int m_a;
    int m_b;

    void Print()
    {
        if (m_a == 0)
        {
            cout << m_b << "i" << endl;
        }
        else if (m_b == 0)
        {
            cout << m_a << endl;
        }
        else if (m_b > 0)
        {
            cout << m_a << "+" << m_b << "i" << endl;
        }
        else
        {
            cout << m_a << m_b << "i" << endl;
        }
    }
};

int main()
{
    ComplexNumber *complexNumber1 = new ComplexNumber(2, 2);
    ComplexNumber *complexNumberCopy = new ComplexNumber(*complexNumber1);

    complexNumberCopy->Print();
    complexNumber1->Print();

    delete complexNumber1;

    return 0;
}
