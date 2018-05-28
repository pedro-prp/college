package JogoBatalhaNaval;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class LoadMap {

	public static String lixo="",leitura="";
	public static String largura;
	public static String altura;
	public static String[][] matrix = new String[50][50];
	public static int matrixInt[][];
	
	private static BufferedReader lerArquivo;
	
	
	public static void LerMapa(String path){
		
		try {
			FileReader arquivo = new FileReader(path);
			lerArquivo = new BufferedReader(arquivo);
		
			try {
				lixo = lerArquivo.readLine();
				
				leitura = lerArquivo.readLine();
				largura = leitura.substring(0, leitura.indexOf(' '));
				altura = leitura.substring((leitura.indexOf(' ')+1),leitura.length());
				
				lixo = lerArquivo.readLine();
				lixo = lerArquivo.readLine();
				
				leitorMatrix();
				
				
			} catch (IOException e) {
				e.printStackTrace();
			}

			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}
	
	public static void leitorMatrix() {
		int x=0,y=0;
		int a=0,b=1;
		
		while(x<Integer.parseInt(altura)) {
			try {
				leitura =lerArquivo.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			while(y<Integer.parseInt(largura)) {
				matrix[x][y]=leitura.substring(a,b);
				a++;
				b++;
				System.out.print(matrix[x][y]);
				y++;
			}
			x++;
			y=0;
			a=0;
			b=1;
			System.out.println("");
		}
	}
}
