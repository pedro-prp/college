package JogoBatalhaNaval.states;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFileChooser;

import JogoBatalhaNaval.Jogo;
import JogoBatalhaNaval.grafico.Assets;

public class MenuState extends State{

	private boolean MapaEscolhido = false;
	public MenuState() {
		
	}
	
	@Override
	public void atualiza() {
		
		if(Jogo.getMouse().getBotao()) {
			boolean botaoAbrirMapa = Jogo.getMouse().getX() > 177 && Jogo.getMouse().getX() < 777
							 	  	&& Jogo.getMouse().getY() > 300 && Jogo.getMouse().getY() < 360;
			boolean botaoJogar = Jogo.getMouse().getX() > 177 && Jogo.getMouse().getX() < 777
				 	  				&& Jogo.getMouse().getY() > 400 && Jogo.getMouse().getY() < 460 && MapaEscolhido;
			if(botaoAbrirMapa) {
				JFileChooser fc = new JFileChooser();
				fc.setDialogTitle("jose");
				fc.showOpenDialog(null);
				Jogo.path = fc.getSelectedFile().getAbsolutePath();
				//Jogo.path = "biblioteca/mapas/map_1.txt";
				GameState.init();
				MapaEscolhido = true;
			}else if(botaoJogar) {
				State.setState(Jogo.getGameState());
			}
		}
	}

	@Override
	public void desenha(Graphics grafico) {
		grafico.setColor(Color.DARK_GRAY);
		grafico.fillRect(0, 0, 955, 754);
		grafico.drawImage(Assets.titulo,77,50, null);
		grafico.drawImage(Assets.botaoAbrirMapa, 177, 300,null);
		grafico.drawImage(Assets.botaoJogar,177,400,null);
		
	}
	
}
