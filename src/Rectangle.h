#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
private:
    int width;
    int height;
    int x;  // Position X (coin inférieur gauche)
    int y;  // Position Y (coin inférieur gauche)
    int id; // Identifiant unique

public:
    // Constructeur
    Rectangle(int w, int h, int identifier);
    
    // Getters
    int getWidth() const;
    int getHeight() const;
    int getX() const;
    int getY() const;
    int getId() const;
    int getArea() const;
    
    // Setters
    void setPosition(int posX, int posY);
    
    // Méthodes utilitaires
    bool overlaps(const Rectangle& other) const;
    void print() const;
    
    // Opérateur de comparaison (pour tri)
    bool operator<(const Rectangle& other) const;
};

#endif // RECTANGLE_H