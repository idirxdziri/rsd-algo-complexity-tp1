# Guide pour les membres du groupe

## 1. Objectif

Le TP demande de résoudre le même problème — déterminer si un entier naturel est premier — avec quatre approches successives, puis de comparer leur comportement expérimental. Les quatre versions doivent rester distinctes : l'objectif n'est pas simplement d'écrire quatre noms pour un même algorithme optimisé.

## 2. Les quatre algorithmes

### A1 — Approche naïve

Tester les diviseurs `2, 3, ..., N-1`. Si l'un divise `N`, le nombre est composé. Sinon, il est premier.

Complexité temporelle au pire cas : **O(N)**. Espace supplémentaire : **O(1)**.

### A2 — Borne N/2

Un diviseur propre de `N` ne peut pas être supérieur à `N/2`. On teste donc les diviseurs de `2` à `N/2`.

Complexité temporelle au pire cas : **O(N)**. Espace supplémentaire : **O(1)**. A2 effectue moins d'itérations qu'A1, mais reste dans la même classe asymptotique.

### A3 — Borne racine carrée

Si `N` est composé, il possède au moins un diviseur inférieur ou égal à `sqrt(N)`. On peut arrêter la recherche à cette limite.

Le code utilise la condition `i <= N / i` plutôt que `i * i <= N`. Pour `N >= 2` et `i > 0`, ces conditions expriment la même limite, mais la division évite un dépassement de capacité dans le produit.

Complexité temporelle au pire cas : **O(√N)**. Espace supplémentaire : **O(1)**.

### A4 — Diviseurs impairs

Dans le prolongement d'A3, le code traite d'abord les nombres pairs : `2` est premier, tout autre nombre pair supérieur à `2` est composé. Pour un nombre impair, il teste uniquement `3, 5, 7, ...` jusqu'à `sqrt(N)`.

Complexité temporelle au pire cas : **O(√N)**. Espace supplémentaire : **O(1)**.

**Interprétation retenue :** le TP présente A4 après A3 et indique de copier le programme précédent avant de le modifier. A4 est donc implémenté ici comme A3 avec l'élimination des diviseurs pairs. Cette interprétation est cohérente avec la progression du sujet ; le texte d'A4 ne répète toutefois pas explicitement la borne `sqrt(N)`.

## 4. Qui utilise quoi ?

- **Personne chargée des données :** prépare les jeux de données demandés dans le TP0. Cette responsabilité est distincte du code des quatre fonctions.
- **Personne chargée des algorithmes :** maintient `primalite.c` et `primalite.h`.
- **Personne chargée des tests expérimentaux :** crée ou adapte son programme de mesure et appelle les fonctions à travers `primalite.h`. Elle chronomètre à l'extérieur des fonctions.
- **Personne chargée du rapport :** explique les principes, ajoute les mesures réalisées par le groupe et compare les courbes avec les complexités théoriques.

## 5. Conseils pour les mesures

Pour comparer équitablement les algorithmes, utilisez le même jeu de données et des conditions de compilation comparables. Évitez d'inclure les affichages console dans la portion chronométrée. Les appels A1/A2 peuvent être très longs pour les grands nombres premiers, car ils sont volontairement moins efficaces. Il est normal d'organiser les expériences prudemment ;

Le programme `main.c` fourni est uniquement une démonstration, pas l'outil de benchmarking final. Pour compiler le programme de mesure d'un camarade, liez son propre fichier source avec `primalite.c`, et n'ajoutez pas `main.c` à cette compilation.
