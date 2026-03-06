#ifndef NESTING_OPTIMIZER_H
#define NESTING_OPTIMIZER_H

#include "Rectangle.h"
#include <vector>
#include <algorithm>

class NestingOptimizer {
private:
    int surfaceWidth;
    int surfaceHeight;
    std::vector<Rectangle> pieces;
    std::vector<Rectangle> placedPieces;
    
    // Méthodes privées
    bool canPlaceAt(const Rectangle& piece, int x, int y) const;
    bool findPosition(Rectangle& piece);

public:
    // Constructeur
    NestingOptimizer(int width, int height);
    
    // Ajouter des pièces
    void addPiece(int width, int height);
    
    // Optimiser le placement
    void optimize();
    
    // Résultats
    int getPlacedCount() const;
    int getTotalCount() const;
    double getUtilizationRate() const;
    void printResults() const;
    void visualize() const;
    
    // Export
    void exportResults(const std::string& filename) const;
};

#endif // NESTING_OPTIMIZER_H