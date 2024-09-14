#ifndef USERDECORATOR_HPP
#define USERDECORATOR_HPP

#include "User.hpp"
using namespace std;

class UserDecorator : public User{
public :
    void sendMessage();
};

#endif