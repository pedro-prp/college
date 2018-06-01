package JogoBatalhaNaval.Audio;

import javax.sound.sampled.Clip;

public class AudioAssets {
	public static Clip abrirJogo;
	public static Clip barcoAfundou;
	public static Clip musicaDeFundo;
	
	
	public static void initAudioAssets() {
		abrirJogo = OpenAudio.loadAudio("smw_coin.wav");
		//barcoAfundou = OpenAudio.loadAudio("smw_1-up.wav");
		musicaDeFundo = OpenAudio.loadAudio("Velvet Happy Hour.wav");
	}
}
