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
			cima = MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixInt(j+1, i);
			baixo = MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixInt(j-1, i);
			
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
				//System.out.println(MatrixCampo.getMatrixSemiExplodeInt(j, i+a));
				System.out.println(MatrixCampo.getMatrixBooleanSemiExplode(j, i-a));
				//direita
				if(direita) {
					if(MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixSemiExplodeInt(j,(i+a))) {
						direitaN++;
					}
				}
				//esquerda
				/*if(esquerda) {
					if(MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixSemiExplodeInt(j,(i-a))) {
						esquerdaN++;
					}
				}*/
				a++;
			}
			if((direitaN + esquerdaN + 1) == MatrixCampo.getMatrixInt(j,i)) {
				return true;
			}
			
			
		}
		
		return false;
			
	}
}
