#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#include "physics.hpp"
// #include "enemy.hpp"
#include "math.hpp"
#include "player.hpp"
#include "AnimatedSprites.hpp"

const int frames = 8;

enum WEAPON_ID {
    NONE,
    FUBU_BEAM,
    AXE,
    SPIDER_COOKING,
    X_POTATO,
    CEO_TEARS,
    FAN_BEAM,
    BL_BOOK,
    PSYCHO_AXE,
    IDOL_SONG,
    ELITE_LAVA,
    CUTTING_BOARD,
    FALLING_BLOCKS,
    ATK_UP,
    SPD_UP,
    HP_UP,
    HP_RECOVER,
};

struct DamagingArea
{
    WEAPON_ID weaponID;
    DamagingArea();
    float timePassed{0};
    float duration;
    float damage;
    Vector2f center;
    Vector2f rotatingCenter;
    Vector2f direction;
    Vector2f size;
    float projectileSpeed;
    int hitLimit;
    float knockbackSpeed{0};
    float knockbackTime{0};
    std::unordered_map<int, float> hitID;
    int currentFrame{-1};
    int frames;
    int attackCount{1};
    float frameTime{0};
    float lastFrameTime{-100};
    int angle{0};
    float radius;
    float fallTime;
    float hitCooldown{0};
    int count{0};
    bool ofPlayer{true};
    bool maxed{false};
    void render(SDL_Renderer* renderer, Player player, int camX, int camY);
};

struct Weapon {
    WEAPON_ID ID;
    Weapon(WEAPON_ID type);
    int level{1};
    float timeBetweenAttacks;
    DamagingArea dmgArea;
    float cooldown{0};
    float specialDuration[2] = {5,5};
    void setHitLimit(int hitLimit);
    void setHitCooldown(float hitCooldown);
    void setDamage(float damage);
    void setAttackInterval(float interval);
    void setArea(float areaIncrease);
    void setDuration(float durationReduction);
    void setAttackCount(int count);
    void setKnockback(float time, float speed);
    void updateStats();
};

void renderWeapon(SDL_Renderer* renderer, DamagingArea& weapon, Player player, int frame, int camX, int camY);

int damageCal(DamagingArea weapon, Player player);

void inflictDamage(DamagingArea &weapon, Player player, int& enemyHealth, bool& isHit, int enemyID);

bool hitEnemy(DamagingArea &weapon, Circle &enemyCollider,int& enemyHealth, bool& isHit, int enemyID, Player player);

bool hitPlayer(DamagingArea& weapon, Player& player);