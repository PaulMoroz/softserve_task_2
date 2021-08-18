#include <iostream>
#include <typeinfo>
#include "AnyType.h"
using namespace std;


int main() {

    AnyType a = 'c';
    a = 9999.1;
    try {
        AnyType a = 1;
        a.toBool();
    }catch(exception& e){
        cout<<e.what()<<endl;
    }
    try {
        AnyType a = '1';
        a.Destroy();
        a.toUnsignedInt();
    }catch(exception& e){
        cout<<e.what()<<endl;
    }
}