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
};

Fractie::Fractie(int x) : x(x){
    cout << "Constructor Called.\n\n";
    int a, b;
    cout << "Type the value of a: ";
    cin >> a;
    cout << "Type the value of b: ";
    cin >> b;
    set_a(a);
    set_b(b);
}

Fractie::~Fractie(){
    cout << "Destructor Called\n\n";
    a = b = x = 0;
}

Fractie &Fractie::operator=(const Fractie &ob){
    set_a(ob.get_a());
    set_b(ob.get_b());
    set_x(ob.get_x());
    return *this;
}

istream &operator>>(istream &in, Fractie &ob){
    int a, b, x;
    cout<<"Type the value of a: ";
    cin>>a;
    cout<<"Type the value of b: ";
    cin>>b;
    cout<<"Type the value of x: ";
    cin>>x;
    ob.set_a(a); ob.set_b(b); ob.set_x(x);
    return in;
}

ostream &operator<<(ostream &out, const Fractie &ob);

int main()
{

    return 0;
}