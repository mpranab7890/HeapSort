#include <SFML/Graphics.hpp>
#include <iostream>
#include "inputPage.hpp"

InputFields::InputFields():n(null){}

InputFields::InputFields( int d[] , int &no):n(no) {

	//dataField = &r[0];
	//dataText = t;
	dataset = &d[0];
	//dataText = &t[0];
	//n = no;
	n = NULL;


	font.loadFromFile("../Resources/arial.ttf");
	button_texture.loadFromFile("../Resources/sort_button.png");
	button_sprite.setTexture(button_texture);


	numberBox.setSize(numberBoxS);
	numberBox.setPosition(numberBoxP);
	numberBox.setOutlineColor(sf::Color::Black);
	numberBox.setOutlineThickness(5);

	EnterMessage = sf::Text("Number of data?", font, 30);
	EnterMessage.setFillColor(sf::Color::Black);
	EnterMessage.setPosition(70, 100);

	DataMessage = sf::Text("Enter the data for sorting", font, 30);
	DataMessage.setPosition(70, 280);
	DataMessage.setFillColor(sf::Color::Black);

	//dataText = new sf::Text;
	//dataset = new int;

	numberofData = sf::Text("", font, 40);
	numberofData.setFillColor(sf::Color::Black);
	numberofData.setPosition(sf::Vector2f(numberBoxP.x + numberBoxS.y / 4, numberBoxP.y));

}

//sf::Vector2f InputFields::numberBoxP(465, 95);
//sf::Vector2f InputFields::numberBoxP.x = 465;


void InputFields::InputEvents(sf::RenderWindow &window , sf::Event &event) {
	if (event.type == sf::Event::TextEntered && isActive == true) {
		input += event.text.unicode;
		numberofData.setString(input);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			numberBox.setFillColor(sf::Color::White);
			n = std::stoi(input);
			dataField = new sf::RectangleShape[n];
			//dataset = new int[n];
			dataText = new sf::Text[n];
			//dataField[n];
			//dataText[n];

			for (int i = 0; i < n; i++) {
				dataText[i].setString("");
				dataText[i].setFont(font);
				dataText[i].setCharacterSize(40);
				dataText[i].setFillColor(sf::Color::Black);

			}
			std::cout << "N :" << n;
			isActive = false;
		}
	}

	if (event.type == sf::Event::TextEntered && dataEntry == true) {
		
		data += event.text.unicode;
		//std::cout << dataField[count].getPosition().x<<"....."<< dataField[i].getPosition().y<<std::endl;
		dataText[count].setString(data);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			dataField[count].setFillColor(sf::Color::White);
			*(dataset+count) = std::stoi(data);
			data = "";
			count++;
			if (count >= n) {
				dataEntry = false;
				displayButton = true;
				for (int i = 0; i < n; i++) {
					std::cout << dataset[i] << std::endl;
				}
			}
			else {
				dataField[count].setFillColor(sf::Color::Color(204, 255, 255));
			}
		}


	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if ((event.mouseButton.x >= numberBoxP.x) && (event.mouseButton.x <= numberBoxP.x + numberBoxS.x)) {
				if ((event.mouseButton.y >= numberBoxP.y) && (event.mouseButton.y <= numberBoxP.y + numberBoxS.y)) {
					numberBox.setFillColor(sf::Color::Color(204, 255, 255));
					/*if (window.waitEvent(event)) {
						if (event.type == sf::Event::TextEntered ) {
							input += event.text.unicode;
							numberofData.setString(input);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
							numberBox.setFillColor(sf::Color::White);
							n = std::stoi(input);
							dataField = new sf::RectangleShape[n];
							std::cout << "N :" << n;
						}
					}*/
					isActive = true;

				}
			}
			if ((event.mouseButton.x >= dataFieldP.x) && (event.mouseButton.x <= dataFieldP.x + dataFieldS.x)) {
				if ((event.mouseButton.y >= dataFieldP.y) && (event.mouseButton.y <= dataFieldP.y + dataFieldS.y)) {
					dataEntry = true;
					dataField[0].setFillColor(sf::Color::Color(204, 255, 255));

					//std::cout << "Trueeuuee";
				}
			}

			if (displayButton) {
				if ((event.mouseButton.x >= button_sprite.getPosition().x) && (event.mouseButton.x <= button_sprite.getPosition().x + button_sprite.getGlobalBounds().width)) {
					if ((event.mouseButton.y >= button_sprite.getPosition().y) && (event.mouseButton.y <= button_sprite.getPosition().y + button_sprite.getGlobalBounds().height)) {
						std::cout << "Pressed";
						running = false;
					}
				}
			}

			std::cout << "the left button was pressed" << std::endl;
			std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			std::cout << "mouse y: " << event.mouseButton.y << std::endl;
		}
	}




	sf::Vector2i position = sf::Mouse::getPosition(window);
	std::cout << "x= " << position.x << "\t y=" << position.y << std::endl;

}

void InputFields::create_data_fields(sf::RenderWindow &window , sf::Vector2f dataFieldP) {

	dataFieldPcopy = dataFieldP ;

	for (int i = 0; i < n; i++) {
		dataField[i].setSize(dataFieldS);
		dataField[i].setOutlineThickness(4);
		dataField[i].setOutlineColor(sf::Color::Black);
		dataField[i].setPosition(dataFieldPcopy);
		window.draw(dataField[i]);
		dataFieldPcopy.x += dataFieldS.x;
		if ((i + 1) % 10 == 0 && i != 0) {
			dataFieldPcopy.y += dataFieldS.y + 4;
			dataFieldPcopy.x -= dataFieldS.x * 10;
		}

		button_sprite.setPosition(380, dataFieldPcopy.y + dataFieldS.y + 40);
		//button_sprite.setScale(1 , );
	}

	for (int i = 0; i < n; i++) {
		dataText[i].setPosition(dataField[i].getPosition() + sf::Vector2f(0, dataFieldS.y / 4));
		window.draw(dataText[i]);

	}
	//std::cout << dataFieldP.x<<">>>>" <<dataFieldP.y<<std::endl;
}

void InputFields::draw(sf::RenderWindow &window) {
	window.draw(numberBox);
	window.draw(EnterMessage);
	if (n != NULL) {
		window.draw(DataMessage);
		create_data_fields(window);
		//std::cout << dataFieldP.x << ">>>>" << dataFieldP.y << std::endl;
		
	}
	if (displayButton)
		window.draw(button_sprite);
	window.draw(numberofData);

}

sf::RectangleShape* InputFields::dataFieldPointer() {
	return dataField;
}

sf::Text* InputFields::TextPointer() {
	return dataText;
}

bool InputFields::isRunning() {
	return running;
}

void InputFields::displaydata() {
	for (int i = 0; i < n; i++) {
		std::cout << dataset[i]<<std::endl;
	}
}