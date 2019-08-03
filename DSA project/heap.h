#pragma once
#include <SFML/Graphics.hpp>
#include "inputPage.hpp"

class Heap {
private:
	sf::CircleShape *node;
	int n;
	int radius;
	sf::Vector2f nodePos = sf::Vector2f(450, 50);
	sf::Vector2f nodePosCopy;
	sf::Sprite &sprite;
	sf::RenderWindow &window;
	sf::RectangleShape* dataFieldD ;
	sf::Text* dataTextD ;
	float *dataset;
	sf::Vector2f dataFieldP = sf::Vector2f(5, (1080 - ((n + 10) / 10) * 100 - 400));
	sf::Vector2f dataFieldPCopy;
	sf::Vector2f sort_next_P;
	int left;
	int right;
	int largest;
	sf::Vector2f v1;
	sf::Vector2f v2;
	float c,x , y, length, angle;

public:
	Heap();
	Heap(int &n , float[] , sf::RectangleShape[] , sf::Text[] , sf::Sprite& , sf::RenderWindow&);
	~Heap();
	static bool isInitialized;
	static bool isSorted;
	void create_heap(sf::RenderWindow &);
	void draw(sf::RenderWindow & , sf::Sprite &button_sprite);
	void move();
	void maxHeapify(float[] , int , int );
	void buildMaxHeap(float [], int );
	void HeapSort(float[], int);
	void display();
	static bool HeapEvents(sf::RenderWindow &, sf::Event& , sf::Sprite & );

};