package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

public class FinalState extends State{

	@Override
	public void atualiza() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void desenha(Graphics grafico) {
		System.out.println("jose");
		grafico.setColor(Color.BLACK);
		grafico.fillRect(0, 0, 955,754);
		
	}

}
