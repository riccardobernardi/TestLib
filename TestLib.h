//
// Created by rr on 08/11/2019.
//

#ifndef TENSORLIB_TESTLIB_H
#define TENSORLIB_TESTLIB_H

#include <functional>
#include <vector>
#include <iostream>
#include <zconf.h>

int test(const std::function<void()>& callback, const std::string& name, int number){
    pid_t pid = fork();

    if (pid == 0) {
        try {
            std::cout << "vvvv---------------TEST " << number << "-----------------------vvvv" << std::endl;
            callback();
            std::cout << std::endl << "***Concluso test [" << name << "]" << std::endl;
            std::cout << "^^^^---------------TEST " << number << "-----------------------^^^^" << std::endl;
        } catch (...) {
            std::cout << "***Errore al test [" << name << "]" << std::endl;
        }
    }else {
        return 1;
    }
    return 0;
}

class Test{
private:
    std::vector<std::function<void()>> _functions;
    std::vector<std::string> _names;

public:
    void launch_test(int x){
        if(x == -1){
            for(unsigned long i=0; i<_functions.size();++i){
                int a = test(_functions[x], _names[x], i );
            }
        }else{
            int a = test(_functions[x], _names[x], x );
        }

    }
    void add(const std::function<void()>& a, const std::string& name){
        _functions.push_back(a);
        _names.push_back(name);
    }
};

#endif //TENSORLIB_TESTLIB_H
