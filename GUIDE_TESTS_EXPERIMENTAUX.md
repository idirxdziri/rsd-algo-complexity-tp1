# Guide destiné au membre chargé des tests expérimentaux

Ce guide explique comment utiliser les quatre fonctions. **Il ne fournit pas un programme de benchmark tout fait** : la lecture des jeux de données, la mesure des temps et la production des tableaux/graphes font partie du travail expérimental du groupe.

## 1. Les fichiers à utiliser

| Fichier | Rôle |
| --- | --- |
| `primalite.c` | Implémentation des quatre algorithmes A1, A2, A3 et A4. |
| `primalite.h` | Déclarations des fonctions à inclure dans ton programme. |
| `main.c` | Programme de démonstration pour essayer un seul algorithme sur un nombre ; ce n'est pas l'outil de mesure. |
| `Makefile` | Raccourcis de compilation pour le programme de démonstration et les tests fonctionnels. |

## 2. Interface disponible

Dans `primalite.h`, les quatre fonctions sont déclarées ainsi :

```c
int est_premier_A1(long long n);
int est_premier_A2(long long n);
int est_premier_A3(long long n);
int est_premier_A4(long long n);
```

Chaque fonction retourne `1` si le nombre est premier et `0` sinon. Les fonctions ne font ni lecture de fichier, ni affichage, ni mesure du temps. Tu peux donc mesurer leur durée depuis ton propre programme.

## 3. Essayer manuellement une fonction

Compile d'abord le programme de démonstration :

```bash
make
```

Puis exécute, par exemple :

```bash
./primalite A3 97
./primalite A4 100
```

Le premier appel doit indiquer que 97 est premier, le second que 100 ne l'est pas. Cette démonstration sert à comprendre l'interface, pas à produire les mesures du TP.

## 4. Utiliser les fonctions dans ton propre programme

Dans le fichier C que tu écriras pour les tests expérimentaux, inclus l'en-tête :

```c
#include "primalite.h"
```

Tu pourras ensuite appeler la fonction souhaitée, par exemple :

```c
long long n = 1000003LL;
int resultat = est_premier_A3(n);
```

Pour compiler ton propre programme, si tu l'as nommé `mesures.c`, utilise :

```bash
gcc -std=c11 -O2 -Wall -Wextra -Wpedantic primalite.c mesures.c -o mesures
```

**N'ajoute pas `main.c` à cette commande** : ton fichier `mesures.c` contient déjà son propre `main()`, tout comme le programme de démonstration.

## 5. Mesurer le temps

Le TP1 mentionne `time.h`. La mesure doit entourer l'appel à la fonction et non la lecture du fichier ou l'affichage des résultats. Un exemple minimal de chronométrage d'un appel est :

```c
#include <time.h>

clock_t debut = clock();
int resultat = est_premier_A3(1000003LL);
clock_t fin = clock();

double temps_secondes = (double)(fin - debut) / CLOCKS_PER_SEC;
```

Pour A3 et A4, un seul appel peut être trop rapide pour obtenir une mesure stable. Tu devras déterminer une méthode de répétition adaptée et calculer un temps moyen. Évite toutefois de répéter inutilement A1 et A2 sur de grands nombres premiers, car ces algorithmes peuvent prendre beaucoup de temps.

Compile A1, A2, A3 et A4 avec les mêmes options et dans le même environnement afin de rendre les résultats comparables. Note dans le rapport le compilateur et les options utilisés.

## 6. Organiser les expériences

1. Récupère auprès du membre chargé des données les jeux prévus dans le TP0.
2. Détermine quels jeux et quelles valeurs seront utilisés pour chaque algorithme.
3. Écris ton programme expérimental pour lire les valeurs, appeler les fonctions et mesurer les temps.
4. Enregistre les résultats bruts dans un format que tu pourras importer dans Excel (par exemple CSV).
5. Utilise les résultats pour compléter les tableaux et produire les graphes demandés dans le TP1.
6. Indique clairement toute valeur non mesurée ou ignorée ; ne la présente pas comme un temps d'exécution.

## 7. Précaution importante : les grands nombres

A1 teste les diviseurs de 2 à `N-1`, A2 de 2 à `N/2`. Ces méthodes peuvent être extrêmement lentes pour les grands nombres premiers. A3 et A4 sont beaucoup plus adaptés aux grands nombres, mais le TP demande de comparer des approches volontairement différentes.
