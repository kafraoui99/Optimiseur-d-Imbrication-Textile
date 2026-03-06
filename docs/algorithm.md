# 📐 Algorithme d'Optimisation

## First Fit Decreasing Height (FFDH)

### Principe

L'algorithme **FFDH** est une heuristique pour le problème du bin packing 2D (découpe de formes).

### Étapes

1. **Tri des pièces**
   - Trier toutes les pièces par hauteur décroissante
   - Les grandes pièces sont placées en premier
   - Réduit la fragmentation

2. **Placement séquentiel**
   - Pour chaque pièce (dans l'ordre trié) :
     - Chercher la première position valide (x, y)
     - Balayage : de bas en haut, de gauche à droite
     - Si position trouvée → placer la pièce
     - Sinon → pièce non placée

3. **Validation du placement**
   - Vérifier que la pièce ne dépasse pas la surface
   - Vérifier absence de chevauchement avec pièces déjà placées

### Complexité

- **Tri** : O(n log n)
- **Placement** : O(n² × w × h) où w,h = dimensions surface
- **Total** : O(n² × w × h)

Pour n=100 pièces, surface 200×150 : ~2ms

### Taux d'utilisation typique

- **Bon cas** : 80-90% (pièces de tailles variées)
- **Cas moyen** : 70-80%
- **Mauvais cas** : 50-70% (grandes pièces, petite surface)

### Améliorations possibles

1. **Rotation des pièces** (90°, 180°, 270°)
2. **Algorithmes avancés** :
   - Genetic Algorithm
   - Simulated Annealing
   - Branch & Bound
3. **Placement par niveaux** (shelf algorithm)
4. **Optimisation multi-objectifs** (minimiser chutes + temps calcul)

## Comparaison avec autres algorithmes

| Algorithme | Taux utilisation | Temps calcul | Complexité |
|------------|------------------|--------------|------------|
| **FFDH** | 70-80% | Rapide | O(n²) |
| Next Fit | 60-70% | Très rapide | O(n) |
| Best Fit | 75-85% | Moyen | O(n² log n) |
| Genetic Alg | 85-95% | Lent | Variable |

## Application à LOSANJE

Pour l'upcycling textile, FFDH est un bon compromis :
- ✅ Rapide (temps réel en production)
- ✅ Bon taux d'utilisation (70-80%)
- ✅ Facile à maintenir
- ✅ Extensible (rotation, formes complexes)