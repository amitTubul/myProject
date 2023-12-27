#include "Graph.hpp"
#include <random>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#define screenWidth 800
#define screenLength 600
#define CIRCLE_SIZE 20.0f

namespace amit {
    Graph::Graph(unsigned long rank) : _rank(rank), _matrix(rank, std::vector<int>(rank, 0)) {
        std::random_device rd;
        std::mt19937 mt(rd());
        for (unsigned long i = 0; i < rank; ++i) {
            for (unsigned long j = 0; j < rank && i!=j; ++j){
                std::uniform_int_distribution<int> dist(0, 1);
                double randomNumber = dist(mt);
                if (randomNumber==0) {
                    if (_matrix[i][j] == 1) continue;
                }
                _matrix[i][j] = randomNumber;
                _matrix[j][i] = randomNumber;
            }
        }
    }

    void Graph::printMatrix() {
        std::cout << "Matrix:\n";
        for (const auto &row: _matrix) {
            for (int value: row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

    void Graph::printGraph() {
        sf::RenderWindow window(sf::VideoMode(screenWidth, screenLength), "Graph visualisation");
        float radius = 250.0f;
        std::vector<sf::CircleShape> nodes;
        for (int i=0; i<_rank;i++) {
            sf::CircleShape circle(CIRCLE_SIZE); // Set radius for each circle
            float angle = static_cast<float>(i) * (2.0f * 3.14159f) / static_cast<float>(_rank);
            float x = 400 + radius * std::cos(angle);
            float y = 300 + radius * std::sin(angle);
            circle.setPosition(x , y); // Offset by half the circle's radius for correct positioning
            circle.setFillColor(sf::Color::Green);
            nodes.push_back(circle);
        }
        std::vector<sf::VertexArray> edges;
        for (unsigned long i=0;i<_rank;i++) {
            for (unsigned long j=0;j<_rank;j++) {
                if (_matrix[i][j]==1){
                    sf::VertexArray line(sf::Lines, 2);
                    line[0].position = sf::Vector2f(nodes[i].getPosition().x+CIRCLE_SIZE,nodes[i].getPosition().y+CIRCLE_SIZE);
                    line[1].position = sf::Vector2f(nodes[j].getPosition().x+CIRCLE_SIZE,nodes[j].getPosition().y+CIRCLE_SIZE);
                    line[0].color = sf::Color::Red;
                    line[1].color = sf::Color::Blue;
                    edges.push_back(line);
                }
            }
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear(sf::Color::Black);
            for (auto node: nodes) {
                window.draw(node);
            }
            for (auto edge: edges) {
                window.draw(edge);
            }
            window.display();
        }
    }
}
