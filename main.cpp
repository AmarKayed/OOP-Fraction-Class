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

    Fractie(int a = 1, int b = 1, int x = 1) : a(a), b(b), x(x) {}

    Fractie(const Fractie &ob) : a(ob.get_a()), b(ob.get_b()), x(ob.get_x()) {}

    ~Fractie();

    Fractie &operator=(const Fractie &ob);

    friend istream &operator>>(istream &in, Fractie &ob);

    friend ostream &operator<<(ostream &out, const Fractie &ob);
};

int main()
{

    return 0;
}