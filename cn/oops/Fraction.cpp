#include <cmath>
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getNumerator() const { return numerator; }

    int getDenominator() const { return denominator; }

    void setNumerator(int numerator) { this->numerator = numerator; }

    void setDenominator(int denominator) { this->denominator = denominator; }

    void print() const
    {
        cout << this->numerator << " / " << this->denominator << endl;
    }

    void simplify()
    {

        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {

            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    // In order to avoid new Fraction f2 creating we are using pass by reference.
    // By using const reference we agree to the contract then we won't be changing f2.
    Fraction add(Fraction const &f2)
    {
        int lcm = this->denominator * f2.denominator;
        int x = lcm / this->denominator;
        int y = lcm / f2.denominator;
        int num = x * this->numerator + y * f2.numerator;
        Fraction f3(num, lcm);

        // this->numerator=num;
        // this->denominator=lcm;
        f3.simplify();
        return f3;
    }

    Fraction multiply(Fraction const &f2)
    {

        int num = this->numerator * f2.numerator;
        int den = this->denominator * f2.denominator;
        Fraction f3(num, den);
        f3.simplify();
        return f3;
    }

    // Operator overloading
    Fraction operator+(Fraction const &f2) const
    {

        int lcm = this->denominator * f2.denominator;
        int x = lcm / this->denominator;
        int y = lcm / f2.denominator;
        int num = x * this->numerator + y * f2.numerator;
        Fraction f3(num, lcm);

        // this->numerator=num;
        // this->denominator=lcm;
        f3.simplify();
        return f3;
    }

    Fraction operator*(Fraction const &f2) const
    {

        int num = this->numerator * f2.numerator;
        int den = this->denominator * f2.denominator;
        Fraction f3(num, den);
        f3.simplify();
        return f3;
    }

    bool operator==(Fraction const &f2) const
    {

        return (this->numerator == f2.numerator && this->denominator == f2.denominator);
    }

    // pre-increment
    //  When we return by reference then buffer memory will not be used
    Fraction &operator++()
    {

        this->numerator = this->numerator + this->denominator;
        this->simplify();
        return *this;
    }

    // post-increment
    Fraction operator++(int)
    {

        Fraction fnew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }

    Fraction &operator+=(Fraction const &f2)
    {
        int lcm = this->denominator * f2.denominator;
        int x = lcm / this->denominator;
        int y = lcm / f2.denominator;
        int num = x * this->numerator + y * f2.numerator;

        this->numerator = num;
        this->denominator = lcm;
        simplify();
        return *this;
    }
};

// f1+f2 here + is a binary operator as it requires two operands
// ++f1 here ++ is a urinary operator as it requires single operands

/*
int i=5;
here first 5 is saved in some buffer memory and then i is created for us and then 5 is copied into i from buffer

int fun(int i){
    i++;
    return i;
}

here we are trying to print directly without receiving into some variable.
Whats actually happening is that when the fun(5) is returning 6 then system will copy 6 into some buffer memory.
Then printing or any other operation works from this buffer memory
int main(){
    cout<<fun(5);
    return 0;
}

int i = 5
int j = ++i; pre increment says first increment then use the value
int j = i++; post increment says first use then increment the value
*/