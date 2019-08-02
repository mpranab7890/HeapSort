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
	int *dataset;
	sf::Vector2f dataFieldP = sf::Vector2f(5, (1080 - ((n + 10) / 10) * 100 - 80));
	sf::Vector2f dataFieldPCopy;
	int left;
	int right;
	int largest;
	sf::Vector2f v1;
	sf::Vector2f v2;
	float c,x , y, length, angle;
	sf::Clock timer;
	
	

public:
	Heap();
	Heap(int &n , int[] , sf::RectangleShape[] , sf::Text[] , sf::Sprite& , sf::RenderWindow&);
	~Heap();
	static bool isInitialized;
	static bool isSorted;
	void create_heap(sf::RenderWindow &);
	void draw(sf::RenderWindow &);
	void move();
	void maxHeapify(int[] , int , int );
	void buildMaxHeap(int [], int );
	void HeapSort(int[], int);
	void display();
	void HeapEvents(sf::RenderWindow &, sf::Event&);

};