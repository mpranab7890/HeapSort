#pragma once
#include <SFML/Graphics.hpp>
#include "heap.h"

class InputFields {
private:
	int null = NULL;

	int count = 0;
	std::string input, data;
	int &n;

	bool isActive = false;
	bool dataEntry = false;
	bool displayButton = false;
	bool running = true;
	//sf::String input;
	sf::Font font;
	
	float *dataset;
	sf::RectangleShape numberBox;
	sf::Text numberofData;
	sf::Text EnterMessage;
	sf::Text DataMessage;

	sf::Vector2f dataFieldP= sf::Vector2f(5, 350);

	sf::Vector2f numberBoxP = sf::Vector2f(465, 95);
	sf::Vector2f numberBoxS = sf::Vector2f (100, 50);
	sf::Vector2f dataFieldPcopy;
	sf::Vector2f dataFieldS = sf::Vector2f (100, 100);
	sf::Vector2f buttonP = sf::Vector2f(NULL, NULL);

	sf::Texture button_texture;
	sf::Sprite button_sprite;
	
	sf::RectangleShape *dataField;
	sf::Text *dataText;

public:
	static bool isRunning;
	InputFields();
	InputFields( float[] , int &);
	~InputFields();
	void InputEvents(sf::RenderWindow & , sf::Event &);
	void create_data_fields(sf::RenderWindow & , sf::Vector2f dataFieldP = sf::Vector2f(5, 350));
	void draw(sf::RenderWindow &);
	//bool isRunning();
	sf::RectangleShape* dataFieldPointer();
	sf::Text* TextPointer();

};



	


