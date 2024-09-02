**RESUME

**Generalites
Utilisez static_cast lorsque vous êtes sûr que les types sont compatibles.
Utilisez dynamic_cast pour les conversions de types polymorphiques et vérifiez toujours le résultat.
Évitez d'utiliser reinterpret_cast sauf si c'est absolument nécessaire, car il peut entraîner des comportements indéfinis.
Utilisez const_cast avec prudence, car il peut violer la constance et entraîner des comportements imprévisibles.


**GESTION DES ERREURS

les différents types de cast (static_cast, dynamic_cast, reinterpret_cast) ont des comportements distincts lorsqu'ils échouent. Voici un résumé des exceptions qui peuvent être lancées par chacun :

1. static_cast
Comportement : static_cast effectue des conversions à la compilation lorsque les types sont compatibles. Cela inclut des conversions entre types arithmétiques, des conversions explicites entre types de pointeurs, ou des conversions vers un type dérivé ou de base.
Exceptions : static_cast ne lance pas d'exceptions. Si la conversion n'est pas possible (par exemple, essayer de caster un pointeur vers un type dérivé qui n'est pas réellement dérivé du type de base), le résultat peut être indéfini (mais il n'y aura pas d'exception).
2. dynamic_cast
Comportement : dynamic_cast est utilisé principalement pour les conversions sécurisées dans une hiérarchie de classes polymorphiques (celles qui ont au moins une fonction membre virtuelle).
Exceptions :
Si vous essayez de convertir un pointeur vers un type qui ne correspond pas au type cible, dynamic_cast retourne un pointeur nullptr au lieu de lancer une exception.
Si vous essayez de convertir une référence vers un type incompatible (lors d'une conversion descendante dans la hiérarchie de classes), dynamic_cast lance une exception de type std::bad_cast.
3. reinterpret_cast
Comportement : reinterpret_cast effectue des conversions de bas niveau, sans vérification de type à la compilation ou à l'exécution. Il peut être utilisé pour convertir des pointeurs en types de données totalement non liés (par exemple, convertir un pointeur en un entier).
Exceptions : reinterpret_cast ne lance pas d'exceptions. Comme il n'y a pas de vérification du type, les résultats sont généralement dépendants de la plateforme et peuvent être indéfinis si la conversion n'est pas correcte.
Résumé
static_cast : Pas d'exception, mais peut mener à un comportement indéfini si utilisé de manière incorrecte.
dynamic_cast : Peut lancer std::bad_cast en cas d'échec lors de la conversion de référence. Retourne nullptr pour les conversions de pointeur échouées.
reinterpret_cast : Pas d'exception, mais le résultat peut être indéfini.


**FONCTIONNEMENT

**static_cast<T>(e)
Fait au moment de la compilation, ou du moins aussi tôt que possible (car pour une conversion d'un nombre entier à un nombre à virgule flottante, il faut quand même travailler un peu à l'exécution), et relativement sécuritaire. Par défaut, c'est probablement celui que vous voudrez privilégier.

On l'utilise :
Pour clarifier des conversions autrement implicites
Quand une conversion est naturelle (float vers int, Enfant vers Parent)
Pour lever une ambiguïté. Par exemple, un enfant a deux parents, qui ont chacun un parent du même type, et on veut traiter l'enfant comme son ancêtre, donc comme l'un de ses grands-parents
Quand une conversion parent à enfant, normalement risquée, est telle que le programmeur sait qu'elle est correcte (et assume l'erreur s'il y a lieu). Prudence!



**dynamic_cast<T>(e)
Fait au moment de l'exécution, sécuritaire, mais demande une certaine prudence méthodologique.

On l'utilise pour des conversions entre pointeurs ou références quand les types source et destination de la conversion sont apparentés, donc qu'ils ont en commun un parent, un enfant, une soeur, etc. et quand la classe source a au moins une méthode polymorphique. Le coût de cette conversion est indéterministe a priori, donc elle est en général proscrite dans un système temps réel (quoique...) mais elle est préférable à une vérification « manuelle » qui chercherait à faire la même chose.



**reinterpret_cast<T>(e)
Produit une valeur temporaire, qui devrait être reconvertie pour être utilisée proprement. Malsain, mais c'est parfois ce dont on a besoin. N'a de sens que sur les pointeurs, et ses résultats ne sont pas portables.

On l'utilise quand on manipule des abstractions de très bas niveau, souvent quand on utilise des services du système d'exploitation ou quand on travaille près du matériel. Il importe de manipuler cette conversion avec prudence.



**const_cast<T>(e)
Voir cette section pour des détails. Se débarrasse ou ajoute temporairement d'une qualification const ou volatile.

On l'utilise souvent quand on interopère avec un outil qui n'est (tristement) pas const-correct, mais aussi quand on sait des choses que le compilateur ne sait pas. La prudence est de mise.