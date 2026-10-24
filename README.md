 TP 1 — Test de primalité en C (USTHB)

Ce projet contient les quatre fonctions de test de primalité demandées dans le TP d'Algorithmique avancée et complexité. Il est organisé pour séparer l'implémentation et la démonstration.

## Contenu du dossier

| Fichier | Rôle |
| --- | --- |
| `primalite.h` | Déclarations des quatre fonctions. |
| `primalite.c` | Implémentation de A1, A2, A3 et A4. |
| `main.c` | Démonstration : exécuter un algorithme sur une valeur. |
| `Makefile` | Raccourcis pour compiler et nettoyer. |
| `GUIDE_TP.md` | Explication des quatre algorithmes et de leur rôle dans le groupe. |
| `GUIDE_TESTS_EXPERIMENTAUX.md` | Guide pour le membre chargé d'écrire et d'exécuter les tests expérimentaux. |

## Compiler

Avec GCC et `make` installé :

```bash
make
```

Ou directement, sans Makefile :

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic primalite.c main.c -o primalite
```

## Utiliser le programme de démonstration

```bash
./primalite A1 97
./primalite A2 97
./primalite A3 97
./primalite A4 97
```

`97` est premier. Pour un nombre composé, essaie par exemple :

```bash
./primalite A3 100
```

Le programme affiche le nom de l'algorithme et le résultat. Il ne mesure pas le temps d'exécution.

## Intégration avec le programme expérimental

Le membre chargé des mesures peut inclure `primalite.h` et appeler les fonctions dans son propre programme. Si son fichier s'appelle `mesures.c`, compile-le ainsi :

```bash
gcc -std=c11 -O2 -Wall -Wextra -Wpedantic primalite.c mesures.c -o mesures
```
