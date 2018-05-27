package JogoBatalhaNaval.grafico;

import java.awt.Graphics;

import JogoBatalhaNaval.LoadMap;

public class MapGfx {
	
	public static void desenhaMap(Graphics grafico) {

		int i = 0,j=0;
		int tam=52;
		int a = Integer.parseInt(LoadMap.largura),
			b = Integer.parseInt(LoadMap.altura);
		int x=25,y=25;
		
		while(i< a) {
			while(j< b) {
				grafico.drawImage(Assets.campo, x, y,null);
				j++;
				y+=tam;
			}
			j=0;
			y=25;
			i++;
			x+=tam;
		}
	}
}
