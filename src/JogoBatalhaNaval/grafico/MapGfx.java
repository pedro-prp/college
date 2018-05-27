package JogoBatalhaNaval.grafico;

import java.awt.Graphics;

import JogoBatalhaNaval.LoadMap;

public class MapGfx {
	
	public static void desenhaMap(Graphics grafico) {
		grafico.fillRect(50, 50, 500, 500);
		
		int i = 0,j=0;
		
		int tamX=0,tamY=0;
		int a = Integer.parseInt(LoadMap.largura),
			b = Integer.parseInt(LoadMap.altura);
		int x=50,y=50;
		
		if(500%a==0){
			tamX = 500/a;
		}else{
			boolean divisao = true;
			int n=1;
			while(divisao) {
				if((500%(a+n)==0)) {
					tamX=500/(a+n);
					divisao = false;
				}
				n++;
			}
		}
		if(500%b==0) {
			tamY = 500/b;
		}else{
			boolean divisao = true;
			int n=1;
			while(divisao) {
				if(500%(b+n)==0) {
					tamY=500/(b+n);
					divisao = false;
				}
				n++;
			}
		}
		
		while(i< a) {
			while(j< b) {
				grafico.drawImage(Assets.campo, x, y,tamX,tamY,null);
				j++;
				y+=tamY;
			}
			j=0;
			y=tamY;
			i++;
			x+=tamX;
		}
	}
}
