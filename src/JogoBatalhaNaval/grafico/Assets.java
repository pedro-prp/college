package JogoBatalhaNaval.grafico;

import java.awt.image.BufferedImage;

public class Assets {
	
	public static BufferedImage campo,campoV,campoF;
	public static BufferedImage[] barcos = new BufferedImage[6];
	
	private static final int largura = 52, altura = 52;
	

	public static void init() {
			SpriteSheet sheet = new SpriteSheet(LoadImage.lerImagem("/texturas/sprites.png"));
			
			campo = sheet.crop(0,0,largura,altura);
			campoV = sheet.crop(52,0,largura,altura);
			campoF = sheet.crop((52*2),0, largura, altura);
			
			barcos[1] = sheet.crop((52*3), 0, largura, altura);
			barcos[2] = sheet.crop((52*4), 0, largura, altura);
			barcos[3] = sheet.crop((52*5), 0, largura, altura);
			barcos[4] = sheet.crop((52*6), 0, largura, altura);
			barcos[5] = sheet.crop((52*7), 0, largura, altura);
	}
}
