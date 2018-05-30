package JogoBatalhaNaval.Check;

public class Botao {
	private static boolean botaoTiroSimplesPress = false;
	private static boolean botaoTiroLinhaPress = false;
	
	//Tiro Simples
	public static void setBotaoTiroSimplesPress(boolean D) {
		botaoTiroSimplesPress = D;
	}
	public static boolean getBotaotiroSimplesPress() {
		return botaoTiroSimplesPress;
	}
	
	//Explodir uma liha
	public static void setBotaoTiroLinhaPress(boolean D) {
		botaoTiroLinhaPress = D;
	}
	public static boolean getBotaotiroLinhaPress() {
		return botaoTiroLinhaPress;
	}
}
