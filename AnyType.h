//
// Created by нободи on 12.08.2021.
//
#include <string>
#include <map>
#include <typeinfo>
#ifndef UNTITLED1_ANYTYPE_H
#define UNTITLED1_ANYTYPE_H
using namespace std;


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

struct GettingNoneObjectError:public exception{
    const char * what () const throw () {
        return "Getting destroyed object error";
    }
};

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
            if(typeid(Value).name()!=typeid(AnyType).name() || this->types.count(typeid(Value).name())){
                if(typeid(Value).name()==typeid(AnyType).name()){
                    AnyType temp = Value;
                    this->value = temp.value;
                    this->type = temp.type;
                    return;
                }
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
            }else
                throw TypeStoringError();
        }
    public:
        AnyType();
        template <typename T>
        AnyType(T value){
            assign(value);
        }

        AnyType(const AnyType& obj);
        ~AnyType();
        string getTypeName();
        void Destroy();
        void checkType(string to);
        bool toBool();
        int toInt();
        float toFloat();
        double toDouble();
        char toChar();
        unsigned int toUnsignedInt();
        template <typename T>
        AnyType& operator=(T other){
            assign(other);
        }
        static void swap(AnyType& a,AnyType& b);
};

#endif //UNTITLED1_ANYTYPE_H
