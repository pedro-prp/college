package JogoBatalhaNaval.states;

import java.awt.Graphics;

import javax.swing.JFileChooser;

import JogoBatalhaNaval.Jogo;

public class MenuState extends State{

	public MenuState() {
		
	}
	
	@Override
	public void atualiza() {
		//JFileChooser fc = new JFileChooser();
		//fc.setDialogTitle("jose");
		//int resposta = fc.showOpenDialog(null);
		
		if(Jogo.getMouse().getBotao()) {
			//JFileChooser fc = new JFileChooser();
			//fc.setDialogTitle("jose");
			//fc.showOpenDialog(null);
			State.setState(Jogo.getGameState());
			//Thread.currentThread();
			//try {
			//	Thread.sleep(1000);
			//} catch (InterruptedException e) {
				// TODO Auto-generated catch block
			//	e.printStackTrace();
			//}
		}
	}

	@Override
	public void desenha(Graphics grafico) {
		// TODO Auto-generated method stub
		
	}
	
}
