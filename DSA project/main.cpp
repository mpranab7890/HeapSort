#include <SFML/Graphics.hpp>
#include "inputPage.hpp"
#include "heap.h"
#include <iostream>
#include <windows.h>



int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1080), "SFML works!");
	sf::Texture texture;
	texture.loadFromFile("../Resources/bg.jpg");
	sf::Sprite sprite(texture);



	int *datasetMain = new int;
	int n;

	InputFields inputPage( datasetMain , n);
	Heap *h1;
	Heap::isInitialized = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if(inputPage.isRunning())
				inputPage.InputEvents(window, event);
			
			
		}
		//std::cout << n;

		window.clear();
		window.draw(sprite);
		if (inputPage.isRunning()) {
			inputPage.draw(window);

		}
		else {
			
			h1 = new Heap (n, datasetMain, inputPage.dataFieldPointer(), inputPage.TextPointer(), sprite, window);

			h1->draw(window);
			h1->move();

			if (!Heap::isSorted)
				h1->HeapSort(datasetMain, n);
			else
				Heap::isInitialized = false;

		}



		window.display();
	}
	//delete datasetMain;

	return 0;
}