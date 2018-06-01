package JogoBatalhaNaval.Player;

import JogoBatalhaNaval.Check.Botao;
import JogoBatalhaNaval.Check.MatrixCampo;
import JogoBatalhaNaval.Check.NavioPart;
import JogoBatalhaNaval.states.GameState;

public class Habilidades {
	public static void tiroSimples(int j,int i) {
			if(!MatrixCampo.getMatrixBooleanPress(j, i)) {
				
				MatrixCampo.setMatrixBooleanPress(j, i);
				String orientacao = NavioPart.checkBarcoContinua(j, i);
				
				boolean explodiu = orientacao == "explodir";
				boolean agua = orientacao == "agua";
				boolean barcoExplodiu = NavioPart.checkBarcoExplodiu(j, i, orientacao);
				
				if(explodiu) {
					MatrixCampo.setMatrixBooleanExplode(j, i);
					GameState.barcoAfundou.start();
					GameState.somAtivo = true;
					
				}else if(agua) {
					MatrixCampo.setMatrixBooleanAgua(j,i);
				}else if(barcoExplodiu) {
					System.out.println("barquin afundou");
					MatrixCampo.setMatrixBooleanExplode(j, i);
					MatrixCampo.setMatrixBooleanSemiExplode(j, i,false);
					NavioPart.setBarcoExplodido(j,i,orientacao);
					GameState.barcoAfundou.start();
					GameState.somAtivo = true;
				}else {
					MatrixCampo.setMatrixBooleanSemiExplode(j, i,true);
					MatrixCampo.setMatrixSemiExplodeInt(j, i);
				}
			}else {
				return;
			}
	}
	public static void tiroEmLinha(int j,int i) {
		int a = 0;
		while(a < 15) {
			i = a;
			if(!MatrixCampo.getMatrixBooleanPress(j, i)) {
				
				MatrixCampo.setMatrixBooleanPress(j, i);
				String orientacao = NavioPart.checkBarcoContinua(j, i);
				
				boolean explodiu = orientacao == "explodir";
				boolean agua = orientacao == "agua";
				boolean barcoExplodiu = NavioPart.checkBarcoExplodiu(j, i, orientacao);
				
				if(explodiu) {
					MatrixCampo.setMatrixBooleanExplode(j, i);
					GameState.barcoAfundou.start();
					GameState.somAtivo = true;
					
				}else if(agua) {
					MatrixCampo.setMatrixBooleanAgua(j,i);
				}else if(barcoExplodiu) {
					System.out.println("barquin afundou");
					MatrixCampo.setMatrixBooleanExplode(j, i);
					MatrixCampo.setMatrixBooleanSemiExplode(j, i,false);
					NavioPart.setBarcoExplodido(j,a,orientacao);
					GameState.barcoAfundou.start();
					GameState.somAtivo = true;
				}else {
					MatrixCampo.setMatrixBooleanSemiExplode(j, i,true);
					MatrixCampo.setMatrixSemiExplodeInt(j, a);
				}
			}
			a++;
		}
	}
}
