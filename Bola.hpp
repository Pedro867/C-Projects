#ifndef BOLA_HPP_
#define BOLA_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Bola {
private:
	sf::CircleShape bola;
	float posX, posY, velX, velY, raio;
	sf::RenderWindow &window;
public:
	Bola(sf::RenderWindow &janela) :
			window(janela) {
		raio = 15;
		bola.setRadius(raio);
		bola.setOrigin(raio, raio);
		bola.setFillColor(sf::Color::Cyan);

		posX = window.getSize().x / 2;
		posY = window.getSize().y / 2;
		bola.setPosition(posX, posY);

		velX = 6;
		velY = -2;
	}

	sf::CircleShape getBola() {
		return bola;
	}

	void moveBola() {
		bola.move(velX, velY);
	}
	void moveInverso() {
		bola.move(-velX, -velY);
	}

	void setInicio() {
		posX = window.getSize().x / 2;
		posY = window.getSize().y / 2;
		bola.setPosition(posX, posY);
	}

	bool saiuBordaP1() {
		if (bola.getPosition().x <= 0) {
			setInicio();
			resetaVelocidade(1);
			return true;
		} else {
			return false;
		}
	}
	bool saiuBordaP2() {
		if (bola.getPosition().x >= window.getSize().x) {
			setInicio();
			resetaVelocidade(2);
			return true;
		} else {
			return false;
		}
	}

	void bateuBorda() {
		if (bola.getPosition().y - bola.getRadius() <= 0
				|| bola.getPosition().y + bola.getRadius()
						>= window.getSize().y) {
			inverteVelY();
		}
	}

	void resetaVelocidade(int controle) {
		if(controle == 1){
			velX = -6;
		}
		if(controle == 2){
			velX = 6;
		}
		velY = -2;
		inverteVel();
	}

	void aumentaVel() {
		if (velX > 0) {
			velX += 0.3;
		} else {
			velX -= 0.3;
		}
		if (velY > 0) {
			velY += 0.3;
		} else {
			velY -= 0.3;
		}
	}

	void inverteVel() {
		this->velX = -velX;
		this->velY = -velY;
	}

	void inverteVelX() {
		this->velX = -velX;
	}

	void inverteVelY() {
		this->velY = -velY;
	}

	float getVelX() {
		return velX;
	}
	float getVelY() {
		return velY;
	}
};

#endif
