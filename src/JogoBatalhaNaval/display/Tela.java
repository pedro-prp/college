package JogoBatalhaNaval.display;

import java.awt.Canvas;
import java.awt.Dimension;

import javax.swing.JFrame;

public class Tela {
	private JFrame frame;
	private Canvas canvas;
	
	private String titulo;
	private int largura,altura;
	
	public Tela(String titulo,int largura,int altura) {
		this.titulo = titulo;
		this.largura = largura;
		this.altura = altura;
		
		criarTela();
	}
	
	private void criarTela() {
		frame = new JFrame(titulo);
		
		frame.setSize(largura,altura);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);
		
		canvas = new Canvas();
		canvas.setPreferredSize(new Dimension(largura,altura));
		canvas.setMaximumSize(new Dimension(largura,altura));
		canvas.setMinimumSize(new Dimension(largura,altura));
		
		frame.add(canvas);
		frame.pack();

		
	}
}
