
public abstract class AFormeGeometrique {
/*
 * une position d'ancrage que l'on peut lire et modifier ;
 * une aire ;
 * un périmètre.
 */
	private int position_ancrage;
	
	public int getPosition_ancrage() {
		return position_ancrage;
	}

	public void setPosition_ancrage(int position_ancrage) {
		this.position_ancrage = position_ancrage;
	}

	public AFormeGeometrique(int pa){
		position_ancrage=pa;
	}
	public double aire() {return 0;}
	public double perimetre() {return 0;}
	
	public String toString() {
		return "Forme [position ancrage : "+position_ancrage+", Aire : "+aire()+", Périmetre : "+perimetre()+"]";
	}
}
