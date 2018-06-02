package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

import JogoBatalhaNaval.Player.Mana;

public class FinalState extends State{

	@Override
	public void atualiza() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void desenha(Graphics grafico) {
		if(Mana.getMana() == 0) {
			grafico.setColor(Color.BLUE);
		}else {
			grafico.setColor(Color.BLACK);
		}
		grafico.fillRect(0, 0, 955,754);
		
	}

}
