package JogoBatalhaNaval.grafico;

import java.awt.Graphics;

import JogoBatalhaNaval.Jogo;
import JogoBatalhaNaval.LoadMap;
import JogoBatalhaNaval.Check.MatrixCampo;

public class MapGfx {
	
	public static int deltaX=(754/2)-(Jogo.getLarguraCampo()/2);
	public static int deltaY=(754/2)-(Jogo.getAlturaCampo()/2);
	
	public static void desenhaMap(Graphics grafico) {

		int i = 0,j=0;
		int tam=47;
		int a = Integer.parseInt(LoadMap.largura),
			b = Integer.parseInt(LoadMap.altura);
		
		int x = deltaX,
			y = deltaY;
		
		
		
		while(i< a) {
			while(j< b) {
				if(MatrixCampo.getMatrixBooleanPress(j,i)) {
					if(MatrixCampo.getMatrixBoolean(j, i)) {
						int barco = MatrixCampo.getMatrixInt(j, i);
						grafico.drawImage(Assets.barcos[barco],x,y,tam,tam,null);
					}else {
						grafico.drawImage(Assets.campoF,x,y,tam,tam,null);
					}
				
				}else {
					grafico.drawImage(Assets.campo, x, y,tam,tam,null);
				}
				j++;
				y+=tam;
			}
			j=0;
			y=deltaY;
			i++;
			x+=tam;
		}
	}
}
