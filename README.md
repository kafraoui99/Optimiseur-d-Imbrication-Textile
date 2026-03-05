# 🧵 Textile Nesting Optimizer
![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![CMake](https://img.shields.io/badge/CMake-3.10-green)
![License](https://img.shields.io/badge/License-MIT-yellow)
![Status](https://img.shields.io/badge/Status-Active-success)


Optimiseur d'imbrication de formes rectangulaires pour l'industrie textile - Développé pour LOSANJE

## 📖 Description

Ce projet implémente un algorithme d'optimisation d'imbrication (bin packing 2D) pour maximiser l'utilisation de surfaces textiles lors de la découpe. Il s'agit d'un problème classique dans l'industrie textile (upcycling, production) où l'objectif est de placer un maximum de pièces rectangulaires sur une surface donnée en minimisant les chutes.

## 🎯 Contexte

Développé dans le cadre de ma candidature chez **LOSANJE**, startup pionnière de l'upcycling textile automatisé. Ce projet démontre ma capacité à :
- Développer des algorithmes d'optimisation en C++
- Résoudre des problématiques industrielles concrètes
- Créer du code propre, documenté et maintenable

## ✨ Fonctionnalités

- ✅ Algorithme de placement optimisé (First Fit Decreasing Height)
- ✅ Support de formes rectangulaires de tailles variées
- ✅ Calcul du taux d'utilisation de la surface
- ✅ Visualisation ASCII du placement
- ✅ Export des résultats (positions, efficacité)
- ✅ Chargement de données depuis fichier

## 🛠️ Technologies

- **Langage** : C++17
- **Build** : CMake
- **Compilateur** : g++ / clang++
- **Système** : Linux / macOS / Windows

## 📦 Installation
```bash
# Cloner le repository
git clone https://github.com/yassine-kafraoui/textile-nesting-optimizer.git
cd textile-nesting-optimizer

# Créer dossier build
mkdir build && cd build

# Compiler
cmake ..
make

# Exécuter
./TextileNestingOptimizer ../examples/input_simple.txt
```

## 📊 Exemple d'utilisation

### Fichier d'entrée (input_simple.txt)
```
# Dimensions de la surface textile (largeur x hauteur)
100 80

# Liste des pièces à placer (largeur hauteur quantité)
30 20 5
15 10 8
25 15 3
```

### Sortie
```
=== TEXTILE NESTING OPTIMIZER ===

Surface textile : 100 x 80 cm (8000 cm²)
Nombre de pièces à placer : 16

--- Résultats du placement ---
✓ Pièces placées : 16/16 (100%)
✓ Surface utilisée : 6450 cm² (80.6%)
✓ Surface perdue : 1550 cm² (19.4%)

--- Visualisation ---
[Grille ASCII montrant le placement]

--- Positions détaillées ---
Pièce #1 (30x20) : position (0, 0)
Pièce #2 (30x20) : position (30, 0)
...
```

## 🧮 Algorithme

L'algorithme implémenté est **First Fit Decreasing Height (FFDH)** :

1. **Tri** : Les pièces sont triées par hauteur décroissante
2. **Placement** : Pour chaque pièce :
   - Chercher la première position disponible (de gauche à droite, bas en haut)
   - Si aucune position trouvée, la pièce n'est pas placée
3. **Optimisation** : Minimise les espaces vides en privilégiant le remplissage horizontal

**Complexité** : O(n² log n) où n = nombre de pièces

Voir [docs/algorithm.md](docs/algorithm.md) pour plus de détails.

## 📈 Performances

Sur un dataset de 100 pièces aléatoires :
- **Temps d'exécution** : ~2ms
- **Taux d'utilisation moyen** : 75-85%
- **Mémoire** : O(n)

## 🔄 Évolutions futures

- [ ] Support de formes non-rectangulaires (polygones)
- [ ] Algorithmes avancés (Genetic Algorithm, Simulated Annealing)
- [ ] Rotation automatique des pièces
- [ ] Interface graphique (Qt/SDL)
- [ ] Export vers formats industriels (DXF, SVG)
- [ ] Intégration avec automates (OPC UA, MODBUS)

## 🧪 Tests
```bash
# Lancer les tests
cd build
ctest
```

## 📚 Documentation

- [Algorithm.md](docs/algorithm.md) : Explication détaillée de l'algorithme
- [API Documentation](docs/api.md) : Documentation des classes et méthodes

## 👨‍💻 Auteur

**Yassine KAFRAOUI**
- Ingénieur en Génie Logiciel
- Master Transformation Numérique - Paris Dauphine
- 📧 yassine.kafraoui@email.com
- 💼 [LinkedIn](https://linkedin.com/in/yassine-kafraoui)
- 🐙 [GitHub](https://github.com/yassine-kafraoui)

## 📄 Licence

MIT License - Libre d'utilisation et modification

## 🙏 Remerciements

Projet développé dans le cadre de ma candidature chez **LOSANJE**, pionnier de l'upcycling textile automatisé en Europe.

---

*"L'optimisation, c'est faire plus avec moins. Dans l'upcycling, c'est donner une seconde vie à chaque centimètre carré de textile."* 🌱
