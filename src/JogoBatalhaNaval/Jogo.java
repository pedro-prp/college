package JogoBatalhaNaval;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;

import JogoBatalhaNaval.display.Tela;
import JogoBatalhaNaval.grafico.LoadImage;

public class Jogo {
	
	
	private Tela tela;
	public int largura,altura;
	String titulo;
	int i=0;
	
	private boolean jogoOn = false;
	
	private BufferStrategy buffer;
	private Graphics grafico; 
	
	private BufferedImage campo;
	
	public Jogo(String titulo,int largura,int altura) {
		
		this.largura = largura;
		this.altura = altura;
		this.titulo = titulo;
	}
	
	public void rodar() {
		iniciaObjetos();
		
		int fps = 60;
		double timePerTick = 1000000000 / fps;
		double delta = 0;
		long now;
		long lastTime = System.nanoTime();
		
		while(jogoOn) {
			
			now = System.nanoTime();
			delta += (now - lastTime) / timePerTick;
			lastTime = now;
			
			if(delta >= 1) {
				atualiza();
				desenha();
				delta--;
			}
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
		campo = LoadImage.lerImagem("/texturas/fundo.png");
	}
	
	public void atualiza() {
		i++;
	}
	public void desenha() {
		
		buffer = tela.getCanvas().getBufferStrategy();
		if(buffer == null) {
			tela.getCanvas().createBufferStrategy(3);
			return;
		}
		
		grafico = buffer.getDrawGraphics();
		//clean
		grafico.clearRect(0, 0, largura, altura);
		//draw
		grafico.setColor(Color.GRAY);
		grafico.fillRect(0, 0, largura, altura);
		
		grafico.drawImage(campo,20,20, null);
		
		//end Draw
		buffer.show();
		grafico.dispose();
		
		
	}
	
}
