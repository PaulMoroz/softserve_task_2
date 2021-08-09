#include <iostream>
#include <map>
#include <typeinfo>
using namespace std;

template <typename T>
class AnyType {
private:
    T value;
    map<string ,string> types = {{"i","int"},{"j","unsigned int"},{"c","char"},{"f","float"},{"d","double"},{"b","bool"}};
public:
    AnyType(){
        this->value = 0;
    }
    AnyType(T value){
        this->value = value;
    }
    AnyType(const AnyType& obj) {
        this->value = obj.value;
    }
    ~AnyType(){

    }
    T getValue(){
        return this->value;
    }
    string getTypeName(){
        return this->types[typeid(this->value).name()];
    }
    bool toBool() {
        return bool(value);
    }
    int toInt() {
        return int(value);
    }
    float toFloat() {
        return float(value);
    }
    double toDouble() {
        return double(value);
    }
    char toChar(){
        return char(value);
    }
    unsigned int toUnsignedInt(){
        return (unsigned int)(value);
    }
    AnyType& operator+=(const AnyType& other){
        this->value += other.value;
        return *this;
    }
    AnyType& operator-=(const AnyType& other){
        this->value /= other.value;
        return *this;
    }
    AnyType& operator*=(const AnyType& other){

        this->value /= other.value;
        return *this;
    }
    AnyType& operator/=(const AnyType& other){

        this->value /= other.value;
        return *this;
    }
    static void swap(T& a,T& b){
        AnyType t = a;
        a = b;
        b = t;
    }
};

int main() {

}
