package JogoBatalhaNaval.Audio;

import javax.sound.sampled.Clip;

public class AudioAssets {
	public static Clip abrirJogo;
	
	
	public static void initAudioAssets() {
		abrirJogo = OpenAudio.loadAudio("biblioteca/audio/smw_coin.wav");
	}
}
