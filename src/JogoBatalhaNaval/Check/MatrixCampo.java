package JogoBatalhaNaval.Check;

import JogoBatalhaNaval.LoadMap;

public class MatrixCampo {
	
	public static boolean[][] matrixBoolean = new boolean[15][15];
	public static boolean[][] matrixBooleanPress = new boolean[15][15];
	
	public static boolean[][] matrixBooleanExplode = new boolean[15][15];
	public static boolean[][] matrixBooleanSemiExplode = new boolean[15][15];
	public static boolean[][] matrixBooleanExplodeBarco = new boolean[15][15];
	public static boolean[][] matrixBooleanAgua = new boolean[15][15];
	
	public static int[][] matrixSemiExplodeInt = new int[15][15];
	public static int[][] matrixInt = new int[15][15];
	
	
	public static void InitCampoMatrix() {
		converterMatrixtoInt();
		//initSemiExplodeInt();
		matrixStringToBoolean();
	}
	
	public static boolean getMatrixBoolean(int x,int y) {
		return matrixBoolean[x][y];
	}
	
	public static void setMatrixBooleanPress(int x,int y) {
		matrixBooleanPress[x][y] = true;
	}
	public static boolean getMatrixBooleanPress(int x,int y) {
		return matrixBooleanPress[x][y];
	}
	
	public static int getMatrixInt(int x,int y) {
		return matrixInt[x][y];
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
	public static void initSemiExplodeInt() {
		int a = 0,b = 0;
		while(a < 15) {
			while(b < 15) {
				matrixSemiExplodeInt[a][b] = 0;
				b++;
			}
			b=0;
			a++;
		}
	}

	public static void setMatrixBooleanExplode(int j, int i) {
		matrixBooleanExplode[j][i] = true;
		
	}
	public static boolean getMatrixBooleanExplode(int j, int i) {
		return matrixBooleanExplode[j][i];
	}
	

	public static void setMatrixBooleanAgua(int j, int i) {
		matrixBooleanAgua[j][i] = true;
	}
	public static boolean getMatrixBooleanAgua(int j,int i) {
		return matrixBooleanAgua[j][i];
	}
	

	public static void setMatrixBooleanSemiExplode(int j, int i) {
		matrixBooleanSemiExplode[j][i] = true;
		
	}
	public static boolean getMatrixBooleanSemiExplode(int j,int i) {
		return matrixBooleanSemiExplode[j][i];
	}
	
	public static void setMatrixSemiExplodeInt(int j, int i) {
		matrixSemiExplodeInt[j][i] = matrixInt[j][i];
		
	}
	public static int getMatrixSemiExplodeInt(int j,int i) {
		return matrixSemiExplodeInt[j][i];
	}
	

}
