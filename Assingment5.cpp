#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

void drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2) {
	sf::Vertex line[] =
	{
              sf::Vertex(sf::Vector2f(x1, y1)),
              sf::Vertex(sf::Vector2f(x2, y2))
	};
	window.draw(line, 2, sf::Lines);
}

void kochCurve(sf::RenderWindow& window, int x1, int y1, int x2, int y2, int iterations) {
	if (iterations == 0) {
              drawLine(window, x1, y1, x2, y2);
	} else {
              int dx = x2 - x1;
              int dy = y2 - y1;

              int x1_1 = x1 + dx / 3;
              int y1_1 = y1 + dy / 3;

              int x1_2 = x1 + 2 * dx / 3;
              int y1_2 = y1 + 2 * dy / 3;

              int peakX = (x1 + x2) / 2 - (dy * 1.732) / 6;
              int peakY = (y1 + y2) / 2 + (dx * 1.732) / 6;

              kochCurve(window, x1, y1, x1_1, y1_1, iterations - 1);
              kochCurve(window, x1_1, y1_1, peakX, peakY, iterations - 1);
              kochCurve(window, peakX, peakY, x1_2, y1_2, iterations - 1);
              kochCurve(window, x1_2, y1_2, x2, y2, iterations - 1);
	}
}

void generateSnowflake(sf::RenderWindow& window, int x1, int y1, int x2, int y2, int x3, int y3, int iterations) {
	kochCurve(window, x1, y1, x2, y2, iterations);
	kochCurve(window, x2, y2, x3, y3, iterations);
	kochCurve(window, x3, y3, x1, y1, iterations);
}

int main() {
	int iterations = 4;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Koch Snowflake");

	int x1 = 300, y1 = 400;
	int x2 = 500, y2 = 400;
	int x3 = 400, y3 = 200;

	while (window.isOpen()) {
       sf::Event event;
              while (window.pollEvent(event)) {
                     if (event.type == sf::Event::Closed) {
                     window.close();
                     }
              }

              window.clear();
              generateSnowflake(window, x1, y1, x2, y2, x3, y3, iterations);
              window.display();
	}

	return 0;
}
