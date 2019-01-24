
import java.util.Arrays;
public class test {
		
	static int rechercheClassique(int x, int t[]) {
		for (int i = 0; i < t.length; i++) 
			if(x == t[i])
				return i;
		return -1;
	}

	static int rechDich(int x, int t[], int debut, int fin)
	{
	     if((fin-debut)<=0)
	    	 return -1;
	     int milieu = (debut+fin)/2;
	     if(x == t[milieu]) 
	          return milieu;
	     else
	     {
	          if (x < t[milieu]){ 
	              return rechDich(x, t, debut, milieu-1);}
	          else{
	              return rechDich(x, t, milieu+1, fin);}
	     }
	}
	static int rechercheDic (int [] T , int e) {
		Arrays.sort(T);
		return rechDich(e,T,0,T.length);
	}
	public static void main(String[] args) {
/*
Recherche
Regardez la documentation de la méthode Arrays.binarySearch discutée en cours. 
Cette méthode renvoie l'indice d'un élément e dans un tableau t. Si l'élément e n'est pas présent dans t alors la méthode renvoie la valeur -1. 
Le seul problème est que le tableau est supposé être trié auparavant. 

Comment faire si le tableau n'est pas trié ? Oui on pourrait le trier (mais cela coûte cher).

Implanter plutôt une méthode recherche qui ne suppose pas que le tableau d'entier est trié ?
Dans le pire des cas quel est le coût de cette opération ?
Est-ce important que le tableau contienne des entiers ? 
Proposer une méthode rechercheDichotomique qui permet de trouver un entier lorsque le tableau est ordonné. 
On pourra utiliser la méthode Arrays.sort pour trier le tableau d'entier (avant d'appeler la méthode). 
Par contre, il est INTERDIT d'utiliser la méthode Arrays.binarySearch et il faudra ré-implanter cette méthode. 
On rappelle pour cela le principe de la recherche dichotomique. 
Je cherche l'indice de l'élément e dans t du début (inclus) à la fin (exclus):

Si j'ai un tableau vide alors je ne peux pas trouver la valeur e
Sinon Je compare e à l'élément qui se trouve au milieu t[milieu]  
Si t[milieu] == e, j'ai terminé et je renvoie l'indice milieu
Si t[milieu] < e, je recommence en 1 et cherche l'élément e entre le milieu (exclus) et la fin  
Si t[milieu] > e, je recommence en 1 et cherche l'élément e entre le début et le milieu (exclus)
 */
		int [] T = {1,2,3,4,5,6,7};

		System.out.println(rechercheDic(T,18));

	}

}
