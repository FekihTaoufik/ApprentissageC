
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
/* 
 * Un Vecteur2D v est un objet qui a deux composantes v=< x, y >.
On sait lire la valeur de chacune des deux composantes x et y
On NE sait PAS modifier les valeurs des composantes d'un vecteur 
On sait multiplier un Vecteur v par un scalaire k (un nombre approché) 
pour obtenir un AUTRE vecteur k * v = < k*x, k*y >
On sait calculer le produit scalaire de deux vecteurs v1 et v2 pour 
obtenir un scalaire :  v1 * v2 = v1.x * v2.x + v1.y * v2.y
On sait transposer un vecteur v pour obtenir un AUTRE vecteur  vt = < y, x >
On sait ajouter deux vecteurs  v1 et v2 pour obtenir un AUTRE 
vecteur :  v1 + v2 = < v1.x + v2.x, v1.y + v2.y >
On sait afficher de manière textuelle les composantes d'un vecteur 
(méthode toString).
Proposer une classe Vecteur2D qui réalise toutes les opérations
 décrites ci-dessus.
 * */
		
		Vecteur v1 = new Vecteur(1,2);
		Vecteur v2 = new Vecteur(3,3);
		
		System.out.println(v1.produitScalaire(v2));
		
		
	}

}
