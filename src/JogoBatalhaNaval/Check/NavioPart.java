package JogoBatalhaNaval.Check;

public class NavioPart {
	private static boolean direita = false;
	private static boolean esquerda = false;
	private static boolean cima = false;
	private static boolean baixo = false;
	private static boolean horizontal;
	private static boolean vertical;
	private static int[][] barcosPartAcertados = new int[15][15];
	
	private static int direitaN,esquerdaN,cimaN,baixoN;
	
	public static String checkBarcoContinua(int j,int i){
		
		if((MatrixCampo.getMatrixInt(j,i) != 1) && (MatrixCampo.getMatrixInt(j,i) != 0)) {
			//direita e esquerda
			direita = MatrixCampo.getMatrixInt(j,i) == MatrixCampo.getMatrixInt(j, i+1);
			esquerda = MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixInt(j, i-1);
			cima = MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixInt(j-1, i);
			baixo = MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixInt(j+1, i);
			
			horizontal = direita || esquerda;
			vertical = cima || baixo;
			if(horizontal) {
				return "horizontal";
			}else if(vertical){
				return "vertical";
			}
		}else if(MatrixCampo.getMatrixInt(j, i) == 1) {
			return "explodir";
		}else if(MatrixCampo.getMatrixInt(j, i) == 0) {
			return "agua";
		}else {
			return "Bug do milênio";
		}
		return null;
	}
	public static void setBarcosPartAcertados(int j,int i) {
		barcosPartAcertados[j][i] = MatrixCampo.getMatrixInt(j, i);
	}
	
	public static boolean checkBarcoExplodiu(int j,int i,String orientacao) {
		//Calculo de barcos possiveis perto
		if(orientacao == "horizontal") {
			
			direitaN = 0;
			esquerdaN = 0;
			int a = 1;
			//direita
			while(a < MatrixCampo.getMatrixInt(j, i)) {
				//direita
				if(direita) {
					if((i+a) < 14) {
						if(MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixSemiExplodeInt(j,(i+a))) {
							direitaN++;
						}
					}
				}
				//esquerda
				if(esquerda) {
					if((i-a ) > 0) {
						if(MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixSemiExplodeInt(j,(i-a))) {
							esquerdaN++;
						}
					}
				}
				a++;
			}
			if((direitaN + esquerdaN + 1) == MatrixCampo.getMatrixInt(j,i)) {
				return true;
			}
		}else if(orientacao == "vertical") {
			
			cimaN = 0;
			baixoN = 0;
			int a = 1;
			//baixo
			while(a < MatrixCampo.getMatrixInt(j, i)) {
				//baixo
				if(baixo) {
					if((j+a) < 14) {
						if(MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixSemiExplodeInt((j+a),i)) {
							baixoN++;
						}
					}
				}
				//cima
				if(cima) {
					if((j-a ) > 0) {
						if(MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixSemiExplodeInt((j-a),i)) {
							cimaN++;
						}
					}
				}
				a++;
			}
			if((baixoN + cimaN + 1) == MatrixCampo.getMatrixInt(j,i)) {
				return true;
			}
		}
		
		return false;
			
	}
	public static void setBarcoExplodido(int j,int i, String orientacao) {
		if(orientacao == "horizontal") {
			int a = 1,b = 1;
			//direita
			if((i+a)<14) {
				System.out.println(direitaN);
				while(a <= direitaN) {
				MatrixCampo.setMatrixBooleanExplode(j, i+a);
				MatrixCampo.setMatrixBooleanSemiExplode(j, i+a,false);
				a++;
				}
			}
			if((i-b)>0) {
				while(b <= esquerdaN) {
					MatrixCampo.setMatrixBooleanExplode(j, i-b);
					MatrixCampo.setMatrixBooleanSemiExplode(j, i-b,false);
					b++;
				}
			}
		}else if(orientacao == "vertical") {
			int a = 1,b = 1;
			//direita
			if((i+a)<14) {
				while(a <= baixoN) {
				MatrixCampo.setMatrixBooleanExplode((j+a), i);
				MatrixCampo.setMatrixBooleanSemiExplode((j+a), i,false);
				a++;
				}
			}
			if((i-b)>0) {
				while(b <= cimaN) {
					MatrixCampo.setMatrixBooleanExplode((j-b), i);
					MatrixCampo.setMatrixBooleanSemiExplode((j-b), i,false);
					b++;
				}
			}
		}
	}
}
