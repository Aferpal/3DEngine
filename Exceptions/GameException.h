#pragma once
#include<exception>

class GameException: public std::exception{
    private:
        const char* msg;
    public:
        GameException(const char* msg){
            this->msg = msg;
            msg = nullptr;
        }
        virtual const char* what() const throw() {
            return this->msg;
        }
};