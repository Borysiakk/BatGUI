//
// Created by borysiak on 04.11.2019.
//

#ifndef BGUI_SIGNAL_HPP
#define BGUI_SIGNAL_HPP

#include <map>
#include <memory>
#include <string>
#include <functional>

enum class TypeSignal
{
    Pressed,

};

class Signal
{
public:
    Signal() = default;
    template <typename Func, typename... Args>
    void connect(TypeSignal type, Func func, Args... args)
    {
        functions[type] = std::bind(func, args...);
    }
protected:
    std::map<TypeSignal , std::function<void()>> functions;
};


#endif //BGUI_SIGNAL_HPP
