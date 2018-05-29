package JogoBatalhaNaval.grafico;

import java.awt.Graphics;

import JogoBatalhaNaval.LoadMap;
import JogoBatalhaNaval.Check.MatrixCampo;

public class MapGfx {
	
	public static void desenhaMap(Graphics grafico) {

		int i = 0,j=0;
		int tam=47;
		int a = Integer.parseInt(LoadMap.largura),
			b = Integer.parseInt(LoadMap.altura);
		int x=25,y=25;
		
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
			y=25;
			i++;
			x+=tam;
		}
	}
}
