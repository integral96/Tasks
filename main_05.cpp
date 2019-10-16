#include <iostream>


template<typename Con>
class print_all
{
private:
    const Con& Obj;
    std::string Name;
public:
    print_all(const Con& obj, std::string name):Obj(obj), Name(name) {}
    std::string get_name() const {return Name;}
    void print_obj() const
    {
        std::cout << "Name: " << Name << "; weight: " << Obj.get_weight()  << "; volume " << Obj.get_volume() << "." << std::endl;
    }
    ~print_all(){}
};

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
    void print() const
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
    void print() const
    {
        std::cout << "cargo #N " << " weight: " << weight  << ", volume " << volume << std::endl;
    }

    ~cargo(){}
};

int main()
{
    cars_w car1(20, 30);
    car1.print();
    
    cargo  cargo1(30, 40);
    cargo1.print();

    print_all<cars_w> prnt1(car1, "Car Kamaz");
    prnt1.print_obj();
    
    print_all<cargo> prnt2(cargo1, "Cargo number 10");
    prnt2.print_obj();
    return 0;
}
