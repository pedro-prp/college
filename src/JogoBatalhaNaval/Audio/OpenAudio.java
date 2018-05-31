package JogoBatalhaNaval.Audio;

import java.io.File;
import java.io.IOException;

import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

public class OpenAudio {

	public static Clip loadAudio(String path) {
		
		File audio = new File("biblioteca/audio/" + path);
		
		try {
			Clip clip = AudioSystem.getClip();
			try {
				clip.open(AudioSystem.getAudioInputStream(audio));
				return clip;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (UnsupportedAudioFileException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} catch (LineUnavailableException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
}
