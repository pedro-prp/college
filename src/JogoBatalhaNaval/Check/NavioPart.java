package JogoBatalhaNaval.Check;

public class NavioPart {
	private static boolean direita = false;
	private static boolean esquerda = false;
	private static boolean cima = false;
	private static boolean baixo = false;
	private static boolean horizontal;
	private static boolean vertical;
	private static int[][] barcosPartAcertados = new int[15][15];
	
	public static String checkBarcoContinua(int j,int i){
		
		if((MatrixCampo.getMatrixInt(j,i) != 1) && (MatrixCampo.getMatrixInt(j,i) != 0)) {
			System.out.println("Jose" + MatrixCampo.getMatrixInt(j,i-1) + MatrixCampo.getMatrixInt(j, i+1));
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
		if(orientacao == "horizontal") {
			
		}else if(orientacao == "vertical") {
			
		}else if(orientacao == "")
	}
}
