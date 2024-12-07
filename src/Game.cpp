#include "Game.h"

#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <ostream>
#include <string>

Game::Game(const std::string& config)
{
	this->init(config);
}

void Game::init(const std::string& config)
{
	// TODO: read config file here
	// use premade player config, enemy config, bullet config variables
	//
	// set up default window paramenters
	this->m_window.create(sf::VideoMode(1280, 720), "Assigment 2");
	this->m_window.setFramerateLimit(60);

	std::cout << config << std::endl;
	this->spawnPlayer();
}

void Game::run()
{
	while (this->m_running) 
	{
		this->m_entities.update();

		this->sEnemySpawner();
		this->sMovement();
		this->sCollison();
		this->sUserInput();
		this->sRender();


		// increment current frame rate
		// may need to be moved when paused implemented
		this->m_currentFrame++;

	}
}



// System methods
void Game::sMovement()
{

}

void Game::sUserInput()
{

}

void Game::sLifeSpan()
{

}

void Game::sRender()
{

	// TODO: change the code below to draw ALL Entites
	// sample drawing of the player entity that we have created
	//
	
	this->m_window.clear();

	// set player position
	this->m_player->cShape->circle.setPosition(this->m_player->cTransform->pos.x, this->m_player->cTransform->pos.y);
	// set rotation 
	this->m_player->cTransform->angle += 1.0f;
	this->m_player->cShape->circle.setRotation(this->m_player->cTransform->angle);

	//draw circle
	this->m_window.draw(this->m_player->cShape->circle);
	this->m_window.display();

}

void Game::sEnemySpawner()
{

}

void Game::sCollison()
{

}

// Spawn

void Game::spawnPlayer()
{
	// TODO: Finish adding all properties of the player  with the correct  values from the config
	//
	// we create create every entity by calling EntityManager.addEntity(tag)
	// this returns a std::shared_ptr<Entity>, so we use auto to save typing
	
}

void Game::spawnEnemy()
{

}

void Game::spawnSmallEnemies(std::shared_ptr<Entity> entity)
{

}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos)
{

}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{

}




