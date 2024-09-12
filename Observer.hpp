#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include <iostream>
#include "User.hpp"
#include "Post.hpp"

using namespace std;

class User;

class Observer{
public:
    static void notifyFollowers(User* currentUser);
    static void notifyCreator(User* userWhoInitialized , Post* targetPost , string actionDone);
};

#endif