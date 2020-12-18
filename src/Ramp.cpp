#include "Ramp.h"


#include "SpaceManager.h"
#include "TextureManager.h"
#include "Util.h"

Ramp::Ramp() {
    TextureManager::Instance()->load("../Assets/textures/animate.png", "block");

    auto size = TextureManager::Instance()->getTextureSize("block");
    setWidth(size.x);
    setHeight(size.y);
    
    getTransform()->position = glm::vec2(100.0f, 100.0f);
    getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
    getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
    getRigidBody()->isColliding = false;
    setType(WOOKIE);
}

Ramp::~Ramp() {
}

void Ramp::draw() {
    const auto rx = cos(m_angle * Util::Deg2Rad);
    const auto ry = sin(m_angle * Util::Deg2Rad);
    getTransform()->rotation = glm::vec2(rx, ry);

    const auto x = getTransform()->position.x;
    const auto y = getTransform()->position.y;

    const auto ScreenPosition = SpaceManager::Instance().WorldToScreen(glm::vec2(x, y));

    // draw the ship
    TextureManager::Instance()->draw("block", ScreenPosition.x, ScreenPosition.y, m_angle, 255, true);
}

void Ramp::update() {
}

void Ramp::clean() {
}
