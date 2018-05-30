package JogoBatalhaNaval;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class LoadMap {

	public static String lixo="",leitura="";
	public static String largura;
	public static String altura;
	public static String[][] matrix = new String[15][15];	
	private static BufferedReader lerArquivo;
	public static int[] barcos = new int[6];
	
	
	public static void LerMapa(String path){
		
		try {
			FileReader arquivo = new FileReader(path);
			lerArquivo = new BufferedReader(arquivo);
		
			try {
				//leitura da Largura e altura
				lixo = lerArquivo.readLine();
				leitura = lerArquivo.readLine();
				largura = leitura.substring(0, leitura.indexOf(' '));
				altura = leitura.substring((leitura.indexOf(' ')+1),leitura.length());			
				lixo = lerArquivo.readLine();
				lixo = lerArquivo.readLine();
					
				//ler Matriz
				leitorMatrix();
				lixo = lerArquivo.readLine();
				lixo = lerArquivo.readLine();
				
				//Quantidade de barcos
				lerBarcos();
				
				
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
				y++;
			}
			x++;
			y=0;
			a=0;
			b=1;
		}
	}
	
	public static void lerBarcos() {
		int a = 1;
		while(a<=5) {
			try {
				leitura = lerArquivo.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			//System.out.println(leitura.substring((leitura.indexOf(' ')+1),leitura.length()));
			barcos[a] = Integer.parseInt(leitura.substring(leitura.indexOf(' ')+1,leitura.length()));
			System.out.println(barcos[a]);
			a++;
		}
	}
}
