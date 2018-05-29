package JogoBatalhaNaval.grafico;

import java.awt.image.BufferedImage;

public class Assets {
	
	public static BufferedImage campo;
	
	private static final int largura = 52, altura = 52;
	

	public static void init() {
			SpriteSheet sheet = new SpriteSheet(LoadImage.lerImagem("/texturas/sprites.png"));
			
			campo = sheet.crop(0,0,largura,altura);
	}
}
