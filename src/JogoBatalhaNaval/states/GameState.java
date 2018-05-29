package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

import JogoBatalhaNaval.LoadMap;
import JogoBatalhaNaval.grafico.MapGfx;

public class GameState extends State{
	
	private int x=0,y=0;
	
	public GameState() {
		
	}

	@Override
	public void atualiza() {
		x++;
		y++;
		
	}

	@Override
	public void desenha(Graphics grafico) {
		
		grafico.setColor(Color.DARK_GRAY);
		grafico.fillRect(0, 0, (Integer.parseInt(LoadMap.largura)*52)+250, (Integer.parseInt(LoadMap.altura)*52)+50);
		grafico.setColor(Color.black);
		grafico.fillRect(20,20,(Integer.parseInt(LoadMap.largura)*52)+10,(Integer.parseInt(LoadMap.altura)*52)+10);
		grafico.setColor(Color.black);
		MapGfx.desenhaMap(grafico);
		grafico.fillRect(x, y, 20, 20);
	}
}
