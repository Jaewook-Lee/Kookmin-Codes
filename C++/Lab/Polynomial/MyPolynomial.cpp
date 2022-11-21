#include "MyPolynomial.h"
#include <vector>
#include <cmath>

/* Constructors */
MyPolynomial::MyPolynomial(int coeff, unsigned int exp) : degree(exp)
{
    MyTerm term = MyTerm(coeff, exp);
    terms = new MyTerm[1];
    terms[0] = term;
}
MyPolynomial::MyPolynomial(int numTerms, int mono[])
{
    terms = new MyTerm[numTerms / 2];

    for (int i=0; i<numTerms/2; i++)
    {
        int term_c = mono[2 * i];
        unsigned int term_e = (unsigned int)mono[2 * i + 1];
        MyTerm *term = new MyTerm(term_c, term_e);
        terms[i] = *term;
        delete term;
    }

    degree = terms->exponent;
}
MyPolynomial::MyPolynomial(const MyPolynomial& poly)
{
    degree = poly.degree;
    terms = new MyTerm[sizeof(*(poly.terms)) / sizeof(MyTerm)];
    for (int i=0; i<sizeof(*terms)/sizeof(MyTerm); i++)
        *(terms + i) = *(poly.terms + i);
}

/* Destructor */
MyPolynomial::~MyPolynomial() { delete terms; }

/* Accessor & Mutator Functions */
unsigned int MyPolynomial::getDegree() const { return degree; }
int MyPolynomial::getNumTerms() const { return (sizeof(*terms)/sizeof(MyTerm)); }
void MyPolynomial::setCoeff(int coeff)
{
    if ((sizeof(*terms) / sizeof(MyTerm)) != 1) return;
    else terms->coefficient = coeff;
}


/* Member Function(private) */
void MyPolynomial::sortPoly(MyTerm* term_array, long size)
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=i; j<size; j++)
        {
            if ((term_array + i)->exponent < (term_array + j)->exponent)
            {
                MyTerm tmp = *(term_array + i);
                *(term_array + i) = *(term_array + j);
                *(term_array + j) = tmp;
            }
        }
    }
}

/* Member Function */
MyPolynomial MyPolynomial::ddx() const
{
    MyPolynomial polynomial = *this;
    for (int i=0; i<(sizeof(*polynomial.terms)/sizeof(MyTerm)); i++)
        *(polynomial.terms + i) = (polynomial.terms + i)->ddx();
}

/* Overloaded binary operatos(with polynomial) */
MyPolynomial MyPolynomial::operator +(const MyPolynomial& poly) const
{
    vector<MyTerm> sum_terms;

    long this_size = sizeof(*terms) / sizeof(MyTerm);
    long param_size = sizeof(*poly.terms) / sizeof(MyTerm);
    long this_term_start = 0, param_term_start = 0;

    while(this_term_start <= this_size && param_term_start <= param_size)
    {
        if (((terms + this_term_start)->exponent) > ((poly.terms + param_term_start)->exponent))
        {
            sum_terms.push_back(*(terms + this_term_start));
            this_term_start++;
        }
        else if (((terms + this_term_start)->exponent) < ((poly.terms + param_term_start)->exponent))
        {
            sum_terms.push_back(*(poly.terms + param_term_start));
            param_term_start++;
        }
        else
        {
            MyTerm sum_term = *(terms + this_term_start) + *(terms + param_term_start);
            sum_terms.push_back(sum_term);
            this_term_start++;
            param_term_start++;
        }
    }
    for (; this_term_start<=this_size; this_term_start++)
        sum_terms.push_back(*(terms + this_term_start));
    for (; param_term_start<=param_size; param_term_start++)
        sum_terms.push_back(*(poly.terms + param_term_start));

    long num_terms = sum_terms.size();
    int real_sum_terms[num_terms * 2];
    for (int i=0; i<num_terms; i++)
    {
        *(real_sum_terms + 2 * i) = sum_terms[i].coefficient;
        *(real_sum_terms + 2 * i + 1) = sum_terms[i].exponent;
    }

    return MyPolynomial(num_terms, real_sum_terms);
}
MyPolynomial MyPolynomial::operator -(const MyPolynomial& poly) const
{
    vector<MyTerm> sum_terms;

    long this_size = sizeof(*terms) / sizeof(MyTerm);
    long param_size = sizeof(*poly.terms) / sizeof(MyTerm);
    long this_term_start = 0, param_term_start = 0;

    while(this_term_start <= this_size && param_term_start <= param_size)
    {
        if (((terms + this_term_start)->exponent) > ((poly.terms + param_term_start)->exponent))
        {
            sum_terms.push_back(*(terms + this_term_start));
            this_term_start++;
        }
        else if (((terms + this_term_start)->exponent) < ((poly.terms + param_term_start)->exponent))
        {
            sum_terms.push_back(*(poly.terms + param_term_start));
            param_term_start++;
        }
        else
        {
            MyTerm sum_term = *(terms + this_term_start) - *(poly.terms + param_term_start);
            sum_terms.push_back(sum_term);
            this_term_start++;
            param_term_start++;
        }
    }
    for (; this_term_start<=this_size; this_term_start++)
        sum_terms.push_back(*(terms + this_term_start));
    for (; param_term_start<=param_size; param_term_start++)
        sum_terms.push_back(*(poly.terms + param_term_start));

    long num_terms = sum_terms.size();
    int real_sum_terms[num_terms * 2];
    for (int i=0; i<num_terms; i++)
    {
        *(real_sum_terms + 2 * i) = sum_terms[i].coefficient;
        *(real_sum_terms + 2 * i + 1) = sum_terms[i].exponent;
    }

    return MyPolynomial(num_terms, real_sum_terms);
}
MyPolynomial MyPolynomial::operator *(const MyPolynomial& poly) const
{
    vector<MyTerm> multiplied_terms;

    for (int i=0; i<sizeof(*terms)/sizeof(MyTerm); i++)
    {
        for (int j=0; j<sizeof(*poly.terms)/sizeof(MyTerm); j++)
        {
            MyTerm multiplied = (*(terms + i)) * (*(terms + j));
            multiplied_terms.push_back(multiplied);
        }
    }

    vector<MyTerm> real_mul_terms;
    while (multiplied_terms.size() != 0)
    {
        MyTerm pivot = multiplied_terms.front();
        multiplied_terms.erase(multiplied_terms.begin());
        for (int i=0; i<multiplied_terms.size(); i++)
        {
            if (multiplied_terms[i].exponent == pivot.exponent)
            {
                pivot += multiplied_terms[i];
                multiplied_terms.erase(multiplied_terms.begin() + i);
                i--;
            }
        }
        real_mul_terms.push_back(pivot);
    }

    long mul_term_size = real_mul_terms.size();
    int num_terms[mul_term_size * 2];
    for (int i=0; i<mul_term_size; i++)
    {
        *(num_terms + 2 * i) = real_mul_terms[i].coefficient;
        *(num_terms + 2 * i + 1) = real_mul_terms[i].exponent;
    }

    return MyPolynomial(mul_term_size, num_terms);
}

/* Overloaded binary operators(with decimal number) */
MyPolynomial MyPolynomial::operator *(int value) const
{
    MyPolynomial multiplied_poly = *this;
    for (int i=0; i<(sizeof(*terms)/sizeof(MyTerm)); i++) { ((multiplied_poly.terms) + i)->coefficient *= value; }
    return multiplied_poly;
}
MyPolynomial operator *(int value, const MyPolynomial& poly)
{
    MyPolynomial multiplied_poly = poly;
    for (int i=0; i<(sizeof(*poly.terms)/sizeof(MyTerm)); i++)
    {
        int coeff = ((multiplied_poly.terms) + i)->getCoeff();
        ((multiplied_poly.terms) + i)->setCoeff(value * coeff);
    }
    return multiplied_poly;
}

/* Overloaded calculate operator */
long MyPolynomial::operator ()(int root) const
{
    long poly_result = 0;
    for (int i=0; i<(sizeof(*terms)/sizeof(MyTerm)); i++)
    {
        long term_result = pow(((terms + i)->coefficient) * root, ((terms + i)->exponent));
        poly_result += term_result;
    }
    return poly_result;
}

/* Overloaded unary operator */
MyPolynomial MyPolynomial::operator -() const
{
    MyPolynomial minus_poly = *this;
    for (int i=0; i<(sizeof(*minus_poly.terms)/sizeof(MyTerm)); i++) { (minus_poly.terms + i)->coefficient = ((terms + i)->coefficient) * -1; }
    return minus_poly;
}

/* Overloaded comparison operators */
bool MyPolynomial::operator ==(const MyPolynomial& poly)
{
    if ((sizeof(*terms)) != (sizeof(*poly.terms))) return false;
    else
    {
        for (int i=0; i<(sizeof(*terms)/sizeof(MyTerm)); i++)
            if (*(terms + i) != *(poly.terms + i)) return false;
        return true;
    }
}
bool MyPolynomial::operator !=(const MyPolynomial& poly)
{
    if ((sizeof(*terms)) != (sizeof(*poly.terms))) return true;
    else
    {
        for (int i=0; i<(sizeof(*terms)/sizeof(MyTerm)); i++)
            if (*(terms + i) != *(poly.terms + i)) return true;
        return false;
    }
}

/* Overloaded assignment operator */
MyPolynomial& MyPolynomial::operator =(const MyPolynomial& poly)
{
    degree = poly.degree;
    for (int i=0; i<(sizeof(*poly.terms)/sizeof(MyTerm)); i++) { *(terms + i) = *(poly.terms + i); }
}

/* Overloaded complex assignment operators(with polynomial) */
MyPolynomial& MyPolynomial::operator +=(const MyPolynomial& poly)
{
    vector<MyTerm> sum_terms;

    long this_size = sizeof(*terms) / sizeof(MyTerm);
    long param_size = sizeof(*poly.terms) / sizeof(MyTerm);
    long this_term_start = 0, param_term_start = 0;

    while(this_term_start <= this_size && param_term_start <= param_size)
    {
        if (((terms + this_term_start)->exponent) > ((poly.terms + param_term_start)->exponent))
        {
            sum_terms.push_back(*(terms + this_term_start));
            this_term_start++;
        }
        else if (((terms + this_term_start)->exponent) < ((poly.terms + param_term_start)->exponent))
        {
            sum_terms.push_back(*(poly.terms + param_term_start));
            param_term_start++;
        }
        else
        {
            MyTerm sum_term = *(terms + this_term_start) + *(terms + param_term_start);
            sum_terms.push_back(sum_term);
            this_term_start++;
            param_term_start++;
        }
    }
    for (; this_term_start<=this_size; this_term_start++)
        sum_terms.push_back(*(terms + this_term_start));
    for (; param_term_start<=param_size; param_term_start++)
        sum_terms.push_back(*(poly.terms + param_term_start));

    long num_terms = sum_terms.size();
    int real_sum_terms[num_terms * 2];
    for (int i=0; i<num_terms; i++)
    {
        *(real_sum_terms + 2 * i) = sum_terms[i].coefficient;
        *(real_sum_terms + 2 * i + 1) = sum_terms[i].exponent;
    }

    *this = MyPolynomial(num_terms, real_sum_terms);
    return *this;
}
MyPolynomial& MyPolynomial::operator -=(const MyPolynomial& poly)
{
    vector<MyTerm> sum_terms;

    long this_size = sizeof(*terms) / sizeof(MyTerm);
    long param_size = sizeof(*poly.terms) / sizeof(MyTerm);
    long this_term_start = 0, param_term_start = 0;

    while(this_term_start <= this_size && param_term_start <= param_size)
    {
        if (((terms + this_term_start)->exponent) > ((poly.terms + param_term_start)->exponent))
        {
            sum_terms.push_back(*(terms + this_term_start));
            this_term_start++;
        }
        else if (((terms + this_term_start)->exponent) < ((poly.terms + param_term_start)->exponent))
        {
            sum_terms.push_back(*(poly.terms + param_term_start));
            param_term_start++;
        }
        else
        {
            MyTerm sum_term = *(terms + this_term_start) - *(poly.terms + param_term_start);
            sum_terms.push_back(sum_term);
            this_term_start++;
            param_term_start++;
        }
    }
    for (; this_term_start<=this_size; this_term_start++)
        sum_terms.push_back(*(terms + this_term_start));
    for (; param_term_start<=param_size; param_term_start++)
        sum_terms.push_back(*(poly.terms + param_term_start));

    long num_terms = sum_terms.size();
    int real_sum_terms[num_terms * 2];
    for (int i=0; i<num_terms; i++)
    {
        *(real_sum_terms + 2 * i) = sum_terms[i].coefficient;
        *(real_sum_terms + 2 * i + 1) = sum_terms[i].exponent;
    }

    *this = MyPolynomial(num_terms, real_sum_terms);
    return *this;
}
MyPolynomial& MyPolynomial::operator *=(const MyPolynomial& poly)
{
    vector<MyTerm> multiplied_terms;

    for (int i=0; i<sizeof(*terms)/sizeof(MyTerm); i++)
    {
        for (int j=0; j<sizeof(*poly.terms)/sizeof(MyTerm); j++)
        {
            MyTerm multiplied = (*(terms + i)) * (*(terms + j));
            multiplied_terms.push_back(multiplied);
        }
    }

    vector<MyTerm> real_mul_terms;
    while (multiplied_terms.size() != 0)
    {
        MyTerm pivot = multiplied_terms.front();
        multiplied_terms.erase(multiplied_terms.begin());
        for (int i=0; i<multiplied_terms.size(); i++)
        {
            if (multiplied_terms[i].exponent == pivot.exponent)
            {
                pivot += multiplied_terms[i];
                multiplied_terms.erase(multiplied_terms.begin() + i);
                i--;
            }
        }
        real_mul_terms.push_back(pivot);
    }

    long mul_term_size = real_mul_terms.size();
    int num_terms[mul_term_size * 2];
    for (int i=0; i<mul_term_size; i++)
    {
        *(num_terms + 2 * i) = real_mul_terms[i].coefficient;
        *(num_terms + 2 * i + 1) = real_mul_terms[i].exponent;
    }

    *this = MyPolynomial(mul_term_size, num_terms);
    return *this;
}

/* Overloaded complex assignment operators(with decimal number) */
MyPolynomial& MyPolynomial::operator*=(int value)
{
    for (int i=0; i<(sizeof(*terms)/sizeof(MyTerm)); i++) { (terms + i)->coefficient *= value; }
    return *this;
}

/* Output operator */
ostream& operator <<(ostream& outStream, const MyPolynomial& poly)
{
    for (int i=0; i<sizeof(*poly.terms)/sizeof(MyTerm); i++)
    {
        outStream << *(poly.terms + i);
    }
    outStream << endl;
    return outStream;
}