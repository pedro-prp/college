package JogoBatalhaNaval.states;

import java.awt.Graphics;

import JogoBatalhaNaval.Jogo;

public class MenuState extends State{

	public MenuState() {
		
	}
	
	@Override
	public void atualiza() {
		if(Jogo.getMouse().getBotao()) {
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
