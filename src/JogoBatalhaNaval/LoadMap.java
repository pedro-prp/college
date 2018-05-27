package JogoBatalhaNaval;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class LoadMap {

	public static String lixo="",leitura="";
	public static String largura;
	public static String altura;
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
				
				
				
			} catch (IOException e) {
				e.printStackTrace();
			}

			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}
}
