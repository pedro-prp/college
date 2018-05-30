package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

import JogoBatalhaNaval.Check.MatrixCampo;
import JogoBatalhaNaval.Check.NavioPart;
import JogoBatalhaNaval.Check.Botao;
import JogoBatalhaNaval.grafico.Assets;
import JogoBatalhaNaval.grafico.MapGfx;
import JogoBatalhaNaval.Jogo;
import JogoBatalhaNaval.LoadMap;

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
			
			boolean botaoTiroLinha = (Jogo.getMouse().getX() > 826 && Jogo.getMouse().getX() < 878) && 
			   		   (Jogo.getMouse().getY() > 30 && Jogo.getMouse().getY() < 82);
			
			if(mouseNoCampo && (Botao.getBotaotiroSimplesPress() || Botao.getBotaotiroLinhaPress())) {
					
					//Ações dos botões
					if(Botao.getBotaotiroSimplesPress()) {
						if(!MatrixCampo.getMatrixBooleanPress(j, i)) {
							MatrixCampo.setMatrixBooleanPress(j, i);
							System.out.println(NavioPart.checkBarcoContinua(j, i));
						}else {
							return;
						}
					}else if(Botao.getBotaotiroLinhaPress()) {
						if(!MatrixCampo.getMatrixBooleanPress(j, i)) {
							int a = 0;
							while(a < Integer.parseInt(LoadMap.largura)) {
								MatrixCampo.setMatrixBooleanPress(j, a);
								a++;
							}
							
						}else {
							return;
						}
					}
					
					//reset de seleção dos botões 
					Botao.setBotaoTiroSimplesPress(false);
					Botao.setBotaoTiroLinhaPress(false);
			}else if(botaoTiroSimples) {
				
				Botao.setBotaoTiroSimplesPress(true);
				System.out.println("Flag do esquisofrenico");
			}else if(botaoTiroLinha) {
				Botao.setBotaoTiroLinhaPress(true);
				System.out.println("Flag do Jose Playboy");
			}
		}
		
	}

	@Override
	public void desenha(Graphics grafico) {
		
		//desenho do background
		grafico.setColor(Color.BLACK);
		grafico.fillRect(0, 0, 754, 754);
		grafico.setColor(Color.DARK_GRAY);
		grafico.fillRect(2, 2, 750, 750);
		grafico.setColor(Color.BLACK);
		grafico.fillRect(((MapGfx.deltaX)-5),((MapGfx.deltaY)-5),Jogo.getLarguraCampo()+10,Jogo.getAlturaCampo()+10);
		
		//desenho do mapa
		MapGfx.desenhaMap(grafico);
		
		//desenho dos botoes
		if(!Botao.getBotaotiroSimplesPress()) {
			grafico.drawImage(Assets.tiroSimples,764, 30,null);
		}else {
			grafico.drawImage(Assets.tiroSimplesPress,764, 30,null);
		}
				
		if(!Botao.getBotaotiroLinhaPress()) {
			grafico.drawImage(Assets.tiroLinha,826,30,null);
		}else {
			grafico.drawImage(Assets.tiroLinhaPress,826,30,null);
		}
	}
}
