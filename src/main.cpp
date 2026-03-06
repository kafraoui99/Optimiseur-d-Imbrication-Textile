#include "NestingOptimizer.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        std::cerr << "Example: " << argv[0] << " examples/input_simple.txt" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return 1;
    }
    
    int surfaceWidth, surfaceHeight;
    std::string line;
    
    // Lire dimensions de la surface
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream iss(line);
        if (iss >> surfaceWidth >> surfaceHeight) break;
    }
    
    NestingOptimizer optimizer(surfaceWidth, surfaceHeight);
    
    // Lire les pièces
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        
        std::istringstream iss(line);
        int width, height, quantity;
        
        if (iss >> width >> height >> quantity) {
            for (int i = 0; i < quantity; i++) {
                optimizer.addPiece(width, height);
            }
        }
    }
    
    file.close();
    
    // Optimiser
    optimizer.optimize();
    
    // Afficher résultats
    optimizer.printResults();
    optimizer.visualize();
    
    // Exporter
    optimizer.exportResults("output_results.csv");
    
    return 0;
}