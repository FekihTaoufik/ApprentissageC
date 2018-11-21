package fr.unice.abr;

public class TestNoeud {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Noeud n1 = new Noeud(1);
		Noeud n2 = new Noeud(2);
		Noeud n = new Noeud(1,n1,n2);
		System.out.println(n);
	}

}
