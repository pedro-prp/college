package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

import JogoBatalhaNaval.Player.Mana;
import JogoBatalhaNaval.grafico.Assets;

public class FinalState extends State{

	@Override
	public void atualiza() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void desenha(Graphics grafico) {
		if(Mana.getMana() == 0) {
			grafico.drawImage(Assets.semMana,0,0,null);
		}else {
			grafico.drawImage(Assets.venceu,0,0,null);
		}
		
	}

}
