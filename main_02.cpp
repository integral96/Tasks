#include <iostream>

class cars_w
{
private:
    int weight;
    int volume;
public:
    cars_w(){}
    cars_w(const int& wght):weight(wght) {}
    cars_w(const int& wght, const int& vol):weight(wght), volume(vol) {}
    int get_weight() const {return weight;}
    int get_volume() const {return volume;}
    virtual void cars_info() const
    {
        if(this->get_volume())
        std::cout << "car #N " << " weight: " << weight  << ", volume " << volume << std::endl;
        else
        std::cout << "car #N " << " weight: " << weight  << std::endl;
        
    }
    ~cars_w(){}
};

class cargo : public cars_w
{
private:
    int weight;
    int volume;
    const cars_w& car_c; 
public:
    cargo(int wght, int vol, const cars_w& car): weight(wght), volume(vol), car_c(car) {}
    int get_weight() const {return weight;}
    int get_volume() const {return volume;}
    virtual void cars_info() const
    {
        if(car_c.get_weight() < (this->get_weight()))
        std::cout << "В эту машину не пометится груз весом: " << weight  << std::endl;
        if(car_c.get_volume() < (this->get_volume()))
        std::cout << "В эту машину не пометится груз объемом: " << volume  << std::endl;
        else
        std::cout << "В эту машину поместится груз, весом: " << weight << " и объемом: " << volume << std::endl;
    }

    ~cargo(){}
};

int main()
{
    cars_w car1(20);
    cars_w car2(20, 30);
    car1.cars_info();
    car2.cars_info();
    cargo  cargo1(30, 40, car1);
    cargo  cargo2(10, 25, car2);
    cargo1.cars_info();
    cargo2.cars_info();
    return 0;
}
