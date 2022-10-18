#include "Collision.h"

Collision::Collision(sf::RectangleShape& body):
    body(body)
{
}

Collision::~Collision()
{
}

bool Collision::CheckCollision(Collision other, float push)
{
    sf::Vector2f otherPostition = other.GetPostition();
    sf::Vector2f otherHalfSize = other.GetHalfOfSize();
    sf::Vector2f thisPostition = other.GetPostition();
    sf::Vector2f thisHalfSize = other.GetHalfOfSize();

    float deltaX = otherPostition.x - thisPostition.x;
    float deltaY = otherPostition.y - thisPostition.y;

    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (intersectX < 0.0f && intersectY < 0.0f) {
        push = std::min(std::max(push, 0.0f), 1.0f);

        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                other.Move(intersectX * push, 0.0f);
                Move(-intersectX * (1.0f - push), 0.0f);
            }
            else {
                other.Move(-intersectX * push, 0.0f);
                Move(intersectX * (1.0f - push), 0.0f);
            }
        }
        else {
            if (deltaY> 0.0f) {
                other.Move(0.0f, intersectY * push);
                Move(0.0f , -intersectY * (1.0f - push));
            }
            else {
                Move(0.0f,intersectY * (1.0f - push));
                other.Move(0.0f , -intersectY * push);
            }
        }
        return true;
    }

    return false;
}
