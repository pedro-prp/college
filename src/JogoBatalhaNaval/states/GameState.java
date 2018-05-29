package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

import JogoBatalhaNaval.LoadMap;
import JogoBatalhaNaval.Check.MatrixCampo;
import JogoBatalhaNaval.grafico.MapGfx;
import JogoBatalhaNaval.Jogo;

public class GameState extends State{	
	public GameState() {
		
	}

	@Override
	public void atualiza() {
		//x++;
		//y++;
		if(Jogo.getMouse().getBotao()==true) {
			System.out.println(Jogo.getMouse().getX() + " " + Jogo.getMouse().getY());
			int tam=52;
			int i=(((Jogo.getMouse().getX()-25)/tam));
			int	j=(((Jogo.getMouse().getY()-25)/tam));
			
			System.out.println(i);
		
			if(MatrixCampo.getMatrixBoolean(j,i)) {
					MatrixCampo.setMatrixBooleanPress(j, i);
			}
		}
		
	}

	@Override
	public void desenha(Graphics grafico) {
		
		grafico.setColor(Color.DARK_GRAY);
		grafico.fillRect(0, 0, (Integer.parseInt(LoadMap.largura)*52)+250, (Integer.parseInt(LoadMap.altura)*52)+50);
		grafico.setColor(Color.black);
		grafico.fillRect(20,20,(Integer.parseInt(LoadMap.largura)*52)+10,(Integer.parseInt(LoadMap.altura)*52)+10);
		grafico.setColor(Color.black);
		MapGfx.desenhaMap(grafico);
		//grafico.fillRect(x, y, 20, 20);
	}
}
