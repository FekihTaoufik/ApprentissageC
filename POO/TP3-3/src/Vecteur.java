import java.util.Arrays;


public class Vecteur {
	private int composants[];
	Vecteur () throws Exception{
		throw new Exception("il n'est pas possible de construire un vecteur avec 1 seule composante !");
	}
	Vecteur (int ... args) throws Exception{
		if(args.length<=1) 
			throw new Exception("il n'est pas possible de construire un vecteur avec 1 seule composante !");
		this.composants = Arrays.copyOf(args, args.length);
	}
	Vecteur (int nb , int args[]) throws Exception{
		if(args.length>nb) 
			throw new Exception("il y a plus de valeurs initiales que de composantes !");
		else if (args.length==nb) 
			this.composants = Arrays.copyOf(args, args.length);
		else {
			
			this.composants = Arrays.copyOf(args, nb);
		}
		
	}
	public String toString() {
		String S ="Vecteur("+this.composants[0];
		for(int i =1;i<this.composants.length;i++) {
			S+=(","+this.composants[i]);
		}
		return S+")";
		
	}
	
	Vecteur multiplierPar(double k) throws Exception {
		int compo[] = Arrays.copyOf(this.composants, this.composants.length);
		for(int i=0;i<compo.length;i++)
			compo[i]*=k;
		return new Vecteur(compo);
	}
	Vecteur transposer() throws Exception {
		int compos[] = Arrays.copyOf(this.composants, this.composants.length);
		int temp;
		for(int i = 0; i < this.composants.length / 2; i++) {
			temp = compos[i];
			compos[i] = compos[this.composants.length - i -1];
			compos[compos.length - i -1] =temp;
		}
		return new Vecteur(compos);
	}
	Vecteur additionner(Vecteur v) throws Exception {
		Vecteur vTemp;
		int compos[];
		if(this.composants.length>=v.getComposants().length) {
			compos = Arrays.copyOf(this.composants, this.composants.length);
			vTemp = new Vecteur(this.composants.length,v.getComposants());
		}else {
			compos = Arrays.copyOf(v.getComposants(), v.getComposants().length);
			vTemp = new Vecteur(v.getComposants().length,this.composants);
		}
			for( int i =0; i<compos.length;i++) 
				compos[i] += vTemp.getComposants()[i];
			
				
		return new Vecteur(compos);
	}
	double produitScalaire(Vecteur v) {
		int p = 0 ;
		for(int i =0 ; i<(this.composants.length>=v.getComposants().length?v.getComposants().length:this.composants.length);i++)
			p+=v.getComposants()[i]*this.composants[i];
		return p;
	}
	

	int[] getComposants() {
		return this.composants;
	}
}
