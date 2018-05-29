package JogoBatalhaNaval.states;

import java.awt.Graphics;

import JogoBatalhaNaval.Jogo;
import JogoBatalhaNaval.Linkador;

public abstract class State {
	
	private static State currentState = null;
	
	public static void setState(State state) {
		currentState = state;
	}
	
	public static State getCurrentState() {
		return currentState;
	}
	
	//CLASS
	
	protected Linkador jogo;
	public State(Linkador jogo) {
		this.jogo = jogo;
	}
	
	public abstract void atualiza();
	public abstract void desenha(Graphics grafico);
	
	
}
