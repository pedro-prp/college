package JogoBatalhaNaval;

import JogoBatalhaNaval.display.Tela;

public class Jogo {
	
	
	private Tela tela;
	public int largura,altura;
	
	public Jogo(String titulo,int largura,int altura) {
		
		this.largura = largura;
		this.altura = altura;
		tela = new Tela(titulo,largura,altura);
	}
	
}
