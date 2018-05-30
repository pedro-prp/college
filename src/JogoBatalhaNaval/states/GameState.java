package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

import JogoBatalhaNaval.LoadMap;
import JogoBatalhaNaval.Check.MatrixCampo;
import JogoBatalhaNaval.grafico.MapGfx;
import JogoBatalhaNaval.Jogo;

public class GameState extends State{	
	int x=0;
	int y=0;
	public GameState() {
		
	}
	public void init() {
		
	}

	@Override
	public void atualiza() {
		x++;
		y++;
		if(Jogo.getMouse().getBotao()) {
			System.out.println(Jogo.getMouse().getX() + " " + Jogo.getMouse().getY());
			int tam=46;
			int i=(((Jogo.getMouse().getX()-MapGfx.deltaX)/tam));
			int	j=(((Jogo.getMouse().getY()-MapGfx.deltaY)/tam));
			System.out.println("flag 1");
			
			System.out.println(i);
			
			boolean quadradoPossivel = (i<Jogo.getAlturaCampo() && j<Jogo.getLarguraCampo());
			boolean mouseXYNaoNegativo = ((Jogo.getMouse().getX()-MapGfx.deltaX) > 0) && ((Jogo.getMouse().getY()-MapGfx.deltaY) > 0);
			
			boolean mouseNoCampo = quadradoPossivel && mouseXYNaoNegativo;
			
			if(mouseNoCampo) {
		
				//if(MatrixCampo.getMatrixBoolean(j,i)) {
					MatrixCampo.setMatrixBooleanPress(j, i);
			
			}
		}
		
	}

	@Override
	public void desenha(Graphics grafico) {
		
		grafico.setColor(Color.BLACK);
		
		
		grafico.setColor(Color.DARK_GRAY);
		grafico.fillRect(0, 0, 754, 754);
		
		grafico.setColor(Color.BLACK);
		grafico.fillRect(MapGfx.deltaX-5,MapGfx.deltaY-5,Jogo.getLarguraCampo()+10,Jogo.getAlturaCampo()+10);
		//grafico.setColor(Color.black);
		MapGfx.desenhaMap(grafico);
		//grafico.fillRect(x, y, 20, 20);
	}
}
