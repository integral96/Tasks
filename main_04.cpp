#include <iostream>

template<typename Con>
void plus_one(Con& con)
{
    using T = typename Con::type;
    T wgh = con.get_weight()+1;
    T vol = con.get_volume()+1;
    con.set_weight(wgh);
    con.set_volume(vol);
}

class cars_w
{
public:
    using type = int;
private:
    int weight;
    int volume;
public:
    cars_w(const int& wght, const int& vol):weight(wght), volume(vol) {}
    int get_weight() const {return weight;}
    int get_volume() const {return volume;}
    void set_weight(const int &w) {weight = w;}
    void set_volume(const int &v) {volume = v;}
    virtual void cars_info() const
    {
        std::cout << "car #N " << " weight: " << weight  << ", volume " << volume << std::endl;
    }
    ~cars_w(){}
};

class cargo 
{
public:
    using type = int;
private:
    int weight;
    int volume;
public:
    cargo(int wght, int vol): weight(wght), volume(vol) {}
    int get_weight() const {return weight;}
    int get_volume() const {return volume;}
    void set_weight(const int &w) {weight = w;}
    void set_volume(const int &v) {volume = v;}
    virtual void cargo_info() const
    {
        std::cout << "cargo #N " << " weight: " << weight  << ", volume " << volume << std::endl;
    }

    ~cargo(){}
};

int main()
{
    cars_w car1(20, 30);
    car1.cars_info();
    
    cargo  cargo1(30, 40);
    cargo1.cargo_info();

    plus_one<cars_w>(car1);
    car1.cars_info();

    plus_one<cargo>(cargo1);
    cargo1.cargo_info();
    
    return 0;
}
