package JogoBatalhaNaval;

import java.applet.Applet;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.io.File;
import java.io.IOException;
import java.net.URL;

import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

import com.sun.media.jfxmedia.AudioClip;

import JogoBatalhaNaval.Audio.AudioAssets;
import JogoBatalhaNaval.Check.MatrixCampo;
import JogoBatalhaNaval.Check.Mouse;
import JogoBatalhaNaval.display.Tela;
import JogoBatalhaNaval.grafico.Assets;
import JogoBatalhaNaval.grafico.Fps;
import JogoBatalhaNaval.states.GameState;
import JogoBatalhaNaval.states.MenuState;
import JogoBatalhaNaval.states.State;

public class Jogo implements Runnable{
	
	
	private static  Tela tela;
	private static Tela jogoTela;
	private static int largura;
	private static int altura;
	String titulo;
	public static String path;
	int i=0;
	
	private static boolean jogoOn = false;
	private static Thread thread;
	
	private BufferStrategy buffer;
	private Graphics grafico;
	//Input
	private static Mouse mouseInput;
	
	//states
	private static State gameState;
	private State menuState;
	
	public Jogo(String titulo) {
		this.titulo = titulo;
		mouseInput = new Mouse();
	}
	
	private void iniciaObjetos() {
		Assets.init();
		LoadMap.LerMapa(path);
		MatrixCampo.InitCampoMatrix();
		
		AudioAssets.initAudioAssets();
		
		
		tela = new Tela(titulo,955,754);
		tela.getFrame().addMouseListener(mouseInput);
		tela.getFrame().addMouseMotionListener(mouseInput);
		tela.getCanvas().addMouseListener(mouseInput);
		tela.getCanvas().addMouseMotionListener(mouseInput);
		
		gameState = new GameState();
		menuState = new MenuState();
		State.setState(menuState);
		
		AudioAssets.abrirJogo.start();
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
	public static synchronized void stop() {
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
		//Clear
		grafico.clearRect(0, 0, largura, altura);
		
		//Draw do State atual
		if(State.getCurrentState() != null) {
			State.getCurrentState().desenha(grafico);
		}
		
		//visibilidade
		buffer.show();
		grafico.dispose();
	}
	
	//gets
	public static Mouse getMouse() {
		return mouseInput;
	}
	public static int getLargura() {
		return largura;
	}
	public static int getAltura() {
		return altura;
	}
	public static int getLarguraCampo() {
		return ((Integer.parseInt(LoadMap.largura))*46);
	}
	public static int getAlturaCampo() {
		return ((Integer.parseInt(LoadMap.altura))*46);
	}
	
	public static State getGameState(){
		return gameState;
	}
	public static Tela getGameTela() {
		return jogoTela;
	}
	//public static void setPath(String path) {
	//	this.path = path;
	//}
	
}
