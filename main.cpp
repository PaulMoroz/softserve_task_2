#include <iostream>
#include <map>
#include <typeinfo>
using namespace std;

union myUnion{
    int i;
    double d;
    float f;
    unsigned int j;
    char c;
    bool b;
};

class AnyType {
private:
    myUnion value;
    string type;
    map<string ,string> types = {{"i","int"},{"j","unsigned int"},{"c","char"},{"f","float"},{"d","double"},{"b","bool"}};

    template <typename T>
    void assign(T Value){
        if(typeid(Value).name()==typeid(AnyType).name()){
            AnyType temp = Value;
            this->value = temp.value;
            this->type = temp.type;
        }else
            if(this->types.count(typeid(Value).name())==0){
                throw "Cannot store that value in the object!";
            }else{
                this->type = typeid(Value).name();
                if(this->type=="i"){
                    this->value.i = Value;
                }
                if(this->type=="f"){
                    this->value.f = Value;
                }
                if(this->type=="d"){
                    this->value.d = Value;
                }
                if(this->type=="c"){
                    this->value.c = Value;
                }
                if(this->type=="b"){
                    this->value.b = Value;
                }
                if(this->type=="j"){
                    this->value.j = Value;
                }
            }
    }
public:
    AnyType(){
        this->type = "";
    }
    template <typename T>
    AnyType(T value){
        assign(value);
    }
    AnyType(const AnyType& obj) {
        this->value = obj.value;
        this->type = obj.type;
    }
    ~AnyType(){

    }
    string getTypeName(){
        return types[this->type];
    }
    bool toBool() {
        return this->value.b;
    }
    int toInt() {
        return this->value.i;
    }
    float toFloat() {
        return this->value.f;
    }
    double toDouble() {
        return this->value.d;
    }
    char toChar(){
        return this->value.c;
    }
    unsigned int toUnsignedInt(){
        return this->value.j;
    }

    template <typename T>
    AnyType& operator=(T other){
        assign(other);
    }
    static void swap(AnyType& a,AnyType& b){
        AnyType t = a;
        a = b;
        b = t;
    }
};

int main() {
    cout<<"Before\n";
    AnyType a;
    a = 1;
    AnyType b;
    b = true;
    cout<<a.getTypeName()<<endl;
    cout<<b.getTypeName()<<endl;
    AnyType::swap(a,b);
}