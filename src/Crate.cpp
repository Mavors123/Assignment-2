#include "Crate.h"


#include "SpaceManager.h"
#include "TextureManager.h"
#include "Util.h"

Crate::Crate() {
    TextureManager::Instance()->load("../Assets/textures/crate.jpg", "crate");

    auto size = TextureManager::Instance()->getTextureSize("crate");
    setWidth(size.x);
    setHeight(size.y);
    
    getTransform()->position = glm::vec2(100.0f, 100.0f);
    getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
    getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
    getRigidBody()->isColliding = false;
    setType(WOOKIE);
}

Crate::~Crate() {
}

void Crate::draw() {
    const auto rx = cos(m_angle * Util::Deg2Rad);
    const auto ry = sin(m_angle * Util::Deg2Rad);
    getTransform()->rotation = glm::vec2(rx, ry);

    const auto x = getTransform()->position.x;
    const auto y = getTransform()->position.y;

    const auto ScreenPosition = SpaceManager::Instance().WorldToScreen(glm::vec2(x, y));

    // draw the ship
    TextureManager::Instance()->draw("crate", ScreenPosition.x, ScreenPosition.y, m_angle, 255, true);
}

void Crate::update() {
    m_move();
}

void Crate::clean() {
}

void Crate::m_reset() {
    getRigidBody()->acceleration = glm::vec2(0, -9.8f);
    getTransform()->position.x = rand() % (Config::SCREEN_WIDTH - 100) + 50;
    getTransform()->position.y = Config::SCREEN_HEIGHT + (rand() % 100 + 1);
    getRigidBody()->velocity = glm::vec2();
}

void Crate::m_stop() {
    getRigidBody()->acceleration = glm::vec2();
    getRigidBody()->velocity = glm::vec2();
}

void Crate::m_move() {
    getRigidBody()->velocity = getRigidBody()->velocity + getRigidBody()->acceleration * (1.f / 60.f);
    
    if (getTransform()->position.y <= 0) {
        m_stop();
    }
    
    getTransform()->position = getTransform()->position + getRigidBody()->velocity;
}
