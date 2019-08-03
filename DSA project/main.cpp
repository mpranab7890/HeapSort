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

	sf::Texture button_texture;
	button_texture.loadFromFile("../Resources/next.png");

	sf::Sprite button_sprite;
	button_sprite.setTexture(button_texture);

	button_sprite.setPosition(500, 540);

	float *datasetMain = new float;
	int n;

	InputFields *inputPage = NULL;
	Heap *h1 = NULL;
	Heap::isInitialized = false;

	while (window.isOpen())
	{
		if(inputPage == NULL)
			inputPage = new InputFields(datasetMain, n);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if(InputFields::isRunning)
				inputPage->InputEvents(window, event);
			
			if (Heap::isSorted) {
				if ((Heap::HeapEvents(window, event, button_sprite)) == true) {
					//delete[] inputPage;
					//delete[] h1;
					inputPage = NULL;
					Heap::isSorted = false;
				}
			}
		}
		//std::cout << n;
		if (inputPage == NULL)
			inputPage = new InputFields(datasetMain, n);

		window.clear();
		window.draw(sprite);
		if (InputFields::isRunning) {
			
			inputPage->draw(window);

		}
		else {
			
			h1 = new Heap (n, datasetMain, inputPage->dataFieldPointer(), inputPage->TextPointer(), sprite, window);

			h1->draw(window , button_sprite);
			h1->move();
			window.display();
			Sleep(1500);

			if (Heap::isSorted==false)
				h1->HeapSort(datasetMain, n);

			else {
				Heap::isInitialized = false;
			}

		}



		window.display();
	}
	//delete datasetMain;


	//return 0;
}