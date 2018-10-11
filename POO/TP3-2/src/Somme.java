import java.util.Arrays;

public class Somme {
	Somme (String ... args){
		System.out.println("Creation somme");
		int somme =0;
		Arrays.sort(args);
		for (int i = 0; i < args.length; i++) {
		    String arg = args[i];
		    int x = Integer.parseInt(args[i]);
		    System.out.println(arg);
		    somme+=x;
		}
		System.out.println("Somme : "+somme);
	}
}
