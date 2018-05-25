package JogoBatalhaNaval.states;

import java.awt.Graphics;

public abstract class State {
	
	private static State currentState = null;
	
	public static void setState(State state) {
		currentState = state;
	}
	
	public static State getCurrentState() {
		return currentState;
	}
	
	//CLASS
	public abstract void atualiza();
	public abstract void desenha(Graphics grafico);
	
	
}
