
public class Carte {
 Couleur c ;
 Valeur v ;
 boolean atout=false;
 Carte(Couleur c , Valeur v){
	 this.c = c;
	 this.v =v;
 }
 Carte(Couleur c , Valeur v,boolean atout){
	 this.c = c;
	 this.v =v;
	 this.atout=atout;
 }
 public int valeur () {
	 if(!this.atout) {
			 switch (this.v) {
				 case AS:  return 11;
				 case DIX:  return 10;
				 case ROI:  return 4;
				 case DAME:  return 3;
				 case VALET:  return 2;
				 default: return 0;
			 }
		 }
		 else {
			 switch (this.v) {
				 case AS:  return 11;
				 case DIX:  return 10;
				 case ROI:  return 4;
				 case DAME:  return 3;
				 case VALET:  return 20;
				 case NEUF:  return 14;
				 default: return 0;
			 }
			 
 }
 }
 
 public String toString() {
	return "Carte ("+this.c+","+this.v+","+this.valeur()+")"; 
 }
}
