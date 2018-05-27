package JogoBatalhaNaval.states;

import java.awt.Graphics;

import JogoBatalhaNaval.LoadMap;
import JogoBatalhaNaval.grafico.Assets;

public class GameState extends State{
	
	public GameState() {
		
	}

	@Override
	public void atualiza() {
		
		
	}

	@Override
	public void desenha(Graphics grafico) {
		
		int i = 0,j=0;
		
		int tamX=0,tamY=0;
		int a = Integer.parseInt(LoadMap.largura),
			b = Integer.parseInt(LoadMap.altura);
		int x=50,y=50;
		
		if((500%a==0) && (500%b==0)) {
			System.out.println("se fudeu");
			tamX = 500/a;
			tamY = 500/b;
		}else {
			boolean divisao = true;
			int n=1;
			while(divisao) {
				if((500%(a-n)==0) && (500%(b-n)==0)) {
					divisao = false;
					n++;
				}
			}
		}
		
		//System.out.println(a);
		//System.out.println(b);
		
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
		
		//grafico.fillRect(0, 0, 400, 400);
	}
}
