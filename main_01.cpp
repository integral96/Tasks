#include <iostream>
#include <utility>
#include <iterator>
#include <set>

int main()
{
    int N, i = 0, k = 1;
    int weight;
    int volume;
    std::set<std::pair<int, int>> cars;
    std::set<std::pair<int, int>>::reverse_iterator ir;
    std::cout << "Введите количество машин:" << std::endl;
    std::cin >> N;
    
    while (i < N)
    {
        std::cout << "Введите вес и объем " << i+1 << " машины, через пробел(потом ввод): " << std::endl;
        std::cin >> weight >> volume;
        cars.insert(std::make_pair( weight , volume ));
        i++;
    }
    for(ir=cars.rbegin(); ir!=cars.rend(); ++ir)
        std::cout << "car #N " << k++ << " weight: " << (*ir).first << "; volume " << (*ir).second << std::endl;
    
    return 0;
}
