package JogoBatalhaNaval.states;

import java.awt.Graphics;

import JogoBatalhaNaval.grafico.Assets;

public class GameState extends State{
	
	public GameState() {
		
	}

	@Override
	public void atualiza() {
		
		
	}

	@Override
	public void desenha(Graphics grafico) {
		grafico.fillRect(00, 0, 100, 100);
		grafico.drawImage(Assets.campo, 100, 100, null);
		
	}

}
