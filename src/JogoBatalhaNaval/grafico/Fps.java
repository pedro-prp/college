package JogoBatalhaNaval.grafico;

public class Fps {
		public static int fps=30;
		public static double timePerTick=1000000000 / fps;
		public static double delta = 0;
		public static long now=0;
		public static long lastTime = System.nanoTime();
	
	public static void calculaFps() {
		
		now = System.nanoTime();
		delta += (now - lastTime) / timePerTick;
		lastTime = now;
	}
}
