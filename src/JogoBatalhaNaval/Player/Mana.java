package JogoBatalhaNaval.Player;

public class Mana {
	private static int mana = 50;
	
	public static void gastarMana(int manaGasta) {
		mana-=manaGasta;
	}
	public static int getMana() {
		return mana;
	}
}
