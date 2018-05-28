package JogoBatalhaNaval;

import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import JogoBatalhaNaval.Check.MatrixCampo;
import JogoBatalhaNaval.display.Tela;
import JogoBatalhaNaval.grafico.Assets;
import JogoBatalhaNaval.grafico.Fps;
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
	
	public Jogo(String titulo) {
		this.titulo = titulo;
	}
	
	private void iniciaObjetos() {
		
		gameState = new GameState();
		State.setState(gameState);
		Assets.init();
		
		LoadMap.LerMapa("biblioteca/mapas/map_1.txt");
		MatrixCampo.InitCampoMatrix();
		
		largura = (Integer.parseInt(LoadMap.largura)*52)+250;
		altura = (Integer.parseInt(LoadMap.altura)*52)+50;
		
		tela = new Tela(titulo,largura,altura);
	}
	
	
	public void run() {
		iniciaObjetos();
		
		while(jogoOn) {
			
			Fps.calculaFps();
			
			if(Fps.delta >= 1) {
				atualiza();
				desenha();
				Fps.delta--;
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
