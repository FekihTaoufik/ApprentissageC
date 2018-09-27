import java.util.Random;

public class Test {

	public static void main(String[] args) {
		Random r = new Random();
		// n>0
		// b>a
		int a,b,n;
		// 1. Générer pseudo-aléatoirement un nombre entier dans l'intervalle [0; 50]
		a = 0;
		b=50;
			System.out.println(r.nextInt(b+1));
			System.out.println((int)Math.floor(Math.random() * b+1));
		// 2. Générer pseudo-aléatoirement un nombre entier dans l'intervalle ]-20; 50]
			a=-20;
			b=50;
			System.out.println((int)(a+1) + Math.random() * (Math.abs(a+1)+b));
		// 3. Générer pseudo-aléatoirement un nombre entier dans l'intervalle [a;b]
		// 4. Générer pseudo-aléatoirement un nombre entier pair dans l'intervalle [a; b]
		// 5. Générer pseudo-aléatoirement un nombre entier multiple de n dans l'intervalle [a; b]
	}

}
