#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include "Bola.hpp"
#include<SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Player {
private:
	sf::RectangleShape player;
	sf::Vector2<float> tamanho;
	float posX, posY, velY;
	int vidas;
	sf::RenderWindow &window;
public:

	Player(sf::RenderWindow &janela) :
			window(janela) {

		tamanho.x = 30.0;
		tamanho.y = 150.0;
		player.setSize(tamanho);

		player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
		player.setFillColor(sf::Color::White);

		posX = 50;
		posY = 240;
		player.setPosition(posX, posY);
		velY = 3;
		vidas = 3;
		//erro na funcao movePlayer() ao trocar a velocidade para 2
	}

	void movePlayer() {
		if (player.getPosition().y - player.getSize().y / 2 < 0) {

			//transporta o player pra dentro da tela se ele sair pra cima
			player.setPosition(posX, player.getSize().y / 2);

		} else if (player.getPosition().y + player.getSize().y / 2
				> window.getSize().y) {

			//transporta o player pra dentro da tela se ele sair pra baixo
			player.setPosition(posX,
					window.getSize().y - player.getSize().y / 2);

		} else {
			int newPosY = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				newPosY -= velY;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				newPosY += velY;
			}
			player.move(0, newPosY);
			posX = player.getPosition().x;
			posY = player.getPosition().y;
		}
	}

	void isColliding(Bola &bola) {
		sf::CircleShape circle = bola.getBola();
		sf::FloatRect rectBola = circle.getGlobalBounds();
		sf::FloatRect rectPlayer = player.getGlobalBounds();

		float posYBola = bola.getBola().getPosition().y + bola.getVelY();
		float posXBola = bola.getBola().getPosition().x + bola.getVelX();
		float teto = posY - tamanho.y / 2;
		float chao = posY + tamanho.y / 2;
		float paredeEsquerda = posX - tamanho.x / 2;
		float paredeDireita = posX + tamanho.x / 2;
		bool controle;

		if (teto <= (posYBola + bola.getBola().getRadius())
				&& (posXBola <= paredeDireita && posXBola >= paredeEsquerda)) {
			bola.inverteVelY();
			controle = true;
		}
		if (chao <= (posYBola - bola.getBola().getRadius())
				&& (posXBola <= paredeDireita && posXBola >= paredeEsquerda)) {
			bola.inverteVelY();
			controle = true;
		}

		if (!controle) {
			if (rectPlayer.intersects(rectBola)) {
				bola.inverteVelX();
				bola.aumentaVel();
			}
		}

		//so eh necessario em um player
		bola.bateuBorda();

		if (bola.saiuBordaP1()) {
			vidas--;
			std::cout << "Vidas Player2 = " << vidas << std::endl;
		}
	}

	sf::RectangleShape getPlayer() {
		return player;
	}

	int getVidas() const {
		return vidas;
	}

	bool perdeu() {
		if (vidas <= 0) {
			return true;
		}
		return false;
	}
};

class Player2 {
private:
	sf::RectangleShape player;
	sf::Vector2<float> tamanho;
	float posX, posY, velY;
	int vidas;
	sf::RenderWindow &window;
public:
	Player2(sf::RenderWindow &janela) :
			window(janela) {

		tamanho.x = 30;
		tamanho.y = 150;
		player.setSize(tamanho);

		player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
		player.setFillColor(sf::Color::White);

		posX = 670;
		posY = 240;
		player.setPosition(posX, posY);
		velY = 3;
		vidas = 3;
	}

	void movePlayer() {

		if (player.getPosition().y - player.getSize().y / 2 < 0) {

			//transporta o player pra dentro da tela se ele sair pra cima
			player.setPosition(posX, player.getSize().y / 2);

		} else if (player.getPosition().y + player.getSize().y / 2
				> window.getSize().y) {

			//transporta o player pra dentro da tela se ele sair pra baixo
			player.setPosition(posX,
					window.getSize().y - player.getSize().y / 2);

		} else {
			int newPosY = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				newPosY -= velY;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				newPosY += velY;
			}
			player.move(0, newPosY);
		}
	}

	void isColliding(Bola &bola) {
		sf::CircleShape circle = bola.getBola();
		sf::FloatRect rectBola = circle.getGlobalBounds();
		sf::FloatRect rectPlayer = player.getGlobalBounds();

		float posYBola = bola.getBola().getPosition().y + bola.getVelY();
		float posXBola = bola.getBola().getPosition().x + bola.getVelX();
		float teto = posY - tamanho.y / 2;
		float chao = posY + tamanho.y / 2;
		float paredeEsquerda = posX - tamanho.x / 2;
		float paredeDireita = posX + tamanho.x / 2;
		bool controle;

		if (teto <= (posYBola + bola.getBola().getRadius())
				&& (posXBola <= paredeDireita && posXBola >= paredeEsquerda)) {
			bola.inverteVelY();
			controle = true;
		}
		if (chao <= (posYBola - bola.getBola().getRadius())
				&& (posXBola <= paredeDireita && posXBola >= paredeEsquerda)) {
			bola.inverteVelY();
			controle = true;
		}

		if (!controle) {
			if (rectPlayer.intersects(rectBola)) {
				bola.inverteVelX();
				bola.aumentaVel();
			}
		}

		if (bola.saiuBordaP2()) {
			vidas--;
			std::cout << "Vidas Player2 = " << vidas << std::endl;
		}
	}

	sf::RectangleShape getPlayer() {
		return player;
	}

	int getVidas() const {
		return vidas;
	}

	bool perdeu() {
		if (vidas == 0) {
			return true;
		}
		return false;
	}
};

#endif
