package JogoBatalhaNaval.grafico;

import java.awt.image.BufferedImage;

public class Assets {
	
	public static BufferedImage campo,campoV,campoF,campoX,campoSemi,tiroSimples,tiroSimplesPress,tiroLinha,tiroLinhaPress,
								radar2x2,radar2x2Press,botaoAbrirMapa,botaoJogar,botaoTiro2x2,botaoTiro2x2Press,titulo;
	public static BufferedImage[] barcos = new BufferedImage[6];
	
	private static final int largura = 52, altura = 52;
	

	public static void init() {
			SpriteSheet sheet = new SpriteSheet(LoadImage.lerImagem("/texturas/sprites.png"));
			
			campo = sheet.crop(0,0,largura,altura);
			campoV = sheet.crop(52,0,largura,altura);
			campoF = sheet.crop((52*2),0, largura, altura);
			campoX = sheet.crop((52),(52), largura, altura);
			campoSemi = sheet.crop(52*2, 52, largura, altura);
			
			botaoAbrirMapa = LoadImage.lerImagem("/texturas/botaoAbrirMapa.png");
			botaoJogar = LoadImage.lerImagem("/texturas/botaoJogar.png");
			titulo = LoadImage.lerImagem("/texturas/titulo.png");
			
			barcos[1] = sheet.crop((52*3), 0, largura, altura);
			barcos[2] = sheet.crop((52*4), 0, largura, altura);
			barcos[3] = sheet.crop((52*5), 0, largura, altura);
			barcos[4] = sheet.crop((52*6), 0, largura, altura);
			barcos[5] = sheet.crop((52*7), 0, largura, altura);
			
			tiroSimples = sheet.crop(52*8, 0, largura, altura);
			tiroSimplesPress = sheet.crop(52*9, 0, largura, altura);
			
			tiroLinha = sheet.crop(52*8, 52, largura, altura);
			tiroLinhaPress = sheet.crop(52*9, 52, largura, altura);
			
			radar2x2 = sheet.crop(52*8, 52*2, largura, altura);
			radar2x2Press = sheet.crop(52*9, 52*2, largura, altura);
			
			botaoTiro2x2 = sheet.crop(52*8, 52*3, largura, altura);
			botaoTiro2x2Press = sheet.crop(52*9, 52*3, largura, altura);

	}
}
