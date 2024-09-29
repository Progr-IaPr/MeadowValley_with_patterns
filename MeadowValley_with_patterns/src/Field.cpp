#include "../include/Field.h"

Field::Field(int id, int plotCount, const sf::Vector2f& pos)
    : fieldID(id), plotCount(plotCount), position(pos), isOwned(false) {}

int Field::getFieldID() const {
    return fieldID;
}

int Field::getPlotCount() const {
    return plotCount;
}

bool Field::isUnlocked() const {
    return isOwned;
}

sf::Vector2f Field::getPosition() const {
    return position;
}

void Field::buyField() {
    isOwned = true;
}