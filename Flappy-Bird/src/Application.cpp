#include "Scene/FlappyBirdScene.h"

class Application : public Elysium::Application
{
private:
    bool m_VSync = false;

public:
    Application(bool imgui=false) : Elysium::Application("Flappy Bird", 1280, 720, imgui)
    {
        m_Window->setVSync(m_VSync);
        m_SceneManager.loadScene(new FlappyBirdScene(m_Window->getWidth(), m_Window->getHeight(), &m_VSync));
    }

    ~Application()
    {
    }

    void ApplicationLogic() override
    {
        m_Window->setVSync(m_VSync);
    }
};

int main(void)
{
    Application* application = new Application(true);
    application->Run();
    delete application;
    return 0;
}