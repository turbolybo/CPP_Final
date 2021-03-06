#include "Enemy.h"

SDL_Texture * Enemy::getDrawable(){
	return m_enemy_drawable;
}

SDL_Rect* Enemy::getCoords(){
	return &m_enemy_coords;
}

int Enemy::getX(){
	return m_enemy_coords.x;
}

int Enemy::getY(){
	return m_enemy_coords.y;
}

void Enemy::setX(int x) {
	m_enemy_coords.x = x;
}

void Enemy::setY(int y) {
	m_enemy_coords.y = y;
}

void Enemy::setDifficulty(int dif) {
	difficulty = dif;
}

int Enemy::getDifficulty() {
	return difficulty;
}

void Enemy::moveX(int direction) {
	if (direction == 0) {
		m_enemy_coords.x -= getDifficulty();
	}
	else {
		m_enemy_coords.x += getDifficulty();
	}
}

void Enemy::moveDown() {
	m_enemy_coords.y += 12;
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}
// Renderer, 1-5 enemytype, pos X, pos Y
Enemy::Enemy(SDL_Renderer * renderer, int enemytype, int x, int y) {
	const char * path;
	if (enemytype == 1) {
		path = "Img/enemy_1.bmp";
	}
	else if (enemytype == 2) {
		path = "Img/enemy_2.bmp";
	}
	else if (enemytype == 3) {
		path = "Img/enemy_3.bmp";
	}
	else if (enemytype == 4) {
		path = "Img/enemy_4.bmp";
	}
	else {
		path = "Img/enemy_5.bmp";
	}

	m_enemy_BMP = SDL_LoadBMP(path);
	m_enemy_drawable = SDL_CreateTextureFromSurface(renderer, m_enemy_BMP);
	m_enemy_coords.h = m_enemy_BMP->h;
	m_enemy_coords.w = m_enemy_BMP->w;
	m_enemy_coords.x = x;
	m_enemy_coords.y = y;
	SDL_FreeSurface(m_enemy_BMP);
}