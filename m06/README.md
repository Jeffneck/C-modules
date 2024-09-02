
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