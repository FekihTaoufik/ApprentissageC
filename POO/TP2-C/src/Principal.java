
public class Principal {

	public static void main(String[] args) {
/*
  La belote
 
Implanter une classe Carte qui représente une carte pour le jeu de belote:

Les couleurs sont TREFLE, PIQUE, CARREAU, COEUR
Les valeurs sont 7, 8, 9, 10, VALET, DAME, ROI, AS
On implantera seulement la version vue en cours qui utilise le mot clé enum.

On veut:

connaître la valeur d'une carte selon qu'elle soit à l'atout ou non;
*étant données quatre cartes, 
on veut savoir quelle est la carte la plus forte?
*étant données quatre cartes, 
on veut savoir quelle est la carte la plus forte, en fonction de l'atout?
 */
		// Partie 1
		Carte C = new Carte (Couleur.PIQUE,Valeur.VALET,true);
		System.out.println(C);
		// Partie 2
		Carte T[] = {
				new Carte (Couleur.PIQUE,Valeur.HUITE,true),
				new Carte (Couleur.CARREAU,Valeur.DIX),
				new Carte (Couleur.COEUR,Valeur.DAME,true),
				new Carte (Couleur.TREFLE,Valeur.VALET)
				};
		Carte laPlusForte = T[0];  
		
		for (int i = 1; i < 4; i++) {
			  if(laPlusForte.valeur()<T[i].valeur())
				  laPlusForte = T[i];
		  }
		System.out.println("La carte la plus forte : " + laPlusForte);

		// Partie 3
		Carte T2[] = {
				new Carte (Couleur.PIQUE,Valeur.HUITE,true),
				new Carte (Couleur.CARREAU,Valeur.DIX,true),
				new Carte (Couleur.COEUR,Valeur.DAME,true),
				new Carte (Couleur.TREFLE,Valeur.VALET,true)
				};
		laPlusForte = T2[0];  
		
		for (int i = 1; i < 4; i++) {
			  if(laPlusForte.valeur()<T2[i].valeur())
				  laPlusForte = T2[i];
		  }
		System.out.println("La carte la plus forte : " + laPlusForte);
	}

}
