package fr.unice.abr;

public class TestArbreBinaire {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Arbre a = new Arbre(20);
		
		
		for (int i = 0; i <=((int)(Math.random()*100)); i++) 
			a.ajouter_valeur((int)(Math.random()*100));
		
		a.afficher();
		
	}

}
