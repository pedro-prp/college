package JogoBatalhaNaval.grafico;

import java.awt.image.BufferedImage;
import java.io.IOException;

import javax.imageio.ImageIO;

public class LoadImage {

	public static BufferedImage lerImagem(String path) {
		try {
			return ImageIO.read(LoadImage.class.getResource(path));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
		return null;
	}
}
