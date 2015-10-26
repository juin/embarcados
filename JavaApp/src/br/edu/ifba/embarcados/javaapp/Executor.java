package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.conector.FabricaConectores;
import br.edu.ifba.embarcados.javaapp.conector.IComunicacaoSensores;

public class Executor {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		IComunicacaoSensores  conector = FabricaConectores.getConector();
		
		if (conector.iniciar("COM5")==0){//coloca a porta que identificou no arduino
			while (true){
				conector.ler();
				System.out.println("AcelX =" + conector.getAcelX());
				System.out.println("AcelY =" + conector.getAcelY());
				System.out.println("AcelZ =" + conector.getAcelZ());
				
				Thread.sleep(100);
			}
		}

	}

}
