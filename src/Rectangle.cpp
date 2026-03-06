#include "Rectangle.h"

Rectangle::Rectangle(int w, int h, int identifier) 
    : width(w), height(h), x(-1), y(-1), id(identifier) {}

int Rectangle::getWidth() const { return width; }
int Rectangle::getHeight() const { return height; }
int Rectangle::getX() const { return x; }
int Rectangle::getY() const { return y; }
int Rectangle::getId() const { return id; }
int Rectangle::getArea() const { return width * height; }

void Rectangle::setPosition(int posX, int posY) {
    x = posX;
    y = posY;
}

bool Rectangle::overlaps(const Rectangle& other) const {
    // Vérifie si deux rectangles se chevauchent
    if (x == -1 || other.x == -1) return false; // Pas encore placé
    
    return !(x + width <= other.x ||  // Complètement à gauche
             other.x + other.width <= x || // Complètement à droite
             y + height <= other.y || // Complètement en bas
             other.y + other.height <= y); // Complètement en haut
}

void Rectangle::print() const {
    std::cout << "Rectangle #" << id 
              << " (" << width << "x" << height << ") "
              << "at position (" << x << ", " << y << ")" << std::endl;
}

bool Rectangle::operator<(const Rectangle& other) const {
    // Tri par hauteur décroissante (pour FFDH algorithm)
    return height > other.height;
}