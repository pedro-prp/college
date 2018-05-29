package JogoBatalhaNaval;

import JogoBatalhaNaval.Check.Mouse;

public class Linkador {
	private Jogo jogo;
	
	public Linkador(Jogo jogo) {
		this.jogo = jogo;
	}
	
	public Mouse getMouse() {
		return jogo.getMouse();
	}
}
