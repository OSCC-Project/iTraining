/**
 * @file MapVisualizer.h
 * @author liuqian
 * @brief display the map
 * @version 0.1
 * @date 2024-7-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef MAP_VISUALIZER_H_
#define MAP_VISUALIZER_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "GridMap.h"
#include "Node.h"

class MapVisualizer {
public:
    void displayMap(const GridMap& map, const std::vector<Node>& path,
                const Node& start, const Node& goal);

private:
    void displayWeights(sf::RenderWindow& window, const GridMap& map,
                        int tileSize);
    void displayObstacles(sf::RenderWindow& window, const GridMap& map,
                        int tileSize);
    void displayStartGoal(sf::RenderWindow& window, const Node& start,
                        const Node& goal, int tileSize);
    void displayPath(sf::RenderWindow& window, const std::vector<Node>& path,
                        int tileSize);

    constexpr static int TOTALWIDTH = 600;   
    constexpr static int TOTALHEIGHT = 600;  
};

#endif  // MAP_VISUALIZER_H_
