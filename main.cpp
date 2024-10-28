#include <iostream>

using namespace std;

class ComplexNumber
{
public:
    ComplexNumber(int a, int b) : m_a(a), m_b(b) {};

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
    ComplexNumber *complexNumber1 = new ComplexNumber(1, 1);
    ComplexNumber *complexNumber2 = new ComplexNumber(1, 1);

    complexNumber1->Print();

    return 0;
}
