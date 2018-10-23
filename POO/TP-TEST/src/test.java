
public class test {
	public static boolean test(int [] tab1,int[]tab2) {
		for(int i=0;i<(tab1.length-tab2.length+1);i++) {	
			for(int j=0;j<tab2.length;j++) {
				if(tab1[i+j]!=tab2[j]) 
					break;
				else if (j==(tab2.length-1))
					return true;			
			}
		}
		return false;
	}
	public static void main(String[] args) {
		int [] tab1 = {1,2,3,4,5,6,7};
		int [] tab2 = {5,6};
	
		System.out.println(test(tab2,tab1));
		
		
	}

}
