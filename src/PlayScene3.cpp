#include "PlayScene3.h"


#include "Background.h"
#include "Brick.h"
#include "EventManager.h"
#include "Game.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "ship.h"
#include "SpaceManager.h"

PlayScene3::PlayScene3() {
    PlayScene3::start();
}

PlayScene3::~PlayScene3() = default;

void PlayScene3::draw() {

    drawDisplayList();

    if (EventManager::Instance().isIMGUIActive()) {
        GUI_Function();
    }

    SDL_SetRenderDrawColor(Renderer::Instance()->getRenderer(), 255, 255, 255, 255);
}

void PlayScene3::update() {
    updateDisplayList();

    // if (CollisionManager::circleAABBCheck(m_pBouncingBall, m_pBrick)) {
        // m_pBouncingBall->getRigidBody()->velocity += m_pBrick->getRigidBody()->velocity;
    // }
}

void PlayScene3::clean() {
    removeAllChildren();
}

void PlayScene3::handleEvents() {
    EventManager::Instance().update();

    if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE)) {
        TheGame::Instance()->quit();
    }

    if (EventManager::Instance().isKeyDown(SDL_SCANCODE_0)) {
        TheGame::Instance()->changeSceneState(START_SCENE);
    }

   

    if (EventManager::Instance().isKeyDown(SDL_SCANCODE_3)) {
        TheGame::Instance()->changeSceneState(PLAY3_SCENE);
    }
    
    if (EventManager::Instance().isKeyDown(SDL_SCANCODE_4)) {
        TheGame::Instance()->changeSceneState(END_SCENE);
    }
    
    // if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A)) {
    //     m_pBrick->moveLeft();
    // }
    //
    // if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D)) {
    //     m_pBrick->moveRight();
    // }

    // m_pBrick->getTransform()->position = SpaceManager::Instance().ScreenToWorld(EventManager::Instance().getMousePosition());
}

void PlayScene3::start() {
    // Set GUI Title
    m_guiTitle = "Play Scene 3";

    // SoundManager::Instance().load("../Assets/audio/yay.ogg", "thunder", SOUND_SFX);

    m_pBackground = new Background();
    const auto Height = Config::SCREEN_HEIGHT;
    const auto Width = Config::SCREEN_WIDTH;
    
    m_pBackground->setWidth(Width);
    m_pBackground->setHeight(Height);
    addChild(m_pBackground);

    // m_pProjectile = new Projectile();
    // addChild(m_pProjectile);
    //
    // m_pBouncingBall = new BouncingBall();
    // m_pBouncingBall->m_reset();
    // addChild(m_pBouncingBall);
    
    m_pRamp = new Ramp();
    m_pRamp->getTransform()->position = glm::vec2(305.f + 150.0f, 50.f);
    addChild(m_pRamp);
    
    m_pCrate = new Crate();
    m_pCrate->getTransform()->position = glm::vec2(Config::SCREEN_WIDTH / 4.f + 60.f, 327.f);
    addChild(m_pCrate);
}

void PlayScene3::GUI_Function() {
    // Always open with a NewFrame
    ImGui::NewFrame();

    // See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
    // ImGui::ShowDemoWindow();

    ImGui::Begin("Sim Options", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar);

    // Initial velocity
    static float vVelocity[1] = { 100.f };
    if(ImGui::SliderFloat("Ramp Width", vVelocity, 0.50f, 100.0f))
    {
        float m_InitialLinearVelocity = vVelocity[0];
        std::cout << vVelocity[0] << std::endl;
        std::cout << "---------------------------\n";
    }

    // Distance
    static float vDistance[1] = { 100.f };
    if(ImGui::SliderFloat("Ramp Height", vDistance, 50.0f, 500.0f))
    {
        float m_Distance = vDistance[0];
        std::cout << vDistance[0] << std::endl;
        std::cout << "---------------------------\n";
    }

    // vAngle
    static float vMass[1] = { 2.2f };
    if(ImGui::SliderFloat("Crate Mass", vMass, 0.5f, 5.0f))
    {
        float m_Mass = vMass[0];
        std::cout << vMass[0] << std::endl;
        std::cout << "---------------------------\n";
    }

    // vAngle
    static float vFriction[1] = { 2.2f };
    if(ImGui::SliderFloat("Friction", vFriction, 0.5f, 5.0f))
    {
        float m_Friction = vFriction[0];
        std::cout << vFriction[0] << std::endl;
        std::cout << "---------------------------\n";
    }
	
    ImGui::Separator();

    ImGui::End();

    // Don't Remove this
    ImGui::Render();
    ImGuiSDL::Render(ImGui::GetDrawData());
    ImGui::StyleColorsDark();
}
