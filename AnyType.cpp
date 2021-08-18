#include "AnyType.h"

AnyType::AnyType() {
    this->type = "None";
}

AnyType::~AnyType(){}

AnyType::AnyType(const AnyType &obj){
    this->value = obj.value;
    this->type = obj.type;
}

void AnyType::Destroy() {
    this->type = "None";
}

void AnyType::checkType(string to) {
    if(this->type=="None")
        throw GettingNoneObjectError();
    if(types[this->type]!=to)
        throw TypeCastingError();
}

string AnyType::getTypeName(){
    return types[this->type];
}

int AnyType::toInt() {
    checkType("int");
    return this->value.i;
}

bool AnyType::toBool() {
    checkType("bool");
    return this->value.b;
}

float AnyType::toFloat() {
    checkType("float");
    return this->value.f;
}


double AnyType::toDouble() {
    checkType("double");
    return this->value.d;
}

char AnyType::toChar() {
    checkType("char");
    return this->value.c;
}

unsigned int AnyType::toUnsignedInt() {
    checkType("unsigned int");
    return this->value.j;
}

void AnyType::swap(AnyType &a, AnyType &b) {
    AnyType t = a;
    a = b;
    b = t;
}

