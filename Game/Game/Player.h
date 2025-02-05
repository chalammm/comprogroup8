#ifndef PLAYER_H
#define PLAYER_H

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING };

class Player
{
private:
    Sprite sprite;
    Texture textureSheet;
    Clock animationTimer;

    short animState;
    IntRect currentFrame;

    bool onGround;
    Vector2f velocity;
    float velocityMax;
    float velocityMin;
    float acceleration;
    float drag;
    float gravity;

    void initAnimState();
    void initTexture();
    void initSprite();
    void initAnimations();
    void initPhysics();

public:
    Player();
    virtual ~Player();

    const FloatRect getGlobalBounds() const;

    void setPosition(const float x, const float y);
    void resetVelocityY();
    void resetVelocityX();

    void move(const float dir_x, const float dir_y);
    void updatePhysics();
    void updateMovement();
    void updateAnimations();
    void update();
    void render(RenderTarget* target);
};

#endif