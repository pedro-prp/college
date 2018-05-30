package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

import JogoBatalhaNaval.Check.MatrixCampo;
import JogoBatalhaNaval.Check.Botao;
import JogoBatalhaNaval.grafico.Assets;
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
			
			//System.out.println(i);
			
			boolean quadradoPossivel = (i<(Jogo.getLarguraCampo()/46) && j<(Jogo.getAlturaCampo()/46));
			boolean mouseXYNaoNegativo = ((Jogo.getMouse().getX()-MapGfx.deltaX) > 0) && ((Jogo.getMouse().getY()-MapGfx.deltaY) > 0);
			
			boolean mouseNoCampo = quadradoPossivel && mouseXYNaoNegativo;
			
			boolean botaoTiroSimples = (Jogo.getMouse().getX() > 764 && Jogo.getMouse().getX() < 816) && 
							   		   (Jogo.getMouse().getY() > 30 && Jogo.getMouse().getY() < 82);
			
			if(mouseNoCampo && Botao.getBotaotiroSimplesPress()) {
					MatrixCampo.setMatrixBooleanPress(j, i);
					Botao.setBotaoTiroSimplesPress(false);
			
			}
			else if(botaoTiroSimples) {
				
				Botao.setBotaoTiroSimplesPress(true);
				System.out.println("Flag do esquisofrenico");
			}
		}
		
	}

	@Override
	public void desenha(Graphics grafico) {
		
		grafico.setColor(Color.BLACK);
		grafico.fillRect(0, 0, 754, 754);
		if(!Botao.getBotaotiroSimplesPress()) {
			grafico.drawImage(Assets.tiroSimples,764, 30,null);
		}else {
			grafico.drawImage(Assets.tiroSimplesPress,764, 30,null);
		}
		
		
		grafico.setColor(Color.DARK_GRAY);
		grafico.fillRect(2, 2, 750, 750);
		
		grafico.setColor(Color.BLACK);
		//System.out.println(MapGfx.deltaX);
		grafico.fillRect(((MapGfx.deltaX)-5),((MapGfx.deltaY)-5),Jogo.getLarguraCampo()+10,Jogo.getAlturaCampo()+10);
		//grafico.setColor(Color.black);
		MapGfx.desenhaMap(grafico);
		//grafico.fillRect(x, y, 20, 20);
	}
}
