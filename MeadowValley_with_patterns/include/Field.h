#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <SFML/System/Vector2.hpp>

class Field {
private:
    int fieldID;
    int plotCount;
    sf::Vector2f position;
    bool isOwned;
public:
    Field(int id, int plotCount, const sf::Vector2f& position);

    int getFieldID() const;
    int getPlotCount() const;
    bool isUnlocked() const;

    sf::Vector2f getPosition() const;  // Returns the position of the field
    void buyField();
};

#endif // FIELD_H