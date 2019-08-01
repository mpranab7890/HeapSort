#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "heap.h"
#include <math.h>

#define PI 3.14159265358979323846264338328

bool Heap::isInitialized = false;
bool Heap::isSorted = false;

Heap::Heap(int &no , int d[] , sf::RectangleShape r[], sf::Text t[] , sf::Sprite &sp , sf::RenderWindow& w):n(no) , sprite(sp) , window(w) {
	node = new sf::CircleShape[n];
	dataFieldD = &r[0];
	dataTextD = &t[0];
	dataset = &d[0];
	
}

void Heap::create_heap(sf::RenderWindow &window) {
	nodePosCopy = nodePos;
	radius = 30;
	int track = 0;
	int count = 1;
	int loop = 0;
	while (loop < n) {
		node[loop].setRadius(radius);
		//node[loop].setOrigin(radius / 2, radius / 2);
		if (loop == 0) {
			node[loop].setPosition(nodePosCopy);
		}
		else if ((loop+1) % 2 == 0) {
			node[loop].setPosition(sf::Vector2f(node[int((loop + 1) / 2) - 1].getPosition().x , nodePosCopy.y) - sf::Vector2f(250/(count-1), 0));
		}
		else {
			node[loop].setPosition(sf::Vector2f(node[int((loop + 1) / 2)-1].getPosition().x, nodePosCopy.y) + sf::Vector2f(250/(count-1), 0));
		}
		window.draw(node[loop]);
		loop++;
		track++;
		if (track==count) {
			nodePosCopy.y += 100;
			count = count * 2;
			track = 0;
			radius *= 0.90;
		}
	}

	for (int i = 0; i < n / 2; i++) {

		v1 = sf::Vector2f(node[i].getPosition().x + node[i].getRadius(), node[i].getPosition().y + 2 * node[i].getRadius());

		for (int j = 1; j < 3; j++) {
			 sf::RectangleShape line;

			 v2 = ((2 * i + j) < n) ? sf::Vector2f(node[2 * i + j].getPosition().x + node[2 * i + j].getRadius(), node[2 * i + j].getPosition().y) : v1;
			 x = fabs((v1 - v2).x);
			 y = fabs((v1 - v2).y);
			 length = int(sqrt(pow(x, 2) + pow(y, 2)));
			 line.setPosition(v1);
			 line.setSize(sf::Vector2f(length, 3.5));
			 line.setFillColor(sf::Color::Black);

			if (j == 1) 
				angle = 90 + (atan(x / y)*(180/PI));

			else {
				angle = 90 - (atan(x / y)*(180 / PI));
				line.setPosition(v1 - sf::Vector2f(2.5,2.7));

			}
			
			line.rotate(angle);
			window.draw(line);



			/*sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(node[i].getPosition().x + node[i].getRadius() , node[i].getPosition().y + 2 * node[i].getRadius()) , sf::Color::Black),
				((2 * i + j) < n) ? sf::Vertex(sf::Vector2f(node[2 * i + j].getPosition().x + node[2 * i + j].getRadius() , node[2 * i + j].getPosition().y) , sf::Color::Black) : sf::Vertex(sf::Vector2f(node[i].getPosition().x + node[i].getRadius() , node[i].getPosition().y + 2 * node[i].getRadius()) , sf::Color::Black)
			};

			window.draw(line, 2, sf::Lines);*/
		}
	}
}

void Heap::draw(sf::RenderWindow &window) {
	dataFieldPCopy = dataFieldP;
	for (int i = 0; i < n; i++) {
		dataFieldD[i].setPosition(dataFieldPCopy);
		window.draw(dataFieldD[i]);
		dataFieldPCopy.x += dataFieldD[i].getSize().x;
		if ((i + 1) % 10 == 0 && i != 0) {
			dataFieldPCopy.y += dataFieldD[i].getSize().y + 4;
			dataFieldPCopy.x -= dataFieldD[i].getSize().x * 10;
		}
	}

	create_heap(window);

	for (int i = 0; i < n; i++) {
		if (!isInitialized) {
			dataTextD[i].setCharacterSize(40);
			dataTextD[i].setPosition(dataFieldD[i].getPosition() + sf::Vector2f(0, dataFieldD[i].getSize().y / 4));
		}
		
		window.draw(dataTextD[i]);
	}
	isInitialized = true;
	
}

void Heap::move() {
	for (int i = 0; i < n; i++) {
		dataTextD[i].setPosition(node[i].getPosition().x + node[i].getGlobalBounds().width/4 , node[i].getPosition().y + node[i].getGlobalBounds().height/4);
		//dataTextD[i].move(dataTextD[i].getPosition().x - node[i].getPosition().x + node[i].getGlobalBounds().width / 4, node[i].getPosition().y - node[i].getPosition().y + node[i].getGlobalBounds().height / 4);
		dataTextD[i].setCharacterSize(node[i].getRadius());
	}
	std::cout << dataTextD[0].getPosition().x << "....." << dataTextD[0].getPosition().y;
}

void Heap::HeapEvents(sf::RenderWindow &, sf::Event&) {

}


void Heap::maxHeapify(int arr[], int n, int i) {
	left = 2 * i + 1;
	right = 2 * i + 2;
	largest = i;
	if (left<n && arr[left]>arr[largest]) {
		largest = left;
	}
	if (right<n && arr[right]>arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		std::swap(arr[largest], arr[i]);
		std::swap(dataTextD[largest], dataTextD[i]);

		node[i].setFillColor(sf::Color(102, 255, 255));
		node[largest].setFillColor(sf::Color(102, 255, 255));

		display();

		Sleep(1500);
		/*sf::Vector2f v1 = dataTextD[largest].getPosition();
		sf::Vector2f v2 = dataTextD[i].getPosition();
		sf::Vector2f v = v2 - v1;
		sf::Vector2f w = v1 - v2;
		float angle = atan(fabs((v1.y - v2.y) / (v1.x - v2.x)));
		float fy = sin(angle);
		float fx = sin(angle);
		sf::Vector2f temp = v1;
		while ((temp - v2)!= sf::Vector2f(1,1)) {

		}*/
		sf::Vector2f temp = dataTextD[largest].getPosition();
		dataTextD[largest].setPosition(dataTextD[i].getPosition());
		dataTextD[i].setPosition(temp);

		float t = dataTextD[largest].getCharacterSize();
		dataTextD[largest].setCharacterSize(dataTextD[i].getCharacterSize());
		dataTextD[i].setCharacterSize(t);


		display();
		Sleep(1500);
		node[i].setFillColor(sf::Color::White);
		node[largest].setFillColor(sf::Color::White);
		maxHeapify(arr, n, largest);
	}

}

void Heap::buildMaxHeap(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		maxHeapify(arr, n, i);
	}
}

void Heap::HeapSort(int arr[], int n) {
	buildMaxHeap(arr, n);
	for (int i = n - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		std::swap(dataTextD[0], dataTextD[i]);

		node[0].setFillColor(sf::Color(102, 255, 255));
		node[i].setFillColor(sf::Color(102, 255, 255));

		display();

		Sleep(1500);

		//sf::Vector2f v1 = dataTextD[0].getPosition();
		//sf::Vector2f v2 = dataTextD[i].getPosition();
		sf::Vector2f temp = dataTextD[0].getPosition();
		dataTextD[0].setPosition(dataTextD[i].getPosition());
		dataTextD[i].setPosition(temp);

		float t = dataTextD[0].getCharacterSize();
		dataTextD[0].setCharacterSize(dataTextD[i].getCharacterSize());
		dataTextD[i].setCharacterSize(t);
		//dataTextD[0].move(v2 - v1);
		//dataTextD[i].move(v1 - v2);
		display();
		Sleep(1500);

		node[0].setFillColor(sf::Color::White);
		node[i].setFillColor(sf::Color(255, 204, 153));

		maxHeapify(arr, i, 0);
	}
	isSorted = true;
}

void Heap::display() {
	window.clear();
	window.draw(sprite);
	this->draw(window);
	window.display();
}