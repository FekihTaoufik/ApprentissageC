
public class Code39 {
	String chaine ;
	static String charCode[] = {"100001001","001001001","101001000","000011001","100011000","001011000","000001101","100001100","001001100","000011100","100000011","001000011","101000010","000010011","100010010","001010010","000000111","100000110","001000110","000010110","110000001","011000001","111000000","010010001","110010000","011010000","000110100","100100001","001100001","101100000","000110001","100110000","001110000","000100101","100100100","001100100","011000100","010000101","010101000","000101010","110000100","010100010","010001010","010010100"};
	static char allowedChars[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9',' ','-','$','%','.','/','+','*'};
	Code39(String chaine){
		this.chaine = '*'+chaine+'*';
	}
	String encoderChar(char c){
		for (int i = 0; i < allowedChars.length; i++) {
			
			if(allowedChars[i] == c) {
				//System.out.println(allowedChars[i]+"|"+charCode[i]);
				return charCode[i];
			}
				
		}
		return "";
	}
	String message() {
		String s ="";
			for (int i = 0; i < chaine.length(); i++) {
				System.out.println(encoderChar(Character.toUpperCase(chaine.charAt(i))));
				s+=encoderChar(chaine.charAt(i));
			}
			System.out.println(s);
		return s;
	}
	public String toString() {
		for (int i = 0; i < chaine.length(); i++) {
			
		}
		return "";
	}
	
}
