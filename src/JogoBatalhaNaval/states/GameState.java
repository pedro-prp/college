package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

import javax.sound.sampled.Clip;

import JogoBatalhaNaval.Check.MatrixCampo;
import JogoBatalhaNaval.Check.NavioPart;
import JogoBatalhaNaval.Check.Botao;
import JogoBatalhaNaval.grafico.Assets;
import JogoBatalhaNaval.grafico.MapGfx;
import JogoBatalhaNaval.Jogo;
import JogoBatalhaNaval.LoadMap;
import JogoBatalhaNaval.Audio.AudioAssets;
import JogoBatalhaNaval.Audio.OpenAudio;

public class GameState extends State{
	private static boolean somAtivo=false;
	private static Clip barcoAfundou;
	public GameState() {
		
	}
	public void init() {
		
	}

	@Override
	public void atualiza() {
		barcoAfundou = OpenAudio.loadAudio("smw_1-up.wav");
	
		if(Jogo.getMouse().getBotao()) {
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
			
			if(mouseNoCampo && (Botao.getBotaotiroSimplesPress() || Botao.getBotaotiroLinhaPress())) {
					//Ações dos botões
					if(Botao.getBotaotiroSimplesPress()) {
						if(!MatrixCampo.getMatrixBooleanPress(j, i)) {
							
							MatrixCampo.setMatrixBooleanPress(j, i);
							String orientacao = NavioPart.checkBarcoContinua(j, i);
							
							boolean explodiu = orientacao == "explodir";
							boolean agua = orientacao == "agua";
							boolean barcoExplodiu = NavioPart.checkBarcoExplodiu(j, i, orientacao);
							
							if(explodiu) {
								MatrixCampo.setMatrixBooleanExplode(j, i);
								barcoAfundou.start();
								somAtivo = true;
								
							}else if(agua) {
								MatrixCampo.setMatrixBooleanAgua(j,i);
							}else if(barcoExplodiu) {
								System.out.println("barquin afundou");
								MatrixCampo.setMatrixBooleanExplode(j, i);
								MatrixCampo.setMatrixBooleanSemiExplode(j, i,false);
								NavioPart.setBarcoExplodido(j,i,orientacao);
								barcoAfundou.start();
								somAtivo = true;
							}else {
								MatrixCampo.setMatrixBooleanSemiExplode(j, i,true);
								MatrixCampo.setMatrixSemiExplodeInt(j, i);
							}
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
					System.out.println(barcoAfundou.isActive());
					if((barcoAfundou.getFramePosition() >= barcoAfundou.getFrameLength()) && somAtivo) {
						System.out.println("flag 1");
						barcoAfundou.close();
						somAtivo = false;
						
					}
			}else if(botaoTiroSimples) {
				Botao.setBotaoTiroSimplesPress(true);
			}else if(botaoTiroLinha) {
				Botao.setBotaoTiroLinhaPress(true);
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
