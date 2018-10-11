
public class Test {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
/*
Un vecteur généralisé de dimension n est un vecteur qui a n composantes. Les mêmes opérations que que sur le vecteur 2D sont possibles.

Les vecteurs sont construits de deux façons différentes:

Soit en donnant la valeur dans chaque composante, la dimension est déterminée en fonction du nombre "variable" de composantes
new Vecteur(12, 23, 40) construit un vecteur de dimension 3
new Vecteur(12) provoque une erreur (il n'est pas possible de construire un vecteur avec 1 seule composante !)
new Vecteur(64, 0, 12, 23) construit un vecteur de dimension 4
Soit en donnant en donnant la dimension et une partie (éventuellement nulle) des valeurs des composantes, 
Les autres composantes sont alors initialisées à zéro
new Vecteur(4, new int[]{}); construit un vecteur de dimension 4 avec toutes les composantes à zéro
new Vecteur(2, new int[]{4, 5, 6}); provoque une erreur, il y a plus de valeurs initiales que de composantes !
new vecteur(3, new int[]{10, 20}); construit le vecteur à 3 dimensions suivants : <10, 20, 0>
Proposer une classe Vecteur.
 */
		Vecteur v2 = new Vecteur(5, new int[]{4, 5, 6});
		
		System.out.println(v2);
		
	}

}
