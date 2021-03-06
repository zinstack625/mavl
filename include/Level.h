//
//  Copyright © 2020 Vladimir Mashir.
//

#ifndef GAYENGINE_LEVEL_H
#define GAYENGINE_LEVEL_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

struct Object
{
    int GetPropertyInt(std::string &input);
    float GetPropertyFloat(std::string &input);
    std::string GetPropertyString(const std::string &input);

    std::string name;
    std::string type;
    sf::Rect<int> rect;
    std::map<std::string, std::string> properties;

    sf::Sprite sprite;
};

struct Layer
{
    int opacity;
    std::vector<sf::Sprite> tiles;
};

class Level
{
public:
    bool LoadFromFile(std::string &filename);
    Object GetObject(const std::string &name);
    std::vector<Object> GetObjects(const std::string &name);
    sf::Vector2i GetTileSize() const;

    void Draw(sf::RenderWindow &window);
    void update(sf::View&, sf::Vector2i&);
    void initObjects(Level&);
    b2Body* GetPlayerBody();

private:
    int width;
    int height;
    int tileWidth;
    int tileHeight;
//    int firstTileID;
    std::vector<std::pair<std::string, int>> firstTileIDs;

    sf::Rect<float> drawingBounds;
    sf::Texture tileSetImage;
    std::vector<Object> objects;
    std::vector<Layer> layers;

    Object player;
    b2Body* playerBody;

    std::vector<Object> coin;
    std::vector<b2Body*> coinBody;

    std::vector<Object> enemy;
    std::vector<b2Body*> enemyBody;

    b2Vec2 gravity;
};

#endif //GAYENGINE_LEVEL_H
