class Tortue {

	double x;
	double y;
	double orientation;
	boolean lever;
	
	public Tortue(double x, double y, double orientation, boolean lever) {
		this.x = x;
		this.y = y;
		this.orientation = orientation;
		this.lever = lever;
	}
	
	public void avance(double d) {
		this.x += d * Math.round(Math.cos(orientation));
		this.y += d * Math.round(Math.sin(orientation));
	}
	
	public void recule(double d) {
		this.x -= d * Math.round(Math.cos(orientation));
		this.y -= d * Math.round(Math.sin(orientation));
	}
	
	public void tourneGauche(double degré) {
		this.orientation += degré*Math.PI/180;
	}
	
	public void tourneDroite(double degré) {
		this.orientation -= degré*Math.PI/180;
	}

	public void inclinaisonStylo() {
		if (lever == true)
			lever = false;
		else
			lever = true;
	}
		
	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	public void setY(double y) {
		this.y = y;
	}

	public double getOrientation() {
		return orientation;
	}

	public void setOrientation(double orientation) {
		this.orientation = orientation;
	}

	public boolean isLever() {
		return lever;
	}

	public void setLever(boolean lever) {
		this.lever = lever;
	}
	
	@Override
	public String toString() {
		return "Tortue [x=" + x + ", y=" + y + ", orientation=" + orientation + ", lever=" + lever + "]";
	}

}
