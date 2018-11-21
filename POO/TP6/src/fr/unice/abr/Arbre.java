package fr.unice.abr;

public class Arbre {
	public static Noeud n_racine;
	public Arbre(int val) {
		n_racine = new Noeud(val);
	}
	
	public void ajouter_valeur(int val) {
		Noeud n = new Noeud(val);
		Noeud courant = n_racine;
		Noeud old = null;
		while(true){
			old = courant;
			if(val<courant.get_valeur()){				
				courant = courant.get_n_gauche();
				if(courant==null){
					old.set_n_gauche(n);
					return;
				}
			}else{
				courant = courant.get_n_droite();
				if(courant==null){
					old.set_n_droite(n);
					return;
				}
			}
		}
	}
	
	public boolean existe_dans_arbre(int val) {

		Noeud courant = n_racine;
		Noeud old = null;
		if(courant.get_valeur()==val)
			return true;
		while(true){
			if(courant == null)
				return false;
			old = courant;
			if(val<courant.get_valeur()){				
				courant = courant.get_n_gauche();
				if(courant!=null)
					if(courant.get_valeur()==val)
						return true;
			}else{
				courant = courant.get_n_droite();
				if(courant!=null)
					if(courant.get_valeur()==val)
						return true;
			}
		}
	}
	public void afficher() {
		this.afficher_arbre(n_racine);
	}
	private void afficher_arbre(Noeud n) {
		if(n!=null){
			afficher_arbre(n.get_n_droite());
			System.out.print("|" + n.get_valeur());
			afficher_arbre(n.get_n_gauche());
		}
	}
	
	public void parcourir() {
		
	}
	
}
