
#include "xtensor/xarray.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xio.hpp"


int main() {
    xt::xarray<double> arr{3.4, 4.4, 3.3, 5.5};
    arr.reshape({2,2});
    std::cout << arr << std::endl;


    return 0;
}
