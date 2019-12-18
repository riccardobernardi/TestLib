//
// Created by Riccardo Bernardi on 18/12/2019.
//

#include "TestLib.h"

using namespace std;

int main(){
    Test a{};
    a.add([](){assert(1==2);}, "ciao");
    a.add([](){cout << "se mi veci funziono" << endl;}, "ciao");
    a.launch_test(-1);
}