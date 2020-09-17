package JogoBatalhaNaval.grafico;

import java.awt.Color;
import java.awt.Graphics;

import JogoBatalhaNaval.Jogo;

public class BackgroundGfx {
	public static void desenhaBackground(Graphics grafico) {
		grafico.setColor(Color.BLACK);
		grafico.fillRect(0, 0, 754, 754);
		grafico.setColor(Color.DARK_GRAY);
		grafico.fillRect(2, 2, 955, 750);
		grafico.setColor(Color.BLACK);
		grafico.fillRect(((MapGfx.deltaX)-5),((MapGfx.deltaY)-5),Jogo.getLarguraCampo()+10,Jogo.getAlturaCampo()+10);
	}
}
