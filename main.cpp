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

struct TypeCastingError:public exception{
    const char * what () const throw () {
        return "Casting types error";
    }
};

struct TypeStoringError:public exception{
    const char * what () const throw () {
        return "Storing types error";
    }
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
                throw TypeStoringError();
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
    void checkType(string to){
        if(types[this->type]==to)throw TypeCastingError();
    }
    bool toBool() {
        checkType("bool");
        return this->value.b;
    }
    int toInt() {
        checkType("int");
        return this->value.i;
    }
    float toFloat() {
        checkType("float");
        return this->value.f;
    }
    double toDouble() {
        checkType("double");
        return this->value.d;
    }
    char toChar(){
        checkType("double");
        return this->value.c;
    }
    unsigned int toUnsignedInt(){
        checkType("unsigned int");
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
    cout<<"After\n";
    cout<<a.getTypeName()<<endl;
    cout<<b.getTypeName()<<endl;

}