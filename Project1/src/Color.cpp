#include "Color.h"

Gio::Color::Color(float r, float g, float b, float a)
    : r(r)
      , g(g)
      , b(b)
      , a(a)
{}

Gio::Color::Color()
    : r(0.0f)
      , g(0.0f)
      , b(0.0f)
      , a(0.0f)
{}

Gio::Color::~Color()
{}