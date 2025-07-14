#include "Game.h"
#include "Components.h"
#include "DebugLog.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

Game::Game(const std::string& config)
{
	this->init(config);
}

void Game::init(const std::string& config)
{
	// TODO: read config file here
	// use premade player config, enemy config, bullet config variables
	std::ifstream fin(config);
	if (!fin.is_open()) {
		LOG("File failed to open!");
		exit(-1);
	}
	std::string cfgName;

	WindowConfig	w;
	FontConfig		f;
	PlayerConfig	p;		
	EnemyConfig		e;
	BulletConfig	b;
	
	while (fin >> cfgName) {
		if (cfgName == "Window") {
			LOG("Window config");
			fin >> w.W >> w.H >> w.FL >> w.FS;
		}else if (cfgName == "Font") {
			LOG("Font config");
			fin >> f.F >> f.S >> f.R >> f.G >> f.B;	
		}else if (cfgName == "Player") {
			LOG("Player config");
			fin >> p.SR >> p.CR >> p.FR >> p.FG >> p.FB >> p.OR >> p.OG >> p.OB >> p.OT >> p.V >> p.S;
		}else if (cfgName == "Enemy") {
			LOG("Enemy config");
			fin >> e.SR >> e.CR >> e.OR >> e.OG >> e.OB >> e.OT >> e.VMIN >> e.VMAX >> e.L >> e.SI >> e.SMIN >> e.SMAX;
		}else if (cfgName == "Bullet") {
			LOG("Bullet config");
			fin >> b.SR >> b.CR >> b.FR >> b.FG >> b.OR >> b.OG >> b.OB >> b.OT >> b.V >> b.L >> b.S;
		}	
	}

	this->m_window.create(sf::VideoMode(w.W, w.H), "Assigment 2");
	this->m_window.setFramerateLimit(w.FL);
	// TODO: implement fullscreen check later

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		LOG("W");
		m_player->cInput->up = true;

		m_player->cTransform->pos.y = m_player->cTransform->pos.y - 10;
		m_player->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);
	}else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		m_player->cInput->up = false;	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		LOG("A");
		m_player->cInput->left = true;

		m_player->cTransform->pos.x = m_player->cTransform->pos.x - 10;
		m_player->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);
	}else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		m_player->cInput->left = false;	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		LOG("D");
		m_player->cInput->right = true;

		m_player->cTransform->pos.x = m_player->cTransform->pos.x + 10;
		m_player->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);

	}else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		m_player->cInput->right = false;	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		LOG("S");
		m_player->cInput->down = true;
		
		// update positions
		m_player->cTransform->pos.y = m_player->cTransform->pos.y + 10;
		m_player->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);

	}else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		m_player->cInput->down = false;	
	}
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
	// set rotation 
	this->m_player->cTransform->angle += 10.0f;
	this->m_player->cShape->circle.setRotation(this->m_player->cTransform->angle);

	//draw circle
	this->m_window.draw(this->m_player->cShape->circle);
	this->m_window.display();

}

void Game::sEnemySpawner()
{
	//LOG("Enemy Spawn");
}

void Game::sCollison()
{
	//LOG("Collison system");
}

// Spawn

void Game::spawnPlayer()
{
	// TODO: Finish adding all properties of the player  with the correct  values from the config
	//
	// we create create every entity by calling EntityManager.addEntity(tag)
	// this returns a std::shared_ptr<Entity>, so we use auto to save typing
	//
	auto entity = this->m_entities.addEntity("player");

	// give this entity a Transform so it spawns at (200,200) with velocity (1,1), and angle 0
	entity->cTransform = std::make_shared<CTransform>(Vec2(200.0f, 200.0f), Vec2(1.0f, 1.0f), 0.0f);

	// the entity's shape will have radius 32, 8 sides, dark gray fill, and read outline of thickness 4
	entity->cShape = std::make_shared<CShape>(32.0f, 8, sf::Color(10,10,10), sf::Color(255,0,0), 4.0f);

	// add an input component to the player  so that we can use inputs
	entity->cInput = std::make_shared<CInput>();

	// since we want this Entity to be our player, set our Game's player variable to be this Entity
	// this goes slightly against the EntityManager paradigm, but we use the player so much it's worth it
	this->m_player = entity;
	
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




