import java.util.Random;

public class Test {

	public static void main(String[] args) {
		Random r = new Random();
		// n>0
		// b>a
		int a,b,n;
		// 1. Générer pseudo-aléatoirement un nombre entier dans l'intervalle [0; 50]
			System.out.println("1. Random : "+r.nextInt(60));
			System.out.println("1. Random : "+((int)Math.floor(Math.random() * 60)));
		// 2. Générer pseudo-aléatoirement un nombre entier dans l'intervalle ]-20; 50]
			System.out.println("2. Random : "+(r.nextInt(50+19) -19));
			System.out.println("2. Math.random : "+(int)((-19) + Math.random() * (50+19)));
		// 3. Générer pseudo-aléatoirement un nombre entier dans l'intervalle [a;b]
			a = -19;
			b = 50;
			System.out.println("3. Random : "+(r.nextInt(b-a) + a));
			System.out.println("3. Math.random : "+(int)((a) + Math.random() * (50+19)));
		// 4. Générer pseudo-aléatoirement un nombre entier pair dans l'intervalle [a; b]
			a = -10;
			b = 0;
			System.out.println("4. Random : "+((r.nextInt(b-a)/2)*2 + a));
			System.out.println("4. Math.random : "+(int)((a) + Math.random() * ((b-a)/2)*2));
		// 5. Générer pseudo-aléatoirement un nombre entier multiple de n dans l'intervalle [a; b]
			a = 10;
			b = 21;
			n = 5;
			System.out.println("5. Random : "+((r.nextInt(b-a)/n)*n + a));
			System.out.println("5. Math.random : "+(int)((a) + Math.random() * ((b-a)/n)*n));
	}

}
