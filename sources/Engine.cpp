//
// Copyright © 2020 Vladimir Mashir
//

#include <Engine.h>

sf::Vector2i Engine::GetScreenSize() {
    return screenSize;
}

Engine::Engine()
{
    screenSize.x = 464;
    screenSize.y = 256;
    Window.create(sf::VideoMode(screenSize.x, screenSize.y), "mavl");
    Window.setFramerateLimit(60);

    view.reset(sf::FloatRect(0.0f, 0.0f, screenSize.x, screenSize.y));
    view.setViewport(sf::FloatRect(0.0f, 0.0f, 2.5f, 2.5f));
//    view.setCenter(sf::Vector2f(300.0f, 300.0f));
//    view.setSize(sf::Vector2f(1920.0f, 1088.0f));
}

void Engine::start()
{
    std::string filename1 = "/Users/sorohimm/CLionProjects/GayEngine/levels/start_level/map1.json";
    std::string filename = "../GayEngine/levels/start_level/map.json";
    level.LoadFromFile(filename1);
    level.initObjects(level);

    while (Window.isOpen()) {
        sf::Event Event;
        while (Window.pollEvent(Event)) {
            input(Event);
        }
        level.update(view, screenSize);
        draw();
    }
}

