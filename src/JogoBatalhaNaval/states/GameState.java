package JogoBatalhaNaval.states;

import java.awt.Graphics;

import JogoBatalhaNaval.grafico.MapGfx;

public class GameState extends State{
	
	public GameState() {
		
	}

	@Override
	public void atualiza() {
		
		
	}

	@Override
	public void desenha(Graphics grafico) {
		
		MapGfx.desenhaMap(grafico);
		
	}
}
