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
			
			/*if (Heap::isInitialized == true) {
				if (event.type == sf::Event::MouseButtonPressed) {
					if (event.mouseButton.button = sf::Mouse::Left) {
						if (isPaused == false) {
							if (event.mouseButton.x >= pauseSprite.getPosition().x && event.mouseButton.x <= pauseSprite.getPosition().x + pauseSprite.getGlobalBounds().width) {
								if (event.mouseButton.y >= pauseSprite.getPosition().y && event.mouseButton.y <= pauseSprite.getPosition().y + pauseSprite.getGlobalBounds().height) {
									isPaused = true;

								}
							}
						}
						else {
							if (event.mouseButton.x >= resumeSprite.getPosition().x && event.mouseButton.x <= resumeSprite.getPosition().x + resumeSprite.getGlobalBounds().width) {
								if (event.mouseButton.y >= resumeSprite.getPosition().y && event.mouseButton.y <= resumeSprite.getPosition().y + resumeSprite.getGlobalBounds().height) {
									isPaused = false;

								}
							}
						}
					}
				}
			}*/

		}
		//std::cout << n;

		window.clear();
		window.draw(sprite);
		if (inputPage.isRunning()) {
			inputPage.draw(window);
		}
		else {
			Heap h1(n, datasetMain, inputPage.dataFieldPointer(), inputPage.TextPointer(), sprite, window);
			h1.draw(window);
			h1.move();

			if (!Heap::isSorted)
				h1.HeapSort(datasetMain, n);
			else
				Heap::isInitialized = false;

		}



		window.display();
	}

	return 0;
}