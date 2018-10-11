
public class Vecteur {
	private double x,y;
	Vecteur(double x,double y){
		this.x = x;
		this.y = y;
	}
	Vecteur multiplierPar(double k) {
		return new Vecteur(this.x *k,this.y *k);
	}
	Vecteur additionner(Vecteur v) {
		return new Vecteur(this.x +v.getX(),this.y+v.getY());
	}
	Vecteur transposer() {
		return new Vecteur(this.y,this.x);
	}
	double produitScalaire(Vecteur v) {
		return this.x * v.getX() + this.y * v.getY();
	}
	double getX() {
		return this.x;
	}
	double getY() {
		return this.y;
	}
	public String toString() {
		return "Vecteur("+this.x+","+this.y+")";
	}
}
