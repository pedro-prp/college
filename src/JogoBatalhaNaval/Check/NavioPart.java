package JogoBatalhaNaval.Check;

public class NavioPart {
	public static String checkBarcoContinua(int j,int i){
		if(MatrixCampo.getMatrixInt(j,i) != 1) {
			System.out.println("Jose" + MatrixCampo.getMatrixInt(j,i-1) + MatrixCampo.getMatrixInt(j, i+1));
			//direita e esquerda
			boolean direita = MatrixCampo.getMatrixInt(j,i) == MatrixCampo.getMatrixInt(j, i+1);
			boolean esquerda = MatrixCampo.getMatrixInt(j, i) == MatrixCampo.getMatrixInt(j, i-1);
			
			boolean horizontal = direita || esquerda;
			if(horizontal) {
				return "horizontal";
			}else{
				return "vertical";
			}
			
			
		}
		return "Bug do milênio";
	}
}
