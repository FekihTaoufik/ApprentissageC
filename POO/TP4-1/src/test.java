import java.awt.Graphics;
import java.applet.*;
import java.awt.*;

public class test extends Applet {

	public void paint(Graphics g) {
		      //g.drawString("Welcome in Java Applet.",40,20);
		String ch = "JAVA 2012";
		Code39 c = new Code39(ch);
		int margeX = 50;
		int margeY = 50;
		int decalage=0;
		String code = c.message();
		boolean large,barre;
		for (int i=0;i<code.length();i++) {
			
			barre=i%2==0;
			large=code.charAt(i)=='1';
			
			g.setColor(new Color(0,0,0,barre?255:0));
			
		  	g.fillRect(margeX+decalage,margeY, large?6:3, 100);
		  	 
		  	decalage += large ? 6 :3 ;
		}
		g.drawString('*'+ch+'*', margeX, 220);
	  	
	   }

}
