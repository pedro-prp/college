package JogoBatalhaNaval.Check;

import JogoBatalhaNaval.LoadMap;

public class MatrixCampo {
	
	public static boolean[][] matrixBoolean = new boolean[15][15];
	public static int[][] matrixInt = new int[15][15];
	
	public static void InitCampoMatrix() {
		converterMatrixtoInt();
		matrixStringToBoolean();
	}
	
	public static void matrixStringToBoolean() {
		System.out.println("");
		int x=0,y=0;
		
		while(x<Integer.parseInt(LoadMap.altura)) {
			while(y < Integer.parseInt(LoadMap.largura)) {
				
				if(Integer.parseInt(LoadMap.matrix[x][y])!=0) {
					System.out.print("T");
					matrixBoolean[x][y] = true;
				}else {
					System.out.print("F");
					matrixBoolean[x][y] = false;
				}
				y++;
			}
			x++;
			y=0;
			System.out.println("");
		}
	}
	
	public static void converterMatrixtoInt() {
		System.out.println("");
		int x=0,y=0;
		
		while(x<Integer.parseInt(LoadMap.altura)) {
			while(y < Integer.parseInt(LoadMap.largura)) {
				matrixInt[x][y] = Integer.parseInt(LoadMap.matrix[x][y]);
				y++;
			}
			x++;
			y=0;
		}
	}
}
