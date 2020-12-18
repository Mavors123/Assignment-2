#pragma once
#include "DisplayObject.h"
#include "GameObject.h"

class Ramp : public DisplayObject {
public:
    Ramp();
    ~Ramp();

    // Inherited via GameObject
    void draw() override;
    void update() override;
    void clean() override;

    // Ramp angle
    float m_angle = 36.87f;
};
