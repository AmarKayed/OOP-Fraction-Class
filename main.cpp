#include <iostream>

using namespace std;

class Fractie
{

private:
    int a;
    int b;
    int x;

    inline void set_a(int a) { this->a = a; }
    inline void set_b(int b) { this->b = b; }
    inline void set_x(int x) { this->x = x; }

public:
    inline int get_a() const { return a; }
    inline int get_b() const { return b; }
    inline int get_x() const { return x; }

    Fractie(int x = 1);

    Fractie(const Fractie &ob) : a(ob.get_a()), b(ob.get_b()), x(ob.get_x()) {}

    ~Fractie();

    Fractie &operator=(const Fractie &ob);

    friend istream &operator>>(istream &in, Fractie &ob);

    friend ostream &operator<<(ostream &out, const Fractie &ob);

    static void print_negative(int n);
};

Fractie::Fractie(int x) : x(x)
{
    cout << "Constructor Called.\n\n";
    int a, b;
    cout << "Type the value of a: ";
    cin >> a;
    cout << "Type the value of b: ";
    cin >> b;
    set_a(a);
    set_b(b);
}

Fractie::~Fractie()
{
    // cout << "Destructor Called\n\n";
    a = b = x = 0;
}

Fractie &Fractie::operator=(const Fractie &ob)
{
    set_a(ob.get_a());
    set_b(ob.get_b());
    set_x(ob.get_x());
    return *this;
}

istream &operator>>(istream &in, Fractie &ob)
{
    int a, b, x;
    cout << "Type the value of a: ";
    cin >> a;
    cout << "Type the value of b: ";
    cin >> b;
    cout << "Type the value of x: ";
    cin >> x;
    ob.set_a(a);
    ob.set_b(b);
    ob.set_x(x);
    return in;
}

ostream &operator<<(ostream &out, const Fractie &ob)
{
    if (ob.get_a() * ob.get_x() + ob.get_b() == 0)
        cout << "Impossible Fraction.\n";
    else
    {
        cout << "1/(";
        Fractie::print_negative(ob.get_a());
        cout << '*';
        Fractie::print_negative(ob.get_x());
        if (ob.get_b() < 0)
            cout << " - " << (-1) * ob.get_b();
        else
            cout << " + " << ob.get_b();
        cout << ") = ";

        float denominator = ob.get_a() * ob.get_x() + ob.get_b();
        float result = 1 / denominator;

        if (denominator < 0)
            cout << "- 1/" << denominator * (-1);
        else
            cout << "1/" << denominator;
        cout << " = " << result << '\n';
    }
}

void Fractie::print_negative(int n)
{
    if (n < 0)
        cout << '(' << n << ')';
    else
        cout << n;
}

class Operatii
{

private:
    Fractie ob;

    inline void set_ob(const Fractie &x) { ob = x; }

public:
    inline Fractie get_ob() const { return ob; }

    Operatii(const Fractie &ob = 0) : ob(ob) {}

    bool conditie() const;

    float valoare();
};

bool Operatii::conditie() const
{
    if (get_ob().get_a() * get_ob().get_x() + get_ob().get_b() == 0)
        return false;
    else
        return true;
}

float Operatii::valoare()
{
    cout << "Type the value of x: ";
    int x;
    cin >> x;

    float result = 1 / float(get_ob().get_a() * get_ob().get_x() + get_ob().get_b());
    cout << "The value of the fraction is: " << result << '\n';
}

Fractie produs(const Fractie x, const Fractie y){ // Two Constructors will be called

}


int main()
{
    Fractie f;
    Operatii o(f);
    o.valoare();
    return 0;
}