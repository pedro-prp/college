package JogoBatalhaNaval;

import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import JogoBatalhaNaval.display.Tela;
import JogoBatalhaNaval.grafico.Assets;
import JogoBatalhaNaval.states.GameState;
import JogoBatalhaNaval.states.State;

public class Jogo implements Runnable{
	
	
	private Tela tela;
	public int largura,altura;
	String titulo;
	int i=0;
	
	private boolean jogoOn = false;
	private Thread thread;
	
	private BufferStrategy buffer;
	private Graphics grafico; 
	
	//states
	private State gameState;
	
	public Jogo(String titulo,int largura,int altura) {
		
		this.largura = largura;
		this.altura = altura;
		this.titulo = titulo;
	}
	
	private void iniciaObjetos() {
		tela = new Tela(titulo,largura,altura);
		
		gameState = new GameState();
		State.setState(gameState);
		Assets.init();
	}
	
	
	public void run() {
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
		
		stop();
	}
	
	public synchronized void start() {
		if(jogoOn) {
			return;
		}
		jogoOn = true;
		thread = new Thread(this);
		thread.start();
	}
	public synchronized void stop() {
		if(!jogoOn) {
			return;
		}
		jogoOn=false;
		try {
			thread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	public void atualiza() {
		if(State.getCurrentState() != null) {
			State.getCurrentState().atualiza();
		}
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
		
		if(State.getCurrentState() != null) {
			State.getCurrentState().desenha(grafico);
		}
		
		buffer.show();
		grafico.dispose();
		
	}
	
}
