#pragma once
#include "Background.h"
#include "BouncingBall.h"
#include "Brick.h"
#include "Crate.h"
#include "Ramp.h"
#include "Scene.h"

class PlayScene3 : public Scene {
public:
    PlayScene3();
    ~PlayScene3();

    // Scene LifeCycle Functions
    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;
    virtual void handleEvents() override;
    virtual void start() override;
    void GUI_Function();

    std::string m_guiTitle;
    Background* m_pBackground;

    Ramp* m_pRamp;
    Crate* m_pCrate;
    // Crate* m_pCrate;
};
