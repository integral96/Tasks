#include <iostream>
#include <vector>
#include  <algorithm>

static auto plus_one_pred([](auto x) {
        return x + 1;
        });
template <typename Cont, typename Pred>
void plus_one(Cont& v, const Pred& pred)
{
    std::transform(v.begin(), v.end(), v.begin(),  pred);
    
}
int main()
{
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};
    for(const auto& x : v) std::cout << x << " ";
    std::cout << std::endl;
    
    plus_one(v, plus_one_pred);
    for(const auto& x : v) std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
