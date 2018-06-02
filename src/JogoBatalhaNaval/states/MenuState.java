package JogoBatalhaNaval.states;

import java.awt.Graphics;

import javax.swing.JFileChooser;

import JogoBatalhaNaval.Jogo;
import JogoBatalhaNaval.grafico.Assets;

public class MenuState extends State{

	public MenuState() {
		
	}
	
	@Override
	public void atualiza() {
		
		if(Jogo.getMouse().getBotao()) {
			boolean botaoAbrirMapa = Jogo.getMouse().getX() > 100 && Jogo.getMouse().getX() < 400
							 	  && Jogo.getMouse().getY() > 100 && Jogo.getMouse().getY() < 300;
			if(botaoAbrirMapa) {
				JFileChooser fc = new JFileChooser();
				fc.setDialogTitle("jose");
				fc.showOpenDialog(null);
				Jogo.path = fc.getSelectedFile().getAbsolutePath();
				GameState.init();
				State.setState(Jogo.getGameState());
			}
		}
	}

	@Override
	public void desenha(Graphics grafico) {
		grafico.drawImage(Assets.botaoAbrirMapa, 100, 100,null);
		
	}
	
}
