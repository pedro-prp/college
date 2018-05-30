package JogoBatalhaNaval;

import javax.swing.JFileChooser;

public class Launcher {
	public static void main(String[] args) {
		
		JFileChooser fc = new JFileChooser();
		fc.setDialogTitle("jose");
		int resposta = fc.showOpenDialog(null);
		
		Jogo jogo = new Jogo("Batalha Naval - Jogo");
		Jogo.path = fc.getSelectedFile().getAbsolutePath();
		jogo.start();
		
	}
}
