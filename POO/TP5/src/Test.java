import java.util.ArrayList;

public class Test {

	public static void main(String[] args){
		
		double x=0;
		double y=0;
		double orientation=0;
		boolean lever = false;
		ArrayList a = new ArrayList();

		System.out.println(a);
		Tortue lea = new Tortue(x,y,orientation,lever);
		
		lea.avance(10);
		lea.tourneGauche(90);
		lea.avance(10);
		lea.tourneGauche(90);
		lea.avance(10);
		lea.tourneGauche(90);
		lea.avance(10);
		
		//lea.recule(30);
		
		System.out.println(lea);
	}
	
}
