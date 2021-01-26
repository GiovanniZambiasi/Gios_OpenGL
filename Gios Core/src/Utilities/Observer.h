#pragma once
#include <GLFW/glfw3native.h>

namespace Gio::Utilities
{
    template<typename T0>
        class Observer
    {
    protected:
        ~Observer()
        {}

    public:
        virtual void Observe(T0 t) = 0;
    };
}
