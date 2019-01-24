package fr.unice.abr;

public class Noeud {
	private int valeur;
	private Noeud n_droite;
	private Noeud n_gauche;

	public Noeud(int val) { valeur = val;}
	public Noeud(int val,Noeud n1,Noeud n2) {
		valeur =val;
		n_droite = n1;
		n_gauche = n2;
	}
	
	public Noeud get_n_droite() {return n_droite;}
	public Noeud get_n_gauche() {return n_gauche;}
	
	public void set_n_droite(Noeud n) {this.n_droite=n;}
	public void set_n_gauche(Noeud n) {this.n_gauche=n;}
	
	public int get_valeur() { return valeur;}
	public void set_valeur(int val) { valeur = val;}
	
	public String toString() {
		return "[Valeur : "+this.valeur+", Noeud droite : "+n_droite+", Noeud gauche : "+n_gauche+"]" ;
		}
}
