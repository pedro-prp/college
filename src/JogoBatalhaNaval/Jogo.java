package JogoBatalhaNaval;

import JogoBatalhaNaval.display.Tela;

public class Jogo {
	
	
	private Tela tela;
	public int largura,altura;
	String titulo;
	
	boolean jogoOn = false;
	
	public Jogo(String titulo,int largura,int altura) {
		
		this.largura = largura;
		this.altura = altura;
		this.titulo = titulo;
	}
	
	public void rodar() {
		iniciaObjetos();
		
		while(jogoOn) {
			atualizaTela();
			desenhaTela();
		}
		
		parar();
	}
	
	public synchronized void iniciar() {
		if(jogoOn) {
			return;
		}
		jogoOn = true;
		rodar();
	}
	public synchronized void parar() {
		if(!jogoOn) {
			return;
		}
		jogoOn=false;
	}
	
	
	private void iniciaObjetos() {
		tela = new Tela(titulo,largura,altura);
	}
	public void atualizaTela() {
		
	}
	public void desenhaTela() {
		
	}
	
}
