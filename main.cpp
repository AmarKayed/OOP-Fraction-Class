#include<iostream>

using namespace std;

class Fractie{

    private:

        int a;
        int b;
        int x;

        inline void set_a(int a){this->a = a;}
        inline void set_b(int b){this->b = b;}
        inline void set_x(int x){this->x = x;}

    public:

        inline int get_a()const{return a;}
        inline int get_b()const{return b;}
        inline int get_x()const{return x;}


        
};


int main(){



    return 0;
}