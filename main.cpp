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

    ComplexNumber operator+(ComplexNumber &obj)
    {
        ComplexNumber addResult;
        addResult.m_a = m_a + obj.m_a;
        addResult.m_b = m_b + obj.m_b;
        return addResult;
    }

    ComplexNumber operator-(ComplexNumber &obj)
    {
        ComplexNumber subtResult;
        subtResult.m_a = m_a - obj.m_a;
        subtResult.m_b = m_b - obj.m_b;
        return subtResult;
    }

    ComplexNumber operator*(ComplexNumber &obj)
    {
        ComplexNumber multResult;
        int multAA = m_a * obj.m_a;
        int multAB = m_a * obj.m_b;
        int multBA = m_b * obj.m_a;
        int multBB = m_b * obj.m_b * -1;
        multResult.m_a = multAA + multBB;
        multResult.m_b = multAB + multBA;
        return multResult;
    }

    ComplexNumber operator/(ComplexNumber &obj)
    {
        if (obj.m_a == 0 && obj.m_b == 0)
        {
            throw invalid_argument("You cannot divide by zero");
        }

        ComplexNumber divResult;
        int divider = (obj.m_a * obj.m_a + obj.m_b * obj.m_b);
        divResult.m_a = (m_a * obj.m_a + m_b * obj.m_b) / divider;
        divResult.m_b = (m_b * obj.m_a - m_a * obj.m_b) / divider;

        return divResult;
    }

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

    float m_a;
    float m_b;
};

int main()
{
    ComplexNumber *complexNumber1 = new ComplexNumber(10, 10);
    ComplexNumber *complexNumber2 = new ComplexNumber(7, 7);
    ComplexNumber *complexNumberCopy = new ComplexNumber(*complexNumber1);
    ComplexNumber complexNumberAdd = *complexNumber1 + *complexNumber2;
    ComplexNumber complexNumberSubt = *complexNumber1 - *complexNumber2;
    ComplexNumber complexNumberMult = *complexNumber1 * *complexNumber2;

    try
    {
        ComplexNumber complexNumberDiv = *complexNumber1 / *complexNumber2;
        complexNumberDiv.Print();
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    complexNumberCopy->Print();
    complexNumber1->Print();
    complexNumberAdd.Print();
    complexNumberSubt.Print();
    complexNumberMult.Print();

    delete complexNumber1;
    delete complexNumber2;
    delete complexNumberCopy;

    return 0;
}
