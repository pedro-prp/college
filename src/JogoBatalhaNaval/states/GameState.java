package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;
import JogoBatalhaNaval.Player.Habilidades;
import JogoBatalhaNaval.Check.Botao;
import JogoBatalhaNaval.Check.GanhouJogo;
import JogoBatalhaNaval.Check.MatrixCampo;
import JogoBatalhaNaval.grafico.Assets;
import JogoBatalhaNaval.grafico.MapGfx;
import JogoBatalhaNaval.Jogo;
import JogoBatalhaNaval.LoadMap;
import JogoBatalhaNaval.Audio.AudioAssets;
import JogoBatalhaNaval.Audio.OpenAudio;

public class GameState extends State{
	public static boolean somAtivo=false;
	//public static Clip barcoAfundou;
	public GameState() {
		
	}
	public static void init() {
		LoadMap.LerMapa(Jogo.path);
		MatrixCampo.InitCampoMatrix();
	}

	@Override
	public void atualiza() {
		if(GanhouJogo.Ganhou()) {
			State.setState(Jogo.getFinalState());
		}else if(Jogo.getMouse().getBotao()) {
			int tam=46;
			int i=(((Jogo.getMouse().getX()-MapGfx.deltaX)/tam));
			int	j=(((Jogo.getMouse().getY()-MapGfx.deltaY)/tam));
			
			boolean quadradoPossivel = (i<(Jogo.getLarguraCampo()/46) && j<(Jogo.getAlturaCampo()/46));
			boolean mouseXYNaoNegativo = ((Jogo.getMouse().getX()-MapGfx.deltaX) > 0) && ((Jogo.getMouse().getY()-MapGfx.deltaY) > 0);
			
			boolean mouseNoCampo = quadradoPossivel && mouseXYNaoNegativo;
			
			boolean botaoTiroSimples = (Jogo.getMouse().getX() > 764 && Jogo.getMouse().getX() < 816) && 
							   		   (Jogo.getMouse().getY() > 30 && Jogo.getMouse().getY() < 82);
			
			boolean botaoTiroLinha = (Jogo.getMouse().getX() > 826 && Jogo.getMouse().getX() < 878) && 
			   		   				 (Jogo.getMouse().getY() > 30 && Jogo.getMouse().getY() < 82);
			
			boolean botaoRadar2x2 = (Jogo.getMouse().getX() > 764 && Jogo.getMouse().getX() < 816) && 
									 (Jogo.getMouse().getY() > 92 && Jogo.getMouse().getY() < 144);
			
			boolean botaoTiro2x2 = (Jogo.getMouse().getX() > 826 && Jogo.getMouse().getX() < 878) && 
		   				 			(Jogo.getMouse().getY() > 92 && Jogo.getMouse().getY() < 144);
			boolean botoes = (Botao.getBotaotiroSimplesPress() || Botao.getBotaotiroLinhaPress() || 
								Botao.getBotaoRadar2x2Press() || Botao.getBotaoTiro2x2Press());
			
			if(mouseNoCampo && botoes) {
					//Ações dos botões
					if(Botao.getBotaotiroSimplesPress()) {
						Habilidades.tiroSimples(j,i);
					}else if(Botao.getBotaotiroLinhaPress()) {
						Habilidades.tiroEmLinha(j, i);
					}else if(Botao.getBotaoRadar2x2Press()) {
						Habilidades.radar2x2(j, i);
					}else if(Botao.getBotaoTiro2x2Press()) {
						Habilidades.tiro2x2(j,i);
					}
					
					//reset
					Botao.setBotaoTiroSimplesPress(false);
					Botao.setBotaoTiroLinhaPress(false);
					Botao.setBotaoRadar2x2Press(false);
					Botao.setBotaoTiro2x2Press(false);
					if((AudioAssets.barcoAfundou.getFramePosition() >= AudioAssets.barcoAfundou.getFrameLength()) && somAtivo) {
						System.out.println("flag 1");
						AudioAssets.barcoAfundou.close();
						AudioAssets.barcoAfundou = OpenAudio.loadAudio("smw_1-up.wav");
						somAtivo = false;
					
					}
			}else if(botaoTiroSimples) {
				Botao.setBotaoTiroSimplesPress(true);
				Botao.setBotaoTiroLinhaPress(false);
				Botao.setBotaoRadar2x2Press(false);
				Botao.setBotaoTiro2x2Press(false);
			}else if(botaoTiroLinha) {
				Botao.setBotaoTiroLinhaPress(true);
				Botao.setBotaoTiroSimplesPress(false);
				Botao.setBotaoRadar2x2Press(false);
				Botao.setBotaoTiro2x2Press(false);
			}else if(botaoRadar2x2) {
				Botao.setBotaoRadar2x2Press(true);
				Botao.setBotaoTiroLinhaPress(false);
				Botao.setBotaoTiroSimplesPress(false);
				Botao.setBotaoTiro2x2Press(false);
			}else if(botaoTiro2x2) {
				Botao.setBotaoTiro2x2Press(true);
				Botao.setBotaoRadar2x2Press(false);
				Botao.setBotaoTiroLinhaPress(false);
				Botao.setBotaoTiroSimplesPress(false);
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
		if(!Botao.getBotaoRadar2x2Press()) {
			grafico.drawImage(Assets.radar2x2,764,92,null);
		}else {
			grafico.drawImage(Assets.radar2x2Press,764,92,null);
		}
		if(!Botao.getBotaoTiro2x2Press()) {
			grafico.drawImage(Assets.botaoTiro2x2,826,92,null);
		}else {
			grafico.drawImage(Assets.botaoTiro2x2Press,826,92,null);
		}
	}
}
