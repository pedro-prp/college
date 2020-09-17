package JogoBatalhaNaval.Player;

public class Mana {
	private static int mana = 100;
	
	public static void gastarMana(int manaGasta) {
		mana-=manaGasta;
	}
	public static int getMana() {
		return mana;
	}
	public static void addMana(int manaAdd) {
		mana+= manaAdd;
	}
}
