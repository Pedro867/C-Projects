/*
 * Autor: Pedro Lucas Moreira Ferreira 2024
 */
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include "Bola.hpp"
#include "Player.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(720, 480), "My Window");
	window.setFramerateLimit(60);
	srand(time(NULL));

	Bola bola(window);
	Player player1(window);
	Player2 player2(window);

	sf::Font fonte;
	fonte.loadFromFile("libs/Arial.ttf");
	sf::Text vidas1, vidas2, derrota;

	vidas1.setFont(fonte);
	vidas2.setFont(fonte);
	derrota.setFont(fonte);

	vidas1.setCharacterSize(20);
	vidas2.setCharacterSize(20);
	derrota.setCharacterSize(50);
	derrota.setOrigin(25, 25);

	vidas1.setFillColor(sf::Color::Blue);
	vidas2.setFillColor(sf::Color::Blue);
	derrota.setFillColor(sf::Color::Red);

	vidas1.setPosition(30, 380);
	vidas2.setPosition(600, 380);
	derrota.setPosition(270, 180);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();

		//Move Objetos
		player1.isColliding(bola);
		player2.isColliding(bola);
		player1.movePlayer();
		player2.movePlayer();

		std::string vidas1String = std::to_string(player1.getVidas());
		std::string vidas2String = std::to_string(player2.getVidas());

		vidas1.setString("Vidas: " + vidas1String);
		vidas2.setString("Vidas: " + vidas2String);
		derrota.setString("DERROTA");

		//Desenha na tela
		if(!player1.perdeu() && !player2.perdeu()){
			bola.moveBola();
			window.draw(bola.getBola());
		}else{
			window.draw(derrota);
		}
		window.draw(player2.getPlayer());
		window.draw(player1.getPlayer());

		window.draw(vidas1);
		window.draw(vidas2);

		window.display();
	}

	return 0;
}
