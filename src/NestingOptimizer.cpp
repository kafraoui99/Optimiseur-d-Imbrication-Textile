#include "NestingOptimizer.h"
#include <iostream>
#include <fstream>
#include <iomanip>

NestingOptimizer::NestingOptimizer(int width, int height)
    : surfaceWidth(width), surfaceHeight(height) {}

void NestingOptimizer::addPiece(int width, int height) {
    pieces.emplace_back(width, height, pieces.size() + 1);
}

bool NestingOptimizer::canPlaceAt(const Rectangle& piece, int x, int y) const {
    // Vérifie si la pièce dépasse la surface
    if (x + piece.getWidth() > surfaceWidth || 
        y + piece.getHeight() > surfaceHeight) {
        return false;
    }
    
    // Vérifie les chevauchements avec pièces déjà placées
    Rectangle tempPiece = piece;
    tempPiece.setPosition(x, y);
    
    for (const auto& placed : placedPieces) {
        if (tempPiece.overlaps(placed)) {
            return false;
        }
    }
    
    return true;
}

bool NestingOptimizer::findPosition(Rectangle& piece) {
    // Algorithme First Fit : cherche la première position valide
    for (int y = 0; y <= surfaceHeight - piece.getHeight(); y++) {
        for (int x = 0; x <= surfaceWidth - piece.getWidth(); x++) {
            if (canPlaceAt(piece, x, y)) {
                piece.setPosition(x, y);
                return true;
            }
        }
    }
    return false;
}

void NestingOptimizer::optimize() {
    // Tri des pièces par hauteur décroissante (FFDH)
    std::sort(pieces.begin(), pieces.end());
    
    // Placement des pièces
    for (auto& piece : pieces) {
        if (findPosition(piece)) {
            placedPieces.push_back(piece);
        }
    }
}

int NestingOptimizer::getPlacedCount() const {
    return placedPieces.size();
}

int NestingOptimizer::getTotalCount() const {
    return pieces.size();
}

double NestingOptimizer::getUtilizationRate() const {
    int totalArea = surfaceWidth * surfaceHeight;
    int usedArea = 0;
    
    for (const auto& piece : placedPieces) {
        usedArea += piece.getArea();
    }
    
    return (totalArea > 0) ? (100.0 * usedArea / totalArea) : 0.0;
}

void NestingOptimizer::printResults() const {
    std::cout << "\n=== TEXTILE NESTING OPTIMIZER ===\n" << std::endl;
    std::cout << "Surface textile : " << surfaceWidth << " x " 
              << surfaceHeight << " cm (" << (surfaceWidth * surfaceHeight) 
              << " cm²)" << std::endl;
    std::cout << "Nombre de pièces à placer : " << getTotalCount() << "\n" << std::endl;
    
    std::cout << "--- Résultats du placement ---" << std::endl;
    std::cout << "✓ Pièces placées : " << getPlacedCount() << "/" 
              << getTotalCount() << " (" 
              << std::fixed << std::setprecision(1)
              << (100.0 * getPlacedCount() / getTotalCount()) << "%)" << std::endl;
    
    int usedArea = 0;
    for (const auto& piece : placedPieces) {
        usedArea += piece.getArea();
    }
    
    int totalArea = surfaceWidth * surfaceHeight;
    std::cout << "✓ Surface utilisée : " << usedArea << " cm² (" 
              << std::setprecision(1) << getUtilizationRate() << "%)" << std::endl;
    std::cout << "✓ Surface perdue : " << (totalArea - usedArea) << " cm² (" 
              << std::setprecision(1) << (100.0 - getUtilizationRate()) << "%)\n" << std::endl;
    
    std::cout << "--- Positions détaillées ---" << std::endl;
    for (const auto& piece : placedPieces) {
        piece.print();
    }
}

void NestingOptimizer::visualize() const {
    std::cout << "\n--- Visualisation ASCII (échelle 1:2) ---\n" << std::endl;
    
    // Créer une grille
    int scaleX = 2; // Échelle horizontale
    int scaleY = 1; // Échelle verticale
    int gridWidth = surfaceWidth / scaleX;
    int gridHeight = surfaceHeight / scaleY;
    
    std::vector<std::vector<char>> grid(gridHeight, std::vector<char>(gridWidth, '.'));
    
    // Remplir la grille avec les pièces placées
    for (const auto& piece : placedPieces) {
        char symbol = '0' + (piece.getId() % 10); // Symbole unique par pièce
        
        for (int y = piece.getY() / scaleY; 
             y < (piece.getY() + piece.getHeight()) / scaleY && y < gridHeight; 
             y++) {
            for (int x = piece.getX() / scaleX; 
                 x < (piece.getX() + piece.getWidth()) / scaleX && x < gridWidth; 
                 x++) {
                grid[gridHeight - 1 - y][x] = symbol;
            }
        }
    }
    
    // Afficher la grille
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
    
    std::cout << "\n(Légende : '.' = espace vide, chiffres = pièces placées)\n" << std::endl;
}

void NestingOptimizer::exportResults(const std::string& filename) const {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }
    
    file << "# Résultats d'optimisation textile\n";
    file << "# Surface: " << surfaceWidth << "x" << surfaceHeight << "\n";
    file << "# Pièces placées: " << getPlacedCount() << "/" << getTotalCount() << "\n";
    file << "# Taux d'utilisation: " << std::setprecision(2) << getUtilizationRate() << "%\n\n";
    file << "# Format: ID, Width, Height, X, Y\n";
    
    for (const auto& piece : placedPieces) {
        file << piece.getId() << ","
             << piece.getWidth() << ","
             << piece.getHeight() << ","
             << piece.getX() << ","
             << piece.getY() << "\n";
    }
    
    file.close();
    std::cout << "✓ Résultats exportés vers " << filename << std::endl;
}