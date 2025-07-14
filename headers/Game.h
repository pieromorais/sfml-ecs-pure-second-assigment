#ifndef GAME_HEADER_H
#define GAME_HEADER_H

#include "Entity.h"
#include "EntityManager.h"
#include "Vec2.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include <string>

struct WindowConfig { int W, H, FL, FS; }; // FL - frame limit, FS - full screen 1 or 0
struct FontConfig	{ std::string F; int S, R, G, B; }; // S - font size
struct PlayerConfig	{ int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; }; // SR - shape radius; CR - collison radius; S speed; F - fill color RGB, O - outline color RGB, OT outline tickness, V shape vertices
struct EnemyConfig	{ int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI; float SMIN, SMAX; }; //smin smax - min and max speeds; vmin and vmax - min and max number of vertices; L - small lifespan; SP spawn interval
struct BulletConfig	{ int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; }; // L lifespan

class Game
{
private:
	sf::RenderWindow	m_window;
	EntityManager		m_entities;
//	sf::Font		m_font;
//	sf::Text		m_text;
	PlayerConfig		m_playerConfig;
	EnemyConfig			m_enemyConfig;
	BulletConfig		m_bulletConfig;
	int					m_score = 0;
	int					m_currentFrame = 0;
	int					m_lastEnemyTimeSpan = 0;
	bool				m_paused = false;
	bool				m_running = true;

	std::shared_ptr<Entity> m_player; 

	void init(const std::string& config); // initialize the game state with a config file path
	void setPaused(bool paused);

	void sMovement();
	void sUserInput();
	void sLifeSpan();
	void sRender();
	void sEnemySpawner();
	void sCollison();

	void spawnPlayer();
	void spawnEnemy();
	void spawnSmallEnemies(std::shared_ptr<Entity> entity);
	void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos);
	void spawnSpecialWeapon(std::shared_ptr<Entity> entity);
public:
	Game(const std::string& config);
	void run();
};

#endif
