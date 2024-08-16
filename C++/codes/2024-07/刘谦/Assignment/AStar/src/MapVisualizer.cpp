/**
 * @file MapVisualizer.cpp
 * @author liuqian
 * @brief
 * @version 0.1
 * @date 2024-7-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "MapVisualizer.h"
#include <SFML/Graphics.hpp>
#include <algorithm>

/**
 * @brief display the grid map with obstacles and path
 * @param map 
 * @param path 
 * @param start 
 * @param goal 
 */
void MapVisualizer::displayMap(const GridMap& map, const
             std::vector<Node>& path, const Node& start, const Node& goal) {
    int width = map.getWidth();
    int height = map.getHeight();

    int tileSize = std::min(TOTALWIDTH / width, TOTALHEIGHT / height);

    sf::RenderWindow window(sf::VideoMode(TOTALWIDTH, TOTALHEIGHT),
                            "A* Pathfinding");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        displayObstacles(window, map, tileSize);
        displayPath(window, path, tileSize);
        displayStartGoal(window, start, goal, tileSize);
        displayWeights(window, map, tileSize);

        window.display();
    }
}

/**
 * @brief display the weights in the map
 * @param window 
 * @param map 
 * @param tileSize  size of each grid point
 */
void MapVisualizer::displayWeights(sf::RenderWindow& window,
                               const GridMap& map, int tileSize) {
    sf::Font font;
    if (!font.loadFromFile("resources/Roboto-Regular.ttf")) {
        return;
    }

    int width = map.getWidth();
    int height = map.getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int weight = map.getWeight(x, y);
            sf::Text text;
            text.setFont(font);
            text.setString(std::to_string(weight));
            text.setCharacterSize(tileSize / 2);
            text.setFillColor(sf::Color::Black);
            text.setOrigin(text.getLocalBounds().width / 2.0f,
                           text.getLocalBounds().height / 2.0f);
            text.setPosition(x * tileSize  + tileSize / 2.0f,
                             y * tileSize +  + tileSize / 2.5f);

            window.draw(text);
        }
    }
}

/**
 * @brief display the obstacles in the map
 * @param window 
 * @param map 
 * @param tileSize 
 */
void MapVisualizer::displayObstacles(sf::RenderWindow& window,
                              const GridMap& map, int tileSize) {
    int width = map.getWidth();
    int height = map.getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            sf::RectangleShape rectangle(sf::Vector2f(tileSize - 1,
                                         tileSize - 1));
            rectangle.setPosition(x * tileSize, y * tileSize);
            rectangle.setOutlineThickness(1);
            rectangle.setOutlineColor(sf::Color::Black);

            if (map.isObstacle(x, y)) {
                rectangle.setFillColor(sf::Color::Black);
            } else {
                rectangle.setFillColor(sf::Color::White);
            }

            window.draw(rectangle);
        }
    }
}

/**
 * @brief display the starting and goal node  
 * @param window 
 * @param start 
 * @param goal 
 * @param tileSize 
 */
void MapVisualizer::displayStartGoal(sf::RenderWindow& window,
                            const Node& start, const Node& goal, int tileSize) {

    sf::CircleShape startCircle(tileSize / 2);
    startCircle.setFillColor(sf::Color::Red);
    startCircle.setPosition(start.x * tileSize, start.y * tileSize);
    window.draw(startCircle);

    sf::CircleShape goalCircle(tileSize / 2);
    goalCircle.setFillColor(sf::Color::Green);
    goalCircle.setPosition(goal.x * tileSize, goal.y * tileSize);
    window.draw(goalCircle);
}

/**
 * @brief display the optimal path
 * @param window 
 * @param path 
 * @param tileSize 
 */
void MapVisualizer::displayPath(sf::RenderWindow& window,
                            const std::vector<Node>& path, int tileSize) {
    for (const auto& node : path) {
        sf::RectangleShape rectangle(sf::Vector2f(tileSize - 1, tileSize - 1));
        rectangle.setPosition(node.x * tileSize, node.y * tileSize);
        rectangle.setOutlineThickness(1);
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setFillColor(sf::Color::Blue);

        window.draw(rectangle);
    }
}
