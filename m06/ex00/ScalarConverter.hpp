#pragma once

/*
Differentes manieres de creer une classe non-instanciable

**Constructeur privé : Empêche la création d'instances depuis l'extérieur de la classe.
Constructeur = delete : Supprime explicitement les constructeurs pour empêcher l'instanciation.
Classe abstraite : Utilise des méthodes pures virtuelles pour créer une classe que vous ne pouvez pas instancier directement.


Utiliser une methode contenue dans une classe non-instanciable (Constructeur prive)

**Méthodes statiques : Utilisez-les si vous n'avez pas besoin d'instances de la classe.
xMéthodes amies : Permettent à des fonctions ou classes spécifiques d'accéder aux membres privés.
xFonctions globales ou membres statiques : Encapsulent la logique d'utilisation des méthodes privées.
xPattern Singleton : Garantit qu'il n'y a qu'une seule instance de la classe et fournit un point d'accès global à cette instance.

Une méthode statique dans une classe en C++ est une méthode qui est associée à la classe elle-même plutôt qu'à une instance spécifique de cette classe. 
Cela signifie que vous pouvez appeler une méthode statique sans avoir besoin de créer une instance de la classe.

*/