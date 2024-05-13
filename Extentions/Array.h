#include <Arduino.h>

template <typename T>
class Array {       
  public:
    int size;
    T array[];

    Array(T* array, int size){
        this.array = array;
        this.size = size;
    }
};