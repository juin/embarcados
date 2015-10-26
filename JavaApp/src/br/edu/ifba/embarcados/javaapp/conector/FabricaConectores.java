package br.edu.ifba.embarcados.javaapp.conector;

import com.sun.jna.Native;
import com.sun.jna.Platform;

public class FabricaConectores {
	
	public static IComunicacaoSensores getConector(){
		IComunicacaoSensores conector = null;
		//jna vai utilizar load library é quem vai pegar os métodos que foram def na interface
		//como a aplicação vai selecionar o sistema, isso garante que vai ser multiplataforma
		if (Platform.isWindows()){
			//utiliza os métodos da biblioteca passando para a interface
			conector =(IComunicacaoSensores) Native.loadLibrary("C:\\WorkSpaceJava\\JavaApp\\comunicacaosensores.dll", IComunicacaoSensores.class);
			
		}else if (Platform.isLinux()){
			conector =(IComunicacaoSensores) Native.loadLibrary("comunicacaosensores.so", IComunicacaoSensores.class);
		}
		return conector;
	}

}
