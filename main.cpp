#include "header.hpp"
GeometryProgression::GeometryProgression(int first_elem, int znam, size_t size, int *arr){
        this->first_elem = first_elem;
        this->znam = znam;
        this->size = size;
        for (size_t i{1}; i < size; i++){
            if (arr[i] != arr[i-1]*znam){
                throw GeometryException("Not a geometry progression \n", *this);
            }
        }
        this->arr = arr;
}
void GeometryProgression::print() const{
        std::cout << first_elem << "\t" << znam<< "\t" << size << std::endl;
        for (size_t i{1}; i < size; i++){
            std::cout << arr[i] << "\t";
        }
}

GeometryException::GeometryException(std::string msg, GeometryProgression& gp1) : std::invalid_argument(msg), gp(gp1){};

void GeometryException::print() const{gp.print();}

int main(){
    int arr[] = {1, 2, 4, 8, 10};
    try{
        GeometryProgression gp(1, 2, 5, arr);
        gp.print();
    }
    catch(const GeometryException& ge){
        std::cout << ge.what() << std::endl;
    }
}