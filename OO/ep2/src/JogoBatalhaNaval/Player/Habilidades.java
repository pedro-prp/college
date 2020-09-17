package JogoBatalhaNaval.Player;

import JogoBatalhaNaval.Audio.AudioAssets;
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
					AudioAssets.barcoAfundou.start();
					GameState.somAtivo = true;
					
				}else if(agua) {
					MatrixCampo.setMatrixBooleanAgua(j,i);
				}else if(barcoExplodiu) {
					MatrixCampo.setMatrixBooleanExplode(j, i);
					MatrixCampo.setMatrixBooleanSemiExplode(j, i,false);
					NavioPart.setBarcoExplodido(j,i,orientacao);
					AudioAssets.barcoAfundou.start();
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
					AudioAssets.barcoAfundou.start();
					GameState.somAtivo = true;
					
				}else if(agua) {
					MatrixCampo.setMatrixBooleanAgua(j,i);
				}else if(barcoExplodiu) {
					MatrixCampo.setMatrixBooleanExplode(j, i);
					MatrixCampo.setMatrixBooleanSemiExplode(j, i,false);
					NavioPart.setBarcoExplodido(j,a,orientacao);
					AudioAssets.barcoAfundou.start();
					GameState.somAtivo = true;
				}else {
					MatrixCampo.setMatrixBooleanSemiExplode(j, i,true);
					MatrixCampo.setMatrixSemiExplodeInt(j, a);
				}
			}
			a++;
		}
	}
	public static void radar2x2(int j,int i) {
		if(!MatrixCampo.getMatrixBooleanPress(j, i)) {
			if(i+1 <= 14 && j+1 <= 14) {
				int a = 0;
				int b = 0;
				while(a <= 1) {
					while(b <= 1) {
						if(!MatrixCampo.getMatrixBooleanPress(j+a, i+b)) {
							
							String orientacao = NavioPart.checkBarcoContinua(j+a, i+b);
							
							boolean agua = orientacao == "agua";
							
							if(!agua) {
								MatrixCampo.setMatrixBooleanMostrar(j+a, i+b);
							}
						}
						b++;
					}
					b=0;
					a++;
				}
			}
		}
	}
	public static void tiro2x2(int j,int i) {
		if(!MatrixCampo.getMatrixBooleanPress(j, i)) {
			if(i+1 <= 14 && j+1 <= 14) {
				int a = 0;
				int b = 0;
				while(a <= 1) {
					while(b <= 1) {
						if(!MatrixCampo.getMatrixBooleanPress(j+a, i+b)) {
							
							MatrixCampo.setMatrixBooleanPress(j+a, i+b);
							String orientacao = NavioPart.checkBarcoContinua(j+a, i+b);
							
							boolean explodiu = orientacao == "explodir";
							boolean agua = orientacao == "agua";
							boolean barcoExplodiu = NavioPart.checkBarcoExplodiu(j+a, i+b, orientacao);
							
							if(explodiu) {
								MatrixCampo.setMatrixBooleanExplode(j+a, i+b);
								AudioAssets.barcoAfundou.start();
								GameState.somAtivo = true;
								
							}else if(agua) {
								MatrixCampo.setMatrixBooleanAgua(j+a,i+b);
							}else if(barcoExplodiu) {
								MatrixCampo.setMatrixBooleanExplode(j+a, i+b);
								MatrixCampo.setMatrixBooleanSemiExplode(j+a, i+b,false);
								NavioPart.setBarcoExplodido(j+a,i+b,orientacao);
								AudioAssets.barcoAfundou.start();
								GameState.somAtivo = true;
							}else {
								MatrixCampo.setMatrixBooleanSemiExplode(j+a, i+b,true);
								MatrixCampo.setMatrixSemiExplodeInt(j+a, i+b);
							}
						}
						b++;
					}
					b=0;
					a++;
				}
			}
		}
	}
}
