//
// Created by Riccardo Bernardi on 18/12/2019.
//

#include "TestLib.h"

using namespace std;

int main(){
    Test a{};
    a.add([=](){assert(1==2);}, "test1");
    a.add([=](){cout << "se mi vedi funziono" << endl;}, "test2");
    a.add([=](){cout << "buonsalve" << endl;}, "test3");
    a.launch_test(-1);
}