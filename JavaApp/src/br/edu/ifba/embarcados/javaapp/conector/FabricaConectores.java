package br.edu.ifba.embarcados.javaapp.conector;

import com.sun.jna.Native;
import com.sun.jna.Platform;

public class FabricaConectores {
	
	public static IComunicacaoSensores getConector(){
		IComunicacaoSensores conector = null;
		//jna vai utilizar load library � quem vai pegar os m�todos que foram def na interface
		//como a aplica��o vai selecionar o sistema, isso garante que vai ser multiplataforma
		if (Platform.isWindows()){
			//utiliza os m�todos da biblioteca passando para a interface
			conector =(IComunicacaoSensores) Native.loadLibrary("E:\\projetos\\embarcados\\JavaApp\\comunicacaosensores.dll", IComunicacaoSensores.class);
			//C:\\WorkSpaceJava\\JavaApp\\comunicacaosensores.dll
		}else if (Platform.isLinux()){
			conector =(IComunicacaoSensores) Native.loadLibrary("comunicacaosensores.so", IComunicacaoSensores.class);
		}
		return conector;
	}

}
