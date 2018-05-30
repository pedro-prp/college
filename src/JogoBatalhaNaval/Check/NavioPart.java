package JogoBatalhaNaval.Check;

public class NavioPart {
	private static boolean direita = false;
	private static boolean esquerda = false;
	private static boolean horizontal = false;
	private static boolean cima = false;
	private static boolean baixo = false;
	private static int i = 0;
	private static int j = 0;
	
	public static String checkBarcoContinua(int j,int i){
		NavioPart.i = i;
		NavioPart.j = j;
		
		if(MatrixCampo.getMatrixInt(j,i) != 1) {
			System.out.println("Jose" + MatrixCampo.getMatrixInt(j,i-1) + MatrixCampo.getMatrixInt(j, i+1));
			//direita e esquerda
			direita = MatrixCampo.getMatrixInt(j,i) == MatrixCampo.getMatrixInt(j, i+1);
			esquerda = MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixInt(j, i-1);
			
			horizontal = direita || esquerda;
			if(horizontal) {
				return "horizontal";
			}else{
				return "vertical";
			}
		}else if(MatrixCampo.getMatrixInt(j, i) == 1) {
			return "explodir";
		}else if(MatrixCampo.getMatrixInt(j, i) == 0) {
			return "agua";
		}else {
			return "Bug do milênio";
		}
	}
	
	public static String setBarcoEmVolta(String orientacao) {
		if(orientacao == "horizontal") {
			if(direita) {
				int a =1,b=(i+1),direitaN=0;
				while(a < MatrixCampo.getMatrixInt(j, i)) {
					if(MatrixCampo.getMatrixInt(j, i)==MatrixCampo.getMatrixInt(j, b)) {
						direitaN++;
						b++;
					}
					a++;
				}
			}
			else if(esquerda) {
				int a =1,b=(i-1),esquerdaN=0;
				while(a < MatrixCampo.getMatrixInt(j, i)) {
					if(MatrixCampo.getMatrixInt(j, i)==MatrixCampo.getMatrixInt(j, b)) {
						esquerdaN++;
						b--;
					}
					a++;
				}
			}
		}
		
		
		return "zezin playboy";
	}
}
