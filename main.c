#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "primalite.h"

typedef int (*FonctionPrimalite)(long long);

static int lire_entier(const char *texte, long long *valeur)
{
  char *fin = NULL;
  long long resultat;

  errno = 0;
  resultat = strtoll(texte, &fin, 10);

  if (texte == fin || *fin != '\0' || errno == ERANGE)
  {
    return 0;
  }

  *valeur = resultat;
  return 1;
}

static void afficher_usage(const char *nom_programme)
{
  fprintf(stderr,
          "Utilisation : %s <A1|A2|A3|A4> <N>\n"
          "Exemple     : %s A3 97\n\n"
          "Attention : A1 et A2 peuvent etre tres lents pour les grands N.\n",
          nom_programme, nom_programme);
}

int main(int argc, char *argv[])
{
  FonctionPrimalite fonction = NULL;
  long long n;
  const char *nom_algorithme;
  int resultat;

  if (argc != 3)
  {
    afficher_usage(argv[0]);
    return EXIT_FAILURE;
  }

  if (!lire_entier(argv[2], &n))
  {
    fprintf(stderr, "Erreur : N doit etre un entier valide.\n");
    afficher_usage(argv[0]);
    return EXIT_FAILURE;
  }

  if (strcmp(argv[1], "A1") == 0)
  {
    fonction = est_premier_A1;
    nom_algorithme = "A1 - approche naive";
  }
  else if (strcmp(argv[1], "A2") == 0)
  {
    fonction = est_premier_A2;
    nom_algorithme = "A2 - borne N/2";
  }
  else if (strcmp(argv[1], "A3") == 0)
  {
    fonction = est_premier_A3;
    nom_algorithme = "A3 - borne racine carree";
  }
  else if (strcmp(argv[1], "A4") == 0)
  {
    fonction = est_premier_A4;
    nom_algorithme = "A4 - diviseurs impairs jusqu'a la racine carree";
  }
  else
  {
    fprintf(stderr, "Erreur : algorithme inconnu '%s'.\n", argv[1]);
    afficher_usage(argv[0]);
    return EXIT_FAILURE;
  }

  resultat = fonction(n);
  printf("Algorithme : %s\n", nom_algorithme);
  printf("N          : %lld\n", n);
  printf("Resultat   : %s\n", resultat ? "premier" : "non premier");

  return EXIT_SUCCESS;
}
