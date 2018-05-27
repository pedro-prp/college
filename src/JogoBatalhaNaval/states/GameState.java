package JogoBatalhaNaval.states;

import java.awt.Graphics;

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
		
		MapGfx.desenhaMap(grafico);
		grafico.fillRect(x, y, 20, 20);
	}
}
