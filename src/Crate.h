#pragma once
#include "DisplayObject.h"

class Crate : public DisplayObject {
public:
    Crate();
    ~Crate();

    // Inherited via GameObject
    void draw() override;
    void update() override;
    void clean() override;
    void m_reset();
    void m_stop();
    void m_move();

    // Ramp angle
    float m_angle = 36.87f;
};
