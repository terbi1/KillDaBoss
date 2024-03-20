#pragma once

#include <iostream>
#include <cmath>

struct Vector2f
{

    Vector2f()
        : x(0.0f), y(0.0f)
    {
    }

    Vector2f(float p_x, float p_y)
        : x(p_x), y(p_y)
    {
    }

    void print()
    {
        std::cout << x << ", " << y << '\n';
    }

    float x, y;

};

struct Circle 
{
    Vector2f center;
    float radius;
    // Circle(Vector2f m_center, float m_radius) {
    //     center = m_center;
    //     radius = m_radius;
    // }
};

Vector2f vectorNormalize(Vector2f vector);

float pointDirection(Vector2f vectorA, Vector2f vectorB);

float distance(Vector2f point1, Vector2f point2);