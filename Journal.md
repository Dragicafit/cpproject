------------------
# Journal de bord
------------------
## Date : 05/02/2020
### Travail effectué:
Aujourd'hui, nous avons commencé par discuter d'une possible implementation du projet, et de ce que nous allions devoir faire.
Nous avons défini comment implementer les différents objets.

Class robot:			
Position			        | #define missile_max( 2)
Vitesse (pourcentage)		| #define size (10x10)
Dégâts (pourcentage)		| #define vitesse_max (10)
Nb missiles en cour 		| #define collision (2%)
Script				        |
Mort (boolean)			    |

Class missile :
Position			| #define vitesse (500)
Position_depart	    | #define distance_max (7000)
				    | #define d_400 (3%)
				    | #define d_200 (5%)
				    | #define d_50 (10%)

Class arene:
Liste robot (max_robot)	|#define x (10 000)
Liste missile			|#define y (10 000)
					    | #define robot (4)


### Travail à faire:

Implementer les class ci-dessus et reflechir à l'implementation du cycle.
