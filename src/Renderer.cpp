#include "Renderer.hpp"
#include <iostream>

void Renderer::initWindow()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	window.create(sf::VideoMode(1500, 700), "GUI 3.0", sf::Style::Default, settings);
	window.setFramerateLimit(60);
}

Renderer::Renderer()
{
	this->initWindow();

	running = true;
	paused = false;

	font.loadFromFile("data/consola.ttf");

	

	frame.setWindow(window);

	button.setSize({ 80, 40 });
	button.setPosition(20, 5);
	button.setBoxFillColor(sf::Color::Transparent);
	button.setBoxOutlineColor(sf::Color(160, 32, 240));
	button.setBoxOutlineThickness(3);
	button.setSelectionFillColor(sf::Color(160, 32, 240, 126));
	button.setSelectionOutlineColor(sf::Color(124, 163, 251));
	button.setSelectionOutlineThickness(5);
	button.setCharacterSize(22);
	button.setTextFillColor(sf::Color::White);
	button.setFont(font);
	button.setString("TextButton");

	text.setSize({ 80, 40 });
	text.setPosition(400, 5);
	text.setBoxFillColor(sf::Color::Transparent);
	text.setBoxOutlineColor(sf::Color(160, 32, 240));
	text.setBoxOutlineThickness(3);
	text.setCharacterSize(22);
	text.setTextFillColor(sf::Color::White);
	text.setFont(font);
	text.setString("TextButton");
	

	button2.setSize({ 80, 40 });
	button2.setPosition(20, 5);
	button2.setBoxFillColor(sf::Color::Transparent);
	button2.setBoxOutlineColor(sf::Color(160, 32, 240));
	button2.setBoxOutlineThickness(3);
	button2.setSelectionFillColor(sf::Color(160, 32, 240, 126));
	button2.setSelectionOutlineColor(sf::Color(124, 163, 251));
	button2.setSelectionOutlineThickness(5);
	button2.setCharacterSize(22);
	button2.setTextFillColor(sf::Color::White);
	button2.setFont(font);
	button2.setString("button2");
	button2.setPosition(120, 5);



	slider.setSize({ 80, 40 });
	slider.setPosition(300, 5);
	slider.setBarFillColor(sf::Color::Red);
	slider.setBarSelectionColor(sf::Color::Yellow);
	slider.setBoxFillColor(sf::Color::Transparent);
	slider.setBoxOutlineColor(sf::Color::Blue);
	slider.setBoxOutlineThickness(3);
	slider.setTextFillColor(sf::Color::White);
	slider.setFont(font);
	slider.setCharacterSize(22);
	slider.setString("Speed");
	slider.setVariable(val, 3, 200);
	

	page.setFillColor(sf::Color(255, 255, 255, 26));
	page.setMaxSize({ 1000, 1000 });
	page.setPosition(1050, 100);
	page.setActiveRegion({ 0,0, 400, 500 });
	page.setScroll(gui::Page::RIGHT);
	page.setScroll(gui::Page::BOTTOM);

	page.setHeader(true, true, true);

	page2.setFillColor(sf::Color(255, 255, 255, 78));
	page2.setMaxSize({ 1000, 1000 });
	page2.setPosition(500, 500);
	page2.setActiveRegion({ 0,0, 300, 300 });
	page2.setScroll(gui::Page::RIGHT);
	page2.setScroll(gui::Page::BOTTOM);

	page2.setHeader(true, true, true);

	drop.setItemHeight(40);
	drop.setHeaderSize({ 300, 40 });
	drop.setPosition(20, 20);
	drop.setFillColor(sf::Color(255, 255, 255, 26));

	dbutton1.setBoxFillColor(sf::Color::Transparent);
	dbutton1.setBoxOutlineColor(sf::Color(160, 32, 240));
	dbutton1.setBoxOutlineThickness(3);
	dbutton1.setSelectionFillColor(sf::Color(160, 32, 240, 126));
	dbutton1.setSelectionOutlineColor(sf::Color(124, 163, 251));
	dbutton1.setSelectionOutlineThickness(5);
	dbutton1.setCharacterSize(22);
	dbutton1.setTextFillColor(sf::Color::White);
	dbutton1.setFont(font);
	dbutton1.setString("dbutton1");
	drop.addItem(dbutton1);

	dbutton2.setBoxFillColor(sf::Color::Transparent);
	dbutton2.setBoxOutlineColor(sf::Color(160, 32, 240));
	dbutton2.setBoxOutlineThickness(3);
	dbutton2.setSelectionFillColor(sf::Color(160, 32, 240, 126));
	dbutton2.setSelectionOutlineColor(sf::Color(124, 163, 251));
	dbutton2.setSelectionOutlineThickness(5);
	dbutton2.setCharacterSize(22);
	dbutton2.setTextFillColor(sf::Color::White);
	dbutton2.setFont(font);
	dbutton2.setString("dbutton2");
	drop.addItem(dbutton2);

	dbutton3.setBoxFillColor(sf::Color::Transparent);
	dbutton3.setBoxOutlineColor(sf::Color(160, 32, 240));
	dbutton3.setBoxOutlineThickness(3);
	dbutton3.setSelectionFillColor(sf::Color(160, 32, 240, 126));
	dbutton3.setSelectionOutlineColor(sf::Color(124, 163, 251));
	dbutton3.setSelectionOutlineThickness(5);
	dbutton3.setCharacterSize(22);
	dbutton3.setTextFillColor(sf::Color::White);
	dbutton3.setFont(font);
	dbutton3.setString("dbutton3");
	drop.addItem(dbutton3);

	drop.setItemLimit(1);
	drop.setTitle("Drop", font, 24);

	rectB.setPointCount(4);
	rectB.setPoint(0, { 300, 300 });
	rectB.setPoint(1, { 600, 300 });
	rectB.setPoint(2, { 600, 500 });
	rectB.setPoint(3, { 300, 500 });
	rectB.setPosition(10, 10);
	page2.addEntity(drop);

	rectB.setFillColor(sf::Color::Red);
	rectB.setSelectionFillColor(sf::Color::Blue);

	page.setPosition(0, 10);

	page3.setFillColor(sf::Color(255, 255, 255, 78));
	page3.setMaxSize({ 500, 500 });
	page3.setPosition(20, 20);
	page3.setActiveRegion({ 0,0, 200, 200 });
	page3.setScroll(gui::Page::RIGHT);
	page3.setScroll(gui::Page::BOTTOM);
	page3.setHeader(true, true, true);


	//page.rotate(45);
	//page2.rotate(-45);
	//page.scale(1.5, 1.5);

	rectB.actionEvent = gui::Entity::ActionEvent::NONE;
	rectB.setAction([this] {if (rectB.isSelected())page.setActive(); else page.setInactive(); });

	page.addEntity(text);
	page.addEntity(button);
	page.addEntity(button2);
	page.addEntity(slider);
	frame.addEntity(page2);

	frame.addEntity(page);
	frame.removeEntity(page2);
	page.addEntity(page2);

	frame.addEntity(rectB);

}

Renderer::~Renderer()
{
}

bool Renderer::isRunning()
{
	return this->running;
}

void Renderer::update()
{
	this->pollEvents();

	if (!this->paused) {
		frame.update();
	}
}

void Renderer::pollEvents()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			this->running = false;

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)this->paused = !this->paused;

		if (!this->paused) {
			frame.pollEvents(event);
			if (event.type == sf::Event::MouseMoved) {
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				
			}
			else if (event.type == sf::Event::MouseButtonReleased) {
				
			}
			else if (event.type == sf::Event::KeyPressed) {

			}
		}
	}
}

void Renderer::render()
{
	this->window.clear();

	frame.draw();

	this->window.display();
}

sf::Vector2f Renderer::getMousePosition()
{
	return window.mapPixelToCoords(sf::Mouse::getPosition(this->window));
}

sf::Vector2f Renderer::getWinSize()
{
	return sf::Vector2f(this->window.getSize());
}