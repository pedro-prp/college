package JogoBatalhaNaval.Check;

import JogoBatalhaNaval.Jogo;

public class GanhouJogo {
	public static boolean Ganhou() {
		boolean flag = true;
		int a = 0;
		int b = 0;
		//System.out.println(Jogo.getAlturaCampo()/46);
		while(a < (Jogo.getAlturaCampo()/46)) {
			while(b < (Jogo.getLarguraCampo()/46)) {
				if(MatrixCampo.getMatrixInt(a, b) != 0) {
					if(!MatrixCampo.getMatrixBooleanPress(a, b)) {
						flag = false;
					}
				}
				b++;
			}
			b=0;
			a++;
		}
		
		return flag;
	}
}
